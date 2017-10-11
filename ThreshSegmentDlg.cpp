// ThreshSegmentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "ThreshSegmentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ThreshSegmentDlg dialog


ThreshSegmentDlg::ThreshSegmentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ThreshSegmentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ThreshSegmentDlg)
	//初始直方图为亮度统计直方图
	m_colorSelect = 3;
	//初始阈值为128
	m_threshSelect = 128;
	//}}AFX_DATA_INIT
}


void ThreshSegmentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ThreshSegmentDlg)
	DDX_CBIndex(pDX, IDC_COMBO_colorSelect, m_colorSelect);
	DDX_Slider(pDX, IDC_Slider_ThreshSelect, m_threshSelect);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ThreshSegmentDlg, CDialog)
	//{{AFX_MSG_MAP(ThreshSegmentDlg)
	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO_colorSelect, OnSelchangeCOMBOcolorSelect)
	ON_WM_SIZE()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ThreshSegmentDlg message handlers

BOOL ThreshSegmentDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	CRect rect;
	//指定直方图绘制区域在对话框中的位置
	rect=CRect(25,51,279,151);
	GetDlgItem(IDC_STATIC_HistRect)->MoveWindow(&rect);

	//指定组合框在对话框中的位置
	rect=CRect(14,15,293,200);
	GetDlgItem(IDC_STATIC_ZHK)->MoveWindow(&rect);

	//指定颜色选择组合框在对话框中的位置
	rect=CRect(70,15,200,115);
	GetDlgItem(IDC_COMBO_colorSelect)->MoveWindow(&rect);

	//指定颜色条在对话框中的位置
	rect=CRect(25,155,279,168);
	GetDlgItem(IDC_STATIC_BmpBar)->MoveWindow(&rect);

	//指定直方图灰度均值统计静态文本框在对话框中的位置
	rect=CRect(29,176,130,193);
	GetDlgItem(IDC_STATIC_Average)->MoveWindow(&rect);

	//指定直方图方差统计静态文本框在对话框中的位置
	rect=CRect(180,176,279,193);
	GetDlgItem(IDC_STATIC_Deviation)->MoveWindow(&rect);


	//指定阈值选择滑竿条在对话框中的位置
	rect=CRect(20,205,285,230);
	GetDlgItem(IDC_Slider_ThreshSelect)->MoveWindow(&rect);

	rect=CRect(280,213,310,230);
	GetDlgItem(IDC_STATIC_thresh)->MoveWindow(&rect);

	//指定“确定”按钮在对话框中的位置
	rect=CRect(120,250,170,274);
	GetDlgItem(IDOK)->MoveWindow(&rect);

	//指定“取消”按钮在对话框中的位置
	rect=CRect(200,250,250,274);
	GetDlgItem(IDCANCEL)->MoveWindow(&rect);

	// TODO: Add extra initialization here
	//如果是灰度图像，则调用computeHistGrey()函数统计直方图，
	//否则对于彩色图像要计算亮度直方图
	if(m_histogramDib.m_nBitCount==8)
    	m_histogramDib.computeHistGray();
	else
		m_histogramDib.computeHistBrightness();
	m_histogramDib.computeAverage();
	m_histogramDib.computeDeviation();

	CString szStr;    
    szStr.Format(_T("均值:%.2f"),m_histogramDib.m_average );            
    SetDlgItemText(IDC_STATIC_Average, szStr);            
    szStr.Format(_T("方差:%.2f"), m_histogramDib.m_deviation);            
    SetDlgItemText(IDC_STATIC_Deviation, szStr); 

	CSliderCtrl *pSlider=(CSliderCtrl *)GetDlgItem(IDC_Slider_ThreshSelect);
	pSlider->SetRange(0,255);
	pSlider->SetPos(m_threshSelect);
	szStr.Format(_T("%d"),m_threshSelect);            
    SetDlgItemText(IDC_STATIC_thresh, szStr);            
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ThreshSegmentDlg::OnPaint() 
{
	
	CPaintDC dc(this); // device context for painting

	if(m_histogramDib.m_nBitCount != 8 && m_histogramDib.m_nBitCount != 24) return ;
 	CRect clientRect;  // Set Draw Window

	GetDlgItem(IDC_STATIC_HistRect)->GetWindowRect(&clientRect);
	ScreenToClient(&clientRect);

	BeginWaitCursor();	    // Draw Back Ground
	dc.SelectStockObject(NULL_BRUSH);
	dc.Rectangle(clientRect.left-1, clientRect.top,
                          clientRect.right+3, clientRect.bottom+1);
	
	
	unsigned int max=0;
	int i = 0;
	for(i=0;i<256;i++){
		if(m_histogramDib.m_histArray[i]>max)
			max=m_histogramDib.m_histArray[i];
	}
	
	DWORD bufTemp[256];
	double x=clientRect.Height();
	for(i=0;i<256;i++){
		bufTemp[i]=(unsigned long)((float)m_histogramDib.m_histArray[i]*x/max);
	}
	for(i=clientRect.left;i<=clientRect.right;i++){
		dc.MoveTo(i,clientRect.bottom);
		dc.LineTo(i,clientRect.bottom-bufTemp[i-clientRect.left]);
	}   

	//创建蓝色画笔
	CPen *pBluePen=new CPen;
	pBluePen->CreatePen(PS_SOLID,1,RGB(0,0,255));

	//选中当前蓝色画笔，并保存旧的画笔
	CGdiObject *pOldPen=dc.SelectObject(pBluePen);

	//在直方图中画出阈值线位置
	dc.MoveTo(m_threshSelect+25,clientRect.bottom);
	dc.LineTo(m_threshSelect+25,clientRect.top);

	//恢复旧画笔
	dc.SelectObject(pOldPen);

 	EndWaitCursor();
}

void ThreshSegmentDlg::OnSelchangeCOMBOcolorSelect() 
{
	UpdateData(1);
	if(m_histogramDib.m_nBitCount!=24){
		m_colorSelect=3;
		UpdateData(0);
		return;
	}
	//如果颜色选择变量为0，则计算蓝色通道直方图
	if(m_colorSelect==0)
		m_histogramDib.computeHistBlue();
	else if(m_colorSelect==1)//绿色通道直方图
		m_histogramDib.computeHistGreen();
	else if(m_colorSelect==2)
		m_histogramDib.computeHistRed();//红色通道直方图
	else if(m_colorSelect==3)
		m_histogramDib.computeHistBrightness();//亮度直方图
	m_histogramDib.computeAverage();//计算直方图均值
	m_histogramDib.computeDeviation();//计算直方图方差

	CString szStr;    
    szStr.Format(_T("均值:%.2f"),m_histogramDib.m_average );            
    SetDlgItemText(IDC_STATIC_Average, szStr);            
    szStr.Format(_T("方差:%.2f"), m_histogramDib.m_deviation);            
    SetDlgItemText(IDC_STATIC_Deviation, szStr); 
	Invalidate();
	
}

void ThreshSegmentDlg::OnSize(UINT nType, int cx, int cy) 
{
	//设置阈值分割对话框的大小
	CDialog::OnSize(nType, cx, cy);

	CRect rect;
	rect=CRect(405,261,722,580);
	//将对话框移至窗口指定位置
	MoveWindow(&rect);
}

void ThreshSegmentDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// 根据滑竿条位置更新阈值
	CSliderCtrl *pSlider=(CSliderCtrl *)pScrollBar;
	m_threshSelect=pSlider->GetPos();

	//在静态框中显示调整的阈值
	CString szStr;
	szStr.Format(_T("%d"),m_threshSelect);            
    SetDlgItemText(IDC_STATIC_thresh, szStr);  
	//刷新显示
	Invalidate();
}

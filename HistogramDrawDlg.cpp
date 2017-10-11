// HistogramDrawDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "HistogramDrawDlg.h"
#include "ImageCenterDib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// HistogramDrawDlg dialog


HistogramDrawDlg::HistogramDrawDlg(CWnd* pParent /*=NULL*/)
	: CDialog(HistogramDrawDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(HistogramDrawDlg)
	//初始化颜色通道为亮度信息
	m_colorSelect = 3;
	//}}AFX_DATA_INIT
}


void HistogramDrawDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(HistogramDrawDlg)
	DDX_CBIndex(pDX, IDC_COMBO_colorSelect, m_colorSelect);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(HistogramDrawDlg, CDialog)
	//{{AFX_MSG_MAP(HistogramDrawDlg)
	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO_colorSelect, OnSelchangeCOMBOcolorSelect)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// HistogramDrawDlg message handlers
//对话框初始化
BOOL HistogramDrawDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//将静态框1移至rect指定位置，用来画直方图
	CRect rect;
	rect=CRect(25,51,279,151);
	GetDlgItem(IDC_STATIC_HistRect)->MoveWindow(&rect);

	//将组合框移至rect指定的位置
	rect=CRect(14,15,293,200);
	GetDlgItem(IDC_STATIC_ZHK)->MoveWindow(&rect);

	//将列表框移至rect指定的位置
	rect=CRect(70,15,200,115);
	GetDlgItem(IDC_COMBO_colorSelect)->MoveWindow(&rect);

	//将颜色提示条移至指定位置
	rect=CRect(25,155,279,168);
	GetDlgItem(IDC_STATIC_BmpBar)->MoveWindow(&rect);

	//将均值静态框移至指定位置
	rect=CRect(29,176,130,193);
	GetDlgItem(IDC_STATIC_Average)->MoveWindow(&rect);

	//将方差静态框移至指定位置
	rect=CRect(180,176,279,193);
	GetDlgItem(IDC_STATIC_Deviation)->MoveWindow(&rect);

	//将确定按钮移至指定位置
	rect=CRect(221,210,277,234);
	GetDlgItem(IDOK)->MoveWindow(&rect);

	// 如果是灰度图像，则调用灰度直方图统计函数
	if(m_histogramDib.m_nBitCount==8)
    	m_histogramDib.computeHistGray();
	else//彩色图像则统计亮度直方图
		m_histogramDib.computeHistBrightness();

	//计算直方图的均值和方差
	m_histogramDib.computeAverage();
	m_histogramDib.computeDeviation();

	//将均值信息显示在均值静态框中
	CString szStr;    
    szStr.Format(_T("均值:%.2f"),m_histogramDib.m_average );            
    SetDlgItemText(IDC_STATIC_Average, szStr);         
	
	//将方差信息显示在方差静态框中
    szStr.Format(_T("方差:%.2f"), m_histogramDib.m_deviation);            
    SetDlgItemText(IDC_STATIC_Deviation, szStr); 

	return TRUE;  
}

void HistogramDrawDlg::OnPaint() 
{
	//设备环境对象
	CPaintDC dc(this); // device context for painting

	//彩色和灰度图像有效
	if(m_histogramDib.m_nBitCount != 8 && m_histogramDib.m_nBitCount != 24) 
		return ;

	//获取直方图绘制静态框的矩形区域
 	CRect clientRect;  
	GetDlgItem(IDC_STATIC_HistRect)->GetWindowRect(&clientRect);
	ScreenToClient(&clientRect);

	BeginWaitCursor();	    // Draw Back Ground
	//画背景
	dc.SelectStockObject(NULL_BRUSH);
	dc.Rectangle(clientRect.left-1, clientRect.top,
                          clientRect.right+3, clientRect.bottom+1);
	
	//画直方图灰度频率与直方图绘制矩形区域比例关系，画直方图
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

 	EndWaitCursor();
}

void HistogramDrawDlg::OnSelchangeCOMBOcolorSelect() 
{
	//该函数根据用户选择直方图颜色通道不同来作出相应操作
	//将对话框用户设置的数据传入对话框内
	UpdateData(1);
	if(m_histogramDib.m_nBitCount!=24){
		m_colorSelect=3;
		UpdateData(0);
		return;
	}

	//根据用户的选择调用相应通道的直方图统计函数
	if(m_colorSelect==0)
		m_histogramDib.computeHistBlue();
	else if(m_colorSelect==1)
		m_histogramDib.computeHistGreen();
	else if(m_colorSelect==2)
		m_histogramDib.computeHistRed();
	else if(m_colorSelect==3)
		m_histogramDib.computeHistBrightness();

	//计算直方图的均值和方差
	m_histogramDib.computeAverage();
	m_histogramDib.computeDeviation();

	//显示均值和方差在相应静态框中
	CString szStr;    
    szStr.Format(_T("均值:%.2f"),m_histogramDib.m_average );            
    SetDlgItemText(IDC_STATIC_Average, szStr);            
    szStr.Format(_T("方差:%.2f"), m_histogramDib.m_deviation);            
    SetDlgItemText(IDC_STATIC_Deviation, szStr); 

	//刷新
	Invalidate();
}

void HistogramDrawDlg::OnSize(UINT nType, int cx, int cy) 
{
	//该函数在创建对话框时调用，确定直方图对话框的大小及客户区中的位置

	CDialog::OnSize(nType, cx, cy);
	CRect rect;
	rect=CRect(405,261,717,545);
	MoveWindow(&rect);
}

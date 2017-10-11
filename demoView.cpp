  // demoView.cpp : implementation of the CDemoView class
//
#include "stdio.h"
#include "stdafx.h"
#include "demo.h"

#include "demoDoc.h"
#include "demoView.h"
#include"math.h"
#include "MainFrm.h"
#include "ImageCenterDib.h"//dib类头文件
#include "SpecialEffectShow.h"//图象的特效显示的头文件
#include "GrayTrans.h"//灰度变换类
#include "linearStretchParamDlg.h"//线性拉伸参数设置对话框
#include "histogram.h"//直方图类
#include "HistogramDrawDlg.h"//直方图绘制对话框
#include "GeometryTrans.h"//几何变换类
#include "GeometryMoveDlg.h"//平移设置对话框
#include "FFT.h"//快速傅立叶变换类
#include "Morphology.h"//形态学处理类
#include "MaskDefineDlg.h"//模板自定义对话框
#include "ThreshSegmentDlg.h"//阈值分割对话框
#include "Segment.h"//图像分割类
#include "RotateSetDlg.h"//旋转设置对话框
#include "Match.h"//匹配类
#include "NonlinearStretchDlg.h"//非线性拉伸(对数或指数)参数设置对话框
#include "RegionGrowDlg.h" //区域生长参数设置对话框
#include "Watershed.h"//水域分割类
#include "WatershedParaDlg.h"//水域分割参数设置对话框
#include "ImageRestore.h"//运动模糊恢复类
#include "ProjectRestoreDlg.h"//投影法运动模糊恢复设置对话框
#include "WienterFilterDlg.h"//维纳滤波设置对话框
#include "InverseFilterDlg.h"//逆旅滤波设置对话框
#include "transeform.h"//小波变换
#include "MedianDialog.h"//中值滤波选择模板对话框
#include "AvgDialog.h"//均值滤波选择模板对话框
#include "ImgEnhance.h"//图像增强类
#include "transform_DCT.h"//离散余弦变换
#include "Register.h"
#include "Zoomdlg.h"//缩放设置对话框
#include "Register.h"
#include "PhaseCorre.h"

//全局变量
Transform_FFT FFTTrans;//傅立叶变换类的对象
transeform_wavelet wltTrans;//小波变换类的对象
transform_DCT DIBDCT;//DCT变换类对象
ImgCenterDib DIB1;//配准算法的输入图像1
ImgCenterDib DIB2;//配准算法的输入图像2

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CScrollView)

BEGIN_MESSAGE_MAP(CDemoView, CScrollView)
	//{{AFX_MSG_MAP(CDemoView)
	ON_COMMAND(ID_SOBEL, OnSobel)
	ON_COMMAND(id_ImgReverse, OnImgReverse)
	ON_COMMAND(id_ColorToGray, OnColorToGray)
	ON_COMMAND(id_Binary, OnBinary)
	ON_COMMAND(id_GrayToColor, OnGrayToColor)
	ON_COMMAND(id_LinearStrecth, OnLinearStrecth)
	ON_COMMAND(id_HistgramAver, OnHistgramAver)
	ON_COMMAND(id_HistogramDraw, OnHistogramDraw)
	ON_COMMAND(ID_FFT, OnFft)
	ON_COMMAND(id_IFFT, OnIfft)
	ON_COMMAND(id_Clockwise90, OnClockwise90)
	ON_COMMAND(id_Anticlockwise90, OnAnticlockwise90)
	ON_COMMAND(id_Rotate180, OnRotate180)
	ON_COMMAND(id_Zoom, OnZoom)
	ON_COMMAND(id_Rotate, OnRotate)
	ON_COMMAND(id_ErosionForBinary, OnErosionForBinary)
	ON_COMMAND(ID__DilationForBinary, OnDilationForBinary)
	ON_COMMAND(id_OpenForBinary, OnOpenForBinary)
	ON_COMMAND(id_CloseForBinary, OnCloseForBinary)
	ON_COMMAND(id_InnerEdgeForBinary, OnInnerEdgeForBinary)
	ON_COMMAND(id_OuterEdgeForBinary, OnOuterEdgeForBinary)
	ON_COMMAND(id_HitMissThinning, OnHitMissThinning)
	ON_COMMAND(id_ErosionForGray, OnErosionForGray)
	ON_COMMAND(id_DilationForGray, OnDilationForGray)
	ON_COMMAND(id_OpenForGray, OnOpenForGray)
	ON_COMMAND(id_CloseForGray, OnCloseForGray)
	ON_COMMAND(id_MorphoGradientForGray, OnMorphoGradientForGray)
	ON_COMMAND(id_TopHatPeak, OnTopHatPeak)
	ON_COMMAND(id_TopHatVally, OnTopHatVally)
	ON_COMMAND(id_TopHatPeakAndVally, OnTopHatPeakAndVally)
	ON_COMMAND(id_InteractiveThresh, OnInteractiveThresh)
	ON_COMMAND(id_OtusThreshold, OnOtusThreshold)
	ON_COMMAND(id_Robert, OnRobert)
	ON_COMMAND(id_Prewitt, OnPrewitt)
	ON_COMMAND(id_EdgeSelectTemplete, OnEdgeSelectTemplete)
	ON_COMMAND(id_HoughTransform, OnHoughTransform)
	ON_COMMAND(id_LineDetectByHough, OnLineDetectByHough)
	ON_COMMAND(id_RegionGrow, OnRegionGrow)
	ON_COMMAND(id_ContourExtract, OnContourExtract)
	ON_COMMAND(id_Gauss_laplacian, OnGausslaplacian)
	ON_COMMAND(id_WatershedSegment, OnWatershedSegment)
	ON_COMMAND(id_DuiShuStretch, OnDuiShuStretch)
	ON_COMMAND(id_ZhiShuStretch, OnZhiShuStretch)
	ON_COMMAND(id_Move, OnMove)
	ON_COMMAND(id_ZhuanZhi, OnZhuanZhi)
	ON_COMMAND(id_HorizontalMirror, OnHorizontalMirror)
	ON_COMMAND(id_VerticalMirror, OnVerticalMirror)
	ON_COMMAND(id_FFTEx, OnFFTEx)
	ON_COMMAND(id_IFFTEx, OnIFFTEx)
	ON_COMMAND(id_Laplacian, OnLaplacian)
	ON_COMMAND(id_Krisch, OnKrisch)
	ON_COMMAND(id_ContourTrace, OnContourTrace)
	ON_COMMAND(id_MorphoContourForBinary, OnMorphoContourForBinary)
	ON_COMMAND(ID_SCAN, OnScan)
	ON_COMMAND(ID_SLIDE, OnSlide)
	ON_COMMAND(ID_FADEIN, OnFadeIn)
	ON_COMMAND(ID_MOSAIK, OnMosaik)
	ON_COMMAND(ID_ProjRestore, OnProjRestore)
	ON_COMMAND(ID_WienerFilter, OnWienerFilter)
	ON_COMMAND(ID_InverseFilter, OnInverseFilter)
	ON_COMMAND(ID_SET2ZERO_DENOISE, OnSet2zeroDenoise)
	ON_COMMAND(ID__HARDTHRESHOLD, OnHardthreshold)
	ON_COMMAND(ID_SOFTTHRESHOLD, OnSoftthreshold)
	ON_COMMAND(ID_PepperSaltNoise, OnPepperSaltNoise)
	ON_COMMAND(ID_Random, OnRandom)
	ON_COMMAND(ID_AveSmooth, OnAveSmooth)
	ON_COMMAND(id_MiddleSmooth, OnMiddleSmooth)
	ON_COMMAND(ID_LaplacienSharp, OnLaplacienSharp)
	ON_COMMAND(ID_CHOOSE_MASK, OnChooseMask)
	ON_COMMAND(ID_POWER_SMOOTH, OnPowerSmooth)
	ON_COMMAND(id_HarrWaveletTrans, OnHarrWaveletTrans)
	ON_COMMAND(id_HarrWaveletITrans, OnHarrWaveletITrans)
	ON_COMMAND(ID_DCT, OnDct)
	ON_COMMAND(ID_GRADESHARP, OnGradesharp)
	ON_COMMAND(ID_SNR, OnSnr)
	ON_COMMAND(id_IDCT, OnIdct)
	ON_COMMAND(ID_SECONDIMAGE, OnSecondimage)
	ON_COMMAND(ID_FIRSTIMAGE, OnFirstimage)
	ON_COMMAND(id_MatchConner, OnMatchConner)
	ON_COMMAND(id_MatchTemplet, OnMatchTemplet)
	ON_COMMAND(id_ConnerDetect, OnConnerDetect)
	ON_COMMAND(ID_MOTION_FOPEN1, OnMotionFopen1)
	ON_COMMAND(ID_MOTION_FOPEN2, OnMotionFopen2)
	ON_COMMAND(ID_MOTION_FEST, OnMotionFest)
	ON_COMMAND(ID_MITON_DEST, OnMitonDest)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDemoView construction/destruction

CDemoView::CDemoView()
{

}

CDemoView::~CDemoView()
{

}

BOOL CDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView drawing

void CDemoView::OnDraw(CDC* pDC)
{

	//获取文档类指针
	CDemoDoc* pDoc = GetDocument();

	if(!pDoc->isAvi){
		//返回m_dib的指针
		ImgCenterDib *pDib=pDoc->GetPDib();

		//获取DIB的尺寸
		CSize sizeFileDib = pDib->GetDimensions();

		//显示DIB
		pDib->Draw(pDC, CPoint(0, 0), sizeFileDib);

	}
	else
	{
		
	}
}

void CDemoView::OnInitialUpdate()
{

	CScrollView::OnInitialUpdate();

	//获取文档类指针
	CDemoDoc* pDoc = GetDocument();

	//获取DIB的指针
	ImgCenterDib *pDib=pDoc->GetPDib();

	//根据DIB尺寸设置视窗大小
	if(pDib!=NULL)
    	SetScrollSizes(MM_TEXT, pDib->GetDimensions());
	else{
		//如果m_dib为空，则设置一个固定的尺寸
		CSize sizeTotal;
		sizeTotal.cx = sizeTotal.cy = 100;
		SetScrollSizes(MM_TEXT, sizeTotal);
	}
	
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView printing

BOOL CDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDemoView diagnostics

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDemoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDemoDoc* CDemoView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDemoDoc)));
	return (CDemoDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDemoView message handlers



void CDemoView::OnImgReverse() 
{
	//获取文档类指针
	CDemoDoc *pDoc=GetDocument();

	//获取ImgCenterDib类对象的指针，访问当前DIB数据
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//DIB类型判断
	if(pDib->m_nBitCount!=24&&pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理彩色和灰度图像"),MB_OK,0);
		return ;
	}
	
	//将pDib中的图像数据作为输入数据，调用带参数的构造函数，
	//定义GrayTrans类的对象graytrans
	GrayTrans graytrans(pDib->GetDimensions(),
		pDib->m_nBitCount,pDib->m_lpColorTable,pDib->m_pImgData);

	//调用ReverseImg()对图像求反
	graytrans.ReverseImg();
	
	//建立一个新视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);

	//发送新建文件的消息，创建一个新的文档-视图
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	//获取新建视图指针
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	

	//获取相关联的新的文档类指针
	CDemoDoc* pDocNew=pView->GetDocument();

	//获取新文档中的ImgCenterDib类对象指针
	ImgCenterDib *dibNew=pDocNew->GetPDib();

	//将变换后的输出图像作为新建文档的DIB进行显示
	dibNew->ReplaceDib(graytrans.GetDimensions(),graytrans.m_nBitCountOut,graytrans.m_lpColorTableOut, graytrans.m_pImgDataOut);
	
	//设置滚动窗口
	pView->OnInitialUpdate();

	//文档数据置脏，提示存盘信息
	pDocNew->SetModifiedFlag(TRUE);

	//各视图刷新显示
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnColorToGray() 
{
	//获取文档类指针
	CDemoDoc *pDoc=GetDocument();
	//获取ImgCenterDib类对象m_dib的指针，访问当前DIB数据
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理彩色图像
	if(pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理彩色图像"),MB_OK,0);
		return ;
	}
	
	//将pDib中的图像数据作为输入数据，调用带参数的构造函数，
	//定义GrayTrans类的对象graytrans
	GrayTrans graytrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//彩色变灰度格式
	graytrans.ColorToGray();
	
	//建立一个新视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	
	//发送新建文件的消息，创建一个新的文档-视图
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	//获取新建视图指针
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	
	//获取相关联的新的文档类指针
	CDemoDoc* pDocNew=pView->GetDocument();

	//获取新文档中的ImgCenterDib类对象指针
	ImgCenterDib *dibNew=pDocNew->GetPDib();

	//将变换后的输出图像作为新建文档的DIB进行显示
	dibNew->ReplaceDib(graytrans.GetDimensions(),graytrans.m_nBitCountOut,graytrans.m_lpColorTableOut, graytrans.m_pImgDataOut);
	
	//设置滚动窗口
	pView->OnInitialUpdate();


	//文档数据置脏，提示存盘信息
	pDocNew->SetModifiedFlag(TRUE);

	//各视图刷新显示
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnBinary() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//异常判断
	if(pDib->m_nBitCount!=24&&pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理彩色和灰度图像"),MB_OK,0);
		return ;
	}
	
	//将pDib中的图像数据作为输入数据，调用带参数的构造函数，
	//定义GrayTrans类的对象graytrans
	GrayTrans graytrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//调用Binary()对图像进行二值化，缺省状态下阈值为
	graytrans.Binary();
	
	//建立一个新视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(graytrans.GetDimensions(),graytrans.m_nBitCountOut,graytrans.m_lpColorTableOut, graytrans.m_pImgDataOut);
	pView->OnInitialUpdate();	
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnGrayToColor() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//将pDib中的图像数据作为输入数据，调用带参数的构造函数，
	//定义GrayTrans类的对象graytrans
	GrayTrans graytrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//灰度变彩色格式
	graytrans.GrayToColor();
	
	//建立一个新视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(graytrans.GetDimensions(),graytrans.m_nBitCountOut,graytrans.m_lpColorTableOut, graytrans.m_pImgDataOut);
	pView->OnInitialUpdate();	
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnLinearStrecth() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//异常判断
	if(pDib->m_nBitCount!=24&&pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理彩色和灰度图像"),MB_OK,0);
		return ;
	}

	//线性拉伸参数设置对话框
	linearStretchParamDlg dlgPara;
	if(dlgPara.DoModal()==IDOK){
		//获取用户设置的两个拉伸转折点
		CPoint point[2];
		point[0].x=dlgPara.m_firstPointX;
		point[0].y=dlgPara.m_firstPointY;
		point[1].x=dlgPara.m_secondPointX;
		point[1].y=dlgPara.m_secondPointY;

		//判断参数的合理性
		if(point[0].x<0||point[0].x>255||point[1].x<0||point[1].x>255
			||point[0].y<0||point[0].y>255||point[1].y<0||point[1].y>255
			||point[0].x>point[1].x){
			::MessageBox(0,_T("参数不合理"),MB_OK,0);
			return;
		}

		//定义灰度变换的类对象
		GrayTrans graytrans(pDib->GetDimensions(),pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);

		//线性拉伸
		graytrans.LinearStrech(point);
		
		//新建窗口显示
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);		
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();	
		dibNew->ReplaceDib(graytrans.GetDimensions(),graytrans.m_nBitCountOut,graytrans.m_lpColorTableOut, graytrans.m_pImgDataOut);
		pView->OnInitialUpdate();	
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}


void CDemoView::OnDuiShuStretch() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//异常判断
	if(pDib->m_nBitCount!=24&&pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理彩色和灰度图像"),MB_OK,0);
		return ;
	}
	
	NonlinearStretchDlg dlgPara;
	//对数拉伸参数初始化
	dlgPara.m_a=0;
	dlgPara.m_b=(float)0.033;
	dlgPara.m_c=(float)2;
	if(dlgPara.DoModal()==IDOK){
		if(dlgPara.m_b==0||dlgPara.m_c==1){
			::MessageBox(0,_T("b不能为0，且c不能为1"),MB_OK,0);
			return;
		}
		//定义灰度变换的类对象
		GrayTrans graytrans(pDib->GetDimensions(),pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);
		
		//传递对数拉伸参数，进行非线性拉伸
		graytrans.DuiShuStrech(dlgPara.m_a, dlgPara.m_b, dlgPara.m_c);
		
		//新建窗口显示
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);		
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();	
		dibNew->ReplaceDib(graytrans.GetDimensions(),graytrans.m_nBitCountOut,graytrans.m_lpColorTableOut, graytrans.m_pImgDataOut);
		pView->OnInitialUpdate();	
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}

void CDemoView::OnZhiShuStretch() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//异常判断
	if(pDib->m_nBitCount!=24&&pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理彩色和灰度图像"),MB_OK,0);
		return ;
	}
	
	NonlinearStretchDlg dlgPara;
	//指数拉伸参数初始化
	dlgPara.m_a=(float)128;
	dlgPara.m_b=2;
	dlgPara.m_c=(float)0.6;
	if(dlgPara.DoModal()==IDOK){
		//定义灰度变换的类对象
		GrayTrans graytrans(pDib->GetDimensions(),pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);
		
		//传递指数拉伸参数，进行非线性拉伸
		graytrans.ZhiShuStrech(dlgPara.m_a, dlgPara.m_b, dlgPara.m_c);
		
		//新建窗口显示
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);		
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();	
		dibNew->ReplaceDib(graytrans.GetDimensions(),graytrans.m_nBitCountOut,graytrans.m_lpColorTableOut, graytrans.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}

void CDemoView::OnHistgramAver() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//将pDib中的图像数据作为输入数据，调用带参数的构造函数，
	//定义Histogram类的对象hist
	Histogram hist(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//直方图均衡
	hist.histAve();
	
	//新建视图窗口，显示变换结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(hist.GetDimensions(),hist.m_nBitCount,hist.m_lpColorTable, hist.m_pImgDataOut);
	pView->OnInitialUpdate();	
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnHistogramDraw() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//异常判断
  if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
	  ::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
	  return ;
  }

  //直方图绘制对话框
  HistogramDrawDlg dlgHist;
  dlgHist.m_histogramDib.ReplaceDib(pDib->GetDimensions(),pDib->m_nBitCount,
	  pDib->m_lpColorTable, pDib->m_pImgData);

  //显示直方图
  dlgHist.DoModal();
}



void CDemoView::OnFft() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断图像大小是否为2的幂次的方阵
	int isValidateFlag=1;
	int width=pDib->GetDimensions().cx;
	int height=pDib->GetDimensions().cy;
	int i=1;
	while(i<width)
		i=i*2;
	if(i!=width)//图像宽不是2的幂次方
		isValidateFlag=0;

	i=1;
	while(i<height)
		i=i*2;
	if(i!=height)//图像高不是2的幂次方
		isValidateFlag=0;

	if(isValidateFlag==0){
		::MessageBox(0,_T("输入图像的宽和高应为2的幂次方"),MB_OK,0);
		return ;
	}
	
	//输入图像数据给transform_FFT类对象FFTTrans
	FFTTrans.InputImgData(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//快速傅立叶变换
	FFTTrans.Fourier();
	
	//新建视图窗口，显示变换结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(FFTTrans.GetDimensions(),FFTTrans.m_nBitCountOut,
		FFTTrans.m_lpColorTable, FFTTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
}

void CDemoView::OnIfft() 
{
	//傅立叶反变换
	FFTTrans.IFourier();
	
    //新建视图窗口，显示图像恢复的结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(FFTTrans.GetDimensions(),FFTTrans.m_nBitCountOut,
		FFTTrans.m_lpColorTable, FFTTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
}


void CDemoView::OnFFTEx() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
    //输入图像数据给transform_FFT类对象FFTTrans
	FFTTrans.InputImgData(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//调用FourierEx()函数进行快速傅立叶变换，该函数不要求输入图像为2的幂次的方阵
	FFTTrans.FourierEx();
	
	//新建视图窗口，显示变换结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(FFTTrans.GetDimensions(),FFTTrans.m_nBitCountOut,
		FFTTrans.m_lpColorTable, FFTTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
}

void CDemoView::OnIFFTEx() 
{
	//傅立叶反变换
	FFTTrans.IFourierEx();
	
	//新建视图窗口，显示图像恢复的结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(FFTTrans.GetDimensions(),FFTTrans.m_nBitCountOut,
		FFTTrans.m_lpColorTable, FFTTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}


void CDemoView::OnMove() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//平移参数设置对话框
	GeometryMoveDlg dlgPara;
	if(dlgPara.DoModal()==IDOK){
		//定义GeometryTrans类的对象geoTrans，用当前DIB对其初始化
		GeometryTrans geoTrans(pDib->GetDimensions(),pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);
		
		//将dlgPara.m_OffsetX, dlgPara.m_OffsetY作为平移量，对图像平移
		geoTrans.Move(dlgPara.m_OffsetX, dlgPara.m_OffsetY);
		
		//新建视图窗口，显示变换结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(geoTrans.GetDimensions(),geoTrans.m_nBitCountOut,geoTrans.m_lpColorTable, geoTrans.m_pImgDataOut);
		pView->OnInitialUpdate();		
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}


void CDemoView::OnHorizontalMirror() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义GeometryTrans类的对象geoTrans，用当前DIB对其初始化
	GeometryTrans geoTrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//水平镜像
	geoTrans.MirrorHori();
	
	//新建视图窗口，显示变换结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(geoTrans.GetDimensions(),geoTrans.m_nBitCountOut,
		geoTrans.m_lpColorTable, geoTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnVerticalMirror() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义GeometryTrans类的对象geoTrans，用当前DIB对其初始化
	GeometryTrans geoTrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//垂直镜像
	geoTrans.MirrorVerti();
	
	//新建视图窗口，显示变换结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(geoTrans.GetDimensions(),geoTrans.m_nBitCountOut,
		geoTrans.m_lpColorTable, geoTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}


void CDemoView::OnZhuanZhi() 
{
	
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义GeometryTrans类的对象geoTrans，用当前DIB对其初始化
	GeometryTrans geoTrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//图像转置
	geoTrans.ZhuanZhi();
	
	//新建视图窗口，显示变换结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW); 
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(geoTrans.GetDimensions(),geoTrans.m_nBitCountOut,
		geoTrans.m_lpColorTable, geoTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
}


void CDemoView::OnClockwise90() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义GeometryTrans类的对象geoTrans，用当前DIB对其初始化
	GeometryTrans geoTrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//顺时针90度
	geoTrans.Clockwise90();
	
	//新建视图窗口，显示变换结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(geoTrans.GetDimensions(),geoTrans.m_nBitCountOut,
		geoTrans.m_lpColorTable, geoTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnAnticlockwise90() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义GeometryTrans类的对象geoTrans，用当前DIB对其初始化
	GeometryTrans geoTrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//逆时针90度
	geoTrans.Anticlockwise90();
	
	//新建视图窗口，显示变换结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(geoTrans.GetDimensions(),geoTrans.m_nBitCountOut,
		geoTrans.m_lpColorTable, geoTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}


void CDemoView::OnRotate180() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义GeometryTrans类的对象geoTrans，用当前DIB对其初始化
	GeometryTrans geoTrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//旋转180度
	geoTrans.Rotate180();
	
	//新建视图窗口，显示变换结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(geoTrans.GetDimensions(),geoTrans.m_nBitCountOut,
		geoTrans.m_lpColorTable, geoTrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}


void CDemoView::OnZoom() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//原图像尺寸
	CSize oldImgSize=pDib->GetDimensions();
	
	//缩放参数设置对话框
	Zoomdlg dlgPara;
	
	//缩放参数设置对话框中原图像尺寸变量赋值
	dlgPara.m_oldHeight=oldImgSize.cy;
	dlgPara.m_oldWidth=oldImgSize.cx;
	
	if(dlgPara.DoModal()==IDOK){
		//定义GeometryTrans类的对象geoTrans，用当前DIB对其初始化
		GeometryTrans geoTrans(pDib->GetDimensions(),pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);
		
		//根据指定的新图的大小对图像进行缩放缩放
		geoTrans.Zoom(dlgPara.m_newWidth, dlgPara.m_newHeight,
			         dlgPara.m_interpolationSelect);
		
		//新建视图窗口，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(geoTrans.GetDimensions(),geoTrans.m_nBitCountOut,
			geoTrans.m_lpColorTable, geoTrans.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}

void CDemoView::OnRotate() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	//旋转参数设置对话框
	RotateSetDlg dlgPara;
	if(dlgPara.DoModal()==IDOK){
		//定义GeometryTrans类的对象geoTrans，用当前DIB对其初始化
		GeometryTrans geoTrans(pDib->GetDimensions(),pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);
		
		//调用Rotate函数进行图像旋转，将角度和插值方式参数传进函数
		geoTrans.Rotate(dlgPara.m_rotateAngle, dlgPara.m_interpolationSelect);
		
		//新建视图窗口，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(geoTrans.GetDimensions(),geoTrans.m_nBitCountOut,
			geoTrans.m_lpColorTable, geoTrans.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
	
}

/***********************************************************************
* 函数名称：
* ValidBinaryMorphMask()
*
*函数参数：
*  int *maskBuf  -结构元素缓冲区
*  int maskW  -结构元素的宽
*  int maskH  -结构元素的高
*
*返回值：
*   无
*
*说明：击中击不中变换,0代表背景,255代表目标
***********************************************************************/
bool CDemoView::ValidBinaryMorphMask(int *maskBuf, int maskW, int maskH)
{
	int i, j, count=0, flag=1;
	for(i=0;i<maskH;i++){
		for(j=0;j<maskW;j++){
			if(maskBuf[i*maskW+j]==1)
				count++;
			if(maskBuf[i*maskW+j]!=0&&maskBuf[i*maskW+j]!=1)
				flag=0;
		}
	}
	//如果结构元素中有非0和1的数或者1的个数少于1，则为无效输入，否则为有
	//效结构元素
	if(flag==0||count<1)
		return 0;
	else 
		return 1;
}
void CDemoView::OnErosionForBinary() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}


	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(size,pDib->m_nBitCount,pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学结构元素选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//验证结构元素的有效性
		if(ValidBinaryMorphMask(dlgPara.m_defineMask,5,5)==0){
			::MessageBox(0,_T("结构元素输入有误，只能是0和1的数，且至少有一个以上的1！"),MB_OK,0);
			return;
		}

		//输入结构元素
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//二值腐蚀
		morph.BinaryErosion();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}

}

void CDemoView::OnDilationForBinary() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}


	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(size,pDib->m_nBitCount,pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学结构元素选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//验证结构元素的有效性
		if(ValidBinaryMorphMask(dlgPara.m_defineMask,5,5)==0){
			::MessageBox(0,_T("结构元素输入有误，只能是0和1的数，且至少有一个以上的1！"),MB_OK,0);
			return;
		}

		//输入结构元素
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//二值膨胀
		morph.BinaryDilation();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}
	
}

void CDemoView::OnOpenForBinary() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}


	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(size,pDib->m_nBitCount,pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学结构元素选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//验证结构元素的有效性
		if(ValidBinaryMorphMask(dlgPara.m_defineMask,5,5)==0){
			::MessageBox(0,_T("结构元素输入有误，只能是0和1的数，且至少有一个以上的1！"),MB_OK,0);
			return;
		}

		//输入结构元素
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//二值开
		morph.BinaryOpen();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}
	
}

void CDemoView::OnCloseForBinary() 
{
//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}


	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(size,pDib->m_nBitCount,pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学结构元素选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//验证结构元素的有效性
		if(ValidBinaryMorphMask(dlgPara.m_defineMask,5,5)==0){
			::MessageBox(0,_T("结构元素输入有误，只能是0和1的数，且至少有一个以上的1！"),MB_OK,0);
			return;
		}

		//输入结构元素
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//二值闭
		morph.BinaryClose();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}
	
}

void CDemoView::OnInnerEdgeForBinary() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}


	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(size,pDib->m_nBitCount,pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学结构元素选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//验证结构元素的有效性
		if(ValidBinaryMorphMask(dlgPara.m_defineMask,5,5)==0){
			::MessageBox(0,_T("结构元素输入有误，只能是0和1的数，且至少有一个以上的1！"),MB_OK,0);
			return;
		}

		//输入结构元素
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//二值形态学内边界
		morph.BinaryInnerEdge();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}

}

void CDemoView::OnOuterEdgeForBinary() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}


	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(size,pDib->m_nBitCount,pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学结构元素选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//验证结构元素的有效性
		if(ValidBinaryMorphMask(dlgPara.m_defineMask,5,5)==0){
			::MessageBox(0,_T("结构元素输入有误，只能是0和1的数，且至少有一个以上的1！"),MB_OK,0);
			return;
		}

		//输入结构元素
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//二值形态学外边界
		morph.BinaryOuterEdge();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}
}

void CDemoView::OnMorphoContourForBinary() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}


	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(size,pDib->m_nBitCount,pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学结构元素选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//验证结构元素的有效性
		if(ValidBinaryMorphMask(dlgPara.m_defineMask,5,5)==0){
			::MessageBox(0,_T("结构元素输入有误，只能是0和1的数，且至少有一个以上的1！"),MB_OK,0);
			return;
		}

		//输入结构元素
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//二值形态学边界
		morph.BinaryContour();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}

}

void CDemoView::OnHitMissThinning() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}


	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//击中击不中进行细化的结构元素是内部定义的,不需要输入
	//morph.InputMask(mask);

	//击中击不中变换进行细化
	morph.MorphoThinning();

	//新建视图，显示处理结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnErosionForGray() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学模板选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	int i,j;
	for(i=1;i<4;i++){
			for(j=1;j<4;j++){
				dlgPara.m_defineMask[i*5+j]=1;
			}
	}
	if(dlgPara.DoModal()==IDOK){
		//输入模板
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//灰值腐蚀
		morph.GrayErosion();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}

}

void CDemoView::OnDilationForGray() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学模板选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//输入模板
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//灰值膨胀
		morph.GrayDilation();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}
}

void CDemoView::OnOpenForGray() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学模板选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//输入模板
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//灰值开
		morph.GrayOpen();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}
}

void CDemoView::OnCloseForGray() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学模板选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//输入模板
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//灰值闭
		morph.GrayClose();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}	
}

void CDemoView::OnMorphoGradientForGray() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学模板选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//输入模板
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//灰值形态学梯度
		morph.GrayGradient();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}
}

void CDemoView::OnTopHatPeak() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学模板选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//输入模板
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//波峰检测
		morph.GrayTopHatPeak();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}
}

void CDemoView::OnTopHatVally() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学模板选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//输入模板
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//波谷检测
		morph.GrayTopHatVally();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}

}

void CDemoView::OnTopHatPeakAndVally() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//定义形态学类的对象morph，并用当前DIB为其初始化
	Morphology morph(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//形态学模板选择对话框
	MaskDefineDlg dlgPara;

	//缺省的结构元素模板
	dlgPara.m_defineMask[7]=1;
	dlgPara.m_defineMask[11]=1;
	dlgPara.m_defineMask[12]=1;
	dlgPara.m_defineMask[13]=1;
	dlgPara.m_defineMask[17]=1;
	if(dlgPara.DoModal()==IDOK){
		//输入模板
		morph.InputMask(dlgPara.m_defineMask,5,5);

		//峰谷检测
		morph.GrayTopHatPeakVally();

		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(morph.GetDimensions(),morph.m_nBitCountOut,morph.m_lpColorTableOut, morph.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);	
	}
}

void CDemoView::OnInteractiveThresh() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//阈值分割对话框类对象threshDlg
	ThreshSegmentDlg threshDlg;
	
	//用当前DIB数据替换threshDlg中成员m_histogramDib的原始数据
	threshDlg.m_histogramDib.ReplaceDib(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	if(threshDlg.DoModal()==IDOK)
	{
		//定义灰度变换类的对象graytrans，并将当前DIB数据作为输入数据传入graytrans中
		GrayTrans graytrans(pDib->GetDimensions(),pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);

		//根据用户选择的阈值，调用二值化函数分割图像
		graytrans.Binary(threshDlg.m_threshSelect);
		
		//新建视图，显示分割结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		
		dibNew->ReplaceDib(graytrans.GetDimensions(),graytrans.m_nBitCountOut,graytrans.m_lpColorTableOut, graytrans.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
	
}

void CDemoView::OnOtusThreshold() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}

	//用直方图类对象来统计直方图
	//定义直方图类的对象hist，并利用当前DIB数据对hist初始化
	Histogram hist(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	//统计直方图
	if(pDib->m_nBitCount==8)
		hist.computeHistGray();
	else
		hist.computeHistBrightness();

	//用分割类对象计算直方图的大津阈值
	ImgSegment segment;
    int thresh=segment.threshOtus(hist.m_histArray);

	//将大津阈值thresh作为二值化分割的参数，对图像二值化分割	
	//定义GrayTrans类的对象graytrans，并用当前DIB数据对graytrans初始化
	GrayTrans graytrans(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	graytrans.Binary(thresh);
	
	//新建视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(graytrans.GetDimensions(),graytrans.m_nBitCountOut,graytrans.m_lpColorTableOut, graytrans.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
}

void CDemoView::OnRobert() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义分割类对象segment，并用当前DIB数据初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//Roberts算子
	segment.Roberts();
	
	//新建视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnSobel() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义分割类对象segment，并用当前DIB数据初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//Sobel算子
	segment.Sobel();
	
	//新建视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnPrewitt() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义分割类对象segment，并用当前DIB数据初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	segment.Prewitt();
	
	//新建视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}



void CDemoView::OnLaplacian() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义分割类对象segment，并用当前DIB数据初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//Laplacian算子
	segment.Laplacian();
	
	//新建视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}


void CDemoView::OnKrisch() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义分割类对象segment，并用当前DIB数据初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//Krisch算子
	segment.Krisch();
	
	//新建视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnGausslaplacian() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	//定义分割类对象segment，并用当前DIB数据初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//高斯拉普拉斯算子
	segment.GaussLaplacian();
	
	//新建视图，显示分割结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnEdgeSelectTemplete() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度和彩色图像
	if(pDib->m_nBitCount!=8&&pDib->m_nBitCount!=24){
		::MessageBox(0,_T("只处理灰度和彩色图像"),MB_OK,0);
		return ;
	}
	
	int  i, j, mask[25];

	//模板自定义对话框
	MaskDefineDlg dlgPara;
	if(dlgPara.DoModal()==IDOK){
		//自定义模板
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				mask[i*5+j]=dlgPara.m_defineMask[i*5+j];
			}
		}
		
		//定义分割类对象segment，并用当前DIB数据初始化
		ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);

		//模板自定义边缘检测
		segment.EdgeByAnyMask(mask,5,5);
		
		//新建视图，显示分割结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,
			          segment.m_lpColorTableOut, segment.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}

void CDemoView::OnHoughTransform() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}
	
	//定义分割类对象segment，并用当前DIB数据初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//极半径检测分辨率和角度检测分辨率
	float radiusResolution=1;
	float angleResolution=1;
	float r, a;

	//Hough变换
	segment.Hough(radiusResolution,angleResolution, &r, &a);
	
	//新建视图，显示处理结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
}

void CDemoView::OnLineDetectByHough() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//如果图像的数据像素灰度值既不为0也不为255,则非二值图像
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}
	
	//定义分割类对象segment，并用当前DIB数据初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	//极半径检测分辨率和角度检测分辨率
	float radiusResolution=1;
	float angleResolution=1;

	//检测最长线
	segment.longestLineDetectByHough(radiusResolution,angleResolution);
	
	//新建视图，显示处理结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnRegionGrow() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//区域生长参数设置对话框
	RegionGrowDlg dlgPara;
	if(dlgPara.DoModal()==IDOK){
		CSize imgSize=pDib->GetDimensions();
		//判断种子点是否在图像范围内
		if(dlgPara.m_seedX<0||dlgPara.m_seedX>imgSize.cx-1
			||dlgPara.m_seedY<0||dlgPara.m_seedY>imgSize.cy-1)
		{
			::MessageBox(0,_T("种子点不在图像范围内"),MB_OK,0);
			return ;
		}

		//判断阈值是否在有效范围内
		if(dlgPara.m_thresh<0||dlgPara.m_thresh>255)
		{
			::MessageBox(0,_T("阈值应在0-255之间"),MB_OK,0);
			return ;
		}

		//创建分割类对象，将当前DIB作为输入数据对segment初始化
		ImgSegment segment(imgSize,pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);
		
		//设定种子点位置
		CPoint p(dlgPara.m_seedX,dlgPara.m_seedY);
		
		//阈值
		int thresh=dlgPara.m_thresh;
		
		//区域生长
		segment.RegionGrow(p, thresh);
		
		//新建视图，显示分割结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}

void CDemoView::OnContourTrace() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255){
				flag=0;
				break;
			}
		}
	}
	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}
	//定义图像分割类对象segment，用当前DIB对其初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//边界跟踪
	segment.ContourTrace();
	
	//新建视图，显示处理结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnContourExtract() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度"),MB_OK,0);
		return ;
	}
	
	//判断是否二值图像，若图像有灰度值既不为0也不为255的像素,则非二值图
	int i, j;
	CSize size=pDib->GetDimensions();
	int lineByte=(size.cx+3)/4*4;
	int flag=1;
	for(i=0;i<size.cy;i++){
		for(j=0; j<size.cx;j++){
			//
			if(*(pDib->m_pImgData+i*lineByte+j)!=0
				&&*(pDib->m_pImgData+i*lineByte+j)!=255)
			{
				flag=0;
				break;
			}
		}
	}

	//非二值图像
	if(!flag){
		::MessageBox(0,_T("需要输入二值图像"),MB_OK,0);
		return ;
	}

	//定义图像分割类对象segment，用当前DIB对其初始化
	ImgSegment segment(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	//轮廓提取
	segment.ContourExtract();
	
	//新建视图，显示出力结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();	
	dibNew->ReplaceDib(segment.GetDimensions(),segment.m_nBitCountOut,
		           segment.m_lpColorTableOut, segment.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}


void CDemoView::OnWatershedSegment() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//水域分割参数设置对话框
	WatershedParaDlg dlgPara;
	if(dlgPara.DoModal()==IDOK){
		int objectCount=dlgPara.m_objectCount;
		if( objectCount!=2 && objectCount!=3){
			::MessageBox(0,_T("只分2类或3类目标"),MB_OK,0);
			return ;
		}

		int contourFlg=dlgPara.m_contourFlg;

		CSize imgSize=pDib->GetDimensions();
		CPoint point[3];
		point[0].x=dlgPara.m_point1X; 
		point[0].y=dlgPara.m_point1Y;
		point[1].x=dlgPara.m_point2X; 
		point[1].y=dlgPara.m_point2Y;
		if(objectCount==3){
			point[2].x=dlgPara.m_point3X; 
			point[2].y=dlgPara.m_point3Y;
		}

		//判断种子点是否在图像范围内
		if(point[0].x<0||point[0].x>imgSize.cx-1
			||point[0].y<0||point[0].y>imgSize.cy-1){
				::MessageBox(0,_T("第一个种子点不在图像范围内"),MB_OK,0);
	    		return ;
		}
		if(point[1].x<0||point[1].x>imgSize.cx-1
			||point[1].y<0||point[1].y>imgSize.cy-1){
				::MessageBox(0,_T("第二个种子点不在图像范围内"),MB_OK,0);
	    		return ;
		}
		if(objectCount==3){
			if(point[2].x<0||point[2].x>imgSize.cx-1
				||point[2].y<0||point[2].y>imgSize.cy-1){
				::MessageBox(0,_T("第三个种子点不在图像范围内"),MB_OK,0);
				return ;
			}
		}
		
		//定义Watershed类的对象watershed，用当前DIB数据对其初始化
		Watershed  watershed(imgSize,pDib->m_nBitCount,
			pDib->m_lpColorTable, pDib->m_pImgData);

		//水域分割
		watershed.WatershedSegment(point,objectCount,contourFlg);
		
		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(watershed.GetDimensions(),watershed.m_nBitCountOut,
			      watershed.m_lpColorTableOut, watershed.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}


void CDemoView::OnScan() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	//只处理彩色图像或灰度图象
	if(pDib->m_nBitCount!=24&&pDib->m_nBitCount!=8){
	  ::MessageBox(0,_T("只处理彩色和灰度图像"),MB_OK,0);
	  return ;
	}

	//定义SpecialEffectShow类的对象SpShow，用当前DIB数据为其初始化
	SpecialEffectShow SpShow(pDib->GetDimensions(),
	  pDib->m_nBitCount,pDib->m_lpColorTable,pDib->m_pImgData);

	CClientDC aDC(this);//获得设备环境变量
	SpShow.Scan(&aDC);//调用扫描程序，传递设备环境指针

}

void CDemoView::OnSlide() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	if(pDib->m_nBitCount!=24&&pDib->m_nBitCount!=8){
	  ::MessageBox(0,_T("只处理彩色和灰度图像"),MB_OK,0);
	  return ;
	}
	//定义SpecialEffectShow类的对象SpShow，用当前DIB数据为其初始化
	SpecialEffectShow SpShow(pDib->GetDimensions(),
	  pDib->m_nBitCount,pDib->m_lpColorTable,pDib->m_pImgData);

	CClientDC aDC(this);//获得设备环境变量
	SpShow.Slide(&aDC);//调用滑动显示程序，传递设备环境指针
}

void CDemoView::OnFadeIn() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	if(pDib->m_nBitCount!=24&&pDib->m_nBitCount!=8){
	  ::MessageBox(0,_T("只处理彩色和灰度图像"),MB_OK,0);
	  return ;
	}

	//定义SpecialEffectShow类的对象SpShow，用当前DIB数据为其初始化
	SpecialEffectShow SpShow(pDib->GetDimensions(),
	  pDib->m_nBitCount,pDib->m_lpColorTable,pDib->m_pImgData);

	CClientDC aDC(this);//获得设备环境变量
	SpShow.FadeIn(&aDC);//调用渐进显示程序，传递设备环境指针
}

void CDemoView::OnMosaik() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	if(pDib->m_nBitCount!=24&&pDib->m_nBitCount!=8){
	  ::MessageBox(0,_T("只处理彩色和灰度图像"),MB_OK,0);
	  return ;
	}

	//定义SpecialEffectShow类的对象SpShow，用当前DIB数据为其初始化
	SpecialEffectShow SpShow(pDib->GetDimensions(),
	  pDib->m_nBitCount,pDib->m_lpColorTable,pDib->m_pImgData);

	CClientDC aDC(this);//获得设备环境变量
	SpShow.Mosaik(&aDC);//调用马赛克显示程序，传递设备环境指针	
}

void CDemoView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	
}

// 投影法运动模糊恢复
void CDemoView::OnProjRestore() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//获得图像的宽度和高度
	int imgWidth = pDib->GetDimensions().cx;
	int imgHeight = pDib->GetDimensions().cy;

	ImageRestore ir;

	
	ProjectRestoreDlg prd;
	if(prd.DoModal() == IDOK){
		
		//分配输出临时空间
		unsigned char * outBuffer = new unsigned char[imgWidth * imgHeight];
		memcpy(outBuffer,pDib->m_pImgData,sizeof(unsigned char) * imgWidth * imgHeight);
	
		// 三个主要参数
		int angle = prd.m_angle;
		int length = prd.m_length;
		int cycleCount = prd.m_cycount;		

		// 计算点扩散函数
		ir.GeneratePSF(length,angle);

		// 投影法恢复
		ir.MapRestoreByteVar(outBuffer,imgWidth,imgHeight,1,cycleCount);
		
		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(pDib->GetDimensions(),pDib->m_nBitCount,pDib->m_lpColorTable,outBuffer);   // 设置新的图像
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);

		delete[] outBuffer;
	}
}

//维纳滤波事件响应程序
void CDemoView::OnWienerFilter() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//获得图像的宽度和高度
	int imgWidth = pDib->GetDimensions().cx;
	int imgHeight = pDib->GetDimensions().cy;

	ImageRestore ir;
	
	WienterFilterDlg wfd;
	if(wfd.DoModal() == IDOK){
		
		//分配输出临时空间
		unsigned char * outBuffer = new unsigned char[imgWidth * imgHeight];
		memcpy(outBuffer,pDib->m_pImgData,sizeof(unsigned char) * imgWidth * imgHeight);
	
		// 三个主要参数
		int angle = wfd.m_angle;
		int length = wfd.m_length;
		double k = wfd.m_k;
		
		//计算点扩散函数
		ir.GeneratePSF(length,angle);

		//维纳滤波
		ir.WienerRestoreByteVar(outBuffer,imgWidth,imgHeight,1,k);
		
		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(pDib->GetDimensions(),pDib->m_nBitCount,pDib->m_lpColorTable,outBuffer);   // 设置新的图像
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);

		delete[] outBuffer;
	}
	
}

// 逆滤波响应函数
void CDemoView::OnInverseFilter() 
{
	//获取文档类中m_dib的指针，访问当前DIB数据
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//获得图像的宽度和高度
	int imgWidth = pDib->GetDimensions().cx;
	int imgHeight = pDib->GetDimensions().cy;

	ImageRestore ir;
	
	InverseFilterDlg ifd;
	if(ifd.DoModal() == IDOK){
		
		//分配输出临时空间
		unsigned char * outBuffer = new unsigned char[imgWidth * imgHeight];
		memcpy(outBuffer,pDib->m_pImgData,sizeof(unsigned char) * imgWidth * imgHeight);
	
		// 三个主要参数
		int angle = ifd.m_angle;
		int length = ifd.m_length;
		
		ir.GeneratePSF(length,angle);

		ir.InverseFilterByte(outBuffer,imgWidth,imgHeight,1);
		
		//新建视图，显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(pDib->GetDimensions(),pDib->m_nBitCount,pDib->m_lpColorTable,outBuffer);   // 设置新的图像
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);

		delete[] outBuffer;
	}	
}

//transeform_wavelet wltTrans;
void CDemoView::OnHarrWaveletTrans() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	wltTrans.ReplaceDIBForNew(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	wltTrans.SimpleWaveletTrans(2);
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);
}

void CDemoView::OnHarrWaveletITrans() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	wltTrans.SimpleWaveletReverse();
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);
}

void CDemoView::OnSet2zeroDenoise() 
{
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	wltTrans.ReplaceDIBForNew(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	wltTrans.SetH2Zero();
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);
}

void CDemoView::OnHardthreshold() 
{
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	wltTrans.ReplaceDIBForNew(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	wltTrans.HardThreshold();
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);	
}

void CDemoView::OnSoftthreshold() 
{
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	wltTrans.ReplaceDIBForNew(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	wltTrans.SoftThreshold();
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
	
	dibNew->ReplaceDib(wltTrans.GetDimensions(), wltTrans.m_nBitCountOut, wltTrans.m_pColorTableOut, wltTrans.m_pImgDataOut);	
}

void CDemoView::OnPepperSaltNoise() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	CImgEnhance imgnoise(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	imgnoise.AddPepperSaltNoise();
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(imgnoise.GetDimensions(),imgnoise.m_nBitCountOut,imgnoise.m_lpColorTable, imgnoise.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
	
}

void CDemoView::OnRandom() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	CImgEnhance imgnoise(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	imgnoise.AddRandomNoise();
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(imgnoise.GetDimensions(),imgnoise.m_nBitCountOut,imgnoise.m_lpColorTable, imgnoise.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
	
}

void CDemoView::OnAveSmooth() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	AvgDialog *dlg=new AvgDialog();
	dlg->DoModal();
	int TempH, TempW, TempCX, TempCY;
	float fCoef;
	float Temp[81];
	int i;
	//设模板为平均模板
	for (i = 0; i < 81; i++)
	{
		Temp[i]=1.0;
	}
	switch(dlg->m_nIndex)
	{
	case 0:
		//初始化模板窗口
		TempH=3;
		TempW=3;
		TempCX=1;
		TempCY=1;
		fCoef=(float)(1.0/9.0);
		break;
	case 1:
		//初始化模板窗口
		TempH=5;
		TempW=5;
		TempCX=2;
		TempCY=2;
		fCoef=(float)(1.0/25.0);
		break;
	case 2:
		//初始化模板窗口
		TempH=9;
		TempW=9;
		TempCX=4;
		TempCY=4;
		fCoef=(float)(1.0/81.0);
		break;
	default:
		break;
	}
	CImgEnhance imgnoise(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
    imgnoise.AvgTemplate(TempH,TempW,TempCX,TempCY,Temp,fCoef);
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(imgnoise.GetDimensions(),imgnoise.m_nBitCountOut,imgnoise.m_lpColorTable, imgnoise.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
	return;
}

void CDemoView::OnMiddleSmooth() 
{
	// TODO: Add your command handler code here
	
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	CMedianDialog *dlg=new CMedianDialog();
	dlg->DoModal();
	int modal;
	switch(dlg->m_nIndex)
	{
	case 0:
		modal=3;break;
	case 1:
		modal=5;break;
	case 2:
		modal=7;break;
	default:
		break;
	}

	CImgEnhance imgnoise(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	int iFilterH=modal;
	int iFilterW=modal;
	int iFilterCX=(modal-1)/2;
	int iFilterCY=(modal-1)/2;
	imgnoise.MedianFilter(iFilterH, iFilterW, iFilterCX, iFilterCY);
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(imgnoise.GetDimensions(),imgnoise.m_nBitCountOut,imgnoise.m_lpColorTable, imgnoise.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
	
}

void CDemoView::OnLaplacienSharp() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	CImgEnhance imgnoise(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	int TempH, TempW, TempCX, TempCY;
	float fCoef;
	float Temp[9];
	//设模板为平均模板
	Temp[0]=-1.0;
	Temp[1]=-1.0;
	Temp[2]=-1.0;
	Temp[3]=-1.0;
	Temp[4]=9.0;
	Temp[5]=-1.0;
	Temp[6]=-1.0;
	Temp[7]=-1.0;
	Temp[8]=-1.0;
    //初始化对话框变量
	TempH=3;
	TempW=3;
	TempCX=1;
	TempCY=1;
	fCoef=1.0;
    imgnoise.LapTemplate(TempH,TempW,TempCX,TempCY,Temp,fCoef);
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(imgnoise.GetDimensions(),imgnoise.m_nBitCountOut,imgnoise.m_lpColorTable, imgnoise.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
}

void CDemoView::OnChooseMask() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	CImgEnhance imgSmooth(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	imgSmooth.ChooseMask();
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(imgSmooth.GetDimensions(),imgSmooth.m_nBitCountOut,imgSmooth.m_lpColorTable, imgSmooth.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
}

void CDemoView::OnPowerSmooth() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	CImgEnhance imgSmooth(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	int TempH, TempW, TempCX, TempCY;
	float fCoef;
	/*
	float Temp[9];
	//设模板为平均模板
	Temp[0]=1.0;
	Temp[1]=2.0;
	Temp[2]=1.0;
	Temp[3]=2.0;
	Temp[4]=4.0;
	Temp[5]=2.0;
	Temp[6]=1.0;
	Temp[7]=2.0;
	Temp[8]=1.0;
    //初始化对话框变量
	TempH=3;
	TempW=3;
	TempCX=1;
	TempCY=1;
	fCoef=(float)(1.0/16.0);*/
	float Temp[25];
	//设模板为平均模板
	Temp[0]=0.0;
	Temp[1]=1.0;
	Temp[2]=2.0;
	Temp[3]=1.0;
	Temp[4]=0.0;

	Temp[5]=1.0;
	Temp[6]=2.0;
	Temp[7]=4.0;
	Temp[8]=2.0;
	Temp[9]=1.0;

	Temp[10]=2.0;
	Temp[11]=4.0;
	Temp[12]=8.0;
	Temp[13]=4.0;
	Temp[14]=2.0;

	Temp[15]=1.0;
	Temp[16]=2.0;
	Temp[17]=4.0;
	Temp[18]=2.0;
	Temp[19]=1.0;

	Temp[20]=0.0;
	Temp[21]=1.0;
	Temp[22]=2.0;
	Temp[23]=1.0;
	Temp[24]=0.0;
    //初始化对话框变量
	TempH=5;
	TempW=5;
	TempCX=2;
	TempCY=2;
	fCoef=(float)(1.0/48.0);

	imgSmooth.AvgTemplate(TempH,TempW,TempCX,TempCY,Temp,fCoef);
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib( imgSmooth.GetDimensions(), imgSmooth.m_nBitCountOut, imgSmooth.m_lpColorTable,  imgSmooth.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
}

/***********************************************************************
* 函数名称：
* OnDct()
*
*函数参数：
*  无
*
*返回值：
*   无
*
*说明：对输入图像进行快速离散余弦变换，要求输入图像的宽和高必须是2的幂次方
***********************************************************************/
void CDemoView::OnDct() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//判断图像大小是否为2的幂次的方阵
	int isValidateFlag=1;
	int width=pDib->GetDimensions().cx;
	int height=pDib->GetDimensions().cy;
	int i=1;
	while(i<width)
		i=i*2;
	if(i!=width)//图像宽不是2的幂次方
		isValidateFlag=0;
	
	i=1;
	while(i<height)
		i=i*2;
	if(i!=height)//图像高不是2的幂次方
		isValidateFlag=0;
	
	if(isValidateFlag==0){
		::MessageBox(0,_T("输入图像的宽和高应为2的幂次方"),MB_OK,0);
		return ;
	}

	DIBDCT.InputImgData(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
    DIBDCT.ImgDCT();
	
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(DIBDCT.GetDimensions(), DIBDCT.m_nBitCountOut,
		DIBDCT.m_lpColorTable, DIBDCT.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();
}

/***********************************************************************
* 函数名称：
* OnIDct()
*
*函数参数：
*  无
*
*返回值：
*   无
*
*说明：对输入图像进行快速离散余弦反变换
***********************************************************************/
void CDemoView::OnIdct() 
{
	//离散余弦反变换
	DIBDCT.ImgIDCT();
	
    //新建视图窗口，显示图像恢复的结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(DIBDCT.GetDimensions(),DIBDCT.m_nBitCountOut,
		DIBDCT.m_lpColorTable, DIBDCT.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
}

void CDemoView::OnGradesharp() 
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	CImgEnhance imgnoise(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);

	unsigned char bThre=30;
	imgnoise.GradSharp(bThre);

	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	
	dibNew->ReplaceDib(imgnoise.GetDimensions(),imgnoise.m_nBitCountOut,imgnoise.m_lpColorTable, imgnoise.m_pImgDataOut);
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);
	
	Invalidate();	
}

void CDemoView::OnSnr() 
{
	// TODO: Add your command handler code here
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	
	//加载原始DIB位图
	CString lpfilter=_T("BMP Filter(*.bmp)|*.bmp");
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,lpfilter);
	if (dlg.DoModal()!=IDOK)
	{
		AfxMessageBox(_T("请选择BMP位图"));
		return;
	}
	CString fileName = dlg.GetPathName();
	ImgCenterDib m_Srcdib;
	if (m_Srcdib.Read(fileName) != TRUE)
	{
		AfxMessageBox(_T("原始图像加载失败!"),MB_ICONINFORMATION);
	}
	
	CImgEnhance imgnoise(pDib->GetDimensions(),pDib->m_nBitCount,
		pDib->m_lpColorTable, pDib->m_pImgData);
	
	CString SNR=imgnoise.SNR(m_Srcdib.m_pImgData);
	CString PSNR=imgnoise.PSNR(m_Srcdib.m_pImgData);
	MessageBox(_T("信噪比:")+SNR+_T("\n")+_T("峰值信噪比:")+PSNR+_T("\n"),_T("图像质量评价"),MB_ICONINFORMATION);
}

void CDemoView::OnFirstimage() 
{	
	TCHAR *pszFile = new TCHAR[MAX_PATH * MAX_PATH];
    memset(pszFile,0,sizeof(TCHAR)*MAX_PATH * MAX_PATH);

	//文件打开对话框
	CFileDialog fdlg(TRUE,NULL, NULL, OFN_HIDEREADONLY,
		_T("BMP图片 (*.bmp)|*.bmp|All Files (*.*)|*.*||"),NULL);
	fdlg.m_ofn.lpstrFile = pszFile;
	fdlg.m_ofn.nMaxFile = MAX_PATH*MAX_PATH;
	CString str;
	if ( fdlg.DoModal() == IDOK )
	{
		POSITION pos = fdlg.GetStartPosition();
		if (pos != NULL)
			str = fdlg.GetNextPathName(pos);

		//读入数据
		DIB1.Read(str);
		
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		pDocNew->SetTitle(str);
		ImgCenterDib *dibNew=pDocNew->GetPDib();	
		dibNew->ReplaceDib(DIB1.GetDimensions(),DIB1.m_nBitCount,
			DIB1.m_lpColorTable, DIB1.m_pImgData);
		pView->OnInitialUpdate();
		pDocNew->UpdateAllViews(pView);
	}
	delete []pszFile;
}

void CDemoView::OnSecondimage() 
{
	TCHAR *pszFile = new TCHAR[MAX_PATH * MAX_PATH];
    memset(pszFile,0,sizeof(TCHAR)*MAX_PATH * MAX_PATH);
	
	//文件打开对话框
	CFileDialog fdlg(TRUE,NULL, NULL, OFN_HIDEREADONLY,
		_T("BMP图片 (*.bmp)|*.bmp|All Files (*.*)|*.*||"),NULL);
	fdlg.m_ofn.lpstrFile = pszFile;
	fdlg.m_ofn.nMaxFile = MAX_PATH*MAX_PATH;
	CString str;
	if ( fdlg.DoModal() == IDOK )
	{
		POSITION pos = fdlg.GetStartPosition();
		if (pos != NULL)
			str = fdlg.GetNextPathName(pos);

		//读入数据
		DIB2.Read(str);
		
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		pDocNew->SetTitle(str);
		ImgCenterDib *dibNew=pDocNew->GetPDib();	
		dibNew->ReplaceDib(DIB2.GetDimensions(),DIB2.m_nBitCount,DIB2.m_lpColorTable, DIB2.m_pImgData);
		pView->OnInitialUpdate();
		pDocNew->UpdateAllViews(pView);
	}
	delete []pszFile;
}

void CDemoView::OnMatchConner() 
{
	CSize size1=DIB1.GetDimensions();
	CSize size2=DIB2.GetDimensions();
	if (size1.cx==0||size1.cy==0){
		::MessageBox(0,_T("请输入待配准图像1"),MB_OK,0);
		return ;
	}
	if (size2.cx==0||size2.cy==0){
		::MessageBox(0,_T("请输入待配准图像2"),MB_OK,0);
		return ;
	}
	if(size1.cx!=size2.cx || size1.cy!=size2.cy){
		::MessageBox(0,_T("待配准的两幅图像应该大小相等"),MB_OK,0);
		return ;
	}

	if ( DIB1.m_nBitCount!=8&&DIB2.m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	//定义图像配准类对象
	Register match;

	//输入待配准的两幅图像
	match.InputImg1(DIB1.GetDimensions(),DIB1.m_nBitCount,
		DIB1.m_lpColorTable,DIB1.m_pImgData);
	match.InputImg2(DIB2.GetDimensions(),DIB2.m_nBitCount,
		DIB2.m_lpColorTable,DIB2.m_pImgData);

	//角点匹配
	if (match.ConnerRegistering())
	{
		//新建视图,显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		pDocNew->SetTitle(_T("角点匹配结果"));
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(match.GetDimensions(), match.m_nBitCountOut,
			match.m_lpColorTableOut, match.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}

void CDemoView::OnMatchTemplet() 
{
	CSize size1=DIB1.GetDimensions();
	CSize size2=DIB2.GetDimensions();
	if (size1.cx==0||size1.cy==0){
		::MessageBox(0,_T("请输入参考图"),MB_OK,0);
		return ;
	}
	if (size2.cx==0||size2.cy==0){
		::MessageBox(0,_T("请输入基准图"),MB_OK,0);
		return ;
	}
	if(size1.cx<=size2.cx || size1.cy<=size2.cy){
		::MessageBox(0,_T("基准图尺寸应小于参考图"),MB_OK,0);
		return ;
	}

	if (DIB1.m_nBitCount!=8&&DIB2.m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}
	//定义图像配准类对象
	Register match;

	//输入参考图和基准图
	match.InputImg1(DIB1.GetDimensions(),DIB1.m_nBitCount,
		DIB1.m_lpColorTable,DIB1.m_pImgData);
	match.InputImg2(DIB2.GetDimensions(),DIB2.m_nBitCount,
		DIB2.m_lpColorTable,DIB2.m_pImgData);

	//模板匹配
	if (match.relativityRegistering())
	{
		//创建新视图,显示处理结果
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		pDocNew->SetTitle(_T("模板匹配结果"));
		ImgCenterDib *dibNew=pDocNew->GetPDib();
		dibNew->ReplaceDib(match.GetDimensions(), match.m_nBitCountOut,
			match.m_lpColorTableOut, match.m_pImgDataOut);
		pView->OnInitialUpdate();
		pDocNew->SetModifiedFlag(TRUE);
		pDocNew->UpdateAllViews(pView);
	}
}

void CDemoView::OnConnerDetect() 
{
	CDemoDoc *pDoc=GetDocument();
	ImgCenterDib *pDib=pDoc->GetPDib();
	
	//只处理灰度图像
	if(pDib->m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	Register match;
	match.InputImg1(pDib->GetDimensions(),pDib->m_nBitCount,
			                pDib->m_lpColorTable,pDib->m_pImgData);
	match.HarisConner();
	
	//新建视图，显示处理结果
	CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
	CDemoDoc* pDocNew=pView->GetDocument();
	ImgCenterDib *dibNew=pDocNew->GetPDib();
	dibNew->ReplaceDib(match.GetDimensions(),match.m_nBitCountOut,
		match.m_lpColorTableOut, match.m_pImgDataOut);
	pView->OnInitialUpdate();
	pDocNew->SetModifiedFlag(TRUE);
	pDocNew->UpdateAllViews(pView);	
}

void CDemoView::OnMotionFopen1() 
{
	TCHAR *pszFile = new TCHAR[MAX_PATH * MAX_PATH];
    memset(pszFile,0,sizeof(TCHAR)*MAX_PATH * MAX_PATH);

	//文件打开对话框
	CFileDialog fdlg(TRUE,NULL, NULL, OFN_HIDEREADONLY,
		_T("BMP图片 (*.bmp)|*.bmp|All Files (*.*)|*.*||"),NULL);
	fdlg.m_ofn.lpstrFile = pszFile;
	fdlg.m_ofn.nMaxFile = MAX_PATH*MAX_PATH;
	CString str;
	if ( fdlg.DoModal() == IDOK )
	{
		POSITION pos = fdlg.GetStartPosition();
		if (pos != NULL)
			str = fdlg.GetNextPathName(pos);

		//读入数据
		DIB1.Read(str);
		
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		pDocNew->SetTitle(str);
		ImgCenterDib *dibNew=pDocNew->GetPDib();	
		dibNew->ReplaceDib(DIB1.GetDimensions(),DIB1.m_nBitCount,
			DIB1.m_lpColorTable, DIB1.m_pImgData);
		pView->OnInitialUpdate();
		pDocNew->UpdateAllViews(pView);
	}
	delete []pszFile;
	
}

void CDemoView::OnMotionFopen2() 
{
	TCHAR *pszFile = new TCHAR[MAX_PATH * MAX_PATH];
    memset(pszFile,0,sizeof(TCHAR)*MAX_PATH * MAX_PATH);
	
	//文件打开对话框
	CFileDialog fdlg(TRUE,NULL, NULL, OFN_HIDEREADONLY,
		_T("BMP图片 (*.bmp)|*.bmp|All Files (*.*)|*.*||"),NULL);
	fdlg.m_ofn.lpstrFile = pszFile;
	fdlg.m_ofn.nMaxFile = MAX_PATH*MAX_PATH;
	CString str;
	if ( fdlg.DoModal() == IDOK )
	{
		POSITION pos = fdlg.GetStartPosition();
		if (pos != NULL)
			str = fdlg.GetNextPathName(pos);

		//读入数据
		DIB2.Read(str);
		
		CMainFrame* pFrame = (CMainFrame *)(AfxGetApp()->m_pMainWnd);
		pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
		CDemoView* pView=(CDemoView*)pFrame->MDIGetActive()->GetActiveView();
		CDemoDoc* pDocNew=pView->GetDocument();
		pDocNew->SetTitle(str);
		ImgCenterDib *dibNew=pDocNew->GetPDib();	
		dibNew->ReplaceDib(DIB2.GetDimensions(),DIB2.m_nBitCount,DIB2.m_lpColorTable, DIB2.m_pImgData);
		pView->OnInitialUpdate();
		pDocNew->UpdateAllViews(pView);
	}
	delete []pszFile;
	
}

void CDemoView::OnMotionFest() 
{
	CSize size1=DIB1.GetDimensions();
	CSize size2=DIB2.GetDimensions();
	if (size1.cx==0||size1.cy==0){
		::MessageBox(0,_T("请输入待配准图像1"),MB_OK,0);
		return ;
	}
	if (size2.cx==0||size2.cy==0){
		::MessageBox(0,_T("请输入待配准图像2"),MB_OK,0);
		return ;
	}
	if(size1.cx!=size2.cx || size1.cy!=size2.cy){
		::MessageBox(0,_T("待配准的两幅图像应该大小相等"),MB_OK,0);
		return ;
	}

	int i = 1;int k = 1;
	while(k < size1.cx)
	{
		k = k * 2;
	}

	if(k!=size1.cx || k!=size2.cx){
		::MessageBox(0,_T("待配准的两幅图像大小应为2的幂次"),MB_OK,0);
		return ;
	}
	if(size1.cx!=size1.cy || size2.cx!=size2.cy){
		::MessageBox(0,_T("图像的长宽必须相等"),MB_OK,0);
		return ;
	}
	
	if ( DIB1.m_nBitCount!=8&&DIB2.m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	int x,y;
	PhaseCorrelation(DIB1.m_pImgData,DIB2.m_pImgData,size1.cx,size2.cy,&x,&y);

	CString str;
	str.Format(_T("相对于第一幅图像\n x方向移动为%d，y方向移动为%d。"),x,y);
	MessageBox(str.GetBuffer(str.GetLength()),MB_OK,0);
	
}

void CDemoView::OnMitonDest() 
{
	CSize size1=DIB1.GetDimensions();
	CSize size2=DIB2.GetDimensions();
	if (size1.cx==0||size1.cy==0){
		::MessageBox(0,_T("请输入待配准图像1"),MB_OK,0);
		return ;
	}
	if (size2.cx==0||size2.cy==0){
		::MessageBox(0,_T("请输入待配准图像2"),MB_OK,0);
		return ;
	}
	if(size1.cx!=size2.cx || size1.cy!=size2.cy){
		::MessageBox(0,_T("待配准的两幅图像应该大小相等"),MB_OK,0);
		return ;
	}

	int i = 1;int k = 1;
	while(k < size1.cx)
	{
		k = k * 2;
	}

	if(k!=size1.cx || k!=size2.cx){
		::MessageBox(0,_T("待配准的两幅图像大小应为2的幂次"),MB_OK,0);
		return ;
	}
	if(size1.cx!=size1.cy || size2.cx!=size2.cy){
		::MessageBox(0,_T("图像的长宽必须相等"),MB_OK,0);
		return ;
	}
	
	if ( DIB1.m_nBitCount!=8&&DIB2.m_nBitCount!=8){
		::MessageBox(0,_T("只处理灰度图像"),MB_OK,0);
		return ;
	}

	int x,y;
	PhaseAngleDiff(DIB1.m_pImgData,DIB2.m_pImgData,size1.cx,size2.cy);

}

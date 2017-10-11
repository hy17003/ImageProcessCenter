// demoView.h : interface of the CDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMOVIEW_H__DE734DBE_1CB6_4B2F_862C_8C090198DB38__INCLUDED_)
#define AFX_DEMOVIEW_H__DE734DBE_1CB6_4B2F_862C_8C090198DB38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CDemoView : public CScrollView
{
protected: // create from serialization only
	CDemoView();
	DECLARE_DYNCREATE(CDemoView)

// Attributes
public:
	CDemoDoc* GetDocument();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoView)
	afx_msg void OnSobel();
	afx_msg void OnImgReverse();
	afx_msg void OnColorToGray();
	afx_msg void OnBinary();
	afx_msg void OnGrayToColor();
	afx_msg void OnLinearStrecth();
	afx_msg void OnHistgramAver();
	afx_msg void OnHistogramDraw();
	afx_msg void OnFft();
	afx_msg void OnIfft();
	afx_msg void OnClockwise90();
	afx_msg void OnAnticlockwise90();
	afx_msg void OnRotate180();
	afx_msg void OnZoom();
	afx_msg void OnRotate();
	afx_msg void OnErosionForBinary();
	afx_msg void OnDilationForBinary();
	afx_msg void OnOpenForBinary();
	afx_msg void OnCloseForBinary();
	afx_msg void OnInnerEdgeForBinary();
	afx_msg void OnOuterEdgeForBinary();
	afx_msg void OnHitMissThinning();
	afx_msg void OnErosionForGray();
	afx_msg void OnDilationForGray();
	afx_msg void OnOpenForGray();
	afx_msg void OnCloseForGray();
	afx_msg void OnMorphoGradientForGray();
	afx_msg void OnTopHatPeak();
	afx_msg void OnTopHatVally();
	afx_msg void OnTopHatPeakAndVally();
	afx_msg void OnInteractiveThresh();
	afx_msg void OnOtusThreshold();
	afx_msg void OnRobert();
	afx_msg void OnPrewitt();
	afx_msg void OnEdgeSelectTemplete();
	afx_msg void OnHoughTransform();
	afx_msg void OnLineDetectByHough();
	afx_msg void OnRegionGrow();
	afx_msg void OnContourExtract();
	afx_msg void OnGausslaplacian();
	afx_msg void OnWatershedSegment();
	afx_msg void OnDuiShuStretch();
	afx_msg void OnZhiShuStretch();
	afx_msg void OnMove();
	afx_msg void OnZhuanZhi();
	afx_msg void OnHorizontalMirror();
	afx_msg void OnVerticalMirror();
	afx_msg void OnFFTEx();
	afx_msg void OnIFFTEx();
	afx_msg void OnLaplacian();
	afx_msg void OnKrisch();
	afx_msg void OnContourTrace();
	afx_msg void OnMorphoContourForBinary();
	afx_msg void OnScan();
	afx_msg void OnSlide();
	afx_msg void OnFadeIn();
	afx_msg void OnMosaik();
	afx_msg void OnProjRestore();
	afx_msg void OnWienerFilter();
	afx_msg void OnInverseFilter();
	afx_msg void OnSet2zeroDenoise();
	afx_msg void OnHardthreshold();
	afx_msg void OnSoftthreshold();
	afx_msg void OnPepperSaltNoise();
	afx_msg void OnRandom();
	afx_msg void OnAveSmooth();
	afx_msg void OnMiddleSmooth();
	afx_msg void OnLaplacienSharp();
	afx_msg void OnChooseMask();
	afx_msg void OnPowerSmooth();
	afx_msg void OnHarrWaveletTrans();
	afx_msg void OnHarrWaveletITrans();
	afx_msg void OnDct();
	afx_msg void OnGradesharp();
	afx_msg void OnSnr();
	afx_msg void OnIdct();
	afx_msg void OnSecondimage();
	afx_msg void OnFirstimage();
	afx_msg void OnMatchConner();
	afx_msg void OnMatchTemplet();
	afx_msg void OnConnerDetect();
	afx_msg void OnMotionFopen1();
	afx_msg void OnMotionFopen2();
	afx_msg void OnMotionFest();
	afx_msg void OnMitonDest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	//判断当前输入二值形态学模板是否有效
	bool ValidBinaryMorphMask(int *maskBuf, int maskW, int maskH);
};

#ifndef _DEBUG  // debug version in demoView.cpp
inline CDemoDoc* CDemoView::GetDocument()
   { return (CDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOVIEW_H__DE734DBE_1CB6_4B2F_862C_8C090198DB38__INCLUDED_)

#if !defined(AFX_THRESHSEGMENTDLG_H__114B2320_1DB2_4855_AE9E_2B820C935C13__INCLUDED_)
#define AFX_THRESHSEGMENTDLG_H__114B2320_1DB2_4855_AE9E_2B820C935C13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThreshSegmentDlg.h : header file
//
#include "histogram.h"
/////////////////////////////////////////////////////////////////////////////
// ThreshSegmentDlg dialog

class ThreshSegmentDlg : public CDialog
{
// Construction
public:
	ThreshSegmentDlg(CWnd* pParent = NULL);   // standard constructor

	Histogram m_histogramDib;

// Dialog Data
	//{{AFX_DATA(ThreshSegmentDlg)
	enum { IDD = IDD_Dlg_ThreshSegment };
	int		m_colorSelect;
	int		m_threshSelect;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ThreshSegmentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ThreshSegmentDlg)
		virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSelchangeCOMBOcolorSelect();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THRESHSEGMENTDLG_H__114B2320_1DB2_4855_AE9E_2B820C935C13__INCLUDED_)

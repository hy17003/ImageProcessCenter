#if !defined(AFX_HISTOGRAMDRAWDLG_H__AE20E64C_3659_4D28_967E_959AFF9C8113__INCLUDED_)
#define AFX_HISTOGRAMDRAWDLG_H__AE20E64C_3659_4D28_967E_959AFF9C8113__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HistogramDrawDlg.h : header file
//
#include "histogram.h"
/////////////////////////////////////////////////////////////////////////////
// HistogramDrawDlg dialog

class HistogramDrawDlg : public CDialog
{
// Construction
public:
	HistogramDrawDlg(CWnd* pParent = NULL);   // standard constructor

	Histogram m_histogramDib;
// Dialog Data
	//{{AFX_DATA(HistogramDrawDlg)
	enum { IDD = IDD_Dlg_HistogramDraw };
	int		m_colorSelect;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(HistogramDrawDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(HistogramDrawDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSelchangeCOMBOcolorSelect();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTOGRAMDRAWDLG_H__AE20E64C_3659_4D28_967E_959AFF9C8113__INCLUDED_)

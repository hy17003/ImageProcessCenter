#if !defined(AFX_LINEARSTRETCHPARAMDLG_H__D1AF0FE6_5B65_4221_8EB7_EC9B1BE38641__INCLUDED_)
#define AFX_LINEARSTRETCHPARAMDLG_H__D1AF0FE6_5B65_4221_8EB7_EC9B1BE38641__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// linearStretchParamDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// linearStretchParamDlg dialog

class linearStretchParamDlg : public CDialog
{
// Construction
public:
	linearStretchParamDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(linearStretchParamDlg)
	enum { IDD = IDD_DlgLinearStretch };
	int		m_firstPointX;
	int		m_secondPointX;
	int		m_secondPointY;
	int		m_firstPointY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(linearStretchParamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(linearStretchParamDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEARSTRETCHPARAMDLG_H__D1AF0FE6_5B65_4221_8EB7_EC9B1BE38641__INCLUDED_)

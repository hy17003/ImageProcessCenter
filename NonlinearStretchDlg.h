#if !defined(AFX_NONLINEARSTRETCHDLG_H__0DEAA82C_948C_47ED_A386_64842FC2705B__INCLUDED_)
#define AFX_NONLINEARSTRETCHDLG_H__0DEAA82C_948C_47ED_A386_64842FC2705B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NonlinearStretchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NonlinearStretchDlg dialog

class NonlinearStretchDlg : public CDialog
{
// Construction
public:
	NonlinearStretchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(NonlinearStretchDlg)
	enum { IDD = IDD_Dlg_NonlinearStretch };
	float	m_a;
	float	m_b;
	float	m_c;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NonlinearStretchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(NonlinearStretchDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NONLINEARSTRETCHDLG_H__0DEAA82C_948C_47ED_A386_64842FC2705B__INCLUDED_)

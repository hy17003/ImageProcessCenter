#if !defined(AFX_WIENTERFILTERDLG_H__7666EB52_02AC_42C2_9FAE_44A58C21CCB3__INCLUDED_)
#define AFX_WIENTERFILTERDLG_H__7666EB52_02AC_42C2_9FAE_44A58C21CCB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WienterFilterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// WienterFilterDlg dialog

class WienterFilterDlg : public CDialog
{
// Construction
public:
	WienterFilterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(WienterFilterDlg)
	enum { IDD = IDD_Dlg_WienerFilter };
	int		m_angle;
	double	m_k;
	int		m_length;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WienterFilterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(WienterFilterDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIENTERFILTERDLG_H__7666EB52_02AC_42C2_9FAE_44A58C21CCB3__INCLUDED_)

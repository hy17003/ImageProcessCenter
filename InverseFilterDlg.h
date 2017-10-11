#if !defined(AFX_INVERSEFILTERDLG_H__59FF9A92_CD27_4C8B_AAC4_1F687D4E4EB1__INCLUDED_)
#define AFX_INVERSEFILTERDLG_H__59FF9A92_CD27_4C8B_AAC4_1F687D4E4EB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InverseFilterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InverseFilterDlg dialog

class InverseFilterDlg : public CDialog
{
// Construction
public:
	InverseFilterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InverseFilterDlg)
	enum { IDD = IDD_Dlg_InverseFilter };
	int		m_angle;
	int		m_length;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InverseFilterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(InverseFilterDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INVERSEFILTERDLG_H__59FF9A92_CD27_4C8B_AAC4_1F687D4E4EB1__INCLUDED_)

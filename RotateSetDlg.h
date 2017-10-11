#if !defined(AFX_ROTATESETDLG_H__E270A01E_447A_4C0C_A549_3839A6FA8529__INCLUDED_)
#define AFX_ROTATESETDLG_H__E270A01E_447A_4C0C_A549_3839A6FA8529__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RotateSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RotateSetDlg dialog

class RotateSetDlg : public CDialog
{
// Construction
public:
	RotateSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RotateSetDlg)
	enum { IDD = IDD_Dlg_RotateSet };
	int		m_rotateAngle;
	int		m_interpolationSelect;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RotateSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RotateSetDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROTATESETDLG_H__E270A01E_447A_4C0C_A549_3839A6FA8529__INCLUDED_)

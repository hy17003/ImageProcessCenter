#if !defined(AFX_MASKDEFINEDLG_H__DEB673BA_CC3E_437D_8AE0_FE6FD5B81892__INCLUDED_)
#define AFX_MASKDEFINEDLG_H__DEB673BA_CC3E_437D_8AE0_FE6FD5B81892__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MaskDefineDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MaskDefineDlg dialog

class MaskDefineDlg : public CDialog
{
// Construction
public:
	MaskDefineDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(MaskDefineDlg)
	enum { IDD = IDD_Dlg_MaskDefine };
	int		m_Edit00;
	int		m_Edit01;
	int		m_Edit02;
	int		m_Edit03;
	int		m_Edit04;
	int		m_Edit10;
	int		m_Edit11;
	int		m_Edit12;
	int		m_Edit13;
	int		m_Edit14;
	int		m_Edit20;
	int		m_Edit21;
	int		m_Edit22;
	int		m_Edit23;
	int		m_Edit24;
	int		m_Edit30;
	int		m_Edit31;
	int		m_Edit32;
	int		m_Edit33;
	int		m_Edit34;
	int		m_Edit40;
	int		m_Edit41;
	int		m_Edit42;
	int		m_Edit43;
	int		m_Edit44;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MaskDefineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
public:
	//存放模板的数组
	int m_defineMask[25];
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(MaskDefineDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MASKDEFINEDLG_H__DEB673BA_CC3E_437D_8AE0_FE6FD5B81892__INCLUDED_)

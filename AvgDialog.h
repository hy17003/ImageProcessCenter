#if !defined(AFX_AVGDIALOG_H__F50BC9D6_A742_4E62_9AB6_68066451DB08__INCLUDED_)
#define AFX_AVGDIALOG_H__F50BC9D6_A742_4E62_9AB6_68066451DB08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AvgDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AvgDialog dialog

class AvgDialog : public CDialog
{
// Construction
public:
	AvgDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AvgDialog)
	enum { IDD = IDD_MEDIANDIALOG };
	CComboBox	m_nCombo;
	//}}AFX_DATA

int	m_nIndex;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AvgDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AvgDialog)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVGDIALOG_H__F50BC9D6_A742_4E62_9AB6_68066451DB08__INCLUDED_)

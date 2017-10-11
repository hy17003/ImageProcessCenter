#if !defined(AFX_MEDIANDIALOG_H__B90EE82E_79F3_4403_A431_98871767DCE6__INCLUDED_)
#define AFX_MEDIANDIALOG_H__B90EE82E_79F3_4403_A431_98871767DCE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MedianDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMedianDialog dialog

class CMedianDialog : public CDialog
{
// Construction
public:
	CMedianDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMedianDialog)
	enum { IDD = IDD_MEDIANDIALOG };
	//}}AFX_DATA
public:
	CComboBox	m_nCombo;
	int	m_nIndex;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMedianDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMedianDialog)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIANDIALOG_H__B90EE82E_79F3_4403_A431_98871767DCE6__INCLUDED_)

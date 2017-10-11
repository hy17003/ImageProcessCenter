#if !defined(AFX_REGIONGROWDLG_H__FF220E5E_840E_4650_8D0B_FC48526EF43A__INCLUDED_)
#define AFX_REGIONGROWDLG_H__FF220E5E_840E_4650_8D0B_FC48526EF43A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegionGrowDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// RegionGrowDlg dialog

class RegionGrowDlg : public CDialog
{
// Construction
public:
	RegionGrowDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(RegionGrowDlg)
	enum { IDD = IDD_Dlg_RegionGrow };
	int		m_seedX;
	int		m_seedY;
	int		m_thresh;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(RegionGrowDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(RegionGrowDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGIONGROWDLG_H__FF220E5E_840E_4650_8D0B_FC48526EF43A__INCLUDED_)

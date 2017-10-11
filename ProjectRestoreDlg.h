#if !defined(AFX_PROJECTRESTOREDLG_H__0E114C94_2098_4ED2_9A97_A5FD2C30219D__INCLUDED_)
#define AFX_PROJECTRESTOREDLG_H__0E114C94_2098_4ED2_9A97_A5FD2C30219D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProjectRestoreDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ProjectRestoreDlg dialog

class ProjectRestoreDlg : public CDialog
{
// Construction
public:
	ProjectRestoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ProjectRestoreDlg)
	enum { IDD = IDD_Dlg_ProjectionRes };
	int		m_angle;
	int		m_cycount;
	int		m_length;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ProjectRestoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ProjectRestoreDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJECTRESTOREDLG_H__0E114C94_2098_4ED2_9A97_A5FD2C30219D__INCLUDED_)

#if !defined(AFX_GEOMETRYMOVEDLG_H__538C13F5_C339_4770_BD1B_A6003C5B9B92__INCLUDED_)
#define AFX_GEOMETRYMOVEDLG_H__538C13F5_C339_4770_BD1B_A6003C5B9B92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GeometryMoveDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// GeometryMoveDlg dialog

class GeometryMoveDlg : public CDialog
{
// Construction
public:
	GeometryMoveDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(GeometryMoveDlg)
	enum { IDD = IDD_Dlg_Move };
	int		m_OffsetX;
	int		m_OffsetY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GeometryMoveDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(GeometryMoveDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GEOMETRYMOVEDLG_H__538C13F5_C339_4770_BD1B_A6003C5B9B92__INCLUDED_)

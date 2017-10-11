#if !defined(AFX_WATERSHEDPARADLG_H__99FA43BA_579C_4D0F_9F55_FE4436D769EC__INCLUDED_)
#define AFX_WATERSHEDPARADLG_H__99FA43BA_579C_4D0F_9F55_FE4436D769EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WatershedParaDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// WatershedParaDlg dialog

class WatershedParaDlg : public CDialog
{
// Construction
public:
	WatershedParaDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(WatershedParaDlg)
	enum { IDD = IDD_Dlg_Watershed };
	int		m_point1X;
	int		m_point1Y;
	int		m_point2X;
	int		m_point2Y;
	int		m_point3X;
	int		m_point3Y;
	int		m_objectCount;
	BOOL	m_contourFlg;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WatershedParaDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(WatershedParaDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WATERSHEDPARADLG_H__99FA43BA_579C_4D0F_9F55_FE4436D769EC__INCLUDED_)

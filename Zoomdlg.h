#if !defined(AFX_ZOOMDLG_H__C79F40FC_BF44_4B52_8028_F05E5E4CC139__INCLUDED_)
#define AFX_ZOOMDLG_H__C79F40FC_BF44_4B52_8028_F05E5E4CC139__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Zoomdlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Zoomdlg dialog

class Zoomdlg : public CDialog
{
// Construction
public:
	Zoomdlg(CWnd* pParent = NULL);   // standard constructor

	//原始图像的宽
	int m_oldHeight;
	//原始图像的高
	int m_oldWidth;

// Dialog Data
	//{{AFX_DATA(Zoomdlg)
	enum { IDD = IDD_Dlg_Zoom };
	int		m_newHeight;
	int		m_newWidth;
	int		m_interpolationSelect;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Zoomdlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Zoomdlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ZOOMDLG_H__C79F40FC_BF44_4B52_8028_F05E5E4CC139__INCLUDED_)

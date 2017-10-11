// NonlinearStretchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "NonlinearStretchDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NonlinearStretchDlg dialog


NonlinearStretchDlg::NonlinearStretchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(NonlinearStretchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(NonlinearStretchDlg)
	m_a = 0.0f;
	m_b = 0.0f;
	m_c = 0.0f;
	//}}AFX_DATA_INIT
}


void NonlinearStretchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(NonlinearStretchDlg)
	DDX_Text(pDX, IDC_EditA, m_a);
	DDX_Text(pDX, IDC_EditB, m_b);
	DDX_Text(pDX, IDC_EditC, m_c);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(NonlinearStretchDlg, CDialog)
	//{{AFX_MSG_MAP(NonlinearStretchDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NonlinearStretchDlg message handlers

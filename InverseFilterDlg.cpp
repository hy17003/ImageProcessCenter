// InverseFilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "InverseFilterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// InverseFilterDlg dialog


InverseFilterDlg::InverseFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(InverseFilterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(InverseFilterDlg)
	m_angle = 0;
	m_length = 0;
	//}}AFX_DATA_INIT
}


void InverseFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InverseFilterDlg)
	DDX_Text(pDX, IDC_EDIT_iAngle, m_angle);
	DDX_Text(pDX, IDC_EDIT_iLength, m_length);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(InverseFilterDlg, CDialog)
	//{{AFX_MSG_MAP(InverseFilterDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InverseFilterDlg message handlers

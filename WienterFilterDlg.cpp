// WienterFilterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "WienterFilterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// WienterFilterDlg dialog


WienterFilterDlg::WienterFilterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(WienterFilterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(WienterFilterDlg)
	m_angle = 0;
	m_k = 0.0;
	m_length = 0;
	//}}AFX_DATA_INIT
}


void WienterFilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(WienterFilterDlg)
	DDX_Text(pDX, IDC_EDIT_wAngle, m_angle);
	DDX_Text(pDX, IDC_EDIT_wK, m_k);
	DDX_Text(pDX, IDC_EDIT_wLength, m_length);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(WienterFilterDlg, CDialog)
	//{{AFX_MSG_MAP(WienterFilterDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// WienterFilterDlg message handlers

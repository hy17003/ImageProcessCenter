// RegionGrowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "RegionGrowDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// RegionGrowDlg dialog


RegionGrowDlg::RegionGrowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(RegionGrowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(RegionGrowDlg)
	m_seedX = 0;
	m_seedY = 0;
	m_thresh = 0;
	//}}AFX_DATA_INIT
}


void RegionGrowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(RegionGrowDlg)
	DDX_Text(pDX, IDC_Edit_SeedX, m_seedX);
	DDX_Text(pDX, IDC_Edit_seedY, m_seedY);
	DDX_Text(pDX, IDC_Edit_Thresh, m_thresh);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(RegionGrowDlg, CDialog)
	//{{AFX_MSG_MAP(RegionGrowDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// RegionGrowDlg message handlers

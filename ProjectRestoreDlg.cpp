// ProjectRestoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "ProjectRestoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ProjectRestoreDlg dialog


ProjectRestoreDlg::ProjectRestoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ProjectRestoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(ProjectRestoreDlg)
	m_angle = 0;
	m_cycount = 0;
	m_length = 0;
	//}}AFX_DATA_INIT
}


void ProjectRestoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ProjectRestoreDlg)
	DDX_Text(pDX, IDC_Edit_pAngle, m_angle);
	DDX_Text(pDX, IDC_Edit_pCyCount, m_cycount);
	DDX_Text(pDX, IDC_Edit_pLength, m_length);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ProjectRestoreDlg, CDialog)
	//{{AFX_MSG_MAP(ProjectRestoreDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ProjectRestoreDlg message handlers

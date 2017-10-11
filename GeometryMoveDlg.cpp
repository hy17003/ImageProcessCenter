// GeometryMoveDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "GeometryMoveDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// GeometryMoveDlg dialog


GeometryMoveDlg::GeometryMoveDlg(CWnd* pParent /*=NULL*/)
	: CDialog(GeometryMoveDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(GeometryMoveDlg)
	m_OffsetX = 0;
	m_OffsetY = 0;
	//}}AFX_DATA_INIT
}


void GeometryMoveDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(GeometryMoveDlg)
	DDX_Text(pDX, IDC_Edit_OffsetX, m_OffsetX);
	DDX_Text(pDX, IDC_Edit_OffsetY, m_OffsetY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GeometryMoveDlg, CDialog)
	//{{AFX_MSG_MAP(GeometryMoveDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// GeometryMoveDlg message handlers

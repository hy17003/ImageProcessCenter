// linearStretchParamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "linearStretchParamDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// linearStretchParamDlg dialog


linearStretchParamDlg::linearStretchParamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(linearStretchParamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(linearStretchParamDlg)
	m_firstPointX = 50;
	m_firstPointY = 100;
	m_secondPointX = 200;
	m_secondPointY = 150;
	//}}AFX_DATA_INIT
}


void linearStretchParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(linearStretchParamDlg)
	DDX_Text(pDX, IDC_EditPointFirstX, m_firstPointX);
	DDX_Text(pDX, IDC_EditPointSecondX, m_secondPointX);
	DDX_Text(pDX, IDC_EditPointSecondY, m_secondPointY);
	DDX_Text(pDX, IDC_EditPointFirstY, m_firstPointY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(linearStretchParamDlg, CDialog)
	//{{AFX_MSG_MAP(linearStretchParamDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// linearStretchParamDlg message handlers

// MedianDialog.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "MedianDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMedianDialog dialog


CMedianDialog::CMedianDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMedianDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMedianDialog)
	m_nIndex = 0;
	//}}AFX_DATA_INIT
}


void CMedianDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMedianDialog)
	DDX_Control(pDX, IDC_MedianCombo, m_nCombo);
	DDX_CBIndex(pDX, IDC_MedianCombo, m_nIndex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMedianDialog, CDialog)
	//{{AFX_MSG_MAP(CMedianDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMedianDialog message handlers

void CMedianDialog::OnOK() 
{
	// TODO: Add extra validation here
	m_nIndex=((CComboBox *)GetDlgItem(IDC_MedianCombo))->GetCurSel();
	CDialog::OnOK();
}

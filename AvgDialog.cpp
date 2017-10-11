// AvgDialog.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "AvgDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AvgDialog dialog


AvgDialog::AvgDialog(CWnd* pParent /*=NULL*/)
	: CDialog(AvgDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(AvgDialog)
	m_nIndex = 0;
	//}}AFX_DATA_INIT
}


void AvgDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AvgDialog)
	DDX_Control(pDX, IDC_MedianCombo, m_nCombo);
	DDX_CBIndex(pDX, IDC_MedianCombo, m_nIndex);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AvgDialog, CDialog)
	//{{AFX_MSG_MAP(AvgDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AvgDialog message handlers

void AvgDialog::OnOK() 
{
	// TODO: Add extra validation here
	m_nIndex=((CComboBox *)GetDlgItem(IDC_MedianCombo))->GetCurSel();
	CDialog::OnOK();
}

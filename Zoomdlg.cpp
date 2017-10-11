// Zoomdlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "Zoomdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Zoomdlg dialog


Zoomdlg::Zoomdlg(CWnd* pParent /*=NULL*/)
	: CDialog(Zoomdlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(Zoomdlg)
	m_newHeight = 0;
	m_newWidth = 0;
	m_interpolationSelect = 0;
	//}}AFX_DATA_INIT
}


void Zoomdlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Zoomdlg)
	DDX_Text(pDX, IDC_Edit_newH, m_newHeight);
	DDX_Text(pDX, IDC_Edit_newW, m_newWidth);
	DDX_Radio(pDX, IDC_RADIO1, m_interpolationSelect);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Zoomdlg, CDialog)
	//{{AFX_MSG_MAP(Zoomdlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Zoomdlg message handlers

BOOL Zoomdlg::OnInitDialog() 
{
	CDialog::OnInitDialog();	

	//将原始图像的高显示在ID为IDC_Static_OldH的静态框中
	CString szStr;
    szStr.Format(_T("原图高:%4d 像素"),m_oldHeight);            
    SetDlgItemText(IDC_Static_OldH, szStr);

	//将原始图像的宽显示在ID为IDC_Static_OldW的静态框中
	szStr.Format(_T("原图宽:%4d 像素"), m_oldWidth);
    SetDlgItemText(IDC_Static_OldW, szStr);  

	//新图像的大小初始值设置为原图像的大小
	m_newHeight=m_oldHeight;
	m_newWidth=m_oldWidth;

	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

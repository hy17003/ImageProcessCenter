// MaskDefineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "MaskDefineDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MaskDefineDlg dialog


MaskDefineDlg::MaskDefineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MaskDefineDlg::IDD, pParent)
{
	//模板数组清零
	int i, j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			m_defineMask[i*5+j]=0;
		}
	}	
}


void MaskDefineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MaskDefineDlg)
	DDX_Text(pDX, IDC_Edit00, m_Edit00);
	DDX_Text(pDX, IDC_Edit01, m_Edit01);
	DDX_Text(pDX, IDC_Edit02, m_Edit02);
	DDX_Text(pDX, IDC_Edit03, m_Edit03);
	DDX_Text(pDX, IDC_Edit04, m_Edit04);
	DDX_Text(pDX, IDC_Edit10, m_Edit10);
	DDX_Text(pDX, IDC_Edit11, m_Edit11);
	DDX_Text(pDX, IDC_Edit12, m_Edit12);
	DDX_Text(pDX, IDC_Edit13, m_Edit13);
	DDX_Text(pDX, IDC_Edit14, m_Edit14);
	DDX_Text(pDX, IDC_Edit20, m_Edit20);
	DDX_Text(pDX, IDC_Edit21, m_Edit21);
	DDX_Text(pDX, IDC_Edit22, m_Edit22);
	DDX_Text(pDX, IDC_Edit23, m_Edit23);
	DDX_Text(pDX, IDC_Edit24, m_Edit24);
	DDX_Text(pDX, IDC_Edit30, m_Edit30);
	DDX_Text(pDX, IDC_Edit31, m_Edit31);
	DDX_Text(pDX, IDC_Edit32, m_Edit32);
	DDX_Text(pDX, IDC_Edit33, m_Edit33);
	DDX_Text(pDX, IDC_Edit34, m_Edit34);
	DDX_Text(pDX, IDC_Edit40, m_Edit40);
	DDX_Text(pDX, IDC_Edit41, m_Edit41);
	DDX_Text(pDX, IDC_Edit42, m_Edit42);
	DDX_Text(pDX, IDC_Edit43, m_Edit43);
	DDX_Text(pDX, IDC_Edit44, m_Edit44);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MaskDefineDlg, CDialog)
	//{{AFX_MSG_MAP(MaskDefineDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MaskDefineDlg message handlers

BOOL MaskDefineDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	//将模板数组数据赋值给编辑框变量
	//模板第0行
	m_Edit00=m_defineMask[0];
	m_Edit01=m_defineMask[1];
	m_Edit02=m_defineMask[2];
	m_Edit03=m_defineMask[3];
	m_Edit04=m_defineMask[4];

	//模板第一行
	m_Edit10=m_defineMask[5];
	m_Edit11=m_defineMask[6];
	m_Edit12=m_defineMask[7];
	m_Edit13=m_defineMask[8];
	m_Edit14=m_defineMask[9];

	//模板第二行
	m_Edit20=m_defineMask[10];
	m_Edit21=m_defineMask[11];
	m_Edit22=m_defineMask[12];
	m_Edit23=m_defineMask[13];
	m_Edit24=m_defineMask[14];

	//模板第三行
	m_Edit30=m_defineMask[15];
	m_Edit31=m_defineMask[16];
	m_Edit32=m_defineMask[17];
	m_Edit33=m_defineMask[18];
	m_Edit34=m_defineMask[19];

	//模板第四行
	m_Edit40=m_defineMask[20];
	m_Edit41=m_defineMask[21];
	m_Edit42=m_defineMask[22];
	m_Edit43=m_defineMask[23];
	m_Edit44=m_defineMask[24];

	//将模板数据显示
	UpdateData(false);
	return TRUE;  
}

void MaskDefineDlg::OnOK() 
{
	//用户输入的数据对对应变量进行更新
	UpdateData(true);

	//将用户指定的模板数据存入模板数组
	//模板第0行
	m_defineMask[0]=m_Edit00;
	m_defineMask[1]=m_Edit01;
	m_defineMask[2]=m_Edit02;
	m_defineMask[3]=m_Edit03;
	m_defineMask[4]=m_Edit04;

	//模板第一行
	m_defineMask[5]=m_Edit10;
	m_defineMask[6]=m_Edit11;
	m_defineMask[7]=m_Edit12;
	m_defineMask[8]=m_Edit13;
	m_defineMask[9]=m_Edit14;

	//模板第二行
	m_defineMask[10]=m_Edit20;
	m_defineMask[11]=m_Edit21;
	m_defineMask[12]=m_Edit22;
	m_defineMask[13]=m_Edit23;
	m_defineMask[14]=m_Edit24;

	//模板第三行
	m_defineMask[15]=m_Edit30;
	m_defineMask[16]=m_Edit31;
	m_defineMask[17]=m_Edit32;
	m_defineMask[18]=m_Edit33;
	m_defineMask[19]=m_Edit34;

	//模板第四行
	m_defineMask[20]=m_Edit40;
	m_defineMask[21]=m_Edit41;
	m_defineMask[22]=m_Edit42;
	m_defineMask[23]=m_Edit43;
	m_defineMask[24]=m_Edit44;

	CDialog::OnOK();
}

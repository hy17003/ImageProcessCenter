// WatershedParaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "WatershedParaDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// WatershedParaDlg dialog


WatershedParaDlg::WatershedParaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(WatershedParaDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(WatershedParaDlg)
	m_point1X = 0;
	m_point1Y = 0;
	m_point2X = 0;
	m_point2Y = 0;
	m_point3X = 0;
	m_point3Y = 0;
	m_objectCount = 0;
	m_contourFlg = FALSE;
	//}}AFX_DATA_INIT
}


void WatershedParaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(WatershedParaDlg)
	DDX_Text(pDX, IDC_Edit_Point1X, m_point1X);
	DDX_Text(pDX, IDC_Edit_Point1Y, m_point1Y);
	DDX_Text(pDX, IDC_Edit_Point2X, m_point2X);
	DDX_Text(pDX, IDC_Edit_Point2Y, m_point2Y);
	DDX_Text(pDX, IDC_Edit_Point3X, m_point3X);
	DDX_Text(pDX, IDC_Edit_Point3Y, m_point3Y);
	DDX_Text(pDX, IDC_Edit_ObjectCount, m_objectCount);
	DDX_Check(pDX, IDC_Check_Contour, m_contourFlg);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(WatershedParaDlg, CDialog)
	//{{AFX_MSG_MAP(WatershedParaDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// WatershedParaDlg message handlers

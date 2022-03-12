// EnterInterfaceDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "EnterInterfaceDialog.h"

#include "SequenceGeneratorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// EnterInterfaceDialog dialog


EnterInterfaceDialog::EnterInterfaceDialog(CWnd* pParent /*=NULL*/)
	: CDialog(EnterInterfaceDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(EnterInterfaceDialog)
	m_interface1 = _T("");
	m_interface2 = _T("");
	m_interface5 = _T("");
	m_interface4 = _T("");
	m_interface3 = _T("");
	m_interface6 = _T("");
	m_interface7 = _T("");
	m_interface8 = _T("");
	//}}AFX_DATA_INIT
}


void EnterInterfaceDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(EnterInterfaceDialog)
	DDX_Text(pDX, IDC_INTERFACE_EDIT1, m_interface1);
	DDX_Text(pDX, IDC_INTERFACE_EDIT2, m_interface2);
	DDX_Text(pDX, IDC_INTERFACE_EDIT5, m_interface5);
	DDX_Text(pDX, IDC_INTERFACE_EDIT4, m_interface4);
	DDX_Text(pDX, IDC_INTERFACE_EDIT3, m_interface3);
	DDX_Text(pDX, IDC_INTERFACE_EDIT6, m_interface6);
	DDX_Text(pDX, IDC_INTERFACE_EDIT7, m_interface7);
	DDX_Text(pDX, IDC_INTERFACE_EDIT8, m_interface8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(EnterInterfaceDialog, CDialog)
	//{{AFX_MSG_MAP(EnterInterfaceDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// EnterInterfaceDialog message handlers

void EnterInterfaceDialog::setComponent(int component)
{
	m_component_num = component;
}

BOOL EnterInterfaceDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_interface1 = CSequenceGeneratorDoc::getCompInterface(m_component_num, 0);
	m_interface2 = CSequenceGeneratorDoc::getCompInterface(m_component_num, 1);
	m_interface3 = CSequenceGeneratorDoc::getCompInterface(m_component_num, 2);
	m_interface4 = CSequenceGeneratorDoc::getCompInterface(m_component_num, 3);
	m_interface5 = CSequenceGeneratorDoc::getCompInterface(m_component_num, 4);
	m_interface6 = CSequenceGeneratorDoc::getCompInterface(m_component_num, 5);
	m_interface7 = CSequenceGeneratorDoc::getCompInterface(m_component_num, 6);
	m_interface8 = CSequenceGeneratorDoc::getCompInterface(m_component_num, 7);
	UpdateData(NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void EnterInterfaceDialog::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CSequenceGeneratorDoc::setCompInterface(m_component_num, 0, m_interface1);
	CSequenceGeneratorDoc::setCompInterface(m_component_num, 1, m_interface2);
	CSequenceGeneratorDoc::setCompInterface(m_component_num, 2, m_interface3);
	CSequenceGeneratorDoc::setCompInterface(m_component_num, 3, m_interface4);
	CSequenceGeneratorDoc::setCompInterface(m_component_num, 4, m_interface5);
	CSequenceGeneratorDoc::setCompInterface(m_component_num, 5, m_interface6);
	CSequenceGeneratorDoc::setCompInterface(m_component_num, 6, m_interface7);
	CSequenceGeneratorDoc::setCompInterface(m_component_num, 7, m_interface8);
	CDialog::OnOK();
}

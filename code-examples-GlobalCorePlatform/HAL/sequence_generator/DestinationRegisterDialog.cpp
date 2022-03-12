// DestinationRegisterDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "DestinationRegisterDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DestinationRegisterDialog dialog


DestinationRegisterDialog::DestinationRegisterDialog(CWnd* pParent /*=NULL*/)
	: CDialog(DestinationRegisterDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(DestinationRegisterDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DestinationRegisterDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DestinationRegisterDialog)
	DDX_Control(pDX, IDC_DESTINATION_REGISTER_COMBO, m_destination_register_cb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DestinationRegisterDialog, CDialog)
	//{{AFX_MSG_MAP(DestinationRegisterDialog)
	ON_BN_CLICKED(ID_DESTINATION_REGISTER_OK, OnDestinationRegisterOk)
	ON_BN_CLICKED(ID_DESTINATION_REGISTER_CANCEL, OnDestinationRegisterCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DestinationRegisterDialog message handlers

void DestinationRegisterDialog::OnDestinationRegisterOk() 
{
	// TODO: Add your control notification handler code here

	int destination_register = m_destination_register_cb.GetCurSel();

	if(destination_register != CB_ERR)
	{
		m_destination_register = destination_register;
	}
	else
		m_destination_register = -1;

	CDialog::OnOK();
}

void DestinationRegisterDialog::OnDestinationRegisterCancel() 
{
	// TODO: Add your control notification handler code here

	CDialog::OnCancel();
}

BOOL DestinationRegisterDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	if(m_destination_register >= 0 && m_destination_register <=31)
		m_destination_register_cb.SetCurSel(m_destination_register);
	else
		 m_destination_register =-1;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int DestinationRegisterDialog::getDestinationRegister()
{
	return m_destination_register;
}

void DestinationRegisterDialog::setDestinationRegister(int destination_register)
{
	m_destination_register = destination_register;
}

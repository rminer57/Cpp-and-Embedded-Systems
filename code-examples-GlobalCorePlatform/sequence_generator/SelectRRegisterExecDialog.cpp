// SelectRRegisterExecDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SelectRRegisterExecDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SelectRRegisterExecDialog dialog


SelectRRegisterExecDialog::SelectRRegisterExecDialog(CWnd* pParent /*=NULL*/)
	: CDialog(SelectRRegisterExecDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(SelectRRegisterExecDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SelectRRegisterExecDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SelectRRegisterExecDialog)
	DDX_Control(pDX, IDC_RETURN_REG_COMBO, m_return_reg_exec_cb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SelectRRegisterExecDialog, CDialog)
	//{{AFX_MSG_MAP(SelectRRegisterExecDialog)
	ON_BN_CLICKED(ID_RREGISTER_EXEC_OK, OnRregisterExecOk)
	ON_BN_CLICKED(ID_RREGISTER_EXEC_CANCEL, OnRregisterExecCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SelectRRegisterExecDialog message handlers

void SelectRRegisterExecDialog::OnRregisterExecOk() 
{
	// TODO: Add your control notification handler code here
	int return_register = m_return_reg_exec_cb.GetCurSel();

	if(return_register != CB_ERR)
	{
		m_return_reg = return_register;
	}
	else
		m_return_reg = -1;


	CDialog::OnOK();
}

void SelectRRegisterExecDialog::OnRregisterExecCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

BOOL SelectRRegisterExecDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	if(m_return_reg >= 0 && m_return_reg <=15)
		m_return_reg_exec_cb.SetCurSel(m_return_reg);
	else
		 m_return_reg =-1;


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void SelectRRegisterExecDialog::setReturnRegister(int return_register)
{
	m_return_reg = return_register;
}

int SelectRRegisterExecDialog::getReturnRegister()
{
	return m_return_reg;
}

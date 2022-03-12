// OperationManipDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "OperationManipDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// OperationManipDialog dialog


OperationManipDialog::OperationManipDialog(CWnd* pParent /*=NULL*/)
	: CDialog(OperationManipDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(OperationManipDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void OperationManipDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(OperationManipDialog)
	DDX_Control(pDX, IDC_OPERATION_MANIP_COMBO, m_operation_manip_cb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(OperationManipDialog, CDialog)
	//{{AFX_MSG_MAP(OperationManipDialog)
	ON_BN_CLICKED(ID_OPERATION_MANIP_OK, OnOperationManipOk)
	ON_BN_CLICKED(ID_OPERATION_MANIP_CANCEL, OnOperationManipCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// OperationManipDialog message handlers

void OperationManipDialog::OnOperationManipOk() 
{
	// TODO: Add your control notification handler code here
	int operation_selection = m_operation_manip_cb.GetCurSel();

	if(operation_selection != CB_ERR)
	{
		m_operation = operation_selection;
	}
	else
		m_operation = -1;


	CDialog::OnOK();
}

void OperationManipDialog::OnOperationManipCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

int OperationManipDialog::getOperation()
{
	return m_operation;
}

void OperationManipDialog::setOperation(int operation)
{
	m_operation = operation;
}

BOOL OperationManipDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_operation >= 0 && m_operation <=6)
		m_operation_manip_cb.SetCurSel(m_operation);
	else
		 m_operation =-1;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

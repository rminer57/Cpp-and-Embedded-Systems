// MiscOperationDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "MiscOperationDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MiscOperationDialog dialog


MiscOperationDialog::MiscOperationDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MiscOperationDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(MiscOperationDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void MiscOperationDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MiscOperationDialog)
	DDX_Control(pDX, IDC_OPERATION_MISC_COMBO, m_misc_operation_combo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MiscOperationDialog, CDialog)
	//{{AFX_MSG_MAP(MiscOperationDialog)
	ON_BN_CLICKED(ID_OPERATION_MISC_OK, OnOperationMiscOk)
	ON_BN_CLICKED(ID_OPERATION_MISC_CANCEL, OnOperationMiscCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MiscOperationDialog message handlers

void MiscOperationDialog::OnOperationMiscOk() 
{
	// TODO: Add your control notification handler code here
	int misc_operation_selection = m_misc_operation_combo.GetCurSel();

	if(misc_operation_selection != CB_ERR)
	{
		m_misc_operation = misc_operation_selection;
	}
	else
		m_misc_operation = -1;
	CDialog::OnOK();	
}

void MiscOperationDialog::OnOperationMiscCancel() 
{
	// TODO: Add your control notification handler code here

	CDialog::OnCancel();
}


BOOL MiscOperationDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	if((m_misc_operation >=0) && (m_misc_operation <= 2))	//Only supports delay, call, end so far.
		m_misc_operation_combo.SetCurSel(m_misc_operation);
	else
		 m_misc_operation =-1;


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void MiscOperationDialog::setMiscOperation(int operation)
{
	m_misc_operation = operation;
}

int MiscOperationDialog::getMiscOperation()
{
	return m_misc_operation;
}

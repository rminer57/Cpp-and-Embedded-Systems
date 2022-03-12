// MoveDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "MoveDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MoveDialog dialog


MoveDialog::MoveDialog(CWnd* pParent /*=NULL*/)
	: CDialog(MoveDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(MoveDialog)
	//}}AFX_DATA_INIT
}


void MoveDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MoveDialog)
	DDX_Control(pDX, IDC_MOVE_TO_EDIT, m_move_to_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MoveDialog, CDialog)
	//{{AFX_MSG_MAP(MoveDialog)
	ON_BN_CLICKED(ID_MOVE_TO_OK, OnMoveToOk)
	ON_BN_CLICKED(ID_MOVE_TO_CANCEL, OnMoveToCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MoveDialog message handlers

void MoveDialog::OnMoveToOk() 
{
	// TODO: Add your control notification handler code here

	m_move_to_edit.GetWindowText(m_move_to_string);
	m_move_to = atoi(m_move_to_string);
	CDialog::OnOK();
}

void MoveDialog::OnMoveToCancel() 
{
	// TODO: Add your control notification handler code here
	m_move_to = -1;
	CDialog::OnCancel();
}

BOOL MoveDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_move_to = -1;


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


int MoveDialog::getMoveTo()
{
	return m_move_to;
}


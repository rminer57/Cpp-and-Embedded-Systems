// JumpOffsetDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "JumpOffsetDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JumpOffsetDialog dialog


JumpOffsetDialog::JumpOffsetDialog(CWnd* pParent /*=NULL*/)
	: CDialog(JumpOffsetDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(JumpOffsetDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void JumpOffsetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JumpOffsetDialog)
	DDX_Control(pDX, IDC_JUMP_OFFSET_EDIT, m_jump_offset_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JumpOffsetDialog, CDialog)
	//{{AFX_MSG_MAP(JumpOffsetDialog)
	ON_BN_CLICKED(ID_JUMP_OFFSET_OK, OnJumpOffsetOk)
	ON_BN_CLICKED(ID_JUMP_OFFSET_CANCEL, OnJumpOffsetCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JumpOffsetDialog message handlers

void JumpOffsetDialog::OnJumpOffsetOk() 
{
	// TODO: Add your control notification handler code here

	m_jump_offset_edit.GetWindowText(m_jump_offset);

	CDialog::OnOK();
}

void JumpOffsetDialog::OnJumpOffsetCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

BOOL JumpOffsetDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_jump_offset_edit.SetWindowText(m_jump_offset);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void JumpOffsetDialog::setJumpOffset(CString jump_offset)
{
	m_jump_offset = jump_offset;
}

CString JumpOffsetDialog::getJumpOffset()
{
	return m_jump_offset;
}

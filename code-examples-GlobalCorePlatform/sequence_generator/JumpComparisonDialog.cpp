// JumpComparisonDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "JumpComparisonDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// JumpComparisonDialog dialog


JumpComparisonDialog::JumpComparisonDialog(CWnd* pParent /*=NULL*/)
	: CDialog(JumpComparisonDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(JumpComparisonDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void JumpComparisonDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(JumpComparisonDialog)
	DDX_Control(pDX, IDC_COMPARISON_JUMP_COMBO, m_jump_comparison_cb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(JumpComparisonDialog, CDialog)
	//{{AFX_MSG_MAP(JumpComparisonDialog)
	ON_BN_CLICKED(ID_COMPARISON_JUMP_OK, OnComparisonJumpOk)
	ON_BN_CLICKED(ID_COMPARISON_JUMP_CANCEL, OnComparisonJumpCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// JumpComparisonDialog message handlers

void JumpComparisonDialog::OnComparisonJumpOk() 
{
	// TODO: Add your control notification handler code here
	int jump_comparison_selection = m_jump_comparison_cb.GetCurSel();

	if(jump_comparison_selection != CB_ERR)
	{
		m_comparison = jump_comparison_selection;
	}
	else
		m_comparison = -1;


	CDialog::OnOK();
}

void JumpComparisonDialog::OnComparisonJumpCancel() 
{
	// TODO: Add your control notification handler code here
		CDialog::OnCancel();
}

int JumpComparisonDialog::getComparison()
{
	return m_comparison;
}

void JumpComparisonDialog::setComparison(int comparison)
{
	m_comparison = comparison;
}

BOOL JumpComparisonDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_comparison >= 0 && m_comparison <=6)
		m_jump_comparison_cb.SetCurSel(m_comparison);
	else
		 m_comparison =-1;


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// EditCommandDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "EditCommandDialog.h"
#include "SequenceGeneratorDoc.h"
//#include "SequenceGeneratorView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditCommandDialog dialog


CEditCommandDialog::CEditCommandDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CEditCommandDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditCommandDialog)
	//}}AFX_DATA_INIT
}


void CEditCommandDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditCommandDialog)
	DDX_Control(pDX, IDC_OPCODE_COMBO, m_command_opcode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditCommandDialog, CDialog)
	//{{AFX_MSG_MAP(CEditCommandDialog)
	ON_CBN_SELCHANGE(IDC_OPCODE_COMBO, OnSelchangeOpcodeCombo)
	ON_BN_CLICKED(IDOK, OnOpcodeOK)
	ON_BN_CLICKED(IDCANCEL, OnOpcodeCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


//OnInitDialog
BOOL CEditCommandDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_isOk = false;

	if(m_opcode >= 0 && m_opcode <=3)
		m_command_opcode.SetCurSel(m_opcode);
	else
		 m_opcode =-1;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


/////////////////////////////////////////////////////////////////////////////
// CEditCommandDialog message handlers

void CEditCommandDialog::OnSelchangeOpcodeCombo() 
{
	// TODO: Add your control notification handler code here
	
	
}

void CEditCommandDialog::OnOpcodeOK() 
{
	// TODO: Add your control notification handler code here
	int opcode_selection = m_command_opcode.GetCurSel();

	if(opcode_selection != CB_ERR)
	{
		m_opcode = opcode_selection;
	}
	else
		m_opcode = -1;

	m_isOk = true;
	CDialog::OnOK();
	
}

int CEditCommandDialog::getOpcode()
{
	return m_opcode;
}

void CEditCommandDialog::OnOpcodeCancel() 
{
	// TODO: Add your control notification handler code here
	m_isOk = false;
	CDialog::OnCancel();
}

void CEditCommandDialog::setOpcode(int opcode)
{
	m_opcode = opcode;
}

bool CEditCommandDialog::isOk()
{
	return m_isOk;
}

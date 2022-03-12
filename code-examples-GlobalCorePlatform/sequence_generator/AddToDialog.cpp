// AddToDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "AddToDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AddToDialog dialog


AddToDialog::AddToDialog(CWnd* pParent /*=NULL*/)
	: CDialog(AddToDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(AddToDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void AddToDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AddToDialog)
	DDX_Control(pDX, IDC_ADD_TO_EDIT, m_add_to_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AddToDialog, CDialog)
	//{{AFX_MSG_MAP(AddToDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AddToDialog message handlers

void AddToDialog::OnOK() 
{
	// TODO: Add extra validation here
	m_add_to_edit.GetWindowText(m_add_to_string);
	m_add_to = atoi(m_add_to_string);

	CDialog::OnOK();
}

void AddToDialog::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_add_to = -1;
	CDialog::OnCancel();
}

BOOL AddToDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_add_to = -1;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int AddToDialog::getAddTo()
{
	return m_add_to;
}

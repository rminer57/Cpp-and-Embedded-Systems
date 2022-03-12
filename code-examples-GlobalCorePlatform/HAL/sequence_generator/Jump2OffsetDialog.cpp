// Jump2OffsetDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "Jump2OffsetDialog.h"
#include "SequenceCommandBaseClass.h"
#include "SelectDataDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Jump2OffsetDialog dialog


Jump2OffsetDialog::Jump2OffsetDialog(CWnd* pParent /*=NULL*/)
	: CDialog(Jump2OffsetDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(Jump2OffsetDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Jump2OffsetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Jump2OffsetDialog)
	DDX_Control(pDX, IDC__OFFSET_REG_BUTTON, m_offset_reg_button);
	DDX_Control(pDX, IDC_OFFSET_EDIT, m_offset_edit);
	DDX_Control(pDX, IDC__OFFSET_REG_EDIT, m_offset_reg_edit);
	DDX_Control(pDX, IDC__OFFSET_REG_CHECK, m_offset_reg_check);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Jump2OffsetDialog, CDialog)
	//{{AFX_MSG_MAP(Jump2OffsetDialog)
	ON_BN_CLICKED(IDC__OFFSET_REG_BUTTON, OnOffsetRegButton)
	ON_BN_CLICKED(IDC__OFFSET_REG_CHECK, OnOffsetRegCheck)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Jump2OffsetDialog message handlers

void Jump2OffsetDialog::OnOffsetRegButton() 
{
	// TODO: Add your control notification handler code here
	SelectDataDialog offsetRegDlg;
	offsetRegDlg.setDataSource(m_offset_reg);
	offsetRegDlg.DoModal();
	
	if(offsetRegDlg.isOk())
	{
		m_offset_reg = offsetRegDlg.getDataSource();
		m_offset_reg_edit.SetWindowText(SequenceCommandBaseClass::getRegString(m_offset_reg));
	}
	UpdateData(NULL);
	
}

void Jump2OffsetDialog::OnOK() 
{
	// TODO: Add extra validation here
	m_offset_edit.GetWindowText(m_offset);
	m_ok = true;
	CDialog::OnOK();
}

void Jump2OffsetDialog::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

BOOL Jump2OffsetDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	//If there is data in the offset register, enable the data register
	//button

	m_ok = false;

	if(m_offset_reg.num >= 0 && m_offset_reg.num <= 31)
	{
		m_offset_reg_button.EnableWindow(TRUE);
		m_offset_reg_check.SetCheck(TRUE);
		m_offset_reg_edit.SetWindowText(SequenceCommandBaseClass::getRegString(m_offset_reg));
	}
	else
		m_offset_reg_button.EnableWindow(FALSE);


	m_offset_edit.SetWindowText(m_offset);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

CString Jump2OffsetDialog::getOffset()
{
	return m_offset;
}

RegisterType Jump2OffsetDialog::getOffsetReg()
{
	return m_offset_reg;
}

void Jump2OffsetDialog::setOffset(CString offset)
{
	m_offset = offset;
}

void Jump2OffsetDialog::setOffsetReg(RegisterType offset_reg)
{
	m_offset_reg.num = offset_reg.num;
	m_offset_reg.ext = offset_reg.ext;
	m_offset_reg.source_type = m_offset_reg.source_type;
}

void Jump2OffsetDialog::OnOffsetRegCheck() 
{
	// TODO: Add your control notification handler code here
	//If check box is checked, enable register button.
	if(m_offset_reg_check.GetCheck())
	{
		m_offset_reg_button.EnableWindow(TRUE);
	}
	else
	{
		m_offset_reg_button.EnableWindow(FALSE);
		m_offset_reg.num = -1;
	}

}

bool Jump2OffsetDialog::isOk()
{
	return m_ok;
}

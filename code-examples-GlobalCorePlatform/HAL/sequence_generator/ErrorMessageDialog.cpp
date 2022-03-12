// ErrorMessageDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "ErrorMessageDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ErrorMessageDialog dialog


ErrorMessageDialog::ErrorMessageDialog(CWnd* pParent /*=NULL*/)
	: CDialog(ErrorMessageDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(ErrorMessageDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	//The following code specifies this dialog as a modeless dialog.
	if(Create(ErrorMessageDialog::IDD, pParent))
	{
		//Show window
		ShowWindow(SW_SHOW);
	}
}


void ErrorMessageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ErrorMessageDialog)
	DDX_Control(pDX, IDC_ERROR_MESSAGE_EDIT, m_error_message_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ErrorMessageDialog, CDialog)
	//{{AFX_MSG_MAP(ErrorMessageDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ErrorMessageDialog message handlers

BOOL ErrorMessageDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_error_message_edit.SetWindowText(m_error_message);

	UpdateData(NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ErrorMessageDialog::setErrorMessage(CString errorMessage)
{
	m_error_message = errorMessage;
	m_error_message_edit.SetWindowText(m_error_message);
	UpdateData(NULL);
}

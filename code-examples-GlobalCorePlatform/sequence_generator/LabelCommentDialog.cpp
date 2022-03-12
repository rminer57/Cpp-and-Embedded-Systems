// LabelCommentDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "LabelCommentDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// LabelCommentDialog dialog


LabelCommentDialog::LabelCommentDialog(CWnd* pParent /*=NULL*/)
	: CDialog(LabelCommentDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(LabelCommentDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void LabelCommentDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(LabelCommentDialog)
	DDX_Control(pDX, IDC_LABEL_EDIT, m_label_edit_control);
	DDX_Control(pDX, IDC__COMMENT_EDIT, m_comment_edit_control);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(LabelCommentDialog, CDialog)
	//{{AFX_MSG_MAP(LabelCommentDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// LabelCommentDialog message handlers

void LabelCommentDialog::OnOK() 
{
	// TODO: Add extra validation here
	
	m_comment_edit_control.GetWindowText(m_comment);
	m_label_edit_control.GetWindowText(m_label);

	CDialog::OnOK();
}

void LabelCommentDialog::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void LabelCommentDialog::setLabel(CString label)
{
	m_label = label;
}

void LabelCommentDialog::setComment(CString comment)
{
	m_comment = comment;
}

CString LabelCommentDialog::getLabel()
{
	return m_label;
}

CString LabelCommentDialog::getComment()
{
	return m_comment;
}

BOOL LabelCommentDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_comment_edit_control.SetWindowText(m_comment);
	m_label_edit_control.SetWindowText(m_label);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

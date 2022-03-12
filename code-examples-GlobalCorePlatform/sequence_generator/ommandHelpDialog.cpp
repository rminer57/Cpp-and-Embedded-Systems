// ommandHelpDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "ommandHelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CommandHelpDialog dialog


CommandHelpDialog::CommandHelpDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CommandHelpDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CommandHelpDialog)
	m_opcode_text = _T("");
	m_data_text = _T("");
	m_command_text = _T("");
	m_commentNLabel_text = _T("");
	//}}AFX_DATA_INIT

	//Create modeless dialog
	if(Create(CommandHelpDialog::IDD, pParent))
	{
		//Show window
		ShowWindow(SW_SHOW);
	}
}


void CommandHelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CommandHelpDialog)
	DDX_Control(pDX, IDC_COMMAND_SEQUENCE_STATIC, m_commandTitle_static);
	DDX_Control(pDX, IDC_COMMTLABEL_STATIC, m_cmmtLabelTitle_static);
	DDX_Control(pDX, IDC_DATA_STATIC, m_dataTitle_static);
	DDX_Control(pDX, IDC_ENTER_OPCODE_STATIC, m_opcodeTitle_static);
	DDX_Control(pDX, IDC_HELP_STATIC, m_helpDlgTitle_static);
	DDX_Text(pDX, IDC_OPCODE_TEXT_STATIC, m_opcode_text);
	DDV_MaxChars(pDX, m_opcode_text, 1000);
	DDX_Text(pDX, IDC_DATA_TEXT_STATIC, m_data_text);
	DDV_MaxChars(pDX, m_data_text, 1000);
	DDX_Text(pDX, IDC_COMMAND_TEXT_STATIC, m_command_text);
	DDV_MaxChars(pDX, m_command_text, 1000);
	DDX_Text(pDX, IDC_CMMTLABEL_TEXT_STATIC, m_commentNLabel_text);
	DDV_MaxChars(pDX, m_commentNLabel_text, 1000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CommandHelpDialog, CDialog)
	//{{AFX_MSG_MAP(CommandHelpDialog)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CommandHelpDialog message handlers

BOOL CommandHelpDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	
	CFont titleFont;
	titleFont.CreateFont(18,5,0,0,FW_BOLD, TRUE,TRUE,1, 1,DEFAULT_CHARSET,OUT_STRING_PRECIS,CLIP_CHARACTER_PRECIS,
							DRAFT_QUALITY,NULL);//,NULL/*EnumFontFamilies*/);

	m_cmmtLabelTitle_static.SetFont(&titleFont,TRUE);
	m_cmmtLabelTitle_static.SetWindowText("Comments and Labels");

	m_opcodeTitle_static.SetFont(&titleFont,TRUE);
	m_opcodeTitle_static.SetWindowText("Selecting an Opcode");

	m_commandTitle_static.SetFont(&titleFont,TRUE);
	m_commandTitle_static.SetWindowText("Command Box");

	m_dataTitle_static.SetFont(&titleFont,TRUE);
	m_dataTitle_static.SetWindowText("Entering Data (After setting Opcode)");

	m_helpDlgTitle_static.SetFont(&titleFont,TRUE);
	m_helpDlgTitle_static.SetWindowText("COMMAND BOX HELP");

	m_command_text = "Each command within a sequence is represented by rectangular box.  All the information within a sequence will be written in this box.  When editing information, either right-click the mouse on the specified location, or double-click the left mouse button to edit information.  The cooresponding information can then be edited through each dialog.  For help on a particular feature/option, select context help button on the right corner of the particular dialog.";

	m_opcode_text = "When adding a new command box, the first action required will be to enter the Opcode of command.  If the Opcode is not selected, other options will be disabled.  In order to select an opcode, simply double-click the right mouse button or left-click on the label ""OPCODE?"".  Afterwards, a dialog box will appear with a combo box.  Select the appropriate Opcode and select OK.  Keep in mind, whenever an opcode is selected, all previous information is reseted.  This also applies to selecting the same Opcode.";
	
	m_data_text = "Once an Opcode is selected, the command box will then display various fields of text.  These fields represent the Opcode-specific information currently in the command box.  When information is available, the information is simply displayed in black text.  If information is unavailable, however, the text will be in bold red with a question mark at the end.  In order to enter information, right-click of double-click the left mouse button on the text fields.  The coresponding dialog will then appear.  For more information,  select the context help option located on upper right corner of the dialog.";
	
	m_commentNLabel_text = "In addition to adding Opcode-specific information, each command box also supports labels and comments.  In order to enter a label and comment for a particular command box, right-click the command box and select the \"Edit Label && Comment\" option.";
	

	UpdateData(NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CommandHelpDialog::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}

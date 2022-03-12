// DefaultHelpDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "DefaultHelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DefaultHelpDialog dialog


DefaultHelpDialog::DefaultHelpDialog(CWnd* pParent /*=NULL*/)
	: CDialog(DefaultHelpDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(DefaultHelpDialog)
	m_command_string = _T("");
	m_end_string = _T("");
	m_jump_string = _T("");
	m_start_string = _T("");
	//}}AFX_DATA_INIT

	//the following code makes this a modeless dialog (prefered style for help dialogs)
	if(Create(DefaultHelpDialog::IDD, pParent))
	{
		//Show window
		ShowWindow(SW_SHOW);
	}
}


void DefaultHelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DefaultHelpDialog)
	DDX_Control(pDX, IDC_START_TITLE, m_startTitle_static);
	DDX_Control(pDX, IDC_JUMP_TITLE, m_jumpTitle_static);
	DDX_Control(pDX, IDC_HELP_TITLE, m_helpTitle_static);
	DDX_Control(pDX, IDC_END_TITLE, m_endTitle_static);
	DDX_Control(pDX, IDC_COMMAND_BOX, m_command_static);
	DDX_Text(pDX, IDC_COMMAND_TEXT, m_command_string);
	DDV_MaxChars(pDX, m_command_string, 1000);
	DDX_Text(pDX, IDC_END_TEXT, m_end_string);
	DDV_MaxChars(pDX, m_end_string, 1000);
	DDX_Text(pDX, IDC_JUMP_TEXT, m_jump_string);
	DDV_MaxChars(pDX, m_jump_string, 1000);
	DDX_Text(pDX, IDC_START_TEXT, m_start_string);
	DDV_MaxChars(pDX, m_start_string, 1000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DefaultHelpDialog, CDialog)
	//{{AFX_MSG_MAP(DefaultHelpDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DefaultHelpDialog message handlers

BOOL DefaultHelpDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFont titleFont;
	titleFont.CreateFont(18,5,0,0,FW_BOLD, TRUE,TRUE,1, 1,DEFAULT_CHARSET,OUT_STRING_PRECIS,CLIP_CHARACTER_PRECIS,
							DRAFT_QUALITY,NULL);//,NULL/*EnumFontFamilies*/);

	m_command_static.SetFont(&titleFont);
	m_command_static.SetWindowText("Sequence Command Box");
	m_endTitle_static.SetFont(&titleFont);
	m_endTitle_static.SetWindowText("End Sequence Ellipse");
	m_helpTitle_static.SetFont(&titleFont);
	m_helpTitle_static.SetWindowText("DEFAULT HELP");
	m_jumpTitle_static.SetFont(&titleFont);
	m_jumpTitle_static.SetWindowText("Jump Arrow");
	m_startTitle_static.SetFont(&titleFont);
	m_startTitle_static.SetWindowText("Start Sequence Ellipse");


	m_start_string = "The start sequence ellipse represents the beginning of a sequence.  This is merely a visual place holder.";
	m_end_string = "The end sequence ellipse represents the end of a sequence.  This is not only an end place holder, but it provides the default end sequence value as well. (endseq value = 0x7F7F)";
	m_jump_string = "When using the jump opcode/operation, by default, a jump arrow appears.  This arrow specifies the next command to be executed if the jump condition is true.  The jump arrow can be set be specifying the offset.  If a destination offset register is used, this feature is disabled.  Otherwise, the jump arrow can be implemented by manually changining the jump offset number or selecting the edge of the arrow (edge at origin) and drawing the arrow to appropriate box.";
	m_command_string = "Each sequence command is represented by a box.  This box requires the user to enter sequence command information.";

	UpdateData(NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

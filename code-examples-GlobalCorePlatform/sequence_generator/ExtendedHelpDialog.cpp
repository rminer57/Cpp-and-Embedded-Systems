// ExtendedHelpDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "ExtendedHelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ExtendedHelpDialog dialog

//Help Text

/*EXECUTE*/						CString m_help_0 = "EXECUTE - This operation/opcode designates that the appropriate command will generate an Execute command.  An Execute command is used primarily to call an appropriate function and pass up to four data storage locations or one immediate data value as the function parameters.  The number of function parameters depends on the function being called.";
/*Return Register*/				CString m_help_1 = "RETURN REGISTER (for Execute Commands)\r\n\r\nThe return register is a required field for Execute commands.  This value represents the corresponding local register location that will store the command's return value. (If there is a return value)"; 
/*Component*/					CString m_help_2 = "COMPONENT (for Execute Commands)\r\n\r\nThe component field represents which of the radio software components will be used for the execute command.";
/*Interface*/					CString m_help_3 = "INTERFACE (for Execute Commands)\r\n\r\nThe interface field represents which of the radio software components will be used for the execute command.  The interface is primarily known as the function that will be called for a particular execute command.";
/*Data*/						CString m_help_4 = "EXECUTE DATA\r\n\r\nSimilar to other data, the user has the option to select immediate or up to 4 non-immediate data registers.  For more information on entering immediate or non-immediate data, see field labeled \"Entering Data\".";
/*Manipulate*/					CString m_help_5 = "MANIPULATE - The Manipulate operation/opcode is usually called when the data register values need to be compared, changed, retrieved, or loaded/moved.  The MANIPULATE operation/opcode will allow the user to take in only one immediate or non-immediate data location/data value parameter.";
/*Move/Load*/					CString m_help_6 = "MOVE/LOAD (for Manipulate Commands)\r\n\r\nThis keyword is used to load values into a particular data register.  In other words, this field prompts the user to enter a data location.";
/*Destination Register*/		CString m_help_7 = "DESTINATION REGISTER\r\n\r\nThis is simply a data location representing the global, local, and data store register locations where information will be stored.";
/*Data*/						CString m_help_8 = "DATA (for Manipulate)\r\nSee Entering Data field.";
/*JUMP*/						CString m_help_9 = "JUMP - This operation compares a data register value with another value.  This value can either be immediate or non-immediate data. If the condition is true, the sequence 'jumps' to the desired command.  The jump could be a forward or backward jump and is dependent on the destination offset register and/or offset field.";
/*Operation*/					CString m_help_10 = "OPERATION (for Jump Commands)\r\n\r\nThis is simply the operation the jump comparison will initiate.";
/*Operand 1*/					CString m_help_11 = "OPERAND 1 (for Jump Commands)\r\n\r\nThis is the first operand that the jump operation will use to compare with.  Selecting a global, local, or data store location is only allowed.";
/*Operand 2*/					CString m_help_12 = "OPERAND 2 (for Jump Commands)\r\n\r\nThis is the second operand that the jump operation uses to compare operand 1 with.  This value can either be a data location (global, local, or data store) or can be an explicit value.";
/*Offset*/						CString m_help_13 = "OFFSET (for Jump Commands)\r\n\r\nThis field represents the value that designates the jump length.  Both a data location or an explicit value can be used to specify the jump length.  If both are selected, the sum of the data location's value and the explicit value will become the jump length.";
/*MISCELLANEOUS*/				CString m_help_14 = "MISCELLANEOUS - This opcode/operation handles a specific operation that does not fall into any of the previous opcode/operation categories.";
/*Operation*/					CString m_help_15 = "OPERATION (for Miscellaneous Commands)\r\nThis is the miscellaneous operation the command will execute.  Currently, the only supporting operations are delay, call, and end sequence.";
/*Data*/						CString m_help_16 = "DATA (for Miscellaneous Commands)\r\n\r\nSome miscellaneous operations require an input parameter.  This parameter can either be immediate or non-immediate data.  Please see \"Entering Data\" field for more information on immediate or non-immediate data.";
/*Entering Data*/				CString m_help_17 = "ENTERING DATA\r\n\r\nWhen entering data, there are two forms.  The first is called immediate data, the second is non-immediate data.  Once one of these options can be selected.\r\n\r\nImmediate Data - This is explicit data passed to the operation specified.  This value is an integer value.\r\n\r\nNon-Immediate Data - This is implicit data that can be passed through the global, local, or data store locations.  Up to four of these values can be selected.\n\r\n\rIn order to choose a particular type of data entry, just select the radio button and enter the data.";
/*Entering Labels and Comments*/CString m_help_18 = "ENTERING LABELS AND COMMENTS\r\n\r\nEach command box allows the user to input a label and comment.  To do so, just right click a particular box and select the \"Enter Label && Comment\" menu option.  After entering a label, the label will be displayed on the upper left corner of the command box.";
/*Jump Arrow*/					CString m_help_19 = "JUMP ARROW\r\n\r\nThe jump arrow signifies the location of the next command if the jump condition is true.  If the jump offset is too high or too low, the jump arrow will extend to that location.  Keep in mind that the jump offset arrow is disabled if using a destination offset register.\r\n\r\nTo edit the jump offset, select the part in which the arrow originates from and drag the new dashed arrow to a specific command box location.  In addition, double clicking the designated location will allow the user to edit this offset number manually.";
/*Editing Components*/			CString m_help_20 = "EDITING COMPONENTS AND INTERFACES\r\n\r\nBecause components and interfaces vary depending on the specific radio software/hardware, Sequence Generator allows the user to edit or add both components and interfaces.(Up to 32 components and 8 interfaces)  To do so, just select the \"Edit Component\\Interface\" option in the Edit menu or press \"Ctrl+I\".  Then in the dialog, edit information and press Ok.  To edit the corresponding interface, press the appropriate button labeled \"Interface\".";
/*     and Interface*/

/*Adding Command Boxes*/		CString m_help_21 = "ADDING COMMAND BOXES\r\n\r\nThere are two Add options available.\r\n\r\nADD TO END\r\n\r\nAllows user to add a command box to the end of the sequence.  To do so, select the red \"+\" sign on the toolbar, press \"Ctrl+A\", or choose the option \"Add Command\" in the edit/right-click menus.\r\n\r\nADD TO...\r\n\r\nThis option adds a command box to a particular location that is specifed by the user.  To select this option, select the yellow \"+\" sign on the toolbar, press \"Ctrl+T\", or select the corresponding value in the edit/right-click menus.";
/*Removing Command Boxes*/		CString m_help_22 = "REMOVING COMMAND BOXES\r\n\r\nThis option allows the user to remove the last command box.  To choose this option, press the \"-\" button on the toolbar, press \"Ctrl+R\", or choose this option in the edit/right-click menus.";
/*Moving Command Boxes*/		CString m_help_23 = "MOVING COMMAND BOXES\r\n\r\nThis option allows the user to move a particular command box to the specified location.  To do so, either double-click or right-click the command number value and choose the \"Move to...\" option";
/*Deleting Command Boxes*/		CString m_help_24 = "DELETING COMMAND BOXES\r\n\r\nTo delete a command box, right-click at the box location and choose delete.  Then choose the yes option.";
/*Compiling*/					CString m_help_25 = "COMPILING\r\n\r\nCompiling creates a .asm file for the given sequence.  This file contains the values/syntax for the given sequence.\r\nTo compile, choose the \"Compile\" option in the Build menu, press the \"C\" button on the toolbar, or press F7.\r\n\r\nNote:  This application will not allow the user to compile if the command boxes are not complete.  A complete command box is represented by a green color, while incomplete command boxes are respresented by a blue color.  If the user chooses to compile with incomplete boxes, a dialog box with a list of errors will appear.";
/*Assemble*/					CString m_help_26 = "ASSEMBLING\r\n\r\nAssembling a .asm file creates a .bin and .map output file.  The .bin file is the binary file, while the .map is the text information of the sequence.\nTo choose this option, choose the \"Assemble\" option in the Build menu, press the \"A\" button on the toolbar, or press F8.";
/*Building*/					CString m_help_27 = "BUILDING\r\n\r\nBuilding both compiles and assembles a sequence at once.  To do this, choose the \"Build\" option in the Build menu, press the \"B\" button in the toolbar, or press F9.";

																										 
ExtendedHelpDialog::ExtendedHelpDialog(CWnd* pParent /*=NULL*/)
	: CDialog(ExtendedHelpDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(ExtendedHelpDialog)
	//}}AFX_DATA_INIT

	//Create modeless dialog
	if(Create(ExtendedHelpDialog::IDD, pParent))
	{
		//Show window
		ShowWindow(SW_SHOW);
	}
}


void ExtendedHelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ExtendedHelpDialog)
	DDX_Control(pDX, IDC_HELPINFO_EDIT, m_help_edit);
	DDX_Control(pDX, IDC_EXTENTEDHELP_TITLE, m_helpTitle_static);
	DDX_Control(pDX, IDC_HELP_COMBO, m_help_combo);
	DDX_Control(pDX, IDC_HELPEDIT_STATIC, m_help_edit_static);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ExtendedHelpDialog, CDialog)
	//{{AFX_MSG_MAP(ExtendedHelpDialog)
	ON_CBN_SELCHANGE(IDC_HELP_COMBO, OnSelchangeHelpCombo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ExtendedHelpDialog message handlers

void ExtendedHelpDialog::OnSelchangeHelpCombo() 
{
	// TODO: Add your control notification handler code here
	CFont titleFont;
	titleFont.CreateFont(14,5,0,0,FW_BOLD/*FW_NORMAL*/, FALSE,FALSE,0, 0,DEFAULT_CHARSET,OUT_STRING_PRECIS,CLIP_CHARACTER_PRECIS,
							PROOF_QUALITY,NULL);

	
	
	
	m_help_edit_static.SetFont(&titleFont);

	m_help_edit.SetFont(&titleFont);
	m_help_edit.SetLimitText(2000);
	m_help_edit.FmtLines(true);
	int help_selection = m_help_combo.GetCurSel();

	switch(help_selection)
	{
	case 0:
		m_help_edit_static.SetWindowText(m_help_0);
		
		break;
	case 1:
		m_help_edit_static.SetWindowText(m_help_1);
		break;
	case 2:
		m_help_edit_static.SetWindowText(m_help_2);
		break;
	case 3:
		m_help_edit_static.SetWindowText(m_help_3);
		break;
	case 4:
		m_help_edit_static.SetWindowText(m_help_4);
		break;
	case 5:
		m_help_edit_static.SetWindowText(m_help_5);
		break;
	case 6:
		m_help_edit_static.SetWindowText(m_help_6);
		break;
	case 7:
		m_help_edit_static.SetWindowText(m_help_7);
		break;
	case 8:
		m_help_edit_static.SetWindowText(m_help_8);
		break;
	case 9:
		m_help_edit_static.SetWindowText(m_help_9);
		break;
	case 10:
		m_help_edit_static.SetWindowText(m_help_10);
		break;
	case 11:
		m_help_edit_static.SetWindowText(m_help_11);
		break;
	case 12:
		m_help_edit_static.SetWindowText(m_help_12);
		break;
	case 13:
		m_help_edit_static.SetWindowText(m_help_13);
		break;
	case 14:
		m_help_edit_static.SetWindowText(m_help_14);
		break;
	case 15:
		m_help_edit_static.SetWindowText(m_help_15);
		break;
	case 16:
		m_help_edit_static.SetWindowText(m_help_16);
		break;
	case 17:
		m_help_edit_static.SetWindowText(m_help_17);
		break;
	case 18:
		m_help_edit_static.SetWindowText(m_help_18);
		break;
	case 19:
		m_help_edit_static.SetWindowText(m_help_19);
		break;
	case 20:
		m_help_edit_static.SetWindowText(m_help_20);
		break;
	case 21:
		m_help_edit_static.SetWindowText(m_help_21);
		break;
	case 22:
		m_help_edit_static.SetWindowText(m_help_22);
		break;
	case 23:
		m_help_edit_static.SetWindowText(m_help_23);
		break;
	case 24:
		m_help_edit_static.SetWindowText(m_help_24);
		break;
	case 25:
		m_help_edit_static.SetWindowText(m_help_25);
		break;
	case 26:
		m_help_edit_static.SetWindowText(m_help_26);
		break;
	case 27:
		m_help_edit_static.SetWindowText(m_help_27);
		break;
	default:
		m_help_edit_static.SetWindowText("Please select a help option");
		break;
	}
	UpdateData(NULL);
}

BOOL ExtendedHelpDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CFont titleFont;
	titleFont.CreateFont(30,10,0,0,FW_BOLD, FALSE,FALSE,0, 0,DEFAULT_CHARSET,OUT_STRING_PRECIS,CLIP_CHARACTER_PRECIS,
							PROOF_QUALITY,NULL);

	m_helpTitle_static.SetFont(&titleFont);
	m_helpTitle_static.SetWindowText("SEQUENCE GENERATOR HELP INFORMATION");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

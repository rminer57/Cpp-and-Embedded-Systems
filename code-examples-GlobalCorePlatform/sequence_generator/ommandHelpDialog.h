#if !defined(AFX_OMMANDHELPDIALOG_H__EE667AF8_90C3_11D5_8C8C_00C04F556625__INCLUDED_)
#define AFX_OMMANDHELPDIALOG_H__EE667AF8_90C3_11D5_8C8C_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ommandHelpDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CommandHelpDialog dialog

class CommandHelpDialog : public CDialog
{
// Construction
public:
	CommandHelpDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CommandHelpDialog)
	enum { IDD = IDD_COMMAND_HELP_DIALOG };
	CStatic	m_commandTitle_static;
	CStatic	m_cmmtLabelTitle_static;
	CStatic	m_dataTitle_static;
	CStatic	m_opcodeTitle_static;
	CStatic	m_helpDlgTitle_static;
	CString	m_opcode_text;
	CString	m_data_text;
	CString	m_command_text;
	CString	m_commentNLabel_text;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CommandHelpDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	

	// Generated message map functions
	//{{AFX_MSG(CommandHelpDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OMMANDHELPDIALOG_H__EE667AF8_90C3_11D5_8C8C_00C04F556625__INCLUDED_)

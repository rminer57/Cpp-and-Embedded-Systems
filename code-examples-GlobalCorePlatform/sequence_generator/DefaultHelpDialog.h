#if !defined(AFX_DEFAULTHELPDIALOG_H__0F9318D2_924D_11D5_8C8E_00C04F556625__INCLUDED_)
#define AFX_DEFAULTHELPDIALOG_H__0F9318D2_924D_11D5_8C8E_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DefaultHelpDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DefaultHelpDialog dialog

class DefaultHelpDialog : public CDialog
{
// Construction
public:
	DefaultHelpDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DefaultHelpDialog)
	enum { IDD = IDD_DEFAULT_HELP_DIALOG };
	CStatic	m_startTitle_static;
	CStatic	m_jumpTitle_static;
	CStatic	m_helpTitle_static;
	CStatic	m_endTitle_static;
	CStatic	m_command_static;
	CString	m_command_string;
	CString	m_end_string;
	CString	m_jump_string;
	CString	m_start_string;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DefaultHelpDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DefaultHelpDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEFAULTHELPDIALOG_H__0F9318D2_924D_11D5_8C8E_00C04F556625__INCLUDED_)

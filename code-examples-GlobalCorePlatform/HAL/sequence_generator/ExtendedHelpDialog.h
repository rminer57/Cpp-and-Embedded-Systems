#if !defined(AFX_EXTENDEDHELPDIALOG_H__4B1CA532_9184_11D5_8C8D_00C04F556625__INCLUDED_)
#define AFX_EXTENDEDHELPDIALOG_H__4B1CA532_9184_11D5_8C8D_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ExtendedHelpDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ExtendedHelpDialog dialog

class ExtendedHelpDialog : public CDialog
{
// Construction
public:
	ExtendedHelpDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ExtendedHelpDialog)
	enum { IDD = IDD_EXTENDED_HELP_DIALOG };
	CEdit	m_help_edit;
	CStatic	m_helpTitle_static;
	CComboBox	m_help_combo;
	CStatic	m_help_edit_static;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ExtendedHelpDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ExtendedHelpDialog)
	afx_msg void OnSelchangeHelpCombo();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTENDEDHELPDIALOG_H__4B1CA532_9184_11D5_8C8D_00C04F556625__INCLUDED_)

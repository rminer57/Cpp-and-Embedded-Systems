#if !defined(AFX_EDITCOMMANDDIALOG_H__285A7351_7F6F_11D5_8C76_00C04F556625__INCLUDED_)
#define AFX_EDITCOMMANDDIALOG_H__285A7351_7F6F_11D5_8C76_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditCommandDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditCommandDialog dialog

class CEditCommandDialog : public CDialog
{
// Construction
public:
	bool isOk();
	void setOpcode(int opcode);
	int getOpcode();
	CEditCommandDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditCommandDialog)
	enum { IDD = IDD_COMMAND_DIALOG };
	CComboBox	m_command_opcode;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditCommandDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool m_isOk;
	int m_opcode;

	// Generated message map functions
	//{{AFX_MSG(CEditCommandDialog)
	afx_msg void OnSelchangeOpcodeCombo();
	virtual BOOL OnInitDialog();
	afx_msg void OnOpcodeOK();
	afx_msg void OnOpcodeCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITCOMMANDDIALOG_H__285A7351_7F6F_11D5_8C76_00C04F556625__INCLUDED_)

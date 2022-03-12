#if !defined(AFX_SELECTRREGISTEREXECDIALOG_H__96019C1A_8100_11D5_8C79_00C04F556625__INCLUDED_)
#define AFX_SELECTRREGISTEREXECDIALOG_H__96019C1A_8100_11D5_8C79_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectRRegisterExecDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SelectRRegisterExecDialog dialog

class SelectRRegisterExecDialog : public CDialog
{
// Construction
public:
	int getReturnRegister();
	void setReturnRegister(int return_register);
	int m_return_reg;
	SelectRRegisterExecDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SelectRRegisterExecDialog)
	enum { IDD = IDD_RETURN_REG_DIALOG };
	CComboBox	m_return_reg_exec_cb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SelectRRegisterExecDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SelectRRegisterExecDialog)
	afx_msg void OnRregisterExecOk();
	afx_msg void OnRregisterExecCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTRREGISTEREXECDIALOG_H__96019C1A_8100_11D5_8C79_00C04F556625__INCLUDED_)

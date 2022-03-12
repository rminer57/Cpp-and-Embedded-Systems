#if !defined(AFX_INTERFACEEXECDIALOG_H__96019C18_8100_11D5_8C79_00C04F556625__INCLUDED_)
#define AFX_INTERFACEEXECDIALOG_H__96019C18_8100_11D5_8C79_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InterfaceExecDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// InterfaceExecDialog dialog

class InterfaceExecDialog : public CDialog
{
// Construction
public:
	int getInterface();
	int getComponent();
	void setInterface(int i_face);
	void populateComboBox();
	void setComponent(int component);
	InterfaceExecDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(InterfaceExecDialog)
	enum { IDD = IDD_INTERFACE_DIALOG };
	CComboBox	m_interface_exec_cb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(InterfaceExecDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_interface;
	int m_component;

	// Generated message map functions
	//{{AFX_MSG(InterfaceExecDialog)
	afx_msg void OnInterfaceExecOk();
	afx_msg void OnInterfaceExecCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTERFACEEXECDIALOG_H__96019C18_8100_11D5_8C79_00C04F556625__INCLUDED_)

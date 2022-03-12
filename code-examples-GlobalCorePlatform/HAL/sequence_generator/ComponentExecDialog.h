#if !defined(AFX_COMPONENTEXECDIALOG_H__96019C15_8100_11D5_8C79_00C04F556625__INCLUDED_)
#define AFX_COMPONENTEXECDIALOG_H__96019C15_8100_11D5_8C79_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ComponentExecDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ComponentExecDialog dialog

class ComponentExecDialog : public CDialog
{
// Construction
public:
	void setComponent(int component);
	int getComponent();
	ComponentExecDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ComponentExecDialog)
	enum { IDD = IDD_COMPONENT_EXEC_DIALOG };
	CComboBox	m_component_exec_cb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ComponentExecDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ComponentExecDialog)
	afx_msg void OnComponentExecOk();
	afx_msg void OnComponentExecCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_component;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPONENTEXECDIALOG_H__96019C15_8100_11D5_8C79_00C04F556625__INCLUDED_)

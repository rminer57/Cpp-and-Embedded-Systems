#if !defined(AFX_ENTERINTERFACEDIALOG_H__DF9A3A15_8CC9_11D5_8C84_00C04F556625__INCLUDED_)
#define AFX_ENTERINTERFACEDIALOG_H__DF9A3A15_8CC9_11D5_8C84_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterInterfaceDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// EnterInterfaceDialog dialog

class EnterInterfaceDialog : public CDialog
{
// Construction
public:
	void setComponent(int component);
	EnterInterfaceDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(EnterInterfaceDialog)
	enum { IDD = IDD_ENTER_INTERFACE_DIALOG };
	CString	m_interface1;
	CString	m_interface2;
	CString	m_interface5;
	CString	m_interface4;
	CString	m_interface3;
	CString	m_interface6;
	CString	m_interface7;
	CString	m_interface8;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(EnterInterfaceDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_component_num;

	// Generated message map functions
	//{{AFX_MSG(EnterInterfaceDialog)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTERINTERFACEDIALOG_H__DF9A3A15_8CC9_11D5_8C84_00C04F556625__INCLUDED_)

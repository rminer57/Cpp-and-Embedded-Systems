#if !defined(AFX_OPERATIONMANIPDIALOG_H__96019C19_8100_11D5_8C79_00C04F556625__INCLUDED_)
#define AFX_OPERATIONMANIPDIALOG_H__96019C19_8100_11D5_8C79_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OperationManipDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// OperationManipDialog dialog

class OperationManipDialog : public CDialog
{
// Construction
public:
	void setOperation(int operation);
	int getOperation();
	OperationManipDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(OperationManipDialog)
	enum { IDD = IDD_OPERATION_MANIP_DIALOG };
	CComboBox	m_operation_manip_cb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(OperationManipDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_operation;

	// Generated message map functions
	//{{AFX_MSG(OperationManipDialog)
	afx_msg void OnOperationManipOk();
	afx_msg void OnOperationManipCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATIONMANIPDIALOG_H__96019C19_8100_11D5_8C79_00C04F556625__INCLUDED_)

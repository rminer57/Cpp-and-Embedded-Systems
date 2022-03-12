#if !defined(AFX_MISCOPERATIONDIALOG_H__F8C689B2_84ED_11D5_8C7C_00C04F556625__INCLUDED_)
#define AFX_MISCOPERATIONDIALOG_H__F8C689B2_84ED_11D5_8C7C_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MiscOperationDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MiscOperationDialog dialog

class MiscOperationDialog : public CDialog
{
// Construction
public:
	int getMiscOperation();
	void setMiscOperation(int operation);
	MiscOperationDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(MiscOperationDialog)
	enum { IDD = IDD_MISC_OPERATION_DIALOG };
	CComboBox	m_misc_operation_combo;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MiscOperationDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_misc_operation;

	// Generated message map functions
	//{{AFX_MSG(MiscOperationDialog)
	afx_msg void OnOperationMiscOk();
	afx_msg void OnOperationMiscCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MISCOPERATIONDIALOG_H__F8C689B2_84ED_11D5_8C7C_00C04F556625__INCLUDED_)

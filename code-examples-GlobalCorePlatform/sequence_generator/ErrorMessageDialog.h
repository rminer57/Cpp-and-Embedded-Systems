#if !defined(AFX_ERRORMESSAGEDIALOG_H__DA8E0A11_9592_11D5_8C91_00C04F556625__INCLUDED_)
#define AFX_ERRORMESSAGEDIALOG_H__DA8E0A11_9592_11D5_8C91_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ErrorMessageDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ErrorMessageDialog dialog

class ErrorMessageDialog : public CDialog
{
// Construction
public:
	void setErrorMessage(CString errorMessage);
	ErrorMessageDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ErrorMessageDialog)
	enum { IDD = IDD_ERROR_DIALOG };
	CEdit	m_error_message_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ErrorMessageDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_error_message;

	// Generated message map functions
	//{{AFX_MSG(ErrorMessageDialog)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ERRORMESSAGEDIALOG_H__DA8E0A11_9592_11D5_8C91_00C04F556625__INCLUDED_)

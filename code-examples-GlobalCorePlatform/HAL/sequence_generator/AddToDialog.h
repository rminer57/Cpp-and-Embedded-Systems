#if !defined(AFX_ADDTODIALOG_H__DF9A39D9_8CC9_11D5_8C84_00C04F556625__INCLUDED_)
#define AFX_ADDTODIALOG_H__DF9A39D9_8CC9_11D5_8C84_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddToDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AddToDialog dialog

class AddToDialog : public CDialog
{
// Construction
public:
	int getAddTo();
	AddToDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AddToDialog)
	enum { IDD = IDD__ADD_TO_DIALOG };
	CEdit	m_add_to_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddToDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_add_to_string;
	int m_add_to;

	// Generated message map functions
	//{{AFX_MSG(AddToDialog)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDTODIALOG_H__DF9A39D9_8CC9_11D5_8C84_00C04F556625__INCLUDED_)

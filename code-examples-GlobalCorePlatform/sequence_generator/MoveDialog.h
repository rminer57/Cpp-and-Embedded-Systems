#if !defined(AFX_MOVEDIALOG_H__E3E07C01_85B8_11D5_8C7D_00C04F556625__INCLUDED_)
#define AFX_MOVEDIALOG_H__E3E07C01_85B8_11D5_8C7D_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MoveDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MoveDialog dialog

class MoveDialog : public CDialog
{
// Construction
public:
	int getMoveTo();
	MoveDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(MoveDialog)
	enum { IDD = IDD_MOVE_DIALOG };
	CEdit	m_move_to_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MoveDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_move_to_string;
	int m_move_to;
	int m_num_of_commands;

	// Generated message map functions
	//{{AFX_MSG(MoveDialog)
	afx_msg void OnMoveToOk();
	afx_msg void OnMoveToCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVEDIALOG_H__E3E07C01_85B8_11D5_8C7D_00C04F556625__INCLUDED_)

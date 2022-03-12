#if !defined(AFX_JUMPOFFSETDIALOG_H__E3E07C04_85B8_11D5_8C7D_00C04F556625__INCLUDED_)
#define AFX_JUMPOFFSETDIALOG_H__E3E07C04_85B8_11D5_8C7D_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JumpOffsetDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// JumpOffsetDialog dialog

class JumpOffsetDialog : public CDialog
{
// Construction
public:
	CString getJumpOffset();
	void setJumpOffset(CString jump_offset);
	JumpOffsetDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(JumpOffsetDialog)
	enum { IDD = IDD_JUMP_OFFSET_DIALOG };
	CEdit	m_jump_offset_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JumpOffsetDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_jump_offset;

	// Generated message map functions
	//{{AFX_MSG(JumpOffsetDialog)
	afx_msg void OnJumpOffsetOk();
	afx_msg void OnJumpOffsetCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JUMPOFFSETDIALOG_H__E3E07C04_85B8_11D5_8C7D_00C04F556625__INCLUDED_)

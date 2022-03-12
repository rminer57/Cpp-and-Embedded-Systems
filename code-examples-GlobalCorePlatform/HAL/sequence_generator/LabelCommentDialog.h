#if !defined(AFX_LABELCOMMENTDIALOG_H__88BFB253_8812_11D5_8C80_00C04F556625__INCLUDED_)
#define AFX_LABELCOMMENTDIALOG_H__88BFB253_8812_11D5_8C80_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LabelCommentDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// LabelCommentDialog dialog

class LabelCommentDialog : public CDialog
{
// Construction
public:
	CString getComment();
	CString getLabel();
	void setComment(CString comment);
	void setLabel(CString label);
	LabelCommentDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(LabelCommentDialog)
	enum { IDD = IDD_LABEL_COMMENT_DIALOG };
	CEdit	m_label_edit_control;
	CEdit	m_comment_edit_control;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(LabelCommentDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_label;
	CString m_comment;

	// Generated message map functions
	//{{AFX_MSG(LabelCommentDialog)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LABELCOMMENTDIALOG_H__88BFB253_8812_11D5_8C80_00C04F556625__INCLUDED_)

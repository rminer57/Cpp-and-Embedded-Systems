#if !defined(AFX_JUMPCOMPARISONDIALOG_H__96019C13_8100_11D5_8C79_00C04F556625__INCLUDED_)
#define AFX_JUMPCOMPARISONDIALOG_H__96019C13_8100_11D5_8C79_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// JumpComparisonDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// JumpComparisonDialog dialog

class JumpComparisonDialog : public CDialog
{
// Construction
public:
	void setComparison(int comparison);
	int getComparison();
	int m_comparison;
	JumpComparisonDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(JumpComparisonDialog)
	enum { IDD = IDD_COMPARISON_JUMP_DIALOG };
	CComboBox	m_jump_comparison_cb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(JumpComparisonDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(JumpComparisonDialog)
	afx_msg void OnComparisonJumpOk();
	afx_msg void OnComparisonJumpCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JUMPCOMPARISONDIALOG_H__96019C13_8100_11D5_8C79_00C04F556625__INCLUDED_)

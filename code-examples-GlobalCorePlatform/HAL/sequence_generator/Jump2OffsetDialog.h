#if !defined(AFX_JUMP2OFFSETDIALOG_H__460F94E1_8A6F_11D5_8C81_00C04F556625__INCLUDED_)
#define AFX_JUMP2OFFSETDIALOG_H__460F94E1_8A6F_11D5_8C81_00C04F556625__INCLUDED_

#include "SequenceCommandBaseClass.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Jump2OffsetDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Jump2OffsetDialog dialog

class Jump2OffsetDialog : public CDialog
{
// Construction
public:
	bool isOk();
	void setOffsetReg(RegisterType offset_reg);
	void setOffset(CString offset);
	RegisterType getOffsetReg();
	CString getOffset();
	Jump2OffsetDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Jump2OffsetDialog)
	enum { IDD = IDD_JUMP2_OFFSET_DIALOG };
	CButton	m_offset_reg_button;
	CEdit	m_offset_edit;
	CEdit	m_offset_reg_edit;
	CButton	m_offset_reg_check;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Jump2OffsetDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool m_ok;
	RegisterType m_offset_reg;
	CString m_offset;

	// Generated message map functions
	//{{AFX_MSG(Jump2OffsetDialog)
	afx_msg void OnOffsetRegButton();
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnOffsetRegCheck();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JUMP2OFFSETDIALOG_H__460F94E1_8A6F_11D5_8C81_00C04F556625__INCLUDED_)

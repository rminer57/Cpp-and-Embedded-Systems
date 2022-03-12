#if !defined(AFX_DATASTORAGEDIALOG_H__96019C16_8100_11D5_8C79_00C04F556625__INCLUDED_)
#define AFX_DATASTORAGEDIALOG_H__96019C16_8100_11D5_8C79_00C04F556625__INCLUDED_

#include "SequenceCommandBaseClass.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataStorageDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DataStorageDialog dialog

class DataStorageDialog : public CDialog
{
// Construction
public:
	bool isOk();
	//CString getRegString(RegisterType arg);
	void setIsImmediate(bool is_immediate);
	bool getIsImmediate();
	CString getImmediateData();
	void setImmediateData(CString immd_data);
	void setArg4(RegisterType arg4);
	void setArg3(RegisterType arg3);
	void setArg2(RegisterType arg2);
	void setArg1(RegisterType arg1);
	RegisterType getArg4();
	RegisterType getArg3();
	RegisterType getArg2();
	RegisterType getArg1();
	DataStorageDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DataStorageDialog)
	enum { IDD = IDD_DATA_DIALOG };
	CEdit	m_edit_reg1;
	CEdit	m_immediate_edit_control;
	CButton	m_data_reg4_button;
	CButton	m_data_reg3_button;
	CButton	m_data_reg2_button;
	CButton	m_data_reg1_button;
	int		m_immd_or_nonimmd;
	CString	m_immediate_edit;
	CString	m_nonimmd_reg1_edit;
	CString	m_nonimmd_reg2_edit;
	CString	m_nonimmd_reg3_edit;
	CString	m_nonimmd_reg4_edit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DataStorageDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool m_ok;
	CString immediate_dialog_data_string;
	bool m_is_immediate;
	RegisterType m_arg3;
	RegisterType m_arg4;
	RegisterType m_arg2;
	RegisterType m_arg1;


	// Generated message map functions
	//{{AFX_MSG(DataStorageDialog)
	afx_msg void OnButtonDataReg1();
	afx_msg void OnButtonDataReg2();
	afx_msg void OnButtonDataReg3();
	afx_msg void OnButtonDataReg4();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnImmediateRadio();
	afx_msg void OnNonimmediateRadio();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASTORAGEDIALOG_H__96019C16_8100_11D5_8C79_00C04F556625__INCLUDED_)

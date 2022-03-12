#if !defined(AFX_SELECTDATADIALOG_H__96019C17_8100_11D5_8C79_00C04F556625__INCLUDED_)
#define AFX_SELECTDATADIALOG_H__96019C17_8100_11D5_8C79_00C04F556625__INCLUDED_




#include "SequenceCommandBaseClass.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelectDataDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SelectDataDialog dialog

class SelectDataDialog : public CDialog
{
// Construction
public:
	bool isOk();
	void setDataSource(RegisterType data_source);
	RegisterType getDataSource();
	SelectDataDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SelectDataDialog)
	enum { IDD = IDD_DATA_REG_DIALOG };
	CComboBox	m_global_local_or_ds_cb;
	CComboBox	m_register_or_datastore_cb;
	CComboBox	m_select_data_reg_cb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SelectDataDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	bool m_isOk;
	RegisterType m_data_source;

	// Generated message map functions
	//{{AFX_MSG(SelectDataDialog)
	afx_msg void OnDatasourceOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeDataRegCombo();
	afx_msg void OnEditchangeRegordatasCombo1();
	afx_msg void OnDatasourceCancel();
	afx_msg void OnSelchangeRegordatasCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTDATADIALOG_H__96019C17_8100_11D5_8C79_00C04F556625__INCLUDED_)

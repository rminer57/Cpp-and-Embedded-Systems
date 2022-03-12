#if !defined(AFX_DESTINATIONREGISTERDIALOG_H__F8C689B1_84ED_11D5_8C7C_00C04F556625__INCLUDED_)
#define AFX_DESTINATIONREGISTERDIALOG_H__F8C689B1_84ED_11D5_8C7C_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DestinationRegisterDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DestinationRegisterDialog dialog

class DestinationRegisterDialog : public CDialog
{
// Construction
public:
	void setDestinationRegister(int destination_register);
	int getDestinationRegister();
	DestinationRegisterDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DestinationRegisterDialog)
	enum { IDD = IDD_DESTINATION_REGISTER_DIALOG };
	CComboBox	m_destination_register_cb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DestinationRegisterDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	int m_destination_register;

	// Generated message map functions
	//{{AFX_MSG(DestinationRegisterDialog)
	afx_msg void OnDestinationRegisterOk();
	afx_msg void OnDestinationRegisterCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESTINATIONREGISTERDIALOG_H__F8C689B1_84ED_11D5_8C7C_00C04F556625__INCLUDED_)

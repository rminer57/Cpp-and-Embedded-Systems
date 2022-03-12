#if !defined(AFX_ENTERCOMPONENTDIALOG_H__DF9A3A07_8CC9_11D5_8C84_00C04F556625__INCLUDED_)
#define AFX_ENTERCOMPONENTDIALOG_H__DF9A3A07_8CC9_11D5_8C84_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnterComponentDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// EnterComponentDialog dialog

class EnterComponentDialog : public CDialog
{
// Construction
public:
	static CString * m_comp_array[32];
	EnterComponentDialog(CWnd* pParent = NULL);   // standard constructor


// Dialog Data
	//{{AFX_DATA(EnterComponentDialog)
	enum { IDD = IDD__ENTER_COMPONENT_DIALOG };
	CString	m_component1;
	CString	m_component10;
	CString	m_component11;
	CString	m_component12;
	CString	m_component13;
	CString	m_component14;
	CString	m_component15;
	CString	m_component16;
	CString	m_component17;
	CString	m_component18;
	CString	m_component19;
	CString	m_component2;
	CString	m_component20;
	CString	m_component21;
	CString	m_component22;
	CString	m_component23;
	CString	m_component24;
	CString	m_component25;
	CString	m_component26;
	CString	m_component27;
	CString	m_component28;
	CString	m_component29;
	CString	m_component3;
	CString	m_component30;
	CString	m_component31;
	CString	m_component32;
	CString	m_component4;
	CString	m_component5;
	CString	m_component7;
	CString	m_component8;
	CString	m_component9;
	CString	m_component6;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(EnterComponentDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(EnterComponentDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnComponentButton();
	afx_msg void OnComponentButton2();
	afx_msg void OnComponentButton3();
	afx_msg void OnComponentButton4();
	afx_msg void OnComponentButton5();
	afx_msg void OnComponentButton6();
	afx_msg void OnComponentButton7();
	afx_msg void OnComponentButton8();
	afx_msg void OnComponentButton9();
	afx_msg void OnComponentButton10();
	afx_msg void OnComponentButton11();
	afx_msg void OnComponentButton12();
	afx_msg void OnComponentButton13();
	afx_msg void OnComponentButton14();
	afx_msg void OnComponentButton15();
	afx_msg void OnComponentButton16();
	afx_msg void OnComponentButton17();
	afx_msg void OnComponentButton18();
	afx_msg void OnComponentButton19();
	afx_msg void OnComponentButton20();
	afx_msg void OnComponentButton21();
	afx_msg void OnComponentButton22();
	afx_msg void OnComponentButton23();
	afx_msg void OnComponentButton24();
	afx_msg void OnComponentButton25();
	afx_msg void OnComponentButton26();
	afx_msg void OnComponentButton27();
	afx_msg void OnComponentButton28();
	afx_msg void OnComponentButton29();
	afx_msg void OnComponentButton30();
	afx_msg void OnComponentButton31();
	afx_msg void OnComponentButton32();

    //load and save component file used in EnterComponentDialog	
	afx_msg void EnterComponentDialog::OnLoadButton(); 
	afx_msg void EnterComponentDialog::OnSaveButton();
	
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENTERCOMPONENTDIALOG_H__DF9A3A07_8CC9_11D5_8C84_00C04F556625__INCLUDED_)

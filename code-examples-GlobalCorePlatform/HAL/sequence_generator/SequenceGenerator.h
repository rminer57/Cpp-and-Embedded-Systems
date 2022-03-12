// SequenceGenerator.h : main header file for the SEQUENCEGENERATOR application
//

#if !defined(AFX_SEQUENCEGENERATOR_H__B5213534_7BA2_11D5_8C72_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEGENERATOR_H__B5213534_7BA2_11D5_8C72_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorApp:
// See SequenceGenerator.cpp for the implementation of this class
//

class CSequenceGeneratorApp : public CWinApp
{
public:
	CSequenceGeneratorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSequenceGeneratorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSequenceGeneratorApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEQUENCEGENERATOR_H__B5213534_7BA2_11D5_8C72_00C04F556625__INCLUDED_)

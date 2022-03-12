// SequenceGeneratorDoc.h : interface of the CSequenceGeneratorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEGENERATORDOC_H__B521353A_7BA2_11D5_8C72_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEGENERATORDOC_H__B521353A_7BA2_11D5_8C72_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Afxcoll.h>
#include <Afxwin.h>
#include "SequencerList.h"

class CSequenceGeneratorDoc : public CDocument
{
  
public:
	bool isCompilable();
  
  // Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CSequenceGeneratorDoc)
  virtual BOOL OnNewDocument();
  virtual void Serialize(CArchive& ar);
  virtual void DeleteContents();
  //}}AFX_VIRTUAL
  
  // return a pointer to the current list
  SequencerList * getList();

  // return the name of a component/interface
  static CString getCompInterface(int compNum, int intNum);
  // set the name of a component/interface
  static void setCompInterface(int compNum, int intNum, CString newString);
  static BOOL CheckAndLoadComponentArchiveFile();
  static void WriteCompArchiveFile();
  static void CompSerialize(CArchive& ar);  
  
  // return the number of commands
  int getNumOfCommands();

  virtual ~CSequenceGeneratorDoc();
#ifdef _DEBUG
  virtual void AssertValid() const;
  virtual void Dump(CDumpContext& dc) const;
#endif

  // Public constants / variables
  static const CString nullString;
  static CString compIntStrings[32][9];
  
protected: // create from serialization only
  CSequenceGeneratorDoc();

    
  DECLARE_DYNCREATE(CSequenceGeneratorDoc)
    
    int m_num_of_commands;
  //{{AFX_MSG(CSequenceGeneratorDoc)
  afx_msg void OnEditAddCommand();
  afx_msg void OnEditRemoveCommand();
  afx_msg void OnBuildButton();
  afx_msg void OnAssembleButton();
  afx_msg void OnCompileButton();
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
    
private:
  // private variables
  SequencerList sequenceCommandList;
  static const CString buildSelected;
  static CString buildFileName;
  
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEQUENCEGENERATORDOC_H__B521353A_7BA2_11D5_8C72_00C04F556625__INCLUDED_)

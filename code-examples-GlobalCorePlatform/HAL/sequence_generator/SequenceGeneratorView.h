// SequenceGeneratorView.h : interface of the CSequenceGeneratorView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SEQUENCEGENERATORVIEW_H__B521353C_7BA2_11D5_8C72_00C04F556625__INCLUDED_)
#define AFX_SEQUENCEGENERATORVIEW_H__B521353C_7BA2_11D5_8C72_00C04F556625__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "SequenceExecuteClass.h"
#include "SequenceManipulate.h"
#include "SequenceJumpClass.h"
#include "SequenceMiscClass.h"

class CSequenceGeneratorView : public CScrollView
{
public:
	int getPasteLocation(CPoint point);
  virtual ~CSequenceGeneratorView();

  CSequenceGeneratorDoc* GetDocument();

  // Dialog windows
	void OnJump2Offset();
	void OnMiscData();
	void OnJumpOffsetRegister();
	void OnJumpOffset();
	void OnJumpOperand2();
	void OnJumpOperand1();
	void OnManipSourceData();
	void OnManipDestinationData();
	void OnMiscOperation();
	void OnJumpComparison();
	void OnDestinationRegister();
	void OnOperationManip();
	void OnReturnRegister();
	void OnInterfaceDialog();
	void OnComponentDialog();
  void OnMove();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSequenceGeneratorView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

protected:
	CSequenceGeneratorView();
	DECLARE_DYNCREATE(CSequenceGeneratorView)

// Generated message map functions

	//{{AFX_MSG(CSequenceGeneratorView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnContextEdit();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLabelCommentContext();
    afx_msg void OnViewSymbolic();
	afx_msg void OnUpdateViewSymbolic(CCmdUI* pCmdUI);
	afx_msg void OnAddToContext();
	afx_msg void OnDeleteContext();
	afx_msg void OnCompintContext();
	afx_msg void OnEditEditaddcomponent();
	afx_msg void OnHelpOption();
	afx_msg void OnExtendedhelpContext();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnGroupEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int getDropLocation(CPoint point);
	CRect getRectCoordinate(int command_num);
	int getCommandNum(CPoint point, CPoint offset);
  void getZones(CPoint point, CPoint offset, int *outputArray);

  // Text drawing functions
  CPoint getPrintCoordinates(int opcode, int zone, int commandNum);
  CRect getPrintBox(int opcode, int zone, int commandNum);
  void printHelper(CDC* pDC, CString printText, CString unknownText, CRect printBox);
  //void printHelperr(CDC* pDC, CString printText, CString unknownText, CRect printPoint);
  void printExecuteText(CDC* pDC, SequenceExecuteClass *exeCommand, int sequenceNumber);
  void printManipulateText(CDC* pDC, SequenceManipulate *manipCommand, int sequenceNumber);
  void printJumpText(CDC* pDC, SequenceJumpClass *jumpCommand, int sequenceNumber);
  int drawJumpArrow(CDC* pDC, SequenceJumpClass *jumpCommand, int sequenceNumber, int numArrows);
  void printMiscText(CDC* pDC, SequenceMiscClass *miscCommand, int sequenceNumber);

  // flag for displaying symbolic data vs. numbers
  bool m_symbolic;
  //Grouping rectange (rubber band) object
  CRectTracker groupItemRect;
  //This link list stores objects to be pasted
  SequencerList clipboardList;
  
};

#ifndef _DEBUG  // debug version in SequenceGeneratorView.cpp
inline CSequenceGeneratorDoc* CSequenceGeneratorView::GetDocument()
   { return (CSequenceGeneratorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEQUENCEGENERATORVIEW_H__B521353C_7BA2_11D5_8C72_00C04F556625__INCLUDED_)

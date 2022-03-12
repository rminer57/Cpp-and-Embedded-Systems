// SequenceGeneratorView.cpp : implementation of the CSequenceGeneratorView class
//


//***********************************************************************************
//Sequence Generator View Class:
//Implemented by Mark Antilla and Mohammad Sheikh
//***********************************************************************************

#include <Afxcoll.h>
#include <string.h>

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SequenceGeneratorDoc.h"
#include "SequenceGeneratorView.h"
#include "SequenceCommandBaseClass.h"

//Include all dialog classes
#include "EditCommandDialog.h"
#include "ComponentExecDialog.h"
#include "InterfaceExecDialog.h"
#include "SelectRRegisterExecDialog.h"
#include "SelectDataDialog.h"
#include "DataStorageDialog.h"
#include "JumpComparisonDialog.h"
#include "OperationManipDialog.h"
#include "MiscOperationDialog.h"
#include "MoveDialog.h"
#include "JumpOffsetDialog.h"
#include "LabelCommentDialog.h"
#include "Jump2OffsetDialog.h"
#include "AddToDialog.h"
#include "EnterComponentDialog.h"
#include "ommandHelpDialog.h"
#include "ExtendedHelpDialog.h"
#include "DefaultHelpDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//////////////Dynamic Menu Options/////////////

#define ID_EXEC_COMPONENT1_CONTEXT    5000 
#define ID_EXEC_INTERFACE_CONTEXT     5001
#define ID_EXEC_RETREGISTER_CONTEXT   5002
#define ID_EXEC_DATA_CONTEXT          5003
#define ID_MANIP_OPERATION_CONTEXT    5004
#define ID_MANIP_DEST_REG_CONTEXT     5005
#define ID_MANIP_SOURCE_REG_CONTEXT   5006
#define ID_JUMP_COMPARISON_CONTEXT    5007
#define ID_JUMP_OPERAND1_CONTEXT      5008
#define ID_JUMP_OPERAND2_CONTEXT      5009
#define ID_JUMP_OFFSET_CONTEXT        5011
#define ID_MISC_OPERATION_CONTEXT     5012
#define ID_MISC_DATA_CONTEXT          5013
#define ID_MOVE_TO_CONTEXT            5014



///////////////////////////////////////////////
// Printing constants
const UINT boxText = TA_CENTER + TA_BASELINE;	// flags to be set for box text
const UINT labelText = TA_RIGHT + TA_BASELINE;	// flags to be set for label text
const UINT commentText = TA_LEFT + TA_BASELINE;	// flags to be set for comment text
const COLORREF redColor = RGB(255,0,0);            // color red
const COLORREF blackColor = RGB(0,0,0);            // color black
const COLORREF pastelGreenColor = RGB(192,255,192);// color pastel green
const COLORREF blueColor = RGB(0,0,255);           // color pastel blue
const COLORREF pastelBlueColor = RGB(140,200,255); //another form of pastel blue (used for incomplete boxes)

const arrowOffset = 15;

// Rectangle dimension constants
const int commandRectWidth = 250; //160
const int commandRectHeight = 110;//100
const int commandRectSpacing = 80;//100
// Drag-and-Drop miniature dimension constants
const int miniRectWidth = 50;
const int miniRectHeight = 40;
// Rectangle Object Constants
const CRect dummyRect(CPoint(0,0), CPoint(commandRectWidth,commandRectHeight));
const CRect minRect_offset(CPoint((commandRectWidth-miniRectWidth)/2, 0-((commandRectSpacing)-(miniRectHeight/2))),
                           CPoint(0-(commandRectWidth-miniRectWidth)/2, 0-(commandRectSpacing + commandRectHeight + commandRectHeight - miniRectHeight)/2));
// Starting point
const CPoint startPoint = CPoint(40,50);
// Invalid rectangle (not drawn)
const CRect nullRect = CRect(CPoint(-1,-1), CPoint(-1,-1));

// execute zones
const CRect exeZoneA = CRect(CPoint(0,0),                                       CPoint(commandRectWidth/6,commandRectHeight/4));
const CRect exeZoneB = CRect(CPoint(commandRectWidth/6,0),                      CPoint(commandRectWidth,commandRectHeight/4));
const CRect exeZoneC = CRect(CPoint(0,commandRectHeight/4),                     CPoint(commandRectWidth/2,commandRectHeight/2));
const CRect exeZoneD = CRect(CPoint(commandRectWidth/2,commandRectHeight/4),    CPoint(commandRectWidth,commandRectHeight/2));
const CRect exeZoneE = CRect(CPoint(0,commandRectHeight/2),                     CPoint(commandRectWidth,commandRectHeight*3/4));
const CRect exeZoneF = CRect(CPoint(0,commandRectHeight*3/4),                   CPoint(commandRectWidth,commandRectHeight));
const CRect exeZones[] = {exeZoneA, exeZoneB, exeZoneC, exeZoneD, exeZoneE, exeZoneF, nullRect};
// manipluate zones
const CRect manZoneA = CRect(CPoint(0,0),                                       CPoint(commandRectWidth/6,commandRectHeight/3));
const CRect manZoneB = CRect(CPoint(commandRectWidth/6,0),                      CPoint(commandRectWidth,commandRectHeight/3));
const CRect manZoneC = CRect(CPoint(0,commandRectHeight/3),                     CPoint(commandRectWidth,commandRectHeight*2/3));
const CRect manZoneD = CRect(CPoint(0,commandRectHeight*2/3),                   CPoint(commandRectWidth/2,commandRectHeight));
const CRect manZoneE = CRect(CPoint(commandRectWidth/2,commandRectHeight*2/3),  CPoint(commandRectWidth,commandRectHeight));
const CRect manZones[] = {manZoneA, manZoneB, manZoneC, manZoneD, manZoneE, nullRect, nullRect};
// jump zones (version 1)
const CRect jmp1ZoneA = CRect(CPoint(0,0),                                      CPoint(commandRectWidth/6,commandRectHeight/4));
const CRect jmp1ZoneB = CRect(CPoint(commandRectWidth/6,0),                     CPoint(commandRectWidth,commandRectHeight/4));
const CRect jmp1ZoneC = CRect(CPoint(0,commandRectHeight/4),                    CPoint(commandRectWidth,commandRectHeight/2));
const CRect jmp1ZoneD = CRect(CPoint(0,commandRectHeight/2),                    CPoint(commandRectWidth/2,commandRectHeight*3/4));
const CRect jmp1ZoneE = CRect(CPoint(commandRectWidth/2,commandRectHeight/2),   CPoint(commandRectWidth,commandRectHeight*3/4));
const CRect jmp1ZoneF = CRect(CPoint(0,commandRectHeight*3/4),                  CPoint(commandRectWidth/2,commandRectHeight));
const CRect jmp1ZoneG = CRect(CPoint(commandRectWidth/2,commandRectHeight*3/4), CPoint(commandRectWidth,commandRectHeight));
const CRect jmp1Zones[] = {jmp1ZoneA, jmp1ZoneB, jmp1ZoneC, jmp1ZoneD, jmp1ZoneE, jmp1ZoneF, jmp1ZoneG};
// jump zones (version 2)
const CRect jmp2ZoneA = CRect(CPoint(0,0),                                      CPoint(commandRectWidth/6,commandRectHeight/3));
const CRect jmp2ZoneB = CRect(CPoint(commandRectWidth/6,0),                     CPoint(commandRectWidth,commandRectHeight/3));
const CRect jmp2ZoneC = CRect(CPoint(0,commandRectHeight/3),                    CPoint(commandRectWidth,commandRectHeight*2/3));
const CRect jmp2ZoneD = CRect(CPoint(0,commandRectHeight*2/3),                  CPoint(commandRectWidth/2,commandRectHeight));
const CRect jmp2ZoneE = CRect(CPoint(commandRectWidth/2,commandRectHeight*2/3), CPoint(commandRectWidth,commandRectHeight));
const CRect jmp2Zones[] = {jmp2ZoneA, jmp1ZoneB, jmp1ZoneC, jmp1ZoneD, jmp1ZoneE, nullRect, nullRect};
// miscellaneous zones
const CRect miscZoneA = CRect(CPoint(0,0),                                      CPoint(commandRectWidth/6,commandRectHeight/3));
const CRect miscZoneB = CRect(CPoint(commandRectWidth/6,0),                     CPoint(commandRectWidth,commandRectHeight/3));
const CRect miscZoneC = CRect(CPoint(0,commandRectHeight/3),                    CPoint(commandRectWidth,commandRectHeight*2/3));
const CRect miscZoneD = CRect(CPoint(0,commandRectHeight*2/3),                  CPoint(commandRectWidth,commandRectHeight));
const CRect miscZones[] = {miscZoneA, miscZoneB, miscZoneC, miscZoneD, nullRect, nullRect, nullRect};

const CRect *allZones[7] = {exeZones, manZones, jmp1Zones, miscZones};


//Flag and data storage variables.
CRect start_crec = dummyRect;
CPoint dragState;
CPoint jumpDragState;
CPoint copyPastePoint;
CPoint scrollPoint;


int leftclick_command = -1;
int rightclick_command = 0;
int m_move_to = 0;
int helpFlag = -1;
int arrowNum = 0;
int scrollFlag = -1;
int numOfGroups = 0;
int currentGroup = 0;
int previousGroup = 0;
int numOfNonGroups = 0;
int paintCounter = 0;
//int rubberBandFlag = -1;

//Global command help dialog pointer (used in constructing a new modeless dialog in leftbuttonDownClick)
//In CSequenceCommandView destructor, the object is deleted.
CommandHelpDialog *commandHlpDlg = NULL;
ExtendedHelpDialog * extendedHlpDlg = NULL;
DefaultHelpDialog * defaultHlpDlg = NULL;

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorView

IMPLEMENT_DYNCREATE(CSequenceGeneratorView, CScrollView)

BEGIN_MESSAGE_MAP(CSequenceGeneratorView, CScrollView)
//{{AFX_MSG_MAP(CSequenceGeneratorView)
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_CONTEXTMENU()
ON_COMMAND(ID_CONTEXT_EDIT, OnContextEdit)
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONDBLCLK()
ON_COMMAND(ID_LABEL_COMMENT_CONTEXT, OnLabelCommentContext)
ON_COMMAND(ID_VIEW_SYMBOLIC, OnViewSymbolic)
ON_UPDATE_COMMAND_UI(ID_VIEW_SYMBOLIC, OnUpdateViewSymbolic)
ON_COMMAND(ID_ADD_TO_CONTEXT, OnAddToContext)
ON_COMMAND(ID_DELETE_CONTEXT, OnDeleteContext)
	ON_COMMAND(ID_COMPINT_CONTEXT, OnCompintContext)
	ON_COMMAND(ID_EDIT_EDITADDCOMPONENT, OnEditEditaddcomponent)
	ON_COMMAND(ID_HELP_OPTION, OnHelpOption)
	ON_COMMAND(ID_EXTENDEDHELP_CONTEXT, OnExtendedhelpContext)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_GROUP_EDIT, OnGroupEdit)
	//}}AFX_MSG_MAP

// Standard printing commands
ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)

//Associate the above ID's with functions/handlers.
ON_COMMAND(ID_EXEC_COMPONENT1_CONTEXT, OnComponentDialog)
ON_COMMAND(ID_EXEC_INTERFACE_CONTEXT, OnInterfaceDialog)
ON_COMMAND(ID_EXEC_RETREGISTER_CONTEXT, OnReturnRegister)
ON_COMMAND(ID_EXEC_DATA_CONTEXT, OnDestinationRegister)
ON_COMMAND(ID_MANIP_OPERATION_CONTEXT, OnOperationManip)
ON_COMMAND(ID_MANIP_DEST_REG_CONTEXT, OnManipDestinationData)
ON_COMMAND(ID_MANIP_SOURCE_REG_CONTEXT, OnManipSourceData)
ON_COMMAND(ID_JUMP_COMPARISON_CONTEXT, OnJumpComparison)
ON_COMMAND(ID_JUMP_OPERAND1_CONTEXT, OnJumpOperand1)
ON_COMMAND(ID_JUMP_OPERAND2_CONTEXT, OnJumpOperand2)
ON_COMMAND(ID_JUMP_OFFSET_CONTEXT, OnJump2Offset)
ON_COMMAND(ID_MISC_OPERATION_CONTEXT, OnMiscOperation)
ON_COMMAND(ID_MISC_DATA_CONTEXT, OnMiscData)
ON_COMMAND(ID_MOVE_TO_CONTEXT, OnMove)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorView construction/destruction
/////////////////////////////////////////////////////////////////////////////
CSequenceGeneratorView::CSequenceGeneratorView()
{
  start_crec.OffsetRect(startPoint);
}

CSequenceGeneratorView::~CSequenceGeneratorView()
{

	//delete command help dialog upon destruction of parent class.
	delete commandHlpDlg;
	commandHlpDlg = NULL;

	//delete extended help dialog upon destruction of parent class.
	delete extendedHlpDlg;
	extendedHlpDlg = NULL;

	//delete default help dialog upon destruction of parent class
	delete defaultHlpDlg;
	defaultHlpDlg = NULL;

	//deallocate clipboardList memory
	clipboardList.~SequencerList();

}

BOOL CSequenceGeneratorView::PreCreateWindow(CREATESTRUCT& cs)
{
  // TODO: Modify the Window class or styles here by modifying
  //  the CREATESTRUCT cs
  
  return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorView drawing
/////////////////////////////////////////////////////////////////////////////
void CSequenceGeneratorView::OnDraw(CDC* pDC)
{
  CSequenceGeneratorDoc* pDoc = GetDocument();  // Document class pointer
  ASSERT_VALID(pDoc);
  CWnd *pWnd = GetWindow(0);                    // Window class pointer
  int i = 0;                                    // Loop variable
  CString cstr;                                 // temp String for printing commandBox text
  SequenceCommandBaseClass *tempSequence;       // temp command to store current command
  CBrush * pOldBrush;                           // pointer to initial brush
  CBrush boxBrush;                              // brush used for box drawing 
  CBrush blueBoxBrush;							// brush used for 'empty' box drawing
  CPoint printCoordinates;
  CRect boxRect;                                // temp variable with coordinates of each box
  /*int*/ arrowNum = 0;                             // count of number of jump arrows (used so arrows don't overlap)
  int listSize = pDoc->getNumOfCommands();      // number of commands
  
  //if(numOfNonGroups == 0)
	//  numOfNonGroups = listSize;
  
  /*---Set up drawing/printing controls---*/
  //Save the current brush
  pOldBrush = pDC->GetCurrentBrush();
  //Create solid pastel green brush
  boxBrush.CreateSolidBrush(pastelGreenColor);
  //Create solid pastel blue brush
  blueBoxBrush.CreateSolidBrush(pastelBlueColor);
  //Select the yellow brush into the device context
  pDC->SelectObject(&boxBrush);
  //Align Text, set text background to transparent
  pDC->SetTextAlign(boxText);
  pDC->SetBkMode(TRANSPARENT);
  
  /*---Draw start/stop elipses and text---*/
  //Draw a line from Start point/ellipse to End point/ellipse
  pDC->MoveTo(getRectCoordinate(0).CenterPoint());
  pDC->LineTo(getRectCoordinate(listSize+1).CenterPoint());
  
  //Draw Start ellipse
  boxRect = getRectCoordinate(0);
  boxRect.DeflateRect(commandRectWidth/5, commandRectHeight/4);
  pDC->Ellipse(boxRect);
  //Draw ending elipse
  boxRect = getRectCoordinate(listSize+1);
  boxRect.DeflateRect(commandRectWidth/5, commandRectHeight/4);
  pDC->Ellipse(boxRect);
  
  // Print Start Text
  pDC->TextOut(getRectCoordinate(0).CenterPoint().x,getRectCoordinate(0).CenterPoint().y + 5,"Start");
  // Print Stop Text
  pDC->TextOut(getRectCoordinate(listSize+1).CenterPoint().x,getRectCoordinate(listSize+1).CenterPoint().y + 5,"Stop");
  
  /*---Draw all commands---*/
  // Loop through list and draw box w/data for each command
  for(i = 1; i <= listSize; i++)
  {
    // Get current command
    tempSequence = pDoc->getList()->getAt(i);

	if(tempSequence->getGroupNum() != -1)
	{
		previousGroup = currentGroup;
		currentGroup = tempSequence->getGroupNum();

		if(currentGroup == previousGroup)
		{	//Draw 'i' on appropriate box

		}
		else
		{
			pDC->SelectObject(&boxBrush);
			boxRect = getRectCoordinate(i);
			pDC->Rectangle(boxRect);
		}

		

	}
	else
	{
    //Set box color to green if the box has complete information.  Otherwise, color boxes light blue.
	pDoc->isCompilable();					//Determines which boxes in the list are compilable.
	if(!tempSequence->getComplete())
	{	
		pDC->SelectObject(&blueBoxBrush);
	}
	else
		pDC->SelectObject(&boxBrush);
	

    /*---Draw command box---*/
    // Get coordinates of current command box
    boxRect = getRectCoordinate(i);
    // Draw rectangle representing each command
    pDC->Rectangle(boxRect);  

	// If isSelected is true, draw an outer rectangle to show that it is selected.
	if(tempSequence->getIsSelected())
	{
		pDC->DrawFocusRect(boxRect);
	}
    
    /*---Print text---*/
    // Draw label (if no label then nullString drawn) to left of connecting line, just above box
    pDC->SetTextColor(blueColor);
    pDC->SetTextAlign(labelText);
    pDC->TextOut(boxRect.CenterPoint().x - 5, boxRect.CenterPoint().y - boxRect.Height()/2 - 10, tempSequence->getLabel());
    
    // Align text for box text printing
    pDC->SetTextAlign(boxText);
    pDC->SetTextColor(blackColor);
    // Get coordinates for command number
    printCoordinates = getPrintCoordinates(0, 0, i);
    // Print command number 
    pDC->TextOut(printCoordinates.x, printCoordinates.y, CString(itoa(i, new char[4], 10))); //string needed for text out
    
    switch(tempSequence->getOpcode())
    {
    case 0:  //Write EXECUTE text
      {
        printExecuteText(pDC, (SequenceExecuteClass *)tempSequence, i);
        break;
      }
    case 1:  //Write MANIPULATE Text
      {
        printManipulateText(pDC, (SequenceManipulate *)tempSequence, i);
        break;
      }
    case 2:  //Write JUMP text / draw jump arrow
      {
        printJumpText(pDC, (SequenceJumpClass *)tempSequence, i);
        arrowNum = drawJumpArrow(pDC, (SequenceJumpClass *)tempSequence, i, arrowNum);
        break;
      }
    case 3:  //Write MISC text
      {
        printMiscText(pDC, (SequenceMiscClass *)tempSequence, i);
        break;
      }
    default: // Unknown opcode
      {
        printHelper(pDC, CSequenceGeneratorDoc::nullString, "OPCODE?", getPrintBox(0, 1, i));
        break;
      }
    }  // end switch

  //Comment should be drawn after Jump arrow is drawn, so it was moved here.
  //Draw Comment (if no comment, a nullString is drawn).  This will be drawn to the right of the box
  pDC->SetTextColor(blueColor);
  pDC->SetTextAlign(commentText);
  pDC->TextOut(boxRect.BottomRight().x + 10, boxRect.BottomRight().y - boxRect.Height()/2 - 10, tempSequence->getComment());
  pDC->SetTextColor(blackColor);	//back to black (default)
	}
  }  // end loop
  

 

  if(dragState.x != -1)
  { 
    CRect windRect;
    pWnd->GetWindowRect(&windRect);
    CRect tempRect;// = dummyRect;
    tempRect.right = dummyRect.Width()/2;
    tempRect.bottom = dummyRect.Height()/2;
    tempRect.top = -1*(tempRect.bottom);
    tempRect.left = -1*tempRect.right;
    tempRect.OffsetRect(dragState);
    //pDC->Rectangle(tempRect);
    CSize dragRectWidth;
    dragRectWidth.cx = 5;
    dragRectWidth.cy = 5;
    
    int drop_loc = getDropLocation(dragState);
    if((drop_loc != leftclick_command)&&(drop_loc != leftclick_command+1))
    {
      CRect frameRect;
      frameRect = getRectCoordinate(drop_loc);
      frameRect.left += minRect_offset.left;
      frameRect.right += minRect_offset.right;
      frameRect.top += minRect_offset.top;
      frameRect.bottom += minRect_offset.bottom;
      //pDC->Rectangle(frameRect);
      CSize dragRectWidth2;
      dragRectWidth2.cx = 3;
      dragRectWidth2.cy = 3;
      frameRect.OffsetRect(CPoint(GetScrollPosition().x * -1, GetScrollPosition().y * -1));
      pDC->DrawDragRect(frameRect, dragRectWidth, frameRect, dragRectWidth2, NULL, NULL);
    }
    pDC->DrawDragRect(tempRect, dragRectWidth,getRectCoordinate(leftclick_command)-GetScrollPosition(),dragRectWidth , NULL, NULL);

  
  }

  //Draw jump drag arrow scheme
  if(jumpDragState.x != -1)
  {
	  //pDC->Rectangle(dummyRect);
	  //Jump drag arrow implementation goes here
	  CPen *currentPen = pDC->GetCurrentPen();//Save current pen
	  CPen dragArrowPen(PS_DASH,1, redColor/*RGB(200,200,50)*/);
	  CRect jumpRect = getRectCoordinate(leftclick_command - 1);
	  CPoint tempArrowPoint = jumpRect.BottomRight() + CPoint(arrowNum * arrowOffset, -1);
	  pDC->SelectObject(&dragArrowPen);
	  pDC->MoveTo(jumpRect.BottomRight() + CPoint(-1,-1));
	  pDC->LineTo(tempArrowPoint);

	  tempArrowPoint.y = jumpDragState.y + GetScrollPosition().y;// + commandRectSpacing + commandRectHeight;
	  pDC->LineTo(tempArrowPoint);
	  tempArrowPoint.x -= arrowNum * arrowOffset;
	  pDC->LineTo(tempArrowPoint);
	  pDC->LineTo(tempArrowPoint + CPoint(7,-7));
	  pDC->MoveTo(tempArrowPoint);
	  pDC->LineTo(tempArrowPoint + CPoint(7, 7));

	  //Restore previous pen color
	  pDC->SelectObject(currentPen);
	  
  }
  
  //Restore the current brush
  pDC->SelectObject(pOldBrush);
  
  //Sets scroll size dynamically depending on number of commands/boxes
  CSize sizeTotal;
  sizeTotal.cx = 300;
  sizeTotal.cy = getRectCoordinate(i+1).bottom + 50;
  SetScrollSizes(MM_TEXT, sizeTotal);

  //If the helpFlag is true (ie. helpFlag = 1), Set the cursor to IDC_HELP
  if(helpFlag == 1)
  {	  
	  SetCursor(LoadCursor(NULL, IDC_HELP));
  }


  //Scroll up or down depending on mouse position and if left mouse button is pressed.
  if(scrollFlag == MK_LBUTTON /*|| rubberBandFlag >= 0*/)
  {
	CRect windowRect;
	GetWindowRect(windowRect);

	if(scrollPoint.y + windowRect.top>= windowRect.BottomRight().y  - 200)
		SetScrollPos(SB_VERT,GetScrollPos(SB_VERT) + 75,FALSE);
	else if(scrollPoint.y + windowRect.top <= windowRect.TopLeft().y  + 100)
		SetScrollPos(SB_VERT,GetScrollPos(SB_VERT) - 75, FALSE);
  }
  
}

void CSequenceGeneratorView::OnInitialUpdate()
{
  CScrollView::OnInitialUpdate();
  CSequenceGeneratorDoc* pDoc = GetDocument();
  CSize sizeTotal;
  
  sizeTotal.cx = 300;
  sizeTotal.cy = pDoc->getNumOfCommands() * 500;
  SetScrollSizes(MM_TEXT, sizeTotal);
  
  dragState.x = -1;
  dragState.y = -1;
  jumpDragState.x = -1;
  jumpDragState.y = -1;
  
}

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorView printing
/////////////////////////////////////////////////////////////////////////////
BOOL CSequenceGeneratorView::OnPreparePrinting(CPrintInfo* pInfo)
{
  // default preparation
  return DoPreparePrinting(pInfo);
}

void CSequenceGeneratorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
  // TODO: add extra initialization before printing
}

void CSequenceGeneratorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
  // TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorView diagnostics
/////////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG
void CSequenceGeneratorView::AssertValid() const
{
  CScrollView::AssertValid();
}

void CSequenceGeneratorView::Dump(CDumpContext& dc) const
{
  CScrollView::Dump(dc);
}

CSequenceGeneratorDoc* CSequenceGeneratorView::GetDocument() // non-debug version is inline
{
  ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSequenceGeneratorDoc)));
  return (CSequenceGeneratorDoc*)m_pDocument;
}
#endif //_DEBUG


/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorView message handlers
/////////////////////////////////////////////////////////////////////////////

//Handle mouse left-click DOWN
void CSequenceGeneratorView::OnLButtonDown(UINT nFlags, CPoint point) 
{
  CSequenceGeneratorDoc* pDoc = GetDocument();
  CDC * pDC = GetDC();
  
  int i = 1;

  
  //Initialize all previously selected items back to being unselected. If shift is NOT
  //selected w/ LButton down
  if(nFlags != MK_LBUTTON + MK_SHIFT)
  {
	for(i = 1; i <= pDoc->getList()->getSize();i++)
	{
	  pDoc->getList()->getAt(i)->setIsSelected(false);
	}
  }
  // If inside a commandBox, then set the global leftclick_command with
  // command number
  int current_command = getCommandNum(point, GetScrollPosition());
  
  //If the helpFlag is true (ie. helpFlag = 1), display help message.
  //Otherwise prepare to drag a box.
  if(helpFlag == 1)
  {
	  if(current_command != 0)
	  {
			//AfxMessageBox("This is a command Box");
		  commandHlpDlg = new CommandHelpDialog(this);
		  
	  }
	  else
	  {
			//AfxMessageBox("Outside - No help necessary");
		  defaultHlpDlg = new DefaultHelpDialog(this);
	  }

	  helpFlag = -1;
  }
  else
  {

	  int drop_loc = getDropLocation(point);

	  CRect currentRect = getRectCoordinate(drop_loc);

	  //For test purposes

	  CPoint scrollPosition = GetScrollPosition();
	
	  CPoint gtPoints = CPoint(currentRect.BottomRight().x + (arrowNum - 1) * arrowOffset, currentRect.BottomRight().y - 5);
	  CPoint ltPoints = CPoint(currentRect.BottomRight().x + (arrowNum * arrowOffset),currentRect.BottomRight().y + 5);

	  CPoint points = (point.x,point.y + commandRectSpacing + commandRectHeight);
	  //arrow edge
	  //tempArrowPoint.y = getRectCoordinate(sequenceNumber + 1 + jumpCommand->getOffset()).CenterPoint().y;
	  //////////////////////////////////
	  if(current_command != 0)
	  {
		//If left button + shift key is pressed, allow user to select command boxes.
		//Otherwise, assume user will drag command box.
		if(nFlags == MK_LBUTTON + MK_SHIFT)
		{
			pDoc->getList()->getAt(current_command)->setIsSelected(true);
		}
		else
		{
			dragState = point;
			leftclick_command = current_command;
		}
	  }
	  else if((point.x >= (currentRect.BottomRight().x/* + ((arrowNum - 1) * arrowOffset)*/))
		&&(point.x <= (currentRect.BottomRight().x + (arrowNum * arrowOffset)))
		&&((point.y + GetScrollPosition().y + commandRectSpacing + commandRectHeight) >= (currentRect.BottomRight().y - 10))
		&&((point.y + GetScrollPosition().y + commandRectSpacing + commandRectHeight)<= (currentRect.BottomRight().y + 10)))
	  {
		jumpDragState = point;
		//AfxMessageBox("It works");
		leftclick_command = drop_loc;
	  }
	  else
	  {

		  //rubberBandFlag = 1;
		  //Draw selection rectangle
		  groupItemRect.TrackRubberBand(this,point,TRUE);
		  
		  CRect groupRect;
		  groupItemRect.GetTrueRect(&groupRect);
		  groupRect.top+=GetScrollPosition().y;
		  groupRect.bottom+=GetScrollPosition().y;
	
		  CRect tempRectCoordinates;

		  CString tempstring;
		  for(i = 1; i <= pDoc->getList()->getSize(); i++)
		  {
				tempRectCoordinates = getRectCoordinate(i);
				if(tempRectCoordinates.top >= groupRect.top && tempRectCoordinates.bottom <= groupRect.bottom
					&& tempRectCoordinates.left >= groupRect.left && tempRectCoordinates.right <= groupRect.right)
				{
				//	tempstring.Format("%d",i);
				//	AfxMessageBox(tempstring + " was selected");
					pDoc->getList()->getAt(i)->setIsSelected(true);
				}
		  }

		  

		 /* CString temp;
			temp.Format("%d",groupRect.top);
			CString temp2;
			temp2.Format("%d",groupRect.bottom);
			temp+=" ";
			temp+=temp2;
			AfxMessageBox(temp);*/
	  }
	  
	  // Request a redraw
	  pDoc->UpdateAllViews(NULL);
  } 
 
  
  
}

//Handle mouse left-click UP (drag-and-drop placement)
void CSequenceGeneratorView::OnLButtonUp(UINT nFlags, CPoint point) 
{
  CSequenceGeneratorDoc* pDoc = GetDocument();
  
  //rubberBandFlag = -1;
  int current_command = getCommandNum(point,GetScrollPosition());
  
  
	
	int drop_command = 0;
	SequencerList *tempList = pDoc->getList();
	  SequenceCommandBaseClass *tempCommand;
  
	  if(dragState.x != -1)
	  {
		dragState.x = -1;
		dragState.y = -1;
    
		drop_command = getDropLocation(point);
		tempCommand = tempList->getAt(leftclick_command);
		if (drop_command < leftclick_command)
		{
		  tempList->removeFrom(leftclick_command);
		  tempList->insertAt(drop_command, tempCommand);
		}
		else
		{
		  tempList->insertAt(drop_command, tempCommand);
		  tempList->removeFrom(leftclick_command);
		}
		pDoc->UpdateAllViews(NULL);
	  }
	  else if(jumpDragState.x != -1)
	  {
		  jumpDragState.x = -1;
		  jumpDragState.y = -1;

		  int new_jump_offset = getCommandNum(CPoint(point.x - (arrowNum * arrowOffset) - 50,point.y),GetScrollPosition()); //getDropLocation(point);
		  SequenceJumpClass *tempJumpCommand = (SequenceJumpClass *)tempList->getAt(leftclick_command - 1);
		  if(new_jump_offset != 0)
		  {
			int old_jump_offset = tempJumpCommand->getOffset();
			tempJumpCommand->setOffset(new_jump_offset - leftclick_command /*-1*/);
		  }

		  //Get object and change jump offset here
		  pDoc->UpdateAllViews(NULL);
	  }
	  else
	  {
		  //See OnLButtonDown implementation.
			/*CRect groupRect;
			groupItemRect.GetTrueRect(&groupRect);
			CString temp;
			temp.Format("%d",groupRect.top);
			CString temp2;
			temp2.Format("%d",groupRect.bottom);
			temp+=" ";
			temp+=temp2;
			AfxMessageBox(temp);*/

		  
	  }
  
  CScrollView::OnLButtonUp(nFlags, point);
}

// Handle mouse double click (edit field)
void CSequenceGeneratorView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
  int *zone = new int[5];
  CSequenceGeneratorDoc* pDoc = GetDocument();
  
  getZones(point, GetScrollPosition(), zone);
  SequenceCommandBaseClass *tempObject;
  
  rightclick_command = zone[0];
  if ((rightclick_command > 0) && (rightclick_command <= pDoc->getList()->getSize()))
  {
    tempObject = pDoc->getList()->getAt(rightclick_command);
    switch(tempObject->getOpcode())
    {
      //Execute
    case 0:
      {
        SequenceExecuteClass * tempExecute = (SequenceExecuteClass*)tempObject;
        switch(zone[1])
        {
        case 1:
          {
            //Move
            OnMove();
            break;  
          }
        case 2:
          {
            OnContextEdit();  //Get Opcode
            break;
          }
        case 3:
          {
            OnComponentDialog();  //Get Component
            break;
          }
        case 4:
          {
            //Get Interface
            OnInterfaceDialog();
            break;
          }
        case 5:
          {
            //Return Register
            OnReturnRegister(); 
            break;
          }
        case 6:
          {
            //data
            OnDestinationRegister();
            break;
          }
        default:
          break;
        }
        
        break;
      }
      //Manipulate
    case 1:
      {
        switch (zone[2])
        {
        case 1:
          {
            //Move
            OnMove();
            break;
          }
        case 2:
          {
            //Opcode
            OnContextEdit();
            break;
          }
        case 3:
          {
            //Operation
            OnOperationManip();
            break;
          }
        case 4:
          {
            //Destination
            OnManipDestinationData();
            break;
          }
        case 5:
          {
            //Source
            OnManipSourceData();
            break;
          }
        }
        
        break;
      }
    case 2:
      {
        switch (zone[3])
        {
        case 1:
          {
            //Move
            OnMove();
            break;
          }
        case 2:
          {
            //Opcode
            OnContextEdit();
            break;
          }
        case 3:
          {
            //Comparison
            OnJumpComparison();
            break;
          }
        case 4:
          {
            //Operand 1
            OnJumpOperand1();
            break;
          }
        case 5:
          {
            //Operand 2
            OnJumpOperand2();
            break;
          }
        case 6:
          {
            //Offset Register
            //OnJumpOffsetRegister();
            OnJump2Offset();
            break;
          }
        case 7:
          {
            //Offset
            //OnJumpOffset();
            OnJump2Offset();
            break;
          }
        default:
          {
            break;
          }
        }
        
        break;
      }
    case 3:
      {
        switch (zone[4])
        {
        case 1:
          {
            //Move
            OnMove();
            break;
          }
        case 2:
          {
            //Opcode
            OnContextEdit();
            break;
          }
        case 3:
          {
            //Operation
            OnMiscOperation();
            break;
          }
        case 4:
          {
            //Data
            OnMiscData();
            break;
          }
        default:
          break;
        }
        
        break;
      }
    default:
      {
        OnContextEdit();
        break;
      }
    }       
  }
  
  CScrollView::OnLButtonDblClk(nFlags, point);
}

// Handle mouse movements (drag-and-drop movements)
void CSequenceGeneratorView::OnMouseMove(UINT nFlags, CPoint point) 
{
	CSequenceGeneratorDoc* pDoc = GetDocument();

	//If helpFlag is ture (ie. helpFlag = 1), set cursor to IDC_HELP
	if(helpFlag == 1)
	{
		SetCursor(LoadCursor(NULL, IDC_HELP));		
	}

  // if dragging, then get new point and repaint
  if(dragState.x != -1)
  {
    
    //CDC * pDC = GetDC();
   // CWnd *pWnd = GetWindow(0);
    
    // Set global dragState to new point
    dragState = point;
    
    // repaint request
	paintCounter++;

	if(paintCounter % 7 == 0)
		pDoc->UpdateAllViews(NULL);
	
  }
  else if(jumpDragState.x != -1)
  {
	 // CDC *pDC = GetDC();
	//  CWnd *pWnd = GetWindow(0);

	  jumpDragState = point;

	  //request paint
	  paintCounter++;

	  if(paintCounter % 7 == 0)
		pDoc->UpdateAllViews(NULL);
  }

  /*if(nFlags == MK_LBUTTON)
  {
	CRect windowRect;
	GetWindowRect(windowRect);

	//Scroll Implementation 1:
	//if(point.y >= windowRect.bottom - 500)
	//{
	//	CPoint scrollPoint = point;
	//	scrollPoint.y+=100;
	//	ScrollToPosition(scrollPoint);
		
	//}
	//Scroll Implementation 2:
	SetScrollPos(SB_VERT, point.y ,FALSE);

  }*/

  scrollPoint = point;
  scrollFlag = nFlags;

  CScrollView::OnMouseMove(nFlags, point);
}

void CSequenceGeneratorView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
  // TODO: Add your message handler code here
 
  //The point stored here is used to paste object in the specified place.
  //pWnd->GetWindowRect()
 // copyPastePoint = point;// + GetScrollPosition();
 
  CMenu contextMenu;
  
  CRect windRect;
  pWnd->GetWindowRect(&windRect);
  
  CSequenceGeneratorDoc *pDoc = GetDocument();
  
  rightclick_command = getCommandNum(point, GetScrollPosition() - CPoint(windRect.left, windRect.top));
  
  if((rightclick_command == 0) || (rightclick_command > pDoc->getList()->getSize()))
  {
    contextMenu.LoadMenu(IDR_CONTEXT2);
	if(clipboardList.getSize() == 0)
	{
		contextMenu.GetSubMenu(0)->EnableMenuItem(ID_EDIT_PASTE,MF_DISABLED + MF_GRAYED);
	}
    contextMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN, point.x,point.y, this);

  }
  else
  {
    //Load context menu, and track
    contextMenu.LoadMenu(IDR_CONTEXT);
    
	//If the clipboard list is empty (ie. size = 0) disable paste.
	if(clipboardList.getSize() == 0)
	{
		contextMenu.GetSubMenu(0)->EnableMenuItem(ID_EDIT_PASTE,MF_DISABLED + MF_GRAYED);
	}


    //Dynamically load menu options depending on zone
    
    //int *zone = new int[5];
    int zone[] = {0, 0, 0, 0, 0};
    CSequenceGeneratorDoc* pDoc = GetDocument();
    
    
    getZones(point, GetScrollPosition() - CPoint(windRect.left, windRect.top), zone);
    SequenceCommandBaseClass *tempObject;
    
    tempObject = pDoc->getList()->getAt(rightclick_command);
	
	//If the user right-clicks on a box, set the isSelected parameter to true.
	pDoc->getList()->getAt(rightclick_command)->setIsSelected(true);
    

	switch(tempObject->getOpcode())
    {
      //Execute
    case 0:
      {
        switch(zone[1])
        {
        case 1:
          {
            //Move
            contextMenu.GetSubMenu(0)->InsertMenu(6, MF_BYPOSITION | MF_STRING, ID_MOVE_TO_CONTEXT,
              "Move to...");
            break;  
          }
        case 2:
          {
            //Opcode is always a menu item, so skip
            break;
          }
        case 3:
          {
            //Add component menu item
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_EXEC_COMPONENT1_CONTEXT, 
              "Edit Com&ponent");
            break;
          }
        case 4:
          {
            //Add interface menu item
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_EXEC_INTERFACE_CONTEXT, 
              "Edit &Interface");
            break;
          }
        case 5:
          {
            //Add Return Register menu item
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_EXEC_RETREGISTER_CONTEXT, 
              "Edit &Return Register");
            break;
          }
        case 6:
          {
            //data
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_EXEC_DATA_CONTEXT, 
              "Edit &Data");
            break;
          }
        default:
          break;
          
        }
        break;
      }
      //Manipulate
    case 1:
      {
        switch (zone[2])
        {
        case 1:
          {
            //Move
            contextMenu.GetSubMenu(0)->InsertMenu(6, MF_BYPOSITION | MF_STRING, ID_MOVE_TO_CONTEXT,
              "Move to...");
            break;
          }
        case 2:
          {
            //Opcode
            //Opcode is always a menu option
            break;
          }
        case 3:
          {
            //Operation
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_MANIP_OPERATION_CONTEXT, 
              "Edit Manipulate &Operation");
            break;
          }
        case 4:
          {
            //Destination
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_MANIP_DEST_REG_CONTEXT, 
              "Edit Manipulate &Destination Register");
            break;
          }
        case 5:
          {
            //Source
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_MANIP_SOURCE_REG_CONTEXT, 
              "Edit Manipulate &Source Register");
            break;
          }
        }
        
        break;
      }
    case 2:
      {
        switch (zone[3])
        {
        case 1:
          {
            //Move
            contextMenu.GetSubMenu(0)->InsertMenu(6, MF_BYPOSITION | MF_STRING, ID_MOVE_TO_CONTEXT,
              "Move to...");
            break;
          }
        case 2:
          {
            //Opcode
            //Opcode is always an option
            break;
          }
        case 3:
          {
            //Comparison
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_JUMP_COMPARISON_CONTEXT, 
              "Edit &Jump Comparison");
            break;
          }
        case 4:
          {
            //Operand 1
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_JUMP_OPERAND1_CONTEXT, 
              "&Edit Jump &Operand1");
            break;
          }
        case 5:
          {
            //Operand 2
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_JUMP_OPERAND2_CONTEXT, 
              "Edit &Jump Operand2");
            break;
          }
        case 6:
          {
            //Offset Register
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_JUMP_OFFSET_CONTEXT, 
              "Edit Jump &Offset Register");
            break;
          }
        case 7:
          {
            //Offset
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_JUMP_OFFSET_CONTEXT, 
              "Edit Jump &Offset");
            break;
          }
        default:
          break;
        }
        
        break;
      }
    case 3:
      {
        switch (zone[4])
        {
        case 1:
          {
            //Move
            contextMenu.GetSubMenu(0)->InsertMenu(6, MF_BYPOSITION | MF_STRING, ID_MOVE_TO_CONTEXT,
              "Move to...");
            break;
          }
        case 2:
          {
            //Opcode
            //Opcode is always an option
            break;
          }
        case 3:
          {
            //Operation
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_MISC_OPERATION_CONTEXT, 
              "Edit &Misc Operation");
            break;
          }
        case 4:
          {
            //Data
            contextMenu.GetSubMenu(0)->InsertMenu(7, MF_BYPOSITION | MF_STRING, ID_MISC_DATA_CONTEXT, 
              "Edit &Misc Data");
            break;
          }
        default:
          break;
        }
        
        break;
      }
    default:
      {
        
        break;
      }
      
      //contextMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN, point.x,point.y, this);
      
    }
    
    contextMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN, point.x,point.y, this);
  }
}
void CSequenceGeneratorView::OnContextEdit() 
{
  // TODO: Add your command handler code here
  CSequenceGeneratorDoc* pDoc = GetDocument();
  
  CEditCommandDialog editDialog;
  
  SequenceCommandBaseClass *temp = pDoc->getList()->getAt(rightclick_command);
  int oldOpcode = temp->getOpcode();
  
  //set combo
  
  editDialog.setOpcode(oldOpcode);
  //  CEditCommandDialog editDialog;  
  editDialog.DoModal();
  if(editDialog.isOk())
  {
	  int newOpcode = editDialog.getOpcode();
  
	  SequenceCommandBaseClass *newTemp = NULL;
	  switch(newOpcode)
	  {
	  case 0:
		newTemp = new SequenceExecuteClass;
		break;
	  case 1:
		newTemp = new SequenceManipulate;
		break;
	  case 2:
		newTemp = new SequenceJumpClass;
		break;
	  case 3:
		newTemp = new SequenceMiscClass;
		break;
	  default:
		break;
	  }
	  if (newTemp != NULL)
	  {
		newTemp->setOpcode(newOpcode);
		pDoc->getList()->setAt(rightclick_command, newTemp);
	  }
  }
  //temp.setOpcode(newOpcode);
  //pDoc->getList()->setAt(rightclick_command, temp);
  pDoc->UpdateAllViews(NULL);
  
  
}

int CSequenceGeneratorView::getDropLocation(CPoint point)
{
  CSequenceGeneratorDoc* pDoc = GetDocument();
  
  int current_midpoint;
  int previous_midpoint;
  int retVal=0;
  CPoint current_point = point + GetScrollPosition();
  
  for(int i = 1; i <= pDoc->getList()->getSize(); i++)
  {
    current_midpoint = getRectCoordinate(i).CenterPoint().y;
    previous_midpoint = getRectCoordinate(i-1).CenterPoint().y;
    if((previous_midpoint < current_point.y) && (current_midpoint >= current_point.y))
    {
      retVal = i;
    }
  }
  if(current_point.y >= current_midpoint)
  {
    retVal = i;
  }
  if(current_point.y <= getRectCoordinate(0).CenterPoint().y)
  {
    retVal = 1;
  }
  
  return retVal;
}

void CSequenceGeneratorView::OnMove()
{
  //get move to command:
  CSequenceGeneratorDoc *pDoc = GetDocument();
  MoveDialog moveDlg;
  
  int command_to_move = rightclick_command;
  
  int isOk = moveDlg.DoModal();
  
  //move to:
  m_move_to = moveDlg.getMoveTo();
  
  //Move
  if(m_move_to != -1)
  {
    //Move
    //Steps: Get/Save command_to_move object, remove command_To_move object from the list,
    //then insert object to specified location.  If location is < 1, move to position 1, if 
    //location is > size of list, move to the last location.
    SequenceCommandBaseClass *tempObject = pDoc->getList()->getAt(command_to_move);
    int size = pDoc->getList()->getSize();
	if(size > 1)
		pDoc->getList()->removeFrom(command_to_move);
    
    if(m_move_to >= size && size > 1)
    {
      pDoc->getList()->addToTail(tempObject);
    }
    else if(m_move_to < 1 && size > 1)
    {
      pDoc->getList()->addToHead(tempObject);
    }
    else if(size > 1)
    {
      pDoc->getList()->insertAt(m_move_to, tempObject);
    }
  }
  
  m_move_to = -1;
  
  pDoc->UpdateAllViews(NULL);
}

void CSequenceGeneratorView::OnAddToContext() 
{
  //get move to command:
  CSequenceGeneratorDoc *pDoc = GetDocument();
  AddToDialog addToDlg;
  
  addToDlg.DoModal();
  
  //get add to:
  int add_to = addToDlg.getAddTo();
  
  //Move
  if(add_to != -1)
  {
    //Add to consists of inserting a new SequenceCommandBaseClass into a specified location
    SequenceCommandBaseClass *newObject = new SequenceCommandBaseClass;
    
    
    if(add_to > pDoc->getList()->getSize())
    {	
      pDoc->getList()->addToTail(newObject);
    }
    else if(add_to < 1)
    {
      pDoc->getList()->addToHead(newObject);
    }
    else
    {
      pDoc->getList()->insertAt(add_to, newObject);
    }
  }
  pDoc->UpdateAllViews(NULL);
}

void CSequenceGeneratorView::OnDeleteContext() 
{
  CSequenceGeneratorDoc *pDoc = GetDocument();
  
  int response = AfxMessageBox( "Are you sure you want to delete the selected command(s)?", MB_YESNO | MB_APPLMODAL, 0);
  
  if(response == IDYES)
  {
   // pDoc->getList()->removeFrom(rightclick_command);
	  /*int listSize = pDoc->getList()->getSize();
	  for(int i = 1; i <= listSize; i++)
	  {
		  if(pDoc->getList()->getAt(i)->getIsSelected())
		  {
			  if(i == 1)
				  pDoc->getList()->removeFromHead();
			  else if (i == listSize)
				  pDoc->getList()->removeFromTail();
			  else
				  pDoc->getList()->removeFrom(i);
		  }
	  }*/
	int listSize = pDoc->getList()->getSize();
	for(int i = 1; i <= pDoc->getList()->getSize(); i++)
	{
		if(pDoc->getList()->getAt(i)->getIsSelected())
		{
			pDoc->getList()->getAt(i)->setIsSelected(false);

			if(pDoc->getList()->getSize() == 1)
			{
				
				pDoc->getList()->removeFromHead();
				i--;
			}
			else if (i == listSize)
			{
				pDoc->getList()->removeFromTail();
				i--;
			}
			else
			{
				pDoc->getList()->removeFrom(i);
				i--;
			}

		}
	}
	pDoc->UpdateAllViews(NULL);
  }
  
  pDoc->UpdateAllViews(NULL);
  
}

void CSequenceGeneratorView::OnViewSymbolic() 
{
  m_symbolic = !m_symbolic;
}

void CSequenceGeneratorView::OnUpdateViewSymbolic(CCmdUI* pCmdUI) 
{
  //Enable the menu item
  pCmdUI->Enable(TRUE);
  
  //Set the current symbolic state
  pCmdUI->SetCheck(m_symbolic?1:0);
}

// Execute:Component dialog
void CSequenceGeneratorView::OnReturnRegister()
{
  
  SelectRRegisterExecDialog returnRegisterDlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceExecuteClass *tempObject = (SequenceExecuteClass *)pDoc->getList()->getAt(rightclick_command);
  
  int oldReturnRegister = tempObject->getReturnRegister();
  if(oldReturnRegister >= 0 && oldReturnRegister <= 15)
    returnRegisterDlg.setReturnRegister(oldReturnRegister);
  
  returnRegisterDlg.DoModal();
  int newReturnRegister = returnRegisterDlg.getReturnRegister();
  if(newReturnRegister >= 0 && newReturnRegister <= 15)
  {
    tempObject->setReturnRegister(newReturnRegister);
    pDoc->getList()->setAt(rightclick_command, tempObject);
  }
  pDoc->UpdateAllViews(NULL);
}

// Execute:Component dialog
void CSequenceGeneratorView::OnComponentDialog()
{
  ComponentExecDialog componentDlg;
  CSequenceGeneratorDoc* pDoc = GetDocument();
  
  SequenceExecuteClass *temp = (SequenceExecuteClass *) pDoc->getList()->getAt(rightclick_command);
  int oldComponent = temp->getComponent();
  
  //set combo
  if(oldComponent >= 0 && oldComponent <= 31)
  {
    componentDlg.setComponent(oldComponent);
    temp->setInterface(-1);
  }
  else
    componentDlg.setComponent(-1);
  
  componentDlg.DoModal();
  
  int newComponent = componentDlg.getComponent();
  if(newComponent >= 0 && newComponent <= 31)
  {
    temp->setComponent(newComponent);
    pDoc->getList()->setAt(rightclick_command, (SequenceCommandBaseClass *) temp);
  }
  pDoc->UpdateAllViews(NULL);
}

// Execute:Interface dialog
void CSequenceGeneratorView::OnInterfaceDialog()
{
  InterfaceExecDialog interfaceDlg;
  CSequenceGeneratorDoc* pDoc = GetDocument();
  SequenceExecuteClass *tempObject = (SequenceExecuteClass *) pDoc->getList()->getAt(rightclick_command);
  int oldInterface = tempObject->getInterface();
  int oldComponent = tempObject->getComponent();
  
  if(oldComponent >= 0 && oldComponent <=31)
  {
    interfaceDlg.setComponent(oldComponent);
    
    if(oldInterface >= 0 && oldInterface <= 7)
    {
      interfaceDlg.setInterface(oldInterface);
      
    }
    
    interfaceDlg.DoModal();
    int newInterface = interfaceDlg.getInterface();
    
    if(newInterface >= 0 && newInterface <= 7)
    {
      tempObject->setInterface(newInterface);
      pDoc->getList()->setAt(rightclick_command, (SequenceCommandBaseClass *)tempObject);
    }
    
  }
  pDoc->UpdateAllViews(NULL);
}

// Data Dialog
void CSequenceGeneratorView::OnDestinationRegister()
{
  DataStorageDialog dataDlg;
  
  CSequenceGeneratorDoc* pDoc = GetDocument();
  SequenceExecuteClass *tempObject = (SequenceExecuteClass *) pDoc->getList()->getAt(rightclick_command);
  
  
  
  if(tempObject->getImmediate())
  {
    dataDlg.setIsImmediate(true);
    
    int immd_arg = tempObject->getArguement();
    //if( immd_arg != -1)
    //{
    CString temp;
    temp.Format("%d", immd_arg);
    dataDlg.setImmediateData(temp);
    //  }
    
  }
  else
  {
    
    dataDlg.setIsImmediate(false);
    
    RegisterType oldArg1 = tempObject->getArg1();
    RegisterType oldArg2 = tempObject->getArg2();
    RegisterType oldArg3 = tempObject->getArg3();
    RegisterType oldArg4 = tempObject->getArg4();
    
    //Error checking done on dialog side.
    
    dataDlg.setArg1(oldArg1);
    dataDlg.setArg2(oldArg2);
    dataDlg.setArg3(oldArg3);
    dataDlg.setArg4(oldArg4);
    
  }
  
  dataDlg.DoModal();
  
  if(dataDlg.isOk())
  {
    if(dataDlg.getIsImmediate())
    {
      //Set tempObject arguement to integer
      tempObject->setImmediate(true);
      
      CString immediateData = dataDlg.getImmediateData();

	  
	  //Support Hex Feature
	  //Eliminate space if necessary
	  /*for(int i = 0; i < immediateData.GetLength(); i++)
	  {
		  if(immediateData[i] == ' ')
			immediateData.Delete(i,1);
	  }

	  int immd_data = 0;
	  //Check is number is a hex.  If so, store hex value
	  if(immediateData[0] == '0')
	  {
		  if(immediateData[1] == 'x' || immediateData[1] == 'X')
		  {
			  immediateData.Delete(0,2);
			  immd_data = sscanf(LPCTSTR(immediateData),"%x");
		  }
	  }
	  else
	  {*/

		int immd_data;
      
		//Convert CString to integer
		immd_data = atoi(LPCTSTR(immediateData));
	  //}
      
      
      tempObject->setArguement(immd_data);
      pDoc->getList()->setAt(rightclick_command, tempObject);
      
    }
    else
    {
      tempObject->SetArg1(dataDlg.getArg1());
      tempObject->SetArg2(dataDlg.getArg2());
      tempObject->SetArg3(dataDlg.getArg3());
      tempObject->SetArg4(dataDlg.getArg4());
      tempObject->setImmediate(false);
      
      pDoc->getList()->setAt(rightclick_command,  tempObject);
    }
  }
  
  pDoc->UpdateAllViews(NULL);
}

/***************************Manipulate Dialogs********************************/
// Manipulate:Operation dialog
void CSequenceGeneratorView::OnOperationManip()
{
  
  OperationManipDialog operationDlg;
  CSequenceGeneratorDoc* pDoc = GetDocument();
  SequenceManipulate *tempObject = (SequenceManipulate *) pDoc->getList()->getAt(rightclick_command);
  
  int oldOperation = tempObject->getOperation();
  
  operationDlg.setOperation(oldOperation);
  
  operationDlg.DoModal();
  
  int newOperation = operationDlg.getOperation();
  
  if(newOperation >= 0 && newOperation <=6)
  {
    tempObject->setOperation(newOperation);
    pDoc->getList()->setAt(rightclick_command, (SequenceCommandBaseClass *) tempObject);
  }
  
  pDoc->UpdateAllViews(NULL);
}

// Manipulate:Destination dialog
void CSequenceGeneratorView::OnManipDestinationData()
{
  SelectDataDialog dRegDlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceManipulate * tempObject = (SequenceManipulate *) pDoc->getList()->getAt(rightclick_command);
  
  //Further error checking in the SelectDataDialog class will set dialog parameters.
  RegisterType oldDReg = tempObject->getDestinationRegister();
  
  
  dRegDlg.setDataSource(oldDReg);
  
  
  dRegDlg.DoModal();
  
  RegisterType newData = dRegDlg.getDataSource();
  
  if(newData.num >= 0 && newData.num <= 31)
  {
    tempObject->setDestinationRegister(newData);
    pDoc->getList()->setAt(rightclick_command, tempObject);
  }
  
  pDoc->UpdateAllViews(NULL);
  
}

// Manipulate:Source dialog
void CSequenceGeneratorView::OnManipSourceData()
{
  DataStorageDialog sourceDataDlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceManipulate * tempObject = (SequenceManipulate *) pDoc->getList()->getAt(rightclick_command);
  
  if(tempObject->getImmediate())
  {
    sourceDataDlg.setIsImmediate(true);
    int oldImmediateData = tempObject->getArguement();
    CString tempstr;
    tempstr.Format("%d", oldImmediateData);
    sourceDataDlg.setImmediateData(tempstr);
  }
  else
  {
    sourceDataDlg.setIsImmediate(false);
    //Error-checking done on dialog side.
    RegisterType oldSourceData = tempObject->getSourceRegister();
    sourceDataDlg.setArg1(oldSourceData);
  }
  
  //It is also recommended to disable dlg buttons 2,3,4; since manipulate only takes in 1 register
  //parameter
  sourceDataDlg.DoModal();
  
  RegisterType newSourceData = sourceDataDlg.getArg1();
  
  if(sourceDataDlg.isOk())
  {
    if(sourceDataDlg.getIsImmediate())
    {
      tempObject->setImmediate(true);
      
      CString immediateData = sourceDataDlg.getImmediateData();
      int immd_data;
      
      //Convert CString to integer
      immd_data = atoi(LPCTSTR(immediateData));
      
      tempObject->setArguement(immd_data);
      pDoc->getList()->setAt(rightclick_command, tempObject);
    }
    else
    {
      tempObject->setImmediate(false);
      //if(newSourceData.num >= 0 && newSourceData.num <= 31)
      //{
      tempObject->setSourceRegister(newSourceData);
      pDoc->getList()->setAt(rightclick_command, tempObject);
      //  }
    }
  }
  
  pDoc->UpdateAllViews(NULL);
  
}


/*****************************Jump Dialogs*************************************/
// Jump:Comparison dialog
void CSequenceGeneratorView::OnJumpComparison()
{
  JumpComparisonDialog comparisonDlg;
  
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceJumpClass *tempObject = (SequenceJumpClass *) pDoc->getList()->getAt(rightclick_command);
  
  int oldComparison = tempObject->getComparison();
  
  if(oldComparison >= 0 && oldComparison <= 6)
    comparisonDlg.setComparison(oldComparison);
  
  comparisonDlg.DoModal();
  
  int newComparison = comparisonDlg.getComparison();
  
  if(newComparison >= 0 && newComparison <= 6)
  {
    tempObject->setComparison(newComparison);
    pDoc->getList()->setAt(rightclick_command,  tempObject);
  }
  
  pDoc->UpdateAllViews(NULL);
  
}

// Jump:Operand1 dialog
void CSequenceGeneratorView::OnJumpOperand1()
{
  SelectDataDialog operand1Dlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceJumpClass * tempObject = (SequenceJumpClass *) pDoc->getList()->getAt(rightclick_command);
  
  RegisterType oldOperand1 = tempObject->getOperand1();
  
  //Error-checking should be done on dialog side
  operand1Dlg.setDataSource(oldOperand1);
  
  
  operand1Dlg.DoModal();
  
  RegisterType newOperand1 = operand1Dlg.getDataSource();
  
  if(newOperand1.num >= 0 && newOperand1.num <= 31)
  {
    tempObject->setOperand1(newOperand1);
    pDoc->getList()->setAt(rightclick_command, tempObject);
  }
  
  pDoc->UpdateAllViews(NULL);
}

// Jump:Operand2 dialog
void CSequenceGeneratorView::OnJumpOperand2()
{
  DataStorageDialog operand2Dlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceJumpClass * tempObject = (SequenceJumpClass *) pDoc->getList()->getAt(rightclick_command);
  
  //Error-checking occurs on dialog side.
  if(tempObject->getImmediate())
  {
    operand2Dlg.setIsImmediate(true);
    
    int oldImmdOperand2 = tempObject->getImmediateOperand2();
    
    CString tempstr;
    tempstr.Format("%d", oldImmdOperand2);
    operand2Dlg.setImmediateData(tempstr);    
    
  }
  else
  {
    operand2Dlg.setIsImmediate(false);
    RegisterType oldNonImmdOperand2 = tempObject->getNonImmdOperand2();
    operand2Dlg.setArg1(oldNonImmdOperand2);
  }
  
  operand2Dlg.DoModal();
  
  if(operand2Dlg.isOk())
  {
    if(operand2Dlg.getIsImmediate())
    {
      tempObject->setImmediate(true);
      
      CString operand2Data = operand2Dlg.getImmediateData();
      int operand2_data;
      
      //Convert CString to integer
      operand2_data = atoi(LPCTSTR(operand2Data));
      
      
      tempObject->setImmediateOperand2(operand2_data);
      pDoc->getList()->setAt(rightclick_command, tempObject);
      
    }
    else
    {
      tempObject->setImmediate(false);
      int arg1Num = operand2Dlg.getArg1().num;
      //  if(arg1Num >= 0 && arg1Num <= 31)
      //  {
      tempObject->setNonImmdOperand2(operand2Dlg.getArg1());
      pDoc->getList()->setAt(rightclick_command, tempObject);
      //  }
    }
  }
  pDoc->UpdateAllViews(NULL);
}


// Obselete
void CSequenceGeneratorView::OnJumpOffset()
{
  JumpOffsetDialog offsetDlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceJumpClass * tempObject = (SequenceJumpClass *) pDoc->getList()->getAt(rightclick_command);
  
  int oldOffset = tempObject->getOffset();
  
  //Convert integer offset to CString offset and send to dialog.
  CString oldOffsetString;
  oldOffsetString.Format("%d", oldOffset);
  
  offsetDlg.setJumpOffset(oldOffsetString);
  
  offsetDlg.DoModal();
  
  CString newOffsetString = offsetDlg.getJumpOffset();
  
  //Convert CString offset to integer and store in tempObject
  int newOffsetInt = atoi(LPCTSTR(newOffsetString));
  
  tempObject->setOffset(newOffsetInt);
  
  pDoc->getList()->setAt(rightclick_command, tempObject);
  
  pDoc->UpdateAllViews(NULL);
  
}

// Obselete
void CSequenceGeneratorView::OnJumpOffsetRegister()
{
  SelectDataDialog offsetRegDlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceJumpClass *tempObject = (SequenceJumpClass *) pDoc->getList()->getAt(rightclick_command);
  
  RegisterType oldOffsetReg = tempObject->getDOffsetRegister();
  offsetRegDlg.setDataSource(oldOffsetReg);
  
  
  offsetRegDlg.DoModal();
  
  RegisterType newOffsetReg = offsetRegDlg.getDataSource();
  
  if(newOffsetReg.num >= 0 && newOffsetReg.num <= 31)
  {
    tempObject->setDOffsetRegister(newOffsetReg);
    pDoc->getList()->setAt(rightclick_command, tempObject);
  }
  
  pDoc->UpdateAllViews(NULL);
}

// Edit label/comments dialog
void CSequenceGeneratorView::OnLabelCommentContext() 
{
  LabelCommentDialog label_commentDlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceCommandBaseClass *tempObject = pDoc->getList()->getAt(rightclick_command);
  
  label_commentDlg.setComment(tempObject->getComment());
  label_commentDlg.setLabel(tempObject->getLabel());
  
  label_commentDlg.DoModal();
  
  tempObject->setComment(label_commentDlg.getComment());
  tempObject->setLabel(label_commentDlg.getLabel());
  
  pDoc->getList()->setAt(rightclick_command, tempObject);
  pDoc->UpdateAllViews(NULL);
}

// Jump:Offsets dialog
void CSequenceGeneratorView::OnJump2Offset()
{
  Jump2OffsetDialog jump2Dlg; 
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceJumpClass *tempObject = (SequenceJumpClass *)pDoc->getList()->getAt(rightclick_command);
  
  jump2Dlg.setOffsetReg(tempObject->getDOffsetRegister());
  CString offsetString;
  offsetString.Format("%d", tempObject->getOffset());
  jump2Dlg.setOffset(offsetString);
  
  jump2Dlg.DoModal();
  
  if(jump2Dlg.isOk())
  {
    RegisterType tempDOffsetReg = jump2Dlg.getOffsetReg();
    
    tempObject->setDOffsetRegister(tempDOffsetReg);
    
    int offset = atoi(jump2Dlg.getOffset());
    
    tempObject->setOffset(offset);
    
    
    pDoc->getList()->setAt(rightclick_command, tempObject);
  }
  
  pDoc->UpdateAllViews(NULL);
}


/*****************************Misc Dialogs*************************************/
// Misc:Operation dialog
void CSequenceGeneratorView::OnMiscOperation()
{
  MiscOperationDialog miscOperationDlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceMiscClass *tempObject = (SequenceMiscClass *) pDoc->getList()->getAt(rightclick_command);
  
  int oldOperation = tempObject->getOperation();
  
  //Error checking done on dialog side
  //if(oldOperation == 0)
  miscOperationDlg.setMiscOperation(oldOperation);
  
  miscOperationDlg.DoModal();
  
  int newOperation = miscOperationDlg.getMiscOperation();
  
  //only supports delay and call right now.
  if(newOperation >= 0 && newOperation <= 2)
  {
    tempObject->setOperation(newOperation);
    pDoc->getList()->setAt(rightclick_command,  tempObject);
  }
  
  pDoc->UpdateAllViews(NULL);
}

// Misc:Data dialog
void CSequenceGeneratorView::OnMiscData()
{
  DataStorageDialog miscDataDlg;
  CSequenceGeneratorDoc *pDoc = GetDocument();
  SequenceMiscClass *tempObject = (SequenceMiscClass *)pDoc->getList()->getAt(rightclick_command);
  
  if(tempObject->getImmediate())
  {
    miscDataDlg.setIsImmediate(true);
    
    int oldMiscData = tempObject->getSourceData();
    
    CString oldMisDataString;
    oldMisDataString.Format("%d", oldMiscData);
    miscDataDlg.setImmediateData(oldMisDataString); 
  }
  else
  {
    miscDataDlg.setIsImmediate(false);
    RegisterType arg1 = tempObject->getSourceRegister();
    miscDataDlg.setArg1(arg1);
    
  }
  
  miscDataDlg.DoModal();
  
  if(miscDataDlg.isOk())
  {
    if(miscDataDlg.getIsImmediate())
    {
      tempObject->setImmediate(true);
      CString newMiscDataString = miscDataDlg.getImmediateData();
      
      int newMiscDataInt;
      
      //Convert CString to integer
      newMiscDataInt = atoi(LPCTSTR(newMiscDataString));
      
      tempObject->setSourceData(newMiscDataInt);
      pDoc->getList()->setAt(rightclick_command, tempObject); 
    }
    else
    {
      tempObject->setImmediate(false);
      
      RegisterType newArg = miscDataDlg.getArg1();
      
      if(newArg.num >= 0 && newArg.num <= 31)
      {
        tempObject->setSourceRegister(newArg);
        pDoc->getList()->setAt(rightclick_command, tempObject);
      }
      
    }
    
  }
  pDoc->UpdateAllViews(NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CSequenceGeneratorView helper functions
/////////////////////////////////////////////////////////////////////////////

//This member function calculate the ofset of a given block/command number
CRect CSequenceGeneratorView::getRectCoordinate(int command_num)
{
  CRect temp = start_crec;
  temp.OffsetRect(0,(commandRectSpacing + commandRectHeight) * command_num);
  return temp;
}

//This member function returns the box/block relative to a given point.
//Depending on the scroll position, an offset is also required.
int CSequenceGeneratorView::getCommandNum(CPoint point, CPoint offset)
{
  CPoint tempPoint; 
  tempPoint.x = point.x + offset.x;
  tempPoint.y = point.y + offset.y;
  CSequenceGeneratorDoc* pDoc = GetDocument();
  CRect temp = getRectCoordinate(0);
  int retVal = 0;
  if(temp.left <= tempPoint.x && temp.right >= tempPoint.x)
  {
    for(int i = 0; i < pDoc->getNumOfCommands(); i++)
    {
      temp = getRectCoordinate(i + 1);
      if(temp.top <= tempPoint.y && temp.bottom >= tempPoint.y)
      {
        retVal = i + 1;
        break;
      }
    }
  }
  
  return retVal; 
}

//This member function calculates all of the possible zone numbers returns the data
//via 5 element integer array passed in
void CSequenceGeneratorView::getZones(CPoint point, CPoint offset, int *outputArray)
{
  // Array position 0 = box number
  // Array position 1 = zone number if execute command
  // Array position 2 = zone number if manipulate command
  // Array position 3 = zone number if jump command
  // Array position 4 = zone number if misc command
  
  // Loop variable
  int i;
  
  // Offset mouse point with scroll/window point
  CPoint p = point + offset;
  
  // set array position 0 to box number (used for offseting zones)
  outputArray[0] = getCommandNum(point, offset);
  
  // init all other array entries to dummy values
  for (i = 1; i < 5; i++)
  {
    outputArray[i] = 0;
  }
  
  if (outputArray[0] > 0)
  {
    for (i = 0; i < 7; i++)
    {
      // check if point in rectangle created by zone define + current box coordinate offset
      if ((exeZones[i] + CPoint(getRectCoordinate(outputArray[0]).left, getRectCoordinate(outputArray[0]).top)).PtInRect(p))
      {
        outputArray[1] = i+1;
      }
      if ((manZones[i] + CPoint(getRectCoordinate(outputArray[0]).left, getRectCoordinate(outputArray[0]).top)).PtInRect(p))
      {
        outputArray[2] = i+1;
      }
      if ((jmp1Zones[i] + CPoint(getRectCoordinate(outputArray[0]).left, getRectCoordinate(outputArray[0]).top)).PtInRect(p))  // change to jmp2 when arrow ready
      {
        outputArray[3] = i+1;
      }
      if ((miscZones[i] + CPoint(getRectCoordinate(outputArray[0]).left, getRectCoordinate(outputArray[0]).top)).PtInRect(p))
      {
        outputArray[4] = i+1;
      }
    }
  }
}

CPoint CSequenceGeneratorView::getPrintCoordinates(int opcode, int zone, int commandNum)
{
  return getPrintBox(opcode, zone, commandNum).CenterPoint();
}

CRect CSequenceGeneratorView::getPrintBox(int opcode, int zone, int commandNum)
{
  return (allZones[opcode][zone] + getRectCoordinate(commandNum).TopLeft()) + CPoint(0,6);
}

void CSequenceGeneratorView::printHelper(CDC* pDC, CString printText, CString unknownText, CRect printBox)
{
  // Create new font incase text does not fit
  CFont newFont;
  int pointSize = 140;
  newFont.CreatePointFont(pointSize, "Arial", pDC);
  // Get pointer to default font
  CFont* pOldFont = pDC->SelectObject(&newFont);
  // Make sure default font is selected
  pDC->SelectObject(pOldFont);
  
  if(printText != CSequenceGeneratorDoc::nullString)
  {
    while (printBox.Width() < pDC->GetTextExtent(printText).cx)
    {
      //decrease size
      newFont.DeleteObject();
      newFont.CreatePointFont(pointSize, "Arial", pDC);
      pDC->SelectObject(&newFont);
      pointSize -= 5;
    }
    pDC->TextOut(printBox.CenterPoint().x, printBox.CenterPoint().y, printText);
  }
  else
  {
    pDC->SetTextColor(redColor);
    while (printBox.Width() < pDC->GetTextExtent(unknownText).cx)
    {
      //decrease size
      newFont.DeleteObject();
      newFont.CreatePointFont(pointSize, "Arial", pDC);
      pDC->SelectObject(&newFont);
      pointSize -= 5;
    }
    pDC->TextOut(printBox.CenterPoint().x, printBox.CenterPoint().y, unknownText);
    pDC->SetTextColor(blackColor);
  }
  
  pDC->SelectObject(pOldFont);
}

void CSequenceGeneratorView::printExecuteText(CDC* pDC, SequenceExecuteClass *exeCommand, int sequenceNumber)
{
  //CPoint coordinates for Execute zones
  CPoint opcodePoint = getPrintCoordinates(0, 1, sequenceNumber);
  CRect compRect = getPrintBox(0, 2, sequenceNumber);
  CRect intRect = getPrintBox(0, 3, sequenceNumber);
  CRect retRect = getPrintBox(0, 4, sequenceNumber);
  CRect dataRect = getPrintBox(0, 5, sequenceNumber);
  
  //Print Opcode Name
  pDC->TextOut(opcodePoint.x, opcodePoint.y, exeCommand->getOpcodeName());
  
  // Print component
  printHelper(pDC, (m_symbolic?CSequenceGeneratorDoc::getCompInterface(exeCommand->getComponent(),-1):
  CString(itoa(exeCommand->getComponent(), new char[2], 10))), "COMPONENT?", compRect);
  
  //Print Interface
  if (CSequenceGeneratorDoc::getCompInterface(exeCommand->getComponent(),-1) != CSequenceGeneratorDoc::nullString)
  {
    printHelper(pDC, (m_symbolic?(((exeCommand->getInterface() >= 0) && 
      (exeCommand->getInterface() < 8))?CSequenceGeneratorDoc::getCompInterface(exeCommand->getComponent(),exeCommand->getInterface()):
    CSequenceGeneratorDoc::nullString):
    CString(itoa(exeCommand->getInterface(), new char[2], 10))), "INTERFACE?", intRect);
  }
  
  // Check for valid return register
  printHelper(pDC, exeCommand->getReturnRegisterString(), "RETURN REGISTER?", retRect);
  
  //Print Data
  printHelper(pDC, exeCommand->getDataString(), "DATA?", dataRect);
}

void CSequenceGeneratorView::printManipulateText(CDC* pDC, SequenceManipulate *manipCommand, int sequenceNumber)
{
  //CPoint coordinates for Manipulate zones
  CPoint opcodePoint = getPrintCoordinates(1, 1, sequenceNumber);
  CRect operationRect = getPrintBox(1, 2, sequenceNumber);
  CRect destRegRect = getPrintBox(1, 3, sequenceNumber);
  CRect sourceRegRect = getPrintBox(1, 4, sequenceNumber);
  
  //Print Opcode Name
  pDC->TextOut(opcodePoint.x, opcodePoint.y, manipCommand->getOpcodeName());
  
  //Print operation text
  printHelper(pDC, manipCommand->getOperationString(), "OPERATION?", operationRect);
  
  //Print destination text
  printHelper(pDC, manipCommand->getDestinationString(), "DEST REG?", destRegRect);
  
  //Check if operation is NOT
  if (manipCommand->getOperation() != 6)
  {
    //Print source data
    printHelper(pDC, manipCommand->getSourceString(), "SRC REG?", sourceRegRect);
  }
}

void CSequenceGeneratorView::printJumpText(CDC* pDC, SequenceJumpClass *jumpCommand, int sequenceNumber)
{
  //CPoint coordinates for Print zones
  CPoint opcodePoint = getPrintCoordinates(2, 1, sequenceNumber);
  CRect comparisonRect = getPrintBox(2, 2, sequenceNumber);
  CRect operand1Rect = getPrintBox(2, 3, sequenceNumber);
  CRect operand2Rect = getPrintBox(2, 4, sequenceNumber);
  CRect offsetRegRect = getPrintBox(2, 5, sequenceNumber);
  CRect offsetRect = getPrintBox(2, 6, sequenceNumber);
  
  //Print Opcode Name
  pDC->TextOut(opcodePoint.x, opcodePoint.y, jumpCommand->getOpcodeName());
  
  //Print comparison text
  printHelper(pDC, jumpCommand->getComparisonString(), "COMPARISON?", comparisonRect);
  
  //Print operand text only if comparison other than always
  if (jumpCommand->getComparison() != 0)
  {
    //Print operand1 text
    printHelper(pDC, jumpCommand->getOperand1String(), "OPERAND 1?", operand1Rect);
  
    //Print operand2 text
    printHelper(pDC, jumpCommand->getOperand2String(), "OPERAND 2?", operand2Rect);
  }

  //Print offset text
  printHelper(pDC, jumpCommand->getOffsetString(), "OFFSET?", offsetRegRect);
  
  //Print offset register text
  printHelper(pDC, jumpCommand->getOffsetRegisterString(), "", offsetRect);
}

int CSequenceGeneratorView::drawJumpArrow(CDC* pDC, SequenceJumpClass *jumpCommand, int sequenceNumber, int numArrows)
{
  int retData = numArrows; //num of arrows
  
  if(jumpCommand->getOffsetRegisterString() == CSequenceGeneratorDoc::nullString)
  {
    retData++;
    CPen *defLine = pDC->GetCurrentPen();     // Save current pen
    CPen lineBr(PS_SOLID, 5, redColor);  
    CRect jumpRect = getRectCoordinate(sequenceNumber);
    CPoint tempArrowPoint = jumpRect.BottomRight() + CPoint(retData*arrowOffset ,-1);
    
    // Set pen color to red
    pDC->SelectObject(&lineBr);
    
    // Draw line from lower right corner of command box to the right
    pDC->MoveTo(jumpRect.BottomRight() + CPoint(-1, -1));
    pDC->LineTo(tempArrowPoint);
    // Draw vertical line to horizontal center coordinate of destination
    tempArrowPoint.y = getRectCoordinate(sequenceNumber + 1 + jumpCommand->getOffset()).CenterPoint().y;
    pDC->LineTo(tempArrowPoint);
    // Draw horizontal line to destination box
    tempArrowPoint.x -= retData*arrowOffset;
    pDC->LineTo(tempArrowPoint);
    // Draw arrow head
    pDC->LineTo(tempArrowPoint + CPoint(7,-7));
    pDC->MoveTo(tempArrowPoint);
    pDC->LineTo(tempArrowPoint + CPoint(7,7));
    
    // Restore previous pen color
    pDC->SelectObject(defLine);
  }
  
  return retData;
}

void CSequenceGeneratorView::printMiscText(CDC* pDC, SequenceMiscClass *miscCommand, int sequenceNumber)
{
  //CPoint coordinates for Execute zones
  CPoint opcodePoint = getPrintCoordinates(3, 1, sequenceNumber);
  CRect operationRect = getPrintBox(3, 2, sequenceNumber);
  CRect dataRect = getPrintBox(3, 3, sequenceNumber);
  
  //Print Opcode Name
  pDC->TextOut(opcodePoint.x, opcodePoint.y, miscCommand->getOpcodeName());
  
  //Print operation text
  printHelper(pDC, miscCommand->getOperationString(), "OPERATION?", operationRect);
  
  //Check if END is operation
  if (miscCommand->getOperation() != 2)
  {
    //Print operand1 text
    printHelper(pDC, miscCommand->getArgString(), "DATA?", dataRect);
  }
}

void CSequenceGeneratorView::OnCompintContext() 
{
	// TODO: Add your command handler code here
	EnterComponentDialog componentDlg;
	componentDlg.DoModal();
}

void CSequenceGeneratorView::OnEditEditaddcomponent() 
{
	// TODO: Add your command handler code here
	EnterComponentDialog componentDlg;
	componentDlg.DoModal();
}

void CSequenceGeneratorView::OnHelpOption() 
{
	// TODO: Add your command handler code here
	CSequenceGeneratorDoc *pDoc = GetDocument();
	helpFlag = 1;

	//CString tempstr;
	//tempstr.Format("%d", helpFlag);
	//AfxMessageBox(tempstr);
	pDoc->UpdateAllViews(NULL);
}

void CSequenceGeneratorView::OnExtendedhelpContext() 
{
	// TODO: Add your command handler code here
	extendedHlpDlg = new ExtendedHelpDialog(this);
}

void CSequenceGeneratorView::OnEditCopy() 
{
	// TODO: Add your command handler code here
	CSequenceGeneratorDoc *pDoc = GetDocument();

	int i = 1;
	//Remove previous objects in the list before placing new items
	//in the list

	clipboardList.~SequencerList();
	/*int clipboardSize = clipboardList.getSize();
	for(i = 1; i <= clipboardSize; i++)
	{
		clipboardList.removeFromTail();
	}*/


	//Place new objects to be copied the clipboard list
	int listSize = pDoc->getList()->getSize();
	SequenceCommandBaseClass *tempObject;
	int temp_opcode = -1;
	for(i = 1; i <= listSize; i++)
	{
		temp_opcode = pDoc->getList()->getAt(i)->getOpcode();
		
		switch (temp_opcode)
		{
		case 0:
			tempObject = new SequenceExecuteClass( *((SequenceExecuteClass *)pDoc->getList()->getAt(i)));
			break;
		case 1:
			tempObject = new SequenceManipulate( *((SequenceManipulate *)pDoc->getList()->getAt(i)));
			break;
		case 2:
			tempObject = new SequenceJumpClass( *((SequenceJumpClass *)pDoc->getList()->getAt(i)));
			break;
		case 3:
			tempObject = new SequenceMiscClass( *((SequenceMiscClass *)pDoc->getList()->getAt(i)));
			break;
		default:
			tempObject = new SequenceCommandBaseClass( *(pDoc->getList()->getAt(i)));
			break;
		}
		
		if(tempObject->getIsSelected() /*pDoc->getList()->getAt(i)->getIsSelected()*/)
		{
	
			tempObject->setIsSelected(false);
			if(clipboardList.getSize() == 0)
				//clipboardList.addToHead((SequenceCommandBaseClass *)pDoc->getList()->getAt(i));
				clipboardList.addToHead(tempObject);
			else
				//clipboardList.addToTail((SequenceCommandBaseClass *)pDoc->getList()->getAt(i));
				clipboardList.addToTail(tempObject);
			
			//pDoc->getList()->getAt(i)->setIsSelected(false);
			//tempObject->setIsSelected(false);
			pDoc->getList()->getAt(i)->setIsSelected(false);
		}

		//Instead of deleting these objects at this point, these objects will be deleted when 
		//the clipboardList destructor function is called.
		//delete tempObject;
		//tempObject = NULL;
	
	}
}

void CSequenceGeneratorView::OnEditCut() 
{
	// TODO: Add your command handler code here
	
	//Similar to copy except it is required that the selected objects
	//should be removed from list.

	CSequenceGeneratorDoc *pDoc = GetDocument();

	int i = 1;
	//Remove previous objects in the list before placing new items
	//in the list

	int clipboardSize = clipboardList.getSize();
/*	for(i = 1; i <= clipboardSize; i++)
	{
		clipboardList.removeFromTail();
	}*/
	clipboardList.~SequencerList();

	int listSize = pDoc->getList()->getSize();
	int temp_opcode = -1;
	SequenceCommandBaseClass *tempObject;
	for(i = 1; i <= listSize; i++)
	{
		temp_opcode = pDoc->getList()->getAt(i)->getOpcode();
		
		switch (temp_opcode)
		{
		case 0:
			tempObject = new SequenceExecuteClass( *((SequenceExecuteClass *)pDoc->getList()->getAt(i)));
			break;
		case 1:
			tempObject = new SequenceManipulate( *((SequenceManipulate *)pDoc->getList()->getAt(i)));
			break;
		case 2:
			tempObject = new SequenceJumpClass( *((SequenceJumpClass *)pDoc->getList()->getAt(i)));
			break;
		case 3:
			tempObject = new SequenceMiscClass( *((SequenceMiscClass *)pDoc->getList()->getAt(i)));
			break;
		default:
			tempObject = new SequenceCommandBaseClass( *(pDoc->getList()->getAt(i)));
			break;
		}

		if(tempObject->getIsSelected())
		{
			tempObject->setIsSelected(false);
			if(clipboardList.getSize() == 0)
			{
				
				clipboardList.addToHead(tempObject);
			}
			else
			{
				clipboardList.addToTail(tempObject);
			}

			//pDoc->getList()->getAt(i)->setIsSelected(false);


		
		}

		//Instead of deleting these objects at this point, these objects will be deleted when 
		//the clipboardList destructor function is called.
		//delete tempObject;
		//tempObject = NULL;
		
	}

	for(i = 1; i <= pDoc->getList()->getSize(); i++)
	{
		if(pDoc->getList()->getAt(i)->getIsSelected())
		{
			pDoc->getList()->getAt(i)->setIsSelected(false);

			if(pDoc->getList()->getSize() == 1)
			{
				
				pDoc->getList()->removeFromHead();
				i--;
			}
			else if (i == listSize)
			{
				pDoc->getList()->removeFromTail();
				i--;
			}
			else
			{
				pDoc->getList()->removeFrom(i);
				i--;
			}

		}
	}
	pDoc->UpdateAllViews(NULL);
}

void CSequenceGeneratorView::OnEditPaste() 
{
	// TODO: Add your command handler code here
	CSequenceGeneratorDoc *pDoc = GetDocument();
	//int drop_location = getDropLocation(copyPastePoint);
	int drop_location = getPasteLocation(copyPastePoint);
	int clipboardSize = clipboardList.getSize();
	for(int i = 1; i <= clipboardSize; i++)
	{
		if(pDoc->getList()->getSize() == 0 || drop_location == 0)
		{	
			pDoc->getList()->addToHead((SequenceCommandBaseClass *)clipboardList.getAt(i));
			drop_location++;

		}
		else if(drop_location > pDoc->getList()->getSize())
		{
			pDoc->getList()->addToTail((SequenceCommandBaseClass *)clipboardList.getAt(i));
			drop_location++;

		}
		else
		{
			pDoc->getList()->insertAt(drop_location, (SequenceCommandBaseClass *)clipboardList.getAt(i));
			drop_location++;
		}
	}
	pDoc->UpdateAllViews(NULL);
//	AfxMessageBox("Pasting implementation is implemented here.");
	copyPastePoint.x = -1;
	copyPastePoint.y = -1;
}




void CSequenceGeneratorView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	copyPastePoint = point + GetScrollPosition();
	CScrollView::OnRButtonDown(nFlags, point);
}

int CSequenceGeneratorView::getPasteLocation(CPoint point)
{
  CSequenceGeneratorDoc* pDoc = GetDocument();
  
  int current_top_point;
  int previous_top_point;
  int retVal=0;
  CPoint current_point = point;// GetScrollPosition();
  
  for(int i = 1; i <= pDoc->getList()->getSize() + 1; i++)
  {
    current_top_point = getRectCoordinate(i).TopLeft().y;
    previous_top_point = getRectCoordinate(i-1).TopLeft().y;
    
	if(i == 1)
	{
		if(current_point.y >= previous_top_point && current_point.y <= current_top_point)
			retVal = 0;
	}
	else if(i == pDoc->getList()->getSize() + 1)
	{
		if(current_point.y >= previous_top_point && current_point.y <= current_top_point)
			retVal = i + 1;
	}
	else 
    {
		if(current_point.y >= previous_top_point && current_point.y <= current_top_point)
			 retVal = i;
    }
  }
  return retVal;
}

void CSequenceGeneratorView::OnGroupEdit() 
{
	// TODO: Add your command handler code here
	CSequenceGeneratorDoc *pDoc = GetDocument();

	numOfGroups+=1;

	int listSize = pDoc->getList()->getSize();
	for(int i = 1; i <= listSize; i++)
	{
		if(pDoc->getList()->getAt(i)->getIsSelected())
		{
			pDoc->getList()->getAt(i)->setGroupNum(numOfGroups);
		}
	}

	pDoc->UpdateAllViews(NULL);

}

void CSequenceGeneratorView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
CSequenceGeneratorDoc* pDoc = GetDocument();  // Document class pointer
  ASSERT_VALID(pDoc);
  CWnd *pWnd = GetWindow(0);                    // Window class pointer
  int i = 0;                                    // Loop variable
  CString cstr;                                 // temp String for printing commandBox text
  SequenceCommandBaseClass *tempSequence;       // temp command to store current command
  CBrush * pOldBrush;                           // pointer to initial brush
  CBrush boxBrush;                              // brush used for box drawing 
  CBrush blueBoxBrush;							// brush used for 'empty' box drawing
  CPoint printCoordinates;
  CRect boxRect;                                // temp variable with coordinates of each box
  /*int*/ arrowNum = 0;                             // count of number of jump arrows (used so arrows don't overlap)
  int listSize = pDoc->getNumOfCommands();      // number of commands
  
  //if(numOfNonGroups == 0)
	//  numOfNonGroups = listSize;
  
  /*---Set up drawing/printing controls---*/
  //Save the current brush
  pOldBrush = pDC->GetCurrentBrush();
  //Create solid pastel green brush
  boxBrush.CreateSolidBrush(pastelGreenColor);
  //Create solid pastel blue brush
  blueBoxBrush.CreateSolidBrush(pastelBlueColor);
  //Select the yellow brush into the device context
  pDC->SelectObject(&boxBrush);
  //Align Text, set text background to transparent
  pDC->SetTextAlign(boxText);
  pDC->SetBkMode(TRANSPARENT);
  
  /*---Draw start/stop elipses and text---*/
  //Draw a line from Start point/ellipse to End point/ellipse
  pDC->MoveTo(CPoint(getRectCoordinate(0).CenterPoint().x * 5,getRectCoordinate(0).CenterPoint().y * 5));
  pDC->LineTo(CPoint(getRectCoordinate(listSize+1).CenterPoint().x * 5,getRectCoordinate(listSize+1).CenterPoint().y * 5));
  
  //Draw Start ellipse

 
  boxRect = CRect(getRectCoordinate(0).left * 5,getRectCoordinate(0).top * 5,getRectCoordinate(0).right * 5,getRectCoordinate(0).bottom * 5);
  boxRect.DeflateRect(commandRectWidth/5, commandRectHeight/4);
  pDC->Ellipse(boxRect);
  //Draw ending elipse
  boxRect = CRect(getRectCoordinate(listSize+1).left * 5,getRectCoordinate(listSize+1).top * 5,getRectCoordinate(listSize+1).right * 5,getRectCoordinate(listSize+1).bottom * 5);
  boxRect.DeflateRect(commandRectWidth/5, commandRectHeight/4);
  pDC->Ellipse(boxRect);
  
  // Print Start Text
  pDC->TextOut(getRectCoordinate(0).CenterPoint().x * 5,getRectCoordinate(0).CenterPoint().y + 5 * 5,"Start");
  // Print Stop Text
  pDC->TextOut(getRectCoordinate(listSize+1).CenterPoint().x * 5,getRectCoordinate(listSize+1).CenterPoint().y + 5 * 5,"Stop");
  
  /*---Draw all commands---*/
  // Loop through list and draw box w/data for each command
  for(i = 1; i <= listSize; i++)
  {
    // Get current command
    tempSequence = pDoc->getList()->getAt(i);

	
    //Set box color to green if the box has complete information.  Otherwise, color boxes light blue.
	pDoc->isCompilable();					//Determines which boxes in the list are compilable.
	if(!tempSequence->getComplete())
	{	
		pDC->SelectObject(&blueBoxBrush);
	}
	else
		pDC->SelectObject(&boxBrush);
	

    /*---Draw command box---*/
    // Get coordinates of current command box
    boxRect = CRect(getRectCoordinate(i).left * 5,getRectCoordinate(i).top * 5,getRectCoordinate(i).right * 5,getRectCoordinate(i).bottom * 5);
    // Draw rectangle representing each command
    pDC->Rectangle(boxRect);  

	
    
    /*---Print text---*/
    // Draw label (if no label then nullString drawn) to left of connecting line, just above box
    pDC->SetTextColor(blueColor);
    pDC->SetTextAlign(labelText);
    pDC->TextOut(boxRect.CenterPoint().x - 5 * 5, boxRect.CenterPoint().y - boxRect.Height()/2 - 10 * 5, tempSequence->getLabel());
    
    // Align text for box text printing
    pDC->SetTextAlign(boxText);
    pDC->SetTextColor(blackColor);
    // Get coordinates for command number
    printCoordinates = CPoint(getPrintCoordinates(0, 0, i).x,getPrintCoordinates(0, 0, i).y);
    // Print command number 
    pDC->TextOut(printCoordinates.x * 5, printCoordinates.y * 5, CString(itoa(i, new char[4], 10))); //string needed for text out
    
    switch(tempSequence->getOpcode())
    {
    case 0:  //Write EXECUTE text
      {
        printExecuteText(pDC, (SequenceExecuteClass *)tempSequence, i);
        break;
      }
    case 1:  //Write MANIPULATE Text
      {
        printManipulateText(pDC, (SequenceManipulate *)tempSequence, i);
        break;
      }
    case 2:  //Write JUMP text / draw jump arrow
      {
        printJumpText(pDC, (SequenceJumpClass *)tempSequence, i);
        arrowNum = drawJumpArrow(pDC, (SequenceJumpClass *)tempSequence, i, arrowNum);
        break;
      }
    case 3:  //Write MISC text
      {
        printMiscText(pDC, (SequenceMiscClass *)tempSequence, i);
        break;
      }
    default: // Unknown opcode
      {
        printHelper(pDC, CSequenceGeneratorDoc::nullString, "OPCODE?", CRect(getPrintBox(0, 1, i).left * 5,
			getPrintBox(0, 1, i).top * 5,getPrintBox(0, 1, i).right * 5,getPrintBox(0, 1, i).bottom * 5));
        break;
      }
    }  // end switch

  //Comment should be drawn after Jump arrow is drawn, so it was moved here.
  //Draw Comment (if no comment, a nullString is drawn).  This will be drawn to the right of the box
  pDC->SetTextColor(blueColor);
  pDC->SetTextAlign(commentText);
  pDC->TextOut(boxRect.BottomRight().x + 10 * 5, boxRect.BottomRight().y - boxRect.Height()/2 - 10 * 5, tempSequence->getComment());
  pDC->SetTextColor(blackColor);	//back to black (default)
	
  }  // end loop
  
  //Restore the current brush
  pDC->SelectObject(pOldBrush);
  
	//CScrollView::OnPrint(pDC, pInfo);
}

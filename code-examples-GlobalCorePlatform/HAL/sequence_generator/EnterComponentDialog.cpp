// EnterComponentDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "EnterComponentDialog.h"

#include "SequenceGeneratorDoc.h"
#include "EnterInterfaceDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif






/////////////////////////////////////////////////////////////////////////////
// EnterComponentDialog dialog
//CString *m_comp_array[32]; 
//CString * EnterComponentDialog::m_comp_array[32] = {m_component1, m_component2,m_component3,m_component4,m_component5,m_component6,
//	m_component7,m_component8,m_component9,m_component10, m_component11, m_component12, m_component13, m_component14,
//	m_component15,m_component16,m_component17,m_component18,m_component19,m_component20,m_component21, m_component22,
//	m_component23,m_component24,m_component25,m_component26,m_component27,m_component28,m_component29,m_component30,
//	m_component31,m_component32};
EnterComponentDialog::EnterComponentDialog(CWnd* pParent /*=NULL*/)
	: CDialog(EnterComponentDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(EnterComponentDialog)
	m_component1 = _T("");
	m_component10 = _T("");
	m_component11 = _T("");
	m_component12 = _T("");
	m_component13 = _T("");
	m_component14 = _T("");
	m_component15 = _T("");
	m_component16 = _T("");
	m_component17 = _T("");
	m_component18 = _T("");
	m_component19 = _T("");
	m_component2 = _T("");
	m_component20 = _T("");
	m_component21 = _T("");
	m_component22 = _T("");
	m_component23 = _T("");
	m_component24 = _T("");
	m_component25 = _T("");
	m_component26 = _T("");
	m_component27 = _T("");
	m_component28 = _T("");
	m_component29 = _T("");
	m_component3 = _T("");
	m_component30 = _T("");
	m_component31 = _T("");
	m_component32 = _T("");
	m_component4 = _T("");
	m_component5 = _T("");
	m_component7 = _T("");
	m_component8 = _T("");
	m_component9 = _T("");
	m_component6 = _T("");
	//}}AFX_DATA_INIT
}


void EnterComponentDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(EnterComponentDialog)
	DDX_Text(pDX, IDC_COMPONENT_EDIT1, m_component1);
	DDX_Text(pDX, IDC_COMPONENT_EDIT10, m_component10);
	DDX_Text(pDX, IDC_COMPONENT_EDIT11, m_component11);
	DDX_Text(pDX, IDC_COMPONENT_EDIT12, m_component12);
	DDX_Text(pDX, IDC_COMPONENT_EDIT13, m_component13);
	DDX_Text(pDX, IDC_COMPONENT_EDIT14, m_component14);
	DDX_Text(pDX, IDC_COMPONENT_EDIT15, m_component15);
	DDX_Text(pDX, IDC_COMPONENT_EDIT16, m_component16);
	DDX_Text(pDX, IDC_COMPONENT_EDIT17, m_component17);
	DDX_Text(pDX, IDC_COMPONENT_EDIT18, m_component18);
	DDX_Text(pDX, IDC_COMPONENT_EDIT19, m_component19);
	DDX_Text(pDX, IDC_COMPONENT_EDIT2, m_component2);
	DDX_Text(pDX, IDC_COMPONENT_EDIT20, m_component20);
	DDX_Text(pDX, IDC_COMPONENT_EDIT21, m_component21);
	DDX_Text(pDX, IDC_COMPONENT_EDIT22, m_component22);
	DDX_Text(pDX, IDC_COMPONENT_EDIT23, m_component23);
	DDX_Text(pDX, IDC_COMPONENT_EDIT24, m_component24);
	DDX_Text(pDX, IDC_COMPONENT_EDIT25, m_component25);
	DDX_Text(pDX, IDC_COMPONENT_EDIT26, m_component26);
	DDX_Text(pDX, IDC_COMPONENT_EDIT27, m_component27);
	DDX_Text(pDX, IDC_COMPONENT_EDIT28, m_component28);
	DDX_Text(pDX, IDC_COMPONENT_EDIT29, m_component29);
	DDX_Text(pDX, IDC_COMPONENT_EDIT3, m_component3);
	DDX_Text(pDX, IDC_COMPONENT_EDIT30, m_component30);
	DDX_Text(pDX, IDC_COMPONENT_EDIT31, m_component31);
	DDX_Text(pDX, IDC_COMPONENT_EDIT32, m_component32);
	DDX_Text(pDX, IDC_COMPONENT_EDIT4, m_component4);
	DDX_Text(pDX, IDC_COMPONENT_EDIT5, m_component5);
	DDX_Text(pDX, IDC_COMPONENT_EDIT7, m_component7);
	DDX_Text(pDX, IDC_COMPONENT_EDIT8, m_component8);
	DDX_Text(pDX, IDC_COMPONENT_EDIT9, m_component9);
	DDX_Text(pDX, IDC_COMPONENT_EDIT6, m_component6);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(EnterComponentDialog, CDialog)
	//{{AFX_MSG_MAP(EnterComponentDialog)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON1, OnComponentButton)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON2, OnComponentButton2)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON3, OnComponentButton3)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON4, OnComponentButton4)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON5, OnComponentButton5)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON6, OnComponentButton6)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON7, OnComponentButton7)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON8, OnComponentButton8)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON9, OnComponentButton9)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON10, OnComponentButton10)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON11, OnComponentButton11)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON12, OnComponentButton12)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON13, OnComponentButton13)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON14, OnComponentButton14)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON15, OnComponentButton15)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON16, OnComponentButton16)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON17, OnComponentButton17)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON18, OnComponentButton18)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON19, OnComponentButton19)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON20, OnComponentButton20)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON21, OnComponentButton21)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON22, OnComponentButton22)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON23, OnComponentButton23)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON24, OnComponentButton24)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON25, OnComponentButton25)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON26, OnComponentButton26)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON27, OnComponentButton27)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON28, OnComponentButton28)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON29, OnComponentButton29)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON30, OnComponentButton30)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON31, OnComponentButton31)
	ON_BN_CLICKED(IDC_COMPONENT_BUTTON32, OnComponentButton32)

    // register the events for clicking of the load and save component config
    // buttons. These two buttons allow loading or saving of the serializer
    // generated file containing the components and interfaces being used by
    // the tool.	
	ON_BN_CLICKED(IDC_BUTTON_ENTCOMP_DIALOG_LOADCNFG, OnLoadButton)
	ON_BN_CLICKED(IDC_BUTTON_ENTCOMP_DIALOG_SAVECNFG, OnSaveButton)
	
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// EnterComponentDialog message handlers


BOOL EnterComponentDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	// TODO: Add extra initialization here
//	for(int i = 0; i < 32; i++)
//	{
//		*m_comp_array[i] = CSequenceGeneratorDoc::getCompInterface(i, -1);
//	}

	m_component1 = CSequenceGeneratorDoc::getCompInterface(0,-1);
	m_component2 = CSequenceGeneratorDoc::getCompInterface(1,-1);
	m_component3 = CSequenceGeneratorDoc::getCompInterface(2,-1);
	m_component4 = CSequenceGeneratorDoc::getCompInterface(3,-1);
	m_component5 = CSequenceGeneratorDoc::getCompInterface(4,-1);
	m_component6 = CSequenceGeneratorDoc::getCompInterface(5,-1);
	m_component7 = CSequenceGeneratorDoc::getCompInterface(6,-1);
	m_component8 = CSequenceGeneratorDoc::getCompInterface(7,-1);
	m_component9 = CSequenceGeneratorDoc::getCompInterface(8,-1);
	m_component10 = CSequenceGeneratorDoc::getCompInterface(9,-1);
	m_component11= CSequenceGeneratorDoc::getCompInterface(10,-1);
	m_component12 = CSequenceGeneratorDoc::getCompInterface(11,-1);
	m_component13 = CSequenceGeneratorDoc::getCompInterface(12,-1);
	m_component14 = CSequenceGeneratorDoc::getCompInterface(13,-1);
	m_component15 = CSequenceGeneratorDoc::getCompInterface(14,-1);
	m_component16 = CSequenceGeneratorDoc::getCompInterface(15,-1);
	m_component17 = CSequenceGeneratorDoc::getCompInterface(16,-1);
	m_component18 = CSequenceGeneratorDoc::getCompInterface(17,-1);
	m_component19 = CSequenceGeneratorDoc::getCompInterface(18,-1);
	m_component20 = CSequenceGeneratorDoc::getCompInterface(19,-1);
	m_component21 = CSequenceGeneratorDoc::getCompInterface(20,-1);
	m_component22 = CSequenceGeneratorDoc::getCompInterface(21,-1);
	m_component23 = CSequenceGeneratorDoc::getCompInterface(22,-1);
	m_component24 = CSequenceGeneratorDoc::getCompInterface(23,-1);
	m_component25 = CSequenceGeneratorDoc::getCompInterface(24,-1);
	m_component26 = CSequenceGeneratorDoc::getCompInterface(25,-1);
	m_component27 = CSequenceGeneratorDoc::getCompInterface(26,-1);
	m_component28 = CSequenceGeneratorDoc::getCompInterface(27,-1);
	m_component29= CSequenceGeneratorDoc::getCompInterface(28,-1);
	m_component30 = CSequenceGeneratorDoc::getCompInterface(29,-1);
	m_component31= CSequenceGeneratorDoc::getCompInterface(30,-1);
	m_component32 = CSequenceGeneratorDoc::getCompInterface(31,-1);
	
	UpdateData(NULL);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void EnterComponentDialog::OnComponentButton() 
{
	// TODO: Add your control notification handler code here
	
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(0);
	interfaceDlg.DoModal();
}



void EnterComponentDialog::OnComponentButton2() 
{
	// TODO: Add your control notification handler code here
	
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(1);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton3() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(2);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton4() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(3);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton5() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(4);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton6() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(5);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton7() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(6);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton8() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(7);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton9() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(8);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton10() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(9);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton11() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(10);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton12() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(11);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton13()
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(12);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton14() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(13);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton15() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(14);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton16() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(15);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton17() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(16);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton18() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(17);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton19() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(18);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton20() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(19);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton21() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(20);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton22() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(21);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton23() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(22);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton24() 
{
	// TODO: Add your control notification handler code here
	//EnterComponentDialog::
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(23);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton25() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(24);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton26() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(25);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton27() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(26);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton28() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(27);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton29() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(28);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton30() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(29);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton31() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(30);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnComponentButton32() 
{
	// TODO: Add your control notification handler code here
	EnterInterfaceDialog interfaceDlg;
	interfaceDlg.setComponent(31);
	interfaceDlg.DoModal();
}

void EnterComponentDialog::OnLoadButton() 
{
	BOOL status;
	 
    status = CSequenceGeneratorDoc::CheckAndLoadComponentArchiveFile();

	m_component1 = CSequenceGeneratorDoc::getCompInterface(0,-1);
	m_component2 = CSequenceGeneratorDoc::getCompInterface(1,-1);
	m_component3 = CSequenceGeneratorDoc::getCompInterface(2,-1);
	m_component4 = CSequenceGeneratorDoc::getCompInterface(3,-1);
	m_component5 = CSequenceGeneratorDoc::getCompInterface(4,-1);
	m_component6 = CSequenceGeneratorDoc::getCompInterface(5,-1);
	m_component7 = CSequenceGeneratorDoc::getCompInterface(6,-1);
	m_component8 = CSequenceGeneratorDoc::getCompInterface(7,-1);
	m_component9 = CSequenceGeneratorDoc::getCompInterface(8,-1);
	m_component10 = CSequenceGeneratorDoc::getCompInterface(9,-1);
	m_component11= CSequenceGeneratorDoc::getCompInterface(10,-1);
	m_component12 = CSequenceGeneratorDoc::getCompInterface(11,-1);
	m_component13 = CSequenceGeneratorDoc::getCompInterface(12,-1);
	m_component14 = CSequenceGeneratorDoc::getCompInterface(13,-1);
	m_component15 = CSequenceGeneratorDoc::getCompInterface(14,-1);
	m_component16 = CSequenceGeneratorDoc::getCompInterface(15,-1);
	m_component17 = CSequenceGeneratorDoc::getCompInterface(16,-1);
	m_component18 = CSequenceGeneratorDoc::getCompInterface(17,-1);
	m_component19 = CSequenceGeneratorDoc::getCompInterface(18,-1);
	m_component20 = CSequenceGeneratorDoc::getCompInterface(19,-1);
	m_component21 = CSequenceGeneratorDoc::getCompInterface(20,-1);
	m_component22 = CSequenceGeneratorDoc::getCompInterface(21,-1);
	m_component23 = CSequenceGeneratorDoc::getCompInterface(22,-1);
	m_component24 = CSequenceGeneratorDoc::getCompInterface(23,-1);
	m_component25 = CSequenceGeneratorDoc::getCompInterface(24,-1);
	m_component26 = CSequenceGeneratorDoc::getCompInterface(25,-1);
	m_component27 = CSequenceGeneratorDoc::getCompInterface(26,-1);
	m_component28 = CSequenceGeneratorDoc::getCompInterface(27,-1);
	m_component29= CSequenceGeneratorDoc::getCompInterface(28,-1);
	m_component30 = CSequenceGeneratorDoc::getCompInterface(29,-1);
	m_component31= CSequenceGeneratorDoc::getCompInterface(30,-1);
	m_component32 = CSequenceGeneratorDoc::getCompInterface(31,-1);
	
	UpdateData(NULL);
         
}

// opens the component config file for saving.  If file
// does not exhist, it will be created. Exhisting file
// will be overwritten

void EnterComponentDialog::OnSaveButton() 
{

	UpdateData();


	CSequenceGeneratorDoc::setCompInterface(0,-1,m_component1);
	CSequenceGeneratorDoc::setCompInterface(1,-1,m_component2);
	CSequenceGeneratorDoc::setCompInterface(2,-1,m_component3);
	CSequenceGeneratorDoc::setCompInterface(3,-1,m_component4);
	CSequenceGeneratorDoc::setCompInterface(4,-1,m_component5);
	CSequenceGeneratorDoc::setCompInterface(5,-1,m_component6);
	CSequenceGeneratorDoc::setCompInterface(6,-1,m_component7);
	CSequenceGeneratorDoc::setCompInterface(7,-1,m_component8);
	CSequenceGeneratorDoc::setCompInterface(8,-1,m_component9);
	CSequenceGeneratorDoc::setCompInterface(9,-1,m_component10);
	CSequenceGeneratorDoc::setCompInterface(10,-1,m_component11);
	CSequenceGeneratorDoc::setCompInterface(11,-1,m_component12);
	CSequenceGeneratorDoc::setCompInterface(12,-1,m_component13);
	CSequenceGeneratorDoc::setCompInterface(13,-1,m_component14);
	CSequenceGeneratorDoc::setCompInterface(14,-1,m_component15);
	CSequenceGeneratorDoc::setCompInterface(15,-1,m_component16);
	CSequenceGeneratorDoc::setCompInterface(16,-1,m_component17);
	CSequenceGeneratorDoc::setCompInterface(17,-1,m_component18);
	CSequenceGeneratorDoc::setCompInterface(18,-1,m_component19);
	CSequenceGeneratorDoc::setCompInterface(19,-1,m_component20);
	CSequenceGeneratorDoc::setCompInterface(20,-1,m_component21);
	CSequenceGeneratorDoc::setCompInterface(21,-1,m_component22);
	CSequenceGeneratorDoc::setCompInterface(22,-1,m_component23);
	CSequenceGeneratorDoc::setCompInterface(23,-1,m_component24);
	CSequenceGeneratorDoc::setCompInterface(24,-1,m_component25);
	CSequenceGeneratorDoc::setCompInterface(25,-1,m_component26);
	CSequenceGeneratorDoc::setCompInterface(26,-1,m_component27);
	CSequenceGeneratorDoc::setCompInterface(27,-1,m_component28);
	CSequenceGeneratorDoc::setCompInterface(28,-1,m_component29);
	CSequenceGeneratorDoc::setCompInterface(29,-1,m_component30);
	CSequenceGeneratorDoc::setCompInterface(30,-1,m_component31);
	CSequenceGeneratorDoc::setCompInterface(31,-1,m_component32);
  
	CSequenceGeneratorDoc::WriteCompArchiveFile(); 
  

}

void EnterComponentDialog::OnOK() 
{
	// TODO: Add extra validation here

	UpdateData();


	CSequenceGeneratorDoc::setCompInterface(0,-1,m_component1);
	CSequenceGeneratorDoc::setCompInterface(1,-1,m_component2);
	CSequenceGeneratorDoc::setCompInterface(2,-1,m_component3);
	CSequenceGeneratorDoc::setCompInterface(3,-1,m_component4);
	CSequenceGeneratorDoc::setCompInterface(4,-1,m_component5);
	CSequenceGeneratorDoc::setCompInterface(5,-1,m_component6);
	CSequenceGeneratorDoc::setCompInterface(6,-1,m_component7);
	CSequenceGeneratorDoc::setCompInterface(7,-1,m_component8);
	CSequenceGeneratorDoc::setCompInterface(8,-1,m_component9);
	CSequenceGeneratorDoc::setCompInterface(9,-1,m_component10);
	CSequenceGeneratorDoc::setCompInterface(10,-1,m_component11);
	CSequenceGeneratorDoc::setCompInterface(11,-1,m_component12);
	CSequenceGeneratorDoc::setCompInterface(12,-1,m_component13);
	CSequenceGeneratorDoc::setCompInterface(13,-1,m_component14);
	CSequenceGeneratorDoc::setCompInterface(14,-1,m_component15);
	CSequenceGeneratorDoc::setCompInterface(15,-1,m_component16);
	CSequenceGeneratorDoc::setCompInterface(16,-1,m_component17);
	CSequenceGeneratorDoc::setCompInterface(17,-1,m_component18);
	CSequenceGeneratorDoc::setCompInterface(18,-1,m_component19);
	CSequenceGeneratorDoc::setCompInterface(19,-1,m_component20);
	CSequenceGeneratorDoc::setCompInterface(20,-1,m_component21);
	CSequenceGeneratorDoc::setCompInterface(21,-1,m_component22);
	CSequenceGeneratorDoc::setCompInterface(22,-1,m_component23);
	CSequenceGeneratorDoc::setCompInterface(23,-1,m_component24);
	CSequenceGeneratorDoc::setCompInterface(24,-1,m_component25);
	CSequenceGeneratorDoc::setCompInterface(25,-1,m_component26);
	CSequenceGeneratorDoc::setCompInterface(26,-1,m_component27);
	CSequenceGeneratorDoc::setCompInterface(27,-1,m_component28);
	CSequenceGeneratorDoc::setCompInterface(28,-1,m_component29);
	CSequenceGeneratorDoc::setCompInterface(29,-1,m_component30);
	CSequenceGeneratorDoc::setCompInterface(30,-1,m_component31);
	CSequenceGeneratorDoc::setCompInterface(31,-1,m_component32);

	CDialog::OnOK();
}
//CString CSequenceGeneratorDoc::getCompInterface(int compNum, int intNum)
//{
//	return ((compNum >= 0) && (compNum <= 31) && (intNum >= -1) && (intNum <= 7))?compIntStrings[compNum][intNum+1]:nullString;
//}


// Static function to set component/interface symbolic name
//void CSequenceGeneratorDoc::setCompInterface(int compNum, int intNum, CString newString)
//{
//	compIntStrings[compNum][intNum+1] = newString;
//}


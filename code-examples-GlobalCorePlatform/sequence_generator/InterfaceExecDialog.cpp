// InterfaceExecDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "InterfaceExecDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "SequenceGeneratorDoc.h"

//CString constants used for interface combo box
/*CString synthesizer[] = {"setRFState", "setFreq", "getFreq", "getError"};
CString synthesizerAdjust[] = {"setRFState", "setWarp"};
CString modulationBalanceAttenuator[] = {"setRFState", "setModBalance"};
CString modulator[] = {"setRFState", "setModSensitivity"};
CString modulationAttenuator[] = {"setRFState", "setModAttenuation"};
CString powerAmplifier[] = {"setRFState", "setPA"};
CString powerControl[] = {"setRFState", "setPowerControl"};
CString antennaSwitch[] = {"setRFState", "setAS"};
CString frontEndFilter[] = {"setRFState", "setFilter"};
CString switchCapacitorFilter[] = {"setRFState", "setSwitchCapacitorFilter"};
CString vcoControl[] = {"setRFState", "setMode"};
CString frequencyConversionReference[] = {"setRFState", "setLO"};
CString synchronousSerialInterface[] = {"setRFState"};
CString RFStatus[] = {"getRFState"};
CString *allComponents[14] = {synthesizer, synthesizerAdjust, modulationBalanceAttenuator, modulator,
							  modulationAttenuator, powerAmplifier, powerControl, antennaSwitch, frontEndFilter, 
							  switchCapacitorFilter, vcoControl, frequencyConversionReference, 
							  synchronousSerialInterface, RFStatus};

int sizeOfComponents[] = {4,2,2,2,2,2,2,2,2,2,2,2,2,1};*/


/////////////////////////////////////////////////////////////////////////////
// InterfaceExecDialog dialog


InterfaceExecDialog::InterfaceExecDialog(CWnd* pParent /*=NULL*/)
	: CDialog(InterfaceExecDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(InterfaceExecDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void InterfaceExecDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(InterfaceExecDialog)
	DDX_Control(pDX, IDC_INTERFACE_COMBO, m_interface_exec_cb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(InterfaceExecDialog, CDialog)
	//{{AFX_MSG_MAP(InterfaceExecDialog)
	ON_BN_CLICKED(ID_INTERFACE_EXEC_OK, OnInterfaceExecOk)
	ON_BN_CLICKED(ID_INTERFACE_EXEC_CANCEL, OnInterfaceExecCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// InterfaceExecDialog message handlers

void InterfaceExecDialog::OnInterfaceExecOk() 
{
	// TODO: Add your control notification handler code here
	int interface_selection = m_interface_exec_cb.GetCurSel();

	if(interface_selection != CB_ERR)
	{
		m_interface = interface_selection;
	}
	else
		m_interface = -1;

	CDialog::OnOK();
}

void InterfaceExecDialog::OnInterfaceExecCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void InterfaceExecDialog::setComponent(int component)
{
	m_component = component;
}

BOOL InterfaceExecDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	for(int i = 0; i < m_interface_exec_cb.GetCount(); i++)
	{
		m_interface_exec_cb.DeleteString(i);
	}
	
	if(m_component >= 0 && m_component <= 31)
	{
		populateComboBox();	//populates combo box with appropriate choices
	}
	
	if(m_interface >= 0 && m_interface <=7)
	{
		m_interface_exec_cb.SetCurSel(m_interface);//allComponents[m_component][m_interface]);
	}
	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void InterfaceExecDialog::populateComboBox()
{
	CString tempInterface;
	
	for(int i = 0; i < 8; i++)
	{
	//	m_interface_exec_cb.AddString(allComponents[m_component][i]);
		tempInterface = CSequenceGeneratorDoc::getCompInterface(m_component,i);
	//	if(tempInterface != "")
			m_interface_exec_cb.AddString(tempInterface);
	//	else
		//	m_interface_exec_cb.AddString("empty");
	}


}

void InterfaceExecDialog::setInterface(int i_face)
{
	m_interface = i_face;
}

int InterfaceExecDialog::getComponent()
{
	return m_component;
}

int InterfaceExecDialog::getInterface()
{
	return m_interface;
}

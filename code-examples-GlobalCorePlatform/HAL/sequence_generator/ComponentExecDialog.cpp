// ComponentExecDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "ComponentExecDialog.h"

#include "SequenceGeneratorDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// serial archiver config file for components
// added March 14 2004 by R. Miner


/////////////////////////////////////////////////////////////////////////////
// ComponentExecDialog dialog


ComponentExecDialog::ComponentExecDialog(CWnd* pParent /*=NULL*/)
	: CDialog(ComponentExecDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(ComponentExecDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ComponentExecDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ComponentExecDialog)
	DDX_Control(pDX, IDC_COMPONENT_EXEC_COMBO, m_component_exec_cb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ComponentExecDialog, CDialog)
	//{{AFX_MSG_MAP(ComponentExecDialog)
	ON_BN_CLICKED(ID_COMPONENT_EXEC_OK, OnComponentExecOk)
	ON_BN_CLICKED(ID_COMPONENT_EXEC_CANCEL, OnComponentExecCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ComponentExecDialog message handlers

void ComponentExecDialog::OnComponentExecOk() 
{
	// TODO: Add your control notification handler code here
	int component_selection = m_component_exec_cb.GetCurSel();

	if(component_selection != CB_ERR)
	{
		m_component = component_selection;
	}
	else
		m_component = -1;


	CDialog::OnOK();
}

void ComponentExecDialog::OnComponentExecCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

BOOL ComponentExecDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	for(int i = 0; i < 32; i++)
	{
		m_component_exec_cb.AddString(CSequenceGeneratorDoc::getCompInterface(i,-1));
	}

	if(m_component >= 0 && m_component <=31)
		m_component_exec_cb.SetCurSel(m_component);
	else
		 m_component =-1;


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int ComponentExecDialog::getComponent()
{
	return m_component;
}

void ComponentExecDialog::setComponent(int component)
{
	m_component = component;
}


/*
synthesizer
synthesizerAdjust
modulationBalanceAttenuator
modulator
modulationAttenuator
powerAmplifier
powerControl
antennaSwitch
frontEndFilter
switchCapacitorFilter
vcoControl
frequencyConversionReference
synchronousSerialInterface
rfStatus
*/
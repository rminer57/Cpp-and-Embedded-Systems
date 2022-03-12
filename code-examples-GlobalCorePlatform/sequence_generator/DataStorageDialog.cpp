// DataStorageDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "DataStorageDialog.h"
#include "SequenceCommandBaseClass.h"
#include "SelectDataDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DataStorageDialog dialog


DataStorageDialog::DataStorageDialog(CWnd* pParent /*=NULL*/)
	: CDialog(DataStorageDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(DataStorageDialog)
	m_immd_or_nonimmd = 0;
	m_immediate_edit = _T("");
	m_nonimmd_reg1_edit = _T("");
	m_nonimmd_reg2_edit = _T("");
	m_nonimmd_reg3_edit = _T("");
	m_nonimmd_reg4_edit = _T("");
	//}}AFX_DATA_INIT
}


void DataStorageDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DataStorageDialog)
	DDX_Control(pDX, IDC_EDIT_DATA_REG1, m_edit_reg1);
	DDX_Control(pDX, IDC_EDIT_DATA_IMMD, m_immediate_edit_control);
	DDX_Control(pDX, IDC_BUTTON_DATA_REG4, m_data_reg4_button);
	DDX_Control(pDX, IDC_BUTTON_DATA_REG3, m_data_reg3_button);
	DDX_Control(pDX, IDC_BUTTON_DATA_REG2, m_data_reg2_button);
	DDX_Control(pDX, IDC_BUTTON_DATA_REG1, m_data_reg1_button);
	DDX_Radio(pDX, IDC_IMMEDIATE_RADIO, m_immd_or_nonimmd);
	DDX_Text(pDX, IDC_EDIT_DATA_IMMD, m_immediate_edit);
	DDX_Text(pDX, IDC_EDIT_DATA_REG1, m_nonimmd_reg1_edit);
	DDX_Text(pDX, IDC_EDIT_DATA_REG2, m_nonimmd_reg2_edit);
	DDX_Text(pDX, IDC_EDIT_DATA_REG3, m_nonimmd_reg3_edit);
	DDX_Text(pDX, IDC_EDIT_DATA_REG4, m_nonimmd_reg4_edit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DataStorageDialog, CDialog)
	//{{AFX_MSG_MAP(DataStorageDialog)
	ON_BN_CLICKED(IDC_BUTTON_DATA_REG1, OnButtonDataReg1)
	ON_BN_CLICKED(IDC_BUTTON_DATA_REG2, OnButtonDataReg2)
	ON_BN_CLICKED(IDC_BUTTON_DATA_REG3, OnButtonDataReg3)
	ON_BN_CLICKED(IDC_BUTTON_DATA_REG4, OnButtonDataReg4)
	ON_BN_CLICKED(IDC_IMMEDIATE_RADIO, OnImmediateRadio)
	ON_BN_CLICKED(IDC_NONIMMEDIATE_RADIO, OnNonimmediateRadio)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DataStorageDialog message handlers

void DataStorageDialog::OnButtonDataReg1() 
{
	SelectDataDialog reg_dialog;

	if(m_arg1.num != -1)
		reg_dialog.setDataSource(m_arg1);
	reg_dialog.DoModal();
	
	if(reg_dialog.isOk())
	{
		m_arg1 = reg_dialog.getDataSource();
		m_nonimmd_reg1_edit = SequenceCommandBaseClass::getRegString(m_arg1);
	}
	UpdateData(NULL);
}

void DataStorageDialog::OnButtonDataReg2() 
{
	SelectDataDialog reg_dialog;
	if(m_arg2.num != -1)
		reg_dialog.setDataSource(m_arg2);
	reg_dialog.DoModal();
	
	if(reg_dialog.isOk())
	{
		m_arg2 = reg_dialog.getDataSource();
		m_nonimmd_reg2_edit = SequenceCommandBaseClass::getRegString(m_arg2);
	}
	UpdateData(NULL);
}

void DataStorageDialog::OnButtonDataReg3() 
{
	SelectDataDialog reg_dialog;
	if(m_arg3.num != -1)
		reg_dialog.setDataSource(m_arg3);
	reg_dialog.DoModal();

	if(reg_dialog.isOk())
	{
		m_arg3 = reg_dialog.getDataSource();
		m_nonimmd_reg3_edit = SequenceCommandBaseClass::getRegString(m_arg3);
	}
	UpdateData(NULL);
}

void DataStorageDialog::OnButtonDataReg4() 
{
	SelectDataDialog reg_dialog;
	if(m_arg4.num != -1)
		reg_dialog.setDataSource(m_arg4);
	reg_dialog.DoModal();
	if(reg_dialog.isOk())
	{
		m_arg4 = reg_dialog.getDataSource();
		m_nonimmd_reg4_edit = SequenceCommandBaseClass::getRegString(m_arg4);
	}
	UpdateData(NULL);
}

void DataStorageDialog::OnOK() 
{
	m_immediate_edit_control.GetWindowText(immediate_dialog_data_string);
	
	m_ok = true;
	//UpdateData is needed below to refresh the non-immediate edit boxes
	//UpdateData(NULL);
	CDialog::OnOK();
}

void DataStorageDialog::OnCancel() 
{
	// TODO: Add extra cleanup here
	m_ok = false;
	CDialog::OnCancel();
}

void DataStorageDialog::OnImmediateRadio() 
{
	m_data_reg1_button.EnableWindow(FALSE);
	m_data_reg2_button.EnableWindow(FALSE);
	m_data_reg3_button.EnableWindow(FALSE);
	m_data_reg4_button.EnableWindow(FALSE);
	m_immediate_edit_control.EnableWindow(TRUE);
	m_is_immediate = true;

}

void DataStorageDialog::OnNonimmediateRadio() 
{
	m_immediate_edit_control.EnableWindow(FALSE);
	m_data_reg1_button.EnableWindow(TRUE);
	m_data_reg2_button.EnableWindow(TRUE);
	m_data_reg3_button.EnableWindow(TRUE);
	m_data_reg4_button.EnableWindow(TRUE);
	m_is_immediate = false;
}

RegisterType DataStorageDialog::getArg1()
{
	return m_arg1;
}

RegisterType DataStorageDialog::getArg2()
{
	return m_arg2;
}

RegisterType DataStorageDialog::getArg3()
{
	return m_arg3;
}

RegisterType DataStorageDialog::getArg4()
{
	return m_arg4;
}

void DataStorageDialog::setArg1(RegisterType arg1)
{
	m_arg1 = arg1;
}

void DataStorageDialog::setArg2(RegisterType arg2)
{
	m_arg2 = arg2;
}

void DataStorageDialog::setArg3(RegisterType arg3)
{
	m_arg3 = arg3;
}

void DataStorageDialog::setArg4(RegisterType arg4)
{
	m_arg4 = arg4;
}

BOOL DataStorageDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_ok = false;
	if(m_is_immediate)
	{
		//Set radio button to Immediate
		m_immd_or_nonimmd = 0;
		
		//If immediate, disable all Non-Immediate 
		m_data_reg1_button.EnableWindow(FALSE);
		m_data_reg2_button.EnableWindow(FALSE);
		m_data_reg3_button.EnableWindow(FALSE);
		m_data_reg4_button.EnableWindow(FALSE);

		//Set Immediate edit box to true.
		m_immediate_edit_control.EnableWindow(TRUE);

		m_immediate_edit_control.SetWindowText(immediate_dialog_data_string);
	}
	else
	{
		//Set radio button to Non-Immediate buttons
		m_immd_or_nonimmd = 1;

		//Disable Immediate Edit box
		m_immediate_edit_control.EnableWindow(FALSE);

		//Set all data register buttons to TRUE
		m_data_reg1_button.EnableWindow(TRUE);
		m_data_reg2_button.EnableWindow(TRUE);
		m_data_reg3_button.EnableWindow(TRUE);
		m_data_reg4_button.EnableWindow(TRUE);

		//If there is any information in the data registers, set them.
		if(m_arg1.num >= 0 && m_arg1.num <= 31)
		{
			m_nonimmd_reg1_edit = SequenceCommandBaseClass::getRegString(m_arg1);
		}

		if(m_arg2.num >= 0 && m_arg2.num <= 31)
		{
			m_nonimmd_reg2_edit = SequenceCommandBaseClass::getRegString(m_arg2);
		}

		if(m_arg3.num >= 0 && m_arg3.num <= 31)
		{
			m_nonimmd_reg3_edit = SequenceCommandBaseClass::getRegString(m_arg3);
		}

		if(m_arg4.num >= 0 && m_arg4.num <= 31)
		{
			m_nonimmd_reg4_edit = SequenceCommandBaseClass::getRegString(m_arg4);
		}

		UpdateData(NULL);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DataStorageDialog::setImmediateData(CString immd_data)
{
	immediate_dialog_data_string = immd_data;
}


CString DataStorageDialog::getImmediateData()
{

	return immediate_dialog_data_string;
}

bool DataStorageDialog::getIsImmediate()
{
	return m_is_immediate;
}

void DataStorageDialog::setIsImmediate(bool is_immediate)
{
	m_is_immediate = is_immediate;
}

bool DataStorageDialog::isOk()
{
	return m_ok;
}

// SelectDataDialog.cpp : implementation file
//

#include "stdafx.h"
#include "SequenceGenerator.h"
#include "SelectDataDialog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// SelectDataDialog dialog


SelectDataDialog::SelectDataDialog(CWnd* pParent /*=NULL*/)
	: CDialog(SelectDataDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(SelectDataDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void SelectDataDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(SelectDataDialog)
	DDX_Control(pDX, IDC_REGORDATAS_COMBO2, m_global_local_or_ds_cb);
	DDX_Control(pDX, IDC_REGORDATAS_COMBO1, m_register_or_datastore_cb);
	DDX_Control(pDX, IDC_DATA_REG_COMBO, m_select_data_reg_cb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(SelectDataDialog, CDialog)
	//{{AFX_MSG_MAP(SelectDataDialog)
	ON_BN_CLICKED(ID_DATASOURCE_OK, OnDatasourceOk)
	ON_CBN_SELCHANGE(IDC_DATA_REG_COMBO, OnSelchangeDataRegCombo)
	ON_CBN_EDITCHANGE(IDC_REGORDATAS_COMBO1, OnEditchangeRegordatasCombo1)
	ON_BN_CLICKED(ID_DATASOURCE_CANCEL, OnDatasourceCancel)
	ON_CBN_SELCHANGE(IDC_REGORDATAS_COMBO1, OnSelchangeRegordatasCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// SelectDataDialog message handlers


void SelectDataDialog::OnDatasourceOk() 
{
	// TODO: Add your control notification handler code here
	int source_type = m_register_or_datastore_cb.GetCurSel();
	int num = m_select_data_reg_cb.GetCurSel();
	int ext = (source_type==2)?m_global_local_or_ds_cb.GetCurSel():source_type;

	int onOKflag = 0;

	//Check valid source type selected.
	if(source_type != CB_ERR) 
	{
		m_data_source.source_type = (source_type == 2);
	}
	else
	{
		AfxMessageBox("Error, please select Global, Local, or Data Store!");
		onOKflag = -1;
	}

	//Check if valid num is selected.
	if(num != CB_ERR)
	{
		m_data_source.num = num;
	}
	else
	{
		AfxMessageBox("Error, please select a value between 0 and 15!");
		onOKflag = -1;
	}

	//If Data Store is selected, check if proper ext is selected.
	//if(source_type)
	//{
		if(ext != CB_ERR)
		{
			m_data_source.ext = ext;
		}
		else if(source_type == 2)
		{
			
			AfxMessageBox("Error, please select a value between L0 and G3!");
			onOKflag = -1;
		}
	//}
	

	m_isOk = true;

	//Eliminate dialog ONLY is all appropriate items are selected.
	if(onOKflag != -1)
	{
		CDialog::OnOK();
		m_isOk = true;
	}
	
}

BOOL SelectDataDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	
	//m_global_local_or_ds_cb.EnableWindow(FALSE);
	m_isOk = false;
	
	//If data_source.num is NOT -1, it has an appropriate input.
	if(m_data_source.num >= 0 && m_data_source.num <= 31 )
	{
		if(m_data_source.source_type)
		{
			//Select Data Store option
			m_register_or_datastore_cb.SetCurSel(2);

			//Set value from L0-G3
			m_global_local_or_ds_cb.SetCurSel(m_data_source.ext);

			
		}
		else
		{
			//Select Global or Local, then data register value
			// if ext = 0, set global.  if ext = 1, set local.
			if(m_data_source.ext == 0)
			{
				m_register_or_datastore_cb.SetCurSel(0);	//Set global
			}
			else if(m_data_source.ext == 1)
			{
				CString tempstring;
				for(int i = 16; i < 32; i++)
				{
					tempstring.Format("%d", i);
					m_select_data_reg_cb.AddString(tempstring);
				}

				m_register_or_datastore_cb.SetCurSel(1);	//Set local
			}

			//Other combo box is disabled, so don't set to anything.
			m_global_local_or_ds_cb.EnableWindow(FALSE);	//Default setting to disable

		}


		//Set register value.
		m_select_data_reg_cb.SetCurSel(m_data_source.num);

	}
	else
		m_global_local_or_ds_cb.EnableWindow(FALSE);	//Default setting to disable


	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void SelectDataDialog::OnSelchangeDataRegCombo() 
{
	// TODO: Add your control notification handler code here
	//Do nothing.
}

RegisterType SelectDataDialog::getDataSource()
{
	return m_data_source; 
}

void SelectDataDialog::setDataSource(RegisterType data_source)
{
	m_data_source.num = data_source.num;
	m_data_source.ext = data_source.ext;
	m_data_source.source_type = data_source.source_type;
}

void SelectDataDialog::OnEditchangeRegordatasCombo1() 
{
	// TODO: Add your control notification handler code here
	//Do nothing.
}

void SelectDataDialog::OnDatasourceCancel() 
{
		// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void SelectDataDialog::OnSelchangeRegordatasCombo1() 
{
	// TODO: Add your control notification handler code here
	
	//get current selection
	int selection = m_register_or_datastore_cb.GetCurSel();

	//Selection 2 = Data Store option, therefore, third dialog will
	//be enabled if 'Data Store' is selected.
	if(selection == 2)
		m_global_local_or_ds_cb.EnableWindow(TRUE);
	else
		m_global_local_or_ds_cb.EnableWindow(FALSE);

	//If selection is selected as Local, add 16 more fields to register list
	if(selection == 1)
	{
		CString tempstring;
		for(int i = 16; i < 32; i++)
		{
			tempstring.Format("%d", i);
			m_select_data_reg_cb.AddString(tempstring);
		}
	}

	//If selection is changed back to global or data store, the registers from 16-31 must be
	//deleted.
	if(selection == 0 || selection == 2)
	{
		int length = m_select_data_reg_cb.GetCount();

		if(length >15)
		{
			for(int i = 31; i > 15; i--)
			{
				m_select_data_reg_cb.DeleteString(i);
			}
		}
	}
}

bool SelectDataDialog::isOk()
{
	return m_isOk;
}

// rfmutilDlg.cpp : implementation file
//

#include "stdafx.h"
#include "rfmutilApp.h"
#include "rfmutilDlg.h"
#include "ChanInitDialog.h"
#include "RFModem.h"
#include "fireground.h"

#include <iostream.h>
//#include "Commdlg.h"
//#include "comdef.h"
//#include "Mmsystem.h"		//Time library for timeGetTime fn.


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define READ_TIMEOUT 50


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


// Globals
int chkcount = 0;
DWORD time1, time2, time3, time4;  
CString m_strCmdMsg;
CFile objWrite;					// Write o/p to file	
int flag_SOCKET_Rxthread_start = 0;			// Thread stopped
CString flag;						// Decision making : file or opcode
CString	m_ctlPath;					// Stores path of file
CFile readb;						// Read file
int flag_end = 1;

byte RxBuffer[512];

// MAKE THESE STATIC AND PUT INSIDE void CrfmutilDlg::OnDisplay(WPARAM wp, LPARAM lp) 
int rxbuffer_index = 0;
int found_rfm_som = 0;
int rfm_data_length_this_msg = 0;
int rfm_msg_total_length = 0;

const UINT WM_DISPLAY = WM_APP+10;
CWnd* pWndOwner = NULL;				// CWnd of owner Window
HWND    m_hWndOwner;				// Handle to owner Window

CString CString_obj_Millennium_TCP("Millennium/TCP");



CRFModem * RFModemIF = NULL;

UINT SOCKETrecvProc(LPVOID pParam);


//****************************************************************************************************//
 
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   
*************************************************************************/   
void CrfmutilDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CrfmutilDlg)
	DDX_Control(pDX, IDC_EDISPLAY, m_editDisp);
	DDX_Control(pDX, IDC_COMBO_PROTOCOL, m_comboProtocol);
	DDX_Control(pDX, IDC_BCONNECT, m_ctlConnect);
	DDX_Text(pDX, IDC_TXTBOX_USER, m_strMessage);
	DDX_Text(pDX, IDC_ESERVNAME, m_strName);
	DDX_Text(pDX, IDC_ESERVPORT, m_iPort);
	DDX_CBString(pDX, IDC_COMBO_PORT, m_strPort);
	DDX_CBString(pDX, IDC_COMBO_PROTOCOL, m_strProtocol);
	DDX_CBString(pDX, IDC_COMBO_BAUD, m_strBaud);
	DDX_CBString(pDX, IDC_COMBO_FLOW, m_strFlow);
	DDX_Text(pDX, IDC_EDISPLAY, m_strDisp);
	DDX_Check(pDX, IDC_PC_LocalCheckbox, m_PC_LocalCheckbox);
	DDX_Check(pDX, IDC_CHECKBOX_TIMEOUTFILTER, m_TimeoutFilterCheckbox);
	DDX_Text(pDX, IDC_EDITFILENAME, m_ctlPath);
	//}}AFX_DATA_MAP
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CrfmutilDlg dialog
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
CrfmutilDlg::CrfmutilDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CrfmutilDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CrfmutilDlg)
	m_strMessage = _T("");
	m_strName = _T("");
	m_iPort = 0;
	pbuf1 = new char[1025];
	m_strPort = _T("");
	m_strProtocol = _T("");
	m_strBaud = _T("");
	m_strFlow = _T("");
	m_strDisp = _T("");
	m_PC_LocalCheckbox = FALSE;
	enableTimeoutMessageDisplay = TRUE;
	m_ctlPath = _T("");
	m_TimeoutFilterCheckbox = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
 	sz_flag = 1;
	tst_flag = 1;
	button_flag = 0;
	m_hsock = 0;
	serial_type = "ASCII";

	RFModemIF =  new CRFModem(XTL5000_PC_FDonSceneSim);  // RF Modem protocol object;

	//Set socket dialog pointers
	RFModemIF->SerialTransportSetParent(this);


}


BEGIN_MESSAGE_MAP(CrfmutilDlg, CDialog)
	//{{AFX_MSG_MAP(CrfmutilDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BCONNECT, OnBconnect)
	ON_BN_CLICKED(IDC_BUTTON_FILESEND, OnFileSendButton)
	ON_BN_CLICKED(IDC_BCLOSE, OnBclose)
	ON_BN_CLICKED(IDC_BUTTON_FILEBROWSE, OnBbrowse)
	ON_BN_CLICKED(IDC_RFILE, OnRfilename)
	ON_BN_CLICKED(IDC_BDIAL, OnBdial)
	ON_BN_CLICKED(IDC_BUTTON_Hangup, OnBHangup)
	ON_BN_CLICKED(IDC_BClear, OnBClear)
	ON_MESSAGE(WM_DISPLAY,  OnDisplay)					      // MESSAGE MAP FOR THREAD
	ON_CBN_SELENDOK(IDC_COMBO_PROTOCOL, OnSelendokComboProtocol)
	ON_BN_CLICKED(IDC_BOPENCOM, OnBopencom)
	ON_BN_CLICKED(IDC_BCLOSECOM, OnBclosecom)
	ON_BN_CLICKED(IDC_CHECKBOX_TIMEOUTFILTER,onTimeoutFilterCheckbox)
	ON_BN_CLICKED(IDC_PC_LocalCheckbox, onPC_LocalCheckbox)
	ON_BN_CLICKED(IDC_BUTTON_AUTOTEST, onBUTTON_AUTOTEST)
	ON_BN_CLICKED(IDC_BUTTON_RADIOSTATUS, onBUTTON_RADIOSTATUS)
	ON_BN_CLICKED(IDC_BUTTON_CHANINIT, onBUTTON_CHINIT)
	ON_BN_CLICKED(IDC_BUTTON_TSBK, OnButtonTsbk)
	ON_BN_CLICKED(IDC_BUTTON_PACKETDATA, OnButtonFGsendAck)
	ON_BN_CLICKED(IDC_BUTTON_FG_POLL, OnFiregroundPollButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_FG_EVAC, OnFiregroundEvacButtonClicked)
	ON_BN_CLICKED(IDC_RFMOPTIONSBUTTON, On_RFModemCmdButtonClicked)
	ON_BN_CLICKED(IDC_RADIOACTIONCMDBUTTON, OnRadioCmdButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_KEYREQ, OnKeyRequestButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_UNLOCKREQ, OnUnlockRequestButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON_AUTOCONN, OnAutoConnButtonClicked)
				
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CrfmutilDlg message handlers
 

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   

BOOL CrfmutilDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    CString m_connect("ready to connect");

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);

	ASSERT(IDM_ABOUTBOX < 0xF000);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
//	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
//    m_connect = "ready to connect";
	m_strName = "192.168.128.1";		//Connects to Radio (IP Adress) 127.0.0.1
	m_iPort = 8001;
	m_strPort = "COM1";
	m_strProtocol = "Millennium/TCP";
	m_strBaud = "9600";
	m_strFlow = "None";
//	m_iAscii = 0;
	//	packet_num = "first";
	
	//Update the controls
//	UpdateData(FALSE);


	TxtBox_User_WrString(m_connect);

    GetDlgItem(IDC_TXTBOX_USER)->EnableWindow(TRUE);

//	RFModemIF =  new CRFModem(XTL5000_PC_FDonSceneSim);  // RF Modem protocol object;
    
	return TRUE;  // return TRUE  unless you set the focus to a control
}

//**********************************************************
//
//  CONNECT BUTTON
//
//**********************************************************
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnBconnect() 
{
	// TODO: Add your control notification handler code here
	// Sync the variables with the controls
	DWORD ErrorCode;
    BOOL conn_status;
	int temp = 0;

	UpdateData(TRUE);

	// Disable the connection and type controls

	GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
	GetDlgItem(IDC_ESERVNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_ESERVPORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATICNAME)->EnableWindow(FALSE);
	GetDlgItem(IDC_STATICPORT)->EnableWindow(FALSE);
	GetDlgItem(IDC_RFILE)->EnableWindow(FALSE);
	
	// client- create a default socket
	
	// if socket is already open, then an unexpected error has occured. 
	// should not happen since the button is disabled after a connection occurs.
	if( !RFModemIF->isSerialTransportConnected() )
	{ 
   
	  //check protocol type selected in the protocol list box.
	  if(m_strProtocol == "Millennium/TCP" )
	  {
	       // this call does everything. if it returns a value of 1 then all is ok
	       temp = RFModemIF->SerialTransportConnectToRadio(RFM_TCP,m_iPort,m_strName);
		
           // create the socket. equivalent to berkely socket call.
		   if(temp == ERROR  )
		   {
			   /* display the string describing the error */
			   AfxMessageBox("RFModemIF.SerialTransportHandleError()");             
		   }
		   else
		   {	
					//m_hsock = m_sConnectSocket.m_hSocket;
					
					//RFModemIF.SerialTransportLaunchRxThread(this);
					SOCKETrecvProcLaunch(this);
					
					// Enable text and message control
					GetDlgItem(IDC_TXTBOX_USER)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON_FILESEND)->EnableWindow(TRUE);
 				    GetDlgItem(IDC_RFILE)->EnableWindow(TRUE);
					GetDlgItem(IDC_BCLOSE)->EnableWindow(TRUE);
					GetDlgItem(IDC_EDITFILENAME)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON_FILEBROWSE)->EnableWindow(TRUE);
                    GetDlgItem(IDC_BUTTON_RADIOSTATUS)->EnableWindow(TRUE);

					TxtBox_User_WrString("Connected!");

			}
		
	
		   } // end if(m_strProtocol == "Millennium/TCP" )


	} // end if( !RFModemIF.isSerialTransportConnected() ) 
    else
	{
		AfxMessageBox("Socket Already open");
	}

}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnAutoConnButtonClicked() 
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox("Not yet implemented, but soon will be!");

    OnBdial();

	OnBconnect();
	//OnKeyRequestButtonClicked();
	OnUnlockRequestButtonClicked();
    //onBUTTON_CHINIT();
}



/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   	
void CrfmutilDlg::onBUTTON_CHINIT()
{
    CString	mstrDisp;     
	int nSend; 
	char strDisp[256];
	
	int channel_freq;
	int base_freq;
	int bandwidth;

	rfm_pro_msg_ch_init_t chan_init_struct;

    mstrDisp = _T("");      

	if( RFModemIF->isSerialTransportConnected() )
	{
		// pop up a dialog with combo boxes, let user select what they want
		// then translate the strings and call fireground		
		// The "knowns" going into the problem are:
		//
		//    the frequency band of the radio as determined by the hardware 
		//    the frequency to be used for tx channel 1
		//    the frequency to be used for tx channel 1
		//    the channel spacing and the channel bandwidth.
		//
		// TX base freq 764,000,000
		/*
		*  formula:  frequency = (channel_increment * 6.25Khz) + 806.00625Mhz
		*            channel_increment = (base_frequency_chosen - frequency_band_start ) / 6.25Khz
		*
		*            thus:
		*                  tx channel increment = 0x0321 = ( 806006250 - 801000000) / 6250  
		*                  rx channel increment = 0x1F41 = ( 806006250 - 801000000) /6250
		*/
 

			// Mikes's VALUES for 851.5Mhz Tx and Rx,NAC code of 293
        chan_init_struct.tx_range = 0xD5;             
		chan_init_struct.tx_ch_bandwidth = 0x32;
		chan_init_struct.tx_ch_increment_msb = ((851500000-740000000)/6250)>>8;
		chan_init_struct.tx_ch_increment_lsb = ((851500000-740000000)/6250)&0xff;
		chan_init_struct.rx_ch_increment_msb = ((851500000-740000000)/6250)>>8;
		chan_init_struct.rx_ch_increment_lsb = ((851500000-740000000)/6250)&0xff;
		chan_init_struct.rx_range = 0xD5;
		chan_init_struct.rx_ch_bandwidth = 0x32;
		chan_init_struct.nac_8bits_msb = 0x29;
		chan_init_struct.nac_lsb4bits_andFlags = 0x30;

		nSend = RFModemIF->msg_format_and_send(toRadio_CH_INIT, &chan_init_struct, sizeof(rfm_pro_msg_ch_init_t) - 1);
	
		if(nSend == ERROR)
		{
			AfxMessageBox("CH INIT failed");

		}
		else 		
		{
			// Display number of bytes written
			wsprintf(strDisp, "Sent Channel Init - %d bytes to the Radio", nSend);
					 mstrDisp += (CString)strDisp + "\r\n";

			UpdateData(FALSE);

			TxtBox_User_WrString("Sent Channel Init to Radio!");		

		}

			// channel init dialog box
			/* CChanInitDialog dlgChinit;
			dlgChinit.DoModal(); */

    }
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}
	
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::onBUTTON_RADIOSTATUS()
{
    int status;
   
	if( RFModemIF->isSerialTransportConnected() )
	{

      status = RFModemIF->msg_format_and_send(toRadio_STATUS_REQ, NULL, 0);

	  if(status == ERROR)
	  {
		AfxMessageBox("radio status send failed");
	  }
	  else 		
	  {
       TxtBox_User_WrString("radio status request sent!");
	  
	  }
	}
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}


        
}


/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnButtonTsbk() 
{
	rfm_pro_msg_inbound_tsbk_t tsbk_struct;
	int status;

  /* sends an emergency tsbk */
  
	if( RFModemIF->isSerialTransportConnected() )
	{

		tsbk_struct.tsbk_octet0  = 0;    /* d5-d7 = version, d0-d4=opcode */
		tsbk_struct.tsbk_octet1  = 0;    /* sector id */
		tsbk_struct.tsbk_octet2  = 0xff; /* sequence # */
		tsbk_struct.tsbk_octet3  = 0x07; /* activity reason */
		tsbk_struct.tsbk_octet4  = 0x1f; /* d4-d7=battery level */
		tsbk_struct.tsbk_octet5  = 0;    /* radio id */
		tsbk_struct.tsbk_octet6  = 0;    /* radio id */
		tsbk_struct.tsbk_octet7  = 0;    /* radio id */
		tsbk_struct.tsbk_octet8  = 0;    /* crc */
		tsbk_struct.tsbk_octet9  = 0;    /* crc */
		tsbk_struct.tsbk_octet10 = 0;    /* crc */
		tsbk_struct.tsbk_octet11 = 0;    /* crc */
 

	    status = RFModemIF->msg_format_and_send(toRadio_TSBK, &tsbk_struct, sizeof(rfm_pro_msg_inbound_tsbk_t) - 1);

	    if(status == ERROR)
		{
		  //ErrorCode = GetLastError();
		  AfxMessageBox("radio status send failed");
		}
	    else		
		{

         TxtBox_User_WrString("tsbk sent!");
	  
		}
	}
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}


}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnButtonFGsendAck() 
{
	rfm_pro_msg_fg_ack_t pd_struct;
	int status;

	if( RFModemIF->isSerialTransportConnected() )
	{
/* Here's Kevin's FG registration Outbound packet data header sent to CT:

2004/2/13/9.28.26: Byte received: 7E
2004/2/13/9.28.26: Byte received: 0D
2004/2/13/9.28.26: Byte received: 0B
2004/2/13/9.28.26: Byte received: 03
2004/2/13/9.28.26: Byte received: 00
2004/2/13/9.28.26: Byte received: 35
2004/2/13/9.28.26: Byte received: C7
2004/2/13/9.28.26: Byte received: 90
2004/2/13/9.28.26: Byte received: FF
2004/2/13/9.28.26: Byte received: FF
2004/2/13/9.28.26: Byte received: FF
2004/2/13/9.28.26: Byte received: 81
2004/2/13/9.28.26: Byte received: 00
2004/2/13/9.28.26: Byte received: 00
2004/2/13/9.28.26: Byte received: 00
2004/2/13/9.28.26: Byte received: 00
2004/2/13/9.28.26: Byte received: 00
2004/2/13/9.28.26: Byte received: DB

Here's Kevin's FG registration Outbound packet data block sent to CT:

2004/2/13/9.28.26: Byte received: 7E
2004/2/13/9.28.26: Byte received: 0C
2004/2/13/9.28.26: Byte received: 0C
2004/2/13/9.28.26: Byte received: 04
2004/2/13/9.28.26: Byte received: 00
2004/2/13/9.28.26: Byte received: 0A
2004/2/13/9.28.26: Byte received: FF
2004/2/13/9.28.26: Byte received: 03
2004/2/13/9.28.26: Byte received: 1F
2004/2/13/9.28.26: Byte received: 00
2004/2/13/9.28.26: Byte received: 00
2004/2/13/9.28.26: Byte received: 37
2004/2/13/9.28.26: Byte received: 22
2004/2/13/9.28.26: Byte received: A3
2004/2/13/9.28.26: Byte received: A9
2004/2/13/9.28.26: Byte received: DC
2004/2/13/9.28.26: Byte received: 38

  Here's the packet data header Kevin sents to the portable to ack
  the fireground registration request

Byte #0: 7E  som
Byte #1: 0D  len
Byte #2: 05  seq
Byte #3: 83  opcode

Byte #4: 23
Byte #5: 08
Byte #6: 90
Byte #7: 00
Byte #8: 00
Byte #9: 37
Byte #10: 80
Byte #11: 00
Byte #12: 0D
Byte #13: E2
Byte #14: 83
Byte #15: C5
Byte #16: 00

Byte #17: C2 cksum */

		pd_struct.fg_ack_hdr_octet0       = 0x23;
		pd_struct.fg_ack_hdr_octet1       = 0x08;
		pd_struct.fg_ack_hdr_octet2       = 0x90;
		pd_struct.fg_ack_hdr_octet3       = 0x00;
		pd_struct.fg_ack_hdr_octet4       = 0x00;
		pd_struct.fg_ack_hdr_octet5       = 0x37;
		pd_struct.fg_ack_hdr_octet6       = 0x80;
		pd_struct.fg_ack_hdr_octet7       = 0x00;
		pd_struct.fg_ack_hdr_octet8       = 0x0d;
		pd_struct.fg_ack_hdr_octet9       = 0xe2;
		pd_struct.fg_ack_hdr_octet10      = 0x83;
		pd_struct.fg_ack_hdr_octet11      = 0xc5;
		pd_struct.blocks_to_follow		  = 0x00;            
	
	
		status =RFModemIF->msg_format_and_send(toRadio_PACKET_DATA, &pd_struct, sizeofFG_ACK_PACKET);    
 
		if(status == ERROR)
		{
		//ErrorCode = GetLastError();
		AfxMessageBox("FG ack packet data cmd send failed");
		}
		else 		
		{

			TxtBox_User_WrString("packet data command sent!");
	  
		}
	}
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}
	
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnFiregroundEvacButtonClicked() 
{
 	

	rfm_pro_msg_fg_evac_t pd_struct;
	int status;

	if( RFModemIF->isSerialTransportConnected() )
	{

		pd_struct.fg_evac_hdr_octet0    = 0x35 ;   //    0x35 
		pd_struct.fg_evac_hdr_octet1    = 0xC7 ;   //    0xC7
		pd_struct.fg_evac_hdr_octet2    = 0x90 ;   //    0x90
		pd_struct.fg_evac_hdr_octet3    = 0xff ;   //    0xFF
		pd_struct.fg_evac_hdr_octet4    = 0xff ;   //    0xFF
		pd_struct.fg_evac_hdr_octet5    = 0xff ;   //    0xFF
		pd_struct.fg_evac_hdr_octet6    = 0x81 ;   //    0x81
		pd_struct.fg_evac_hdr_octet7    = 0x02 ;   //    0x02
		pd_struct.fg_evac_hdr_octet8    = 0x00 ;   //    0x00
		pd_struct.fg_evac_hdr_octet9    = 0x00 ;   //    0x00
		pd_struct.fg_evac_hdr_octet10   = 0x6f ;   //    0x6F
		pd_struct.fg_evac_hdr_octet11   = 0x6c ;   //    0x6C
		pd_struct.blocks_to_follow      = 0x01 ;   //    always 0x01 
		pd_struct.fg_evac_data_octet0   = 0x00 ;   //    0x00  
		pd_struct.fg_evac_data_octet1   = 0x00 ;   //    0x00  
		pd_struct.fg_evac_data_octet2   = 0x15 ;   //    0x15  
		pd_struct.fg_evac_data_octet3   = 0x14 ;   //    0x14  
		pd_struct.fg_evac_data_octet4   = 0x00 ;   //    0x00  
		pd_struct.fg_evac_data_octet5   = 0xff ;   //    0xFF  
		pd_struct.fg_evac_data_octet6   = 0xff ;   //    0xFF  
		pd_struct.fg_evac_data_octet7   = 0xff ;   //    0xFF  
		pd_struct.fg_evac_data_octet8   = 0x7d ;   //    0x7D
		pd_struct.fg_evac_data_octet9   = 0x85 ;   //    0x85        
		pd_struct.fg_evac_data_octet10  = 0x36 ;   //    0x36  
		pd_struct.fg_evac_data_octet11  = 0x30 ;   //    0x30  
  
		
		status =RFModemIF->msg_format_and_send(toRadio_PACKET_DATA, &pd_struct, sizeofFG_EVAC_PACKET);    
 
		if(status == ERROR)
		{
		//ErrorCode = GetLastError();
		AfxMessageBox("packet data cmd send failed");
		}
		else 		
		{

			TxtBox_User_WrString("FG evac packet data command sent!");
	  
		}
	}
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}
	

}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnFiregroundPollButtonClicked() 
{

	rfm_pro_msg_fg_poll_t pd_struct;
	int status;

	if( RFModemIF->isSerialTransportConnected() )
	{

		pd_struct.fg_poll_hdr_octet0    = 0x35 ;  //    0x35 
		pd_struct.fg_poll_hdr_octet1    = 0xc7 ;  //    0xC7
		pd_struct.fg_poll_hdr_octet2    = 0x90 ;  //    0x90
		pd_struct.fg_poll_hdr_octet3    = 0x00 ;  //    0x00
		pd_struct.fg_poll_hdr_octet4    = 0x00 ;  //    0x00
		pd_struct.fg_poll_hdr_octet5    = 0x37 ;  //    0x37
		pd_struct.fg_poll_hdr_octet6    = 0x81 ;  //    0x81
		pd_struct.fg_poll_hdr_octet7    = 0x02 ;  //    0x02
		pd_struct.fg_poll_hdr_octet8    = 0x00 ;  //    0x00
		pd_struct.fg_poll_hdr_octet9    = 0x00 ;  //    0x00
		pd_struct.fg_poll_hdr_octet10   = 0xaf ;  //    0xAF
		pd_struct.fg_poll_hdr_octet11   = 0x37 ;  //    0x37
		pd_struct.blocks_to_follow      = 0x01 ;  //    always 0x01
		pd_struct.fg_poll_data_octet0   = 0x00 ;  //    0x00  
		pd_struct.fg_poll_data_octet1   = 0x00 ;  //    0x00  
		pd_struct.fg_poll_data_octet2   = 0xff ;  //    0xFF  
		pd_struct.fg_poll_data_octet3   = 0x13 ;  //    0x13  
		pd_struct.fg_poll_data_octet4   = 0x00 ;  //    0x00  
		pd_struct.fg_poll_data_octet5   = 0x00 ;  //    0x00  
		pd_struct.fg_poll_data_octet6   = 0x00 ;  //    0x00  
		pd_struct.fg_poll_data_octet7   = 0x37 ;  //    0x37  
		pd_struct.fg_poll_data_octet8   = 0xb6 ;  //    0xB6
		pd_struct.fg_poll_data_octet9   = 0xa3 ;  //    0xA3       
		pd_struct.fg_poll_data_octet10  = 0x93 ;  //    0x93 
		pd_struct.fg_poll_data_octet11  = 0xd0 ;  //    0xD0  	

		
		status =RFModemIF->msg_format_and_send(toRadio_PACKET_DATA, &pd_struct, sizeofFG_POLL_PACKET);    
 
		if(status == ERROR)
		{
		//ErrorCode = GetLastError();
		AfxMessageBox("packet data cmd send failed");
		}
		else 		
		{

			TxtBox_User_WrString("FG evac packet data command sent!");
	  
		}
	}
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}
	

}



/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::onBUTTON_AUTOTEST()
{
      AfxMessageBox("sorry, autotest not yet implemented");    
}


/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   

void CrfmutilDlg::OnClose()
{


    RFModemIF->SerialTransportClose();
	
	// Disable msg sending controls
	GetDlgItem(IDC_TXTBOX_USER)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_FILESEND)->EnableWindow(FALSE);
	GetDlgItem(IDC_BCLOSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_ESERVNAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_ESERVPORT)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATICNAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_STATICPORT)->EnableWindow(TRUE);
 	GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);

	GetDlgItem(IDC_EDITFILENAME)->EnableWindow(FALSE);

	GetDlgItem(IDC_RFILE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_FILEBROWSE)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON_RADIOSTATUS)->EnableWindow(FALSE);
}

//**********************************************************
//
//  FILE SEND BUTTON
//
//**********************************************************
void CrfmutilDlg::OnFileSendButton() 
{
	
	UpdateData(TRUE);

	if(m_strProtocol == "Astro Spectra/RS232" )
	{
		OnATsend();
	}
	else if(m_strProtocol == "Millennium/TCP" )
	{
		FileSend();
	}
	else 
	{

      AfxMessageBox("CrfmutilDlg::OnFileSendButton UNKNOWN PROTOCOL TO BE SENT");	
	}
}

//**********************************************************
//
//  send file method
//
//**********************************************************
void CrfmutilDlg::FileSend()
{
	
	char strDisp[256];
	CString	mstrDisp; 
	int bytes_to_send = 0;
	int bytes_sent;
	int status;
	int index = 0;
	byte FileBuffer[50000];	 
 	byte * size, b[1];
	size = new byte[3];
	BOOL bOpen;
 	
    mstrDisp = _T(""); 

	//Open file to send in read-write mode
	bOpen = readb.Open(m_ctlPath, CFile::modeReadWrite);
	
	if(bOpen > 0)
	{ 
		bytes_to_send = 0;

		// Read file into FileBuffer skipping carriage return and 
		//linefeed characters
		while((readb.Read(b,1)) > 0)
		{
			if( !( ( b[0] == (byte)0x0A) || 
				   ( b[0] == (byte)0x0D)
			
			  )  )
			{ 
				//bug fixes
				FileBuffer[bytes_to_send] = b[0];
			    bytes_to_send++;
   			}
		}								
	}


	// Write buffer out through the socket

	status = RFModemIF->SendBytesOverSerialTransport( &FileBuffer[0], bytes_to_send);

    bytes_sent = RFModemIF->GetBytesSent();

	if(status == ERROR)
	{
			// Display number of bytes written
		 wsprintf(strDisp, "File Send Write failed: Sent %d bytes to the Radio", bytes_sent);

		 mstrDisp += (CString)strDisp + "\r\n";

		AfxMessageBox(mstrDisp);
	}
	else		
	{  
        index += bytes_sent;
				
		// If number of bytes written is less than bytes_to_send, then complete writing
		// out all the bytes
		while(bytes_to_send < bytes_to_send)
		{
	        status = RFModemIF->SendBytesOverSerialTransport( &FileBuffer[index], bytes_to_send);

            bytes_sent = RFModemIF->GetBytesSent();

			index += bytes_sent;

			bytes_to_send -= bytes_sent;
		}

		// Display number of bytes written
		wsprintf(strDisp, "Sent %d bytes to the Radio", bytes_sent);

		m_strDisp += (CString)strDisp + "\r\n";
	}

	
	UpdateData(FALSE);
	
	if(bOpen)
		readb.Close();				// close file
}




 

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::TxtBox_User_WrString(CString string_obj)
{
	//DDX_Text(pDX, IDC_TXTBOX_USER, m_strMessage);
    m_strMessage = string_obj;
	UpdateData(FALSE);
}




/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
// When the connect button is pressed, according to the mode of the 
// radio buttons (client/server), a socket is created on the client or servcer side
// Lets say we are in listen mode so the socket object calls the listen function and
// This triggers the event function OnAccept inherited from the CASynSocket class and
// which calls the OnAccept() fn in the Sock Dlgs class as this has to Enable some
// changes in the GUI and also accept the socket.

void CrfmutilDlg::OnAccept()
{
	int temp = 0;
     // Function called by OnAccept() from Socket class
	
	DWORD ErrorCode;

	// Accepts the connection request
    //temp = m_sListenSocket.Accept(m_sConnectSocket)

	if(temp == 0 )
	{
		ErrorCode = GetLastError();
//		m_errorMsg.ErrorDisplay(ErrorCode);
	}

	// Enable text and message control
	GetDlgItem(IDC_TXTBOX_USER)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_FILESEND)->EnableWindow(TRUE);

	GetDlgItem(IDC_RFILE)->EnableWindow(TRUE);
}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnConnect()
{
 	// Enable text and message control
	 
	GetDlgItem(IDC_BUTTON_FILESEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_BCLOSE)->EnableWindow(TRUE);

	GetDlgItem(IDC_RFILE)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDITFILENAME)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON_FILEBROWSE)->EnableWindow(TRUE);
	GetDlgItem(IDC_TXTBOX_USER)->EnableWindow(TRUE);
	
	 	
}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   

void CrfmutilDlg::OnBbrowse() 
{
	// TODO: Add your control notification handler code here
	CString path = "hello";
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDOK)
	{
		cout << (LPCTSTR)dlg.GetPathName()<<endl;
	}
	
	if(flag == "file")
		m_ctlPath = (LPCTSTR)dlg.GetPathName();
	else if(flag == "opcode")
	{
		m_strMessage = (LPCTSTR)dlg.GetPathName();
		m_strCmdMsg = m_strMessage;
	}

	UpdateData(FALSE);	
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnRfilename() 
{
	// TODO: Add your control notification handler code here
	//Disable message controls
	 

	GetDlgItem(IDC_BUTTON_FILEBROWSE)->EnableWindow(TRUE);
	GetDlgItem(IDC_TXTBOX_USER)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDITFILENAME)->EnableWindow(TRUE);

	UpdateData(TRUE);
	
	flag = "file";	
}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/    
void CrfmutilDlg::OnSelendokComboProtocol() 
{
	// TODO: Add your control notification handler code here

	UpdateData(TRUE); 
	
	CString strCmpProto;

	// CComboBox	m_comboProtocol; this call reads the box contents
	m_comboProtocol.GetWindowText(strCmpProto);

	UpdateData(TRUE);

	// CString	m_strProtocol;
	if( m_strProtocol == "Astro Spectra/RS232" )
	{
		// Change to SERIAL mode
		// Disable server name, server port, Connect button, dial button, and Hangup button
	    GetDlgItem(IDC_ESERVNAME)->EnableWindow(FALSE);
		GetDlgItem(IDC_ESERVPORT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BCONNECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BDIAL)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_Hangup)->EnableWindow(FALSE);

		// Enable, Com Port, Open button, and command line
		GetDlgItem(IDC_COMBO_BAUD)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_FLOW)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_PORT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BOPENCOM)->EnableWindow(TRUE);

		GetDlgItem(IDC_TXTBOX_USER)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_FILESEND)->EnableWindow(TRUE);


	}
	else if(m_strProtocol == "Millennium/TCP")
	{
        		
		// Changes to TCP/IP mode
		// Enable server name, server port, Connect button, dial button, and Hangup button
		GetDlgItem(IDC_ESERVNAME)->EnableWindow(TRUE);
		GetDlgItem(IDC_ESERVPORT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BCONNECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BDIAL)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_Hangup)->EnableWindow(TRUE);

		// Disable, Com Port, Open button, and command line
		GetDlgItem(IDC_COMBO_BAUD)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_FLOW)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_PORT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BOPENCOM)->EnableWindow(FALSE);

		GetDlgItem(IDC_TXTBOX_USER)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_FILESEND)->EnableWindow(FALSE);

		if(m_commObj.IsOpen())
		{
			AfxMessageBox("Closing COM port");
			if(m_commObj.Close())
			{
				GetDlgItem(IDC_BCLOSECOM)->EnableWindow(FALSE);
			}
		}
				
	}
	else
	{
        AfxMessageBox("Combo box error");
	}
	UpdateData(FALSE);

}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
// Action handler executed when the timeout checkbox is modified.
void CrfmutilDlg::onTimeoutFilterCheckbox() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	
    if(m_TimeoutFilterCheckbox == TRUE)
    {
       enableTimeoutMessageDisplay = !m_TimeoutFilterCheckbox;  
    }
    else
    {
       enableTimeoutMessageDisplay = !m_TimeoutFilterCheckbox;    
    }



    UpdateData(FALSE);
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
// Action handler executed when the PC_LOCAL checkbox is modified.
// change this to select radio v.s. local PC IP address.
void CrfmutilDlg::onPC_LocalCheckbox() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);

	// this can be changed to a name such as PC thread to thread.
	// an unchecked box would use the radio ip address
	if(m_PC_LocalCheckbox == TRUE)
	{
		m_strName = "127.0.0.1";			// local pc thread to thread
		m_iPort = 4001;
	}
	else
	{
		m_strName = "192.168.128.1";			// radio ip
		m_iPort = 4001;
	}

	UpdateData(FALSE);
	


}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   

void CrfmutilDlg::On_RFModemCmdButtonClicked() 
{
   int status;
   static int timeoutstate = 1;

   rfm_pro_msg_modemcmd_t modem_struct;

   modem_struct.modemcmd_arg_lsb = 0;
   modem_struct.modemcmd_arg_msb = 0;


	if( RFModemIF->isSerialTransportConnected() )
	{
       if(timeoutstate == 1)
	   {
         timeoutstate = 0;
         modem_struct.modemcmd_enum = SET_MODEM_CT_LINK_TIMER_DISABLE;
	   }
	   else
	   {
         timeoutstate = 1;
         modem_struct.modemcmd_enum = SET_MODEM_CT_LINK_TIMER_ENABLE;
	   }
		//typedef struct
		//{  
		//	rfm_pro_msg_header_t rfmodem_hdr;   
		//	UINT8 modemcmd_enum;
		//	UINT8 modemcmd_arg_msb;
		//	UINT8 modemcmd_arg_lsb;
      
		//} rfm_pro_msg_modemcmd_t;

      status = RFModemIF->msg_format_and_send(toRadio_RFMODEM_CMD, &modem_struct, sizeof(rfm_pro_msg_modemcmd_t));

	  if(status == ERROR)
	  {
		AfxMessageBox("rf modem command send failed");
	  }
	  else 		
	  {
       TxtBox_User_WrString("rf modem command sent!");
	  
	  }
	}
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}


}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnRadioCmdButtonClicked() 
{
  int status;
   static int timeoutstate = 1;

   rfm_pro_msg_radiocmd_t radio_struct;

   radio_struct.radiocmd_arg_lsb = 0;
   radio_struct.radiocmd_arg_msb = 0;


	if( RFModemIF->isSerialTransportConnected() )
	{
    
      radio_struct.radiocmd_enum = RFM_RIF_RCNTL_RADIO_RESET;

 
      status = RFModemIF->msg_format_and_send(toRadio_RADIO_CMD, &radio_struct, sizeof(rfm_pro_msg_radiocmd_t));

	  if(status == ERROR)
	  {
		AfxMessageBox("radio command send failed");
	  }
	  else 		
	  {
       TxtBox_User_WrString("radio command sent!");
	  
	  }
	}
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}

}



//************************************************************
// old code still needed
//************************************************************
void CrfmutilDlg::OnReceive()
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox("CrfmutilDlg::OnReceive()!");	
}

 
void CrfmutilDlg::OnSend()
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox("CrfmutilDlg::OnSend()!");		
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnBclose() 
{
	// TODO: Add your control notification handler code here
	
	if(flag_end != 0)
	{
		flag_end = 0;
		Sleep(100);

	}
    
	RFModemIF->SerialTransportStopRxThread();

	// Stop Reader thread 
	if(flag_SOCKET_Rxthread_start != 0)
	{
		flag_SOCKET_Rxthread_start = 0;
	}

	OnClose();
	 
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnBdial() 
{
	
	int value;
	value = DialRadio();
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
int CrfmutilDlg :: DialRadio()
{
	
	WinExec("Rasphone -D MotorolaFG", SW_SHOW);

	return 0;	
}
 
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnBHangup() 
{
	 


	WinExec("Rasphone -h Connectivity", 0);

}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnBClear() 
{

	m_strDisp.Empty();
	UpdateData(FALSE);	
}



/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   

void CrfmutilDlg::Scroll(int count)
{
	 
//	m_editDisp.LineScroll(count*10, 0);
	UpdateData(FALSE);
	
	if(m_editDisp.GetLineCount() >= 1000)
		OnBClear();
		
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnBopencom() 
{
	// TODO: Add your control notification handler code here

	CString strComPort;
	bool isComOpen = false;
	UpdateData(TRUE);

	strComPort = m_strPort;

	isComOpen = m_commObj.Open(m_strPort);
	if(isComOpen)
	{
		GetDlgItem(IDC_BOPENCOM)->EnableWindow(FALSE);
		GetDlgItem(IDC_BCLOSECOM)->EnableWindow(TRUE);
		
//		if(!SetCommSpeed())
//		{
//			AfxMessageBox("Unable to set selected baud rate");
//		}
		
//		if(!SetCommFlow())
//		{
//			AfxMessageBox("Unable to set selected flow");
//		}
	}
	
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
bool CrfmutilDlg::SetCommFlow()
{
	
	CString strCommFlow;
	strCommFlow = m_strFlow;

		
	if (strCommFlow == "None")
	{
		 if(m_commObj.SetFlow(strCommFlow))
			return true;
		 else  
			 return false;
	}  
	else if (strCommFlow == "Hardware")
	{
		if(m_commObj.SetFlow(strCommFlow))
			return true;
		else  
			 return false;
	}
	else if (strCommFlow == "Software")
	{
		if(m_commObj.SetFlow(strCommFlow))
			return true;
		else  
			return false;
	}
	else
	{
		return false;
	}
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
bool CrfmutilDlg::SetCommSpeed() 
{
	bool retVal = false;
	CString strCommSpeed;
	strCommSpeed = m_strBaud;
		
	if (strCommSpeed == "9600")
	{
		if(m_commObj.SetSpeed(4))
			retVal = true;
	}
	else if (strCommSpeed == "19200")
	{
		if(m_commObj.SetSpeed(3))
			retVal = true;
	}  
	else if (strCommSpeed == "38400")
	{
		if(m_commObj.SetSpeed(2))
			retVal = true;
	}
	else if (strCommSpeed == "57600")
	{
		if(m_commObj.SetSpeed(1))
			retVal = true;
	}
	else if (strCommSpeed == "115200")
	{
		if(m_commObj.SetSpeed(0))
			retVal = true;
	}
 
	return retVal;
}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnBclosecom() 
{
	// TODO: Add your control notification handler code here

	bool isComOpen = false;

	isComOpen = m_commObj.Close();
	if(isComOpen)
	{
		GetDlgItem(IDC_BOPENCOM)->EnableWindow(TRUE);
		GetDlgItem(IDC_BCLOSECOM)->EnableWindow(FALSE);
	}
	
}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
bool CrfmutilDlg::SendHexData()
{
	CString m_strAsciiCmd;
	
	//DWORD ErrorCode;
	int iLength, byteLength, nRead, nCmpRead=0, size = 5000;
	CString display;
	byte * sbuff, finalByte, lhsbyte, data;
	sbuff = new byte[128];
	byte * rbuff;
	rbuff = new byte[128];
	char * opcode, code;
	opcode = new char[128];
	bool valid_flag = true, isWrite;
	char m_ResponseToHex[5000];


	/***************** RECEIVE HEX ***********************/
	byte firstValue, secValue, display1, display2;	//declare various variable used
	CString strRecvd, strDisp, m_strShow;			// strRecvd to copy data from buffer if file sent

	//m_strAsciiCmd = m_strMessage;
	m_strMessage.MakeUpper();
	m_strMessage.Remove(' ');
	iLength = m_strMessage.GetLength();
	
	
	//If no opcode is entered, display an error message
	if((iLength % 2) == 1 || iLength == 0)
	{
		valid_flag = false;
		MessageBox("Please enter a valid command!");
		m_strMessage.Empty();
		UpdateData(FALSE);		
	}
	else
	{	
		//convert opcode from string to character array 
		opcode = m_strMessage.GetBuffer(iLength);
		opcode[iLength] = NULL;
	
	
	  for(int i=0,j=1,k=0; i < iLength-1; i+=2,j+=2,k++)
	  {
		//store first character
		code = opcode[i];
		//convert char to first half of byte
		data = byteDisplay(code);
		//if invalid opcode, that is exceeds letter F, display error message
		if(data == 99)
		{
			valid_flag = false;
			MessageBox("Invalid command");
			break;
		}
		
		lhsbyte = data << 4;
		code = opcode[j];
		data = byteDisplay(code);
		if(data == 99)
		{
			valid_flag = false;
			MessageBox("Invalid opcode");
			break;
		}
		finalByte = lhsbyte | data;
	
		//store the byte leaving 1st 2 spaces blank to store size
		sbuff[k] = finalByte;
	  }
		
	  // Set the size of opcode in the the 1st 2 bytes of buffer
	  byteLength = iLength/2;
	  // sbuff[0] = (byte)((byteLength >> 8) & 0x00FF );
	  // sbuff[1] = (byte)(byteLength & 0x00FF);
	}
	
	isWrite = m_commObj.Write(sbuff, byteLength);
	
	if(isWrite)
	{
		do
		{
			nRead = m_commObj.Read(m_ResponseToHex+nCmpRead, size, READ_TIMEOUT);
			nCmpRead += nRead;

		}while(nRead > 0);
	}
	
	if(nCmpRead > 0)
	{
		m_ResponseToHex[nCmpRead] = NULL;
		
		for(int i=0; i < nCmpRead; i++)				// loop to process opcode
		{
			firstValue = secValue = m_ResponseToHex[i];		// copy ith byte into firstValue and secondValue
				
			display1 = (firstValue >> 4);			// shift right by 4 bits in byte
			strDisp = StrDisplay(display1);			// call func StrDisplay - converts byte to string
	
		//	m_strOpcode = m_strOpcode + strDisp;	// concatenate to string to be displayed
			m_strShow = m_strShow + strDisp;

			UpdateData(FALSE);						// sync variables
			 
			display2 = (secValue & 0x0F);			// and byte with 0x0F to get the right half (4bits) of the byte
			strDisp = StrDisplay(display2);			// call func StrDisplay - converts byte to string
				
		//	m_strOpcode = m_strOpcode + strDisp + " ";	// display byte on screen, insert space between each byte
			m_strShow = m_strShow + strDisp + " ";
			
			//UpdateData(FALSE);	 
		}
		
		m_strDisp += m_strShow + "\r\n";
	}

	UpdateData(FALSE);
	
	
	return true;
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnATsend()
{
	// TODO: Add your control notification handler code here
	CString m_copyATstr, m_strResp;
	CString m_strCommand;
	char m_ResponseToAT[50000];
	bool isWrite;
	int nlen, nRead=1, nCmpRead=0, size = 50000;
		
	//copy At command string from editbox to variable
	UpdateData(TRUE);
	  
	if(serial_type == "HEX")
		SendHexData();
	else{
	m_strCommand = m_strMessage;
	m_strCommand.MakeUpper();
	m_strCommand.Remove(' ');

	m_copyATstr.Insert(0, m_strMessage);
	if (m_strMessage != "+++" && m_strMessage != "CLIENT")
	{
		nlen = m_copyATstr.GetLength();
		m_copyATstr.Insert(nlen, "\r");
	}

	//Write string to port and then write carriage return chars
	isWrite = m_commObj.Write((LPVOID)m_copyATstr.GetBuffer(1024), m_copyATstr.GetLength());
	m_copyATstr.ReleaseBuffer();
		
	if(isWrite)
	{
		while(nRead > 0)
		{
			nRead = m_commObj.Read(m_ResponseToAT+nCmpRead, size, READ_TIMEOUT);
			nCmpRead += nRead;
		}
	}
	
	if(nCmpRead > 0)
	{
		m_ResponseToAT[nCmpRead] = NULL;
		m_strResp = m_ResponseToAT;
		m_strDisp += m_strResp;
//		m_ctlSent.AddString(m_strResp);
	}

	UpdateData(FALSE);
	 
	if(SetClientConfig(m_strCommand, m_strResp))
		m_strResp.Empty();
	}
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
bool CrfmutilDlg::SetClientConfig(CString m_strCommand, CString m_strResp)
{
	//CString strAT;
	//strAT = m_strMessage;

	if(m_strCommand == "AT+IPR=19200" && m_strResp == "\r\nOK\r\n")
	{
		if(m_commObj.SetSpeed(3))
			return true;
		else  
			return false;
	}  
	else if (m_strCommand == "AT+IPR=38400" && m_strResp == "\r\nOK\r\n")
	{
		if(m_commObj.SetSpeed(2))
			return true;
		else  
			return false;
	}
	else if (m_strCommand == "AT+IPR=57600" && m_strResp == "\r\nOK\r\n")
	{
		if(m_commObj.SetSpeed(1))
			return true;
		else  
			return false;
	}
	else if (m_strCommand == "AT+IPR=115200" && m_strResp == "\r\nOK\r\n")
	{
		if(m_commObj.SetSpeed(0))
			return true;
		else  
			return false;
	}
	else if (m_strCommand == "AT&K3" && m_strResp == "\r\nOK\r\n")
	{
		if(m_commObj.SetFlow("Hardware"))
			return true;
		 else  
			 return false;
	}
	else if (m_strCommand == "AT&K4" && m_strResp == "\r\nOK\r\n")
	{
		if(m_commObj.SetFlow("Software"))
			return true;
		else  
			return false;
	}
	else if (m_strCommand == "AT&TBA" && m_strResp == "\r\nOK\r\n")
	{
		if(m_commObj.SetFlow("None"))
			return true;
		else  
			return false;
	}
	else
	{
		return false;
	}
}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CrfmutilDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CrfmutilDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnClient() 
{
	// TODO: Add your control notification handler code here
	
}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   

// Function StrDisplay: Coverts byte to string
CString CrfmutilDlg::StrDisplay(byte data)
{
	byte cmp;
	cmp = data;

	switch (cmp)
	{
	case 0x00:	return "0";
		break;
	case 0x01:	return "1";
		break;
	case 0x02:	return "2";
		break;
	case 0x03:	return "3";
		break;
	case 0x04:	return "4";
		break;
	case 0x05:	return "5";
		break;
	case 0x06:	return "6";
		break;
	case 0x07:	return "7";
		break;
	case 0x08:	return "8";
		break;
	case 0x09:	return "9";
		break;
	case 0x0A:	return "A";
		break;
	case 0x0B:	return "B";
		break;
	case 0x0C:	return "C";
		break;
	case 0x0D:	return "D";
		break;
	case 0x0E:	return "E";
		break;
	case 0x0F:	return "F";
		break;
	default:	return "Unrecognized value";
	}

}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
// Function byteDisplay: Converts char to byte - Hex value
byte CrfmutilDlg::byteDisplay(char data)
{
	char cmp;
	cmp = data;

	switch (cmp)
	{
	case '0':	return 0x00;
		break;
	case  '1':	return 0x01;
		break;
	case  '2':	return 0x02;
		break;
	case  '3':	return 0x03;
		break;
	case  '4':	return 0x04;
		break;
	case  '5':	return 0x05;
		break;
	case  '6':	return 0x06;
		break;
	case  '7':	return 0x07;
		break;
	case  '8':	return 0x08;
		break;
	case  '9':	return 0x09;
		break;
	case  'A':	return 0x0A;
		break;
	case  'B':	return 0x0B;
		break;
	case  'C':	return 0x0C;
		break;
	case  'D':	return 0x0D;
		break;
	case  'E':	return 0x0E;
		break;
	case  'F':	return 0x0F;
		break;
	default:	return 99;
	}

}



/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
/**************************************************************/
// misc FUNCTIONS
/**************************************************************/

void CrfmutilDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}




/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
//CObject<-CWnd<-CDialog
// CWnd * pWndOwner = NULL;				// CWnd of owner Window
// HWND    m_hWndOwner;				// Handle to owner Window
// int flag_SOCKET_Rxthread_start = 0;			// Thread stopped
// method to start the independent receive thread SOCKETrecvProc
 
void CrfmutilDlg::SOCKETrecvProcLaunch(CWnd * parent_app_message_handler_ptr)
{
	flag_SOCKET_Rxthread_start = 1;
		
	pWndOwner = parent_app_message_handler_ptr;
 	
	AfxBeginThread(SOCKETrecvProc, 0, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
}


/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
//**********************************************************
//
//  method to display the rf modem protocol message in an array
//
//**********************************************************
void CrfmutilDlg::rfm_msg_display(byte * rfm_msg_ptr)
{ 
    BOOL display_the_message = TRUE;
    
	//byte 0 is som, 1 is length, 2 is sequence, 3 is opcode
	char strDisp[256];
	//char strDisplayMsg[512];
	CString CString_obj;
    CString radio_status_string;
	CString data_ack_string;
    CString error_string;
	char * msgname = "";
	char * appended_msgtext = " "; /* to add space or whatever to end of msg in big box */

	int som = 0;
	int len = 0;
	int seq = 0;
	int opcode = 0;
	int checksum = 0;
	char * fband = "";
	char * errorcategory = "";
	char * dataack = "";    

	char * RadioStatus_800Mhz  = "800Mhz";   //00
	char * RadioStatus_900Mhz  = "900Mhz";   //01
	char * RadioStatus_1500Mhz = "1500Mhz";  //02

	char * RadioStatus_VHF     = "VHF";     //03
	char * RadioStatus_UHFL    = "UHFL";    //04
	char * RadioStatus_UHFH    = "UHFH";    //05
	char * RadioStatus_RBAND   = "RBAND";   //06

	char * RadioStatus_VHF1    = "VHF1"; //07
	char * RadioStatus_VHF2    = "VHF2"; //08
	char * RadioStatus_VHF3    = "VHF3"; //09
	char * RadioStatus_VHF4    = "VHF4"; //0A


	char * RadioStatus_UHF1    = "UHF1";     //0B
	char * RadioStatus_UHF2    = "UHF2";     //0C
	char * RadioStatus_UHF3    = "UHF3";     //0D
	char * RadioStatus_UHF3_5  = "UHF3_5";   //0E
	char * RadioStatus_UHF4    = "UHF4";     //0F
	char * RadioStatus_MIDBAND = "MIDBAND";  //10
	char * RadioStatus_LOW     = "LOW";      //00	
	char * RadioStatus_700Mhz  = "700/800Mhz";   //12

	char * sRFM_PROTO_ERR_SOM = "SOM BYTE NOT 7E";
	char * sRFM_PROTO_ERR_LEN_FIELD = "LEN FIELD WRONG";
	char * sRFM_PROTO_ERR_MSG_LEN_MISMATCH = "MSG LEN MISMATCH";
	char * sRFM_PROTO_ERR_CKSUM = "CKSUM BAD";
	char * sRFM_PROTO_ERR_SEQUENCE_BAD = "SEQUENCE BAD";
	char * sRFM_PROTO_ERR_SECURITYFAIL = "SECURITY FAIL";
	char * sRFM_PROTO_ERR_UNKNOWNMSG = "UNKNOWN CT MSG OPCODE";

	char * sRFM_ERR_NOERROR = " vr_send_astro_data_tx() successful";
	char * sRFM_ERR_TSBK_TX_INBOUND_BUSY = " tsbk tx inbound busy, vr_send_astro_data_tx() err: 0x01 see dsp.h";  /* INBOUND_BUSY 0x01 error */
	char * sRFM_ERR_TSBK_TX_FRAME_NOT_FOUND = " tsbk tx frame not found, vr_send_astro_data_tx() err: 0x04 see dsp.h";       /* FRAME_NOT_FOUND 0x04 error  */
	char * sRFM_ERR_TSBK_TX_VALID_SLOT_NOT_FOUND = " tsbk tx valid slot not found, vr_send_astro_data_tx() err: 0x06 see dsp.h";  /*  error 0x06  */
  
  /* packet data tx to radio from CT failures, i.e., vr_send_astro_data_tx() failed, message not sent */  
	char * sRFM_ERR_PDATA_TX_INBOUND_BUSY = " packet data tx inbound busy, vr_send_astro_data_tx() err: 0x01 see dsp.h";         /* INBOUND_BUSY 0x01 error */
	char * sRFM_ERR_PDATA_TX_FRAME_NOT_FOUND = " packet data tx frame not found, vr_send_astro_data_tx() err: 0x04 see dsp.h";      /* FRAME_NOT_FOUND 0x04 error  */
	char * sRFM_ERR_PDATA_TX_VALID_SLOT_NOT_FOUND = " packet data tx valid slot not found, vr_send_astro_data_tx() err: 0x06 see dsp.h"; /*  error 0x06  */			


	som = rfm_msg_ptr[0];
    len = rfm_msg_ptr[1];
    seq = rfm_msg_ptr[2];
    opcode = rfm_msg_ptr[3];
    checksum = rfm_msg_ptr[RFMODEM_HDR_SIZE + len];

 
	switch (opcode)
	{
	    case 0x00:
                  msgname = "OUTBOUND-NET-ID_DETECTED";
		break;

	    case 0x01:
                  msgname = "OUTBOUND-NET_ID_UNDETECTED";
                  
                  if( enableTimeoutMessageDisplay == FALSE ) display_the_message = FALSE;
				  
		break;

	    case 0x02:
                  msgname = "OUTBOUND-TSBK";
		break;

	    case 0x03:
                  msgname = "OUTBOUND-PDH";
		break;

	    case 0x04:
                  msgname = "OUTBOUND-PDB";
		break;

	    case 0x05:
                  msgname = "OUTBOUND-LC";
		break;

	    case 0x06:
                  msgname = "OUTBOUND-LC-FAILED-DECODE";
		break;

	    case 0x07:
                  msgname = "OUTBOUND-NORMAL-ENTRY-VOICE-DETECTED";
		break;

	    case 0x08:
                  msgname = "OUTBOUND-LATE-ENTRY-VOICE-DETECTED";
		break;

	    case 0x09:
                  msgname = "OUTBOUND-LATE_ENTRY-ESYNC-DETECTED";
		break;


	    case 0x0A:
                  msgname = "OUTBOUND-LOW-SPEED-DATA";
		break;

	    case 0x0B:
                  msgname = "OUTBOUND-LOW_SPEED_DATA_FAILED-DECODE";
		break;

	    case 0x0C:
                  msgname = "OUTBOUND-CH-INIT-ACK";
				  TxtBox_User_WrString("OUTBOUND-CH-INIT-ACK");
		break;

	    case 0x0D:
                  msgname = "OUTBOUND-RADIO-STATUS";


                  switch( rfm_msg_ptr[4] )  //frequency band code
				  {
				      case 0x00:
	                  fband = RadioStatus_800Mhz;   //00
					  break;

				      case 0x01:
	                  fband = RadioStatus_900Mhz;   //01
					  break;

				      case 0x02:
	                  fband = RadioStatus_1500Mhz;  //02
					  break;

				      case 0x03:
	                  fband = RadioStatus_VHF;     //03
					  break;

				      case 0x04:
	                  fband = RadioStatus_UHFL;    //04
					  break;

				      case 0x05:
	                  fband = RadioStatus_UHFH;    //05
					  break;

				      case 0x06:
	                  fband = RadioStatus_RBAND;   //06
					  break;

				      case 0x07:
	                  fband = RadioStatus_VHF1; //07
					  break;

				      case 0x08:
	                  fband = RadioStatus_VHF2 ; //08
					  break;

				      case 0x09:
	                  fband = RadioStatus_VHF3; //09
					  break;

				      case 0x0a:
	                  fband = RadioStatus_VHF4; //0A
					  break;

				      case 0x0b:
	                  fband = RadioStatus_UHF1;     //0B
					  break;

				      case 0x0c:
	                  fband = RadioStatus_UHF2;     //0C
					  break;

				      case 0x0d:
	                  fband = RadioStatus_UHF3;     //0D
					  break;

				      case 0x0e:
	                  fband = RadioStatus_UHF3_5;   //0E
					  break;

				      case 0x0f:
	                  fband = RadioStatus_UHF4;     //0F
					  break;

				      case 0x10:
	                  fband = RadioStatus_MIDBAND;  //10
					  break;

				      case 0x11:
	                  fband = RadioStatus_LOW;      //11	
					  break;

				      case 0x12:
	                  fband = RadioStatus_700Mhz;   //12
					  break;

					  default:
                      fband = "unknown";
					  break;
				  }

             		radio_status_string.Format("RADIO STATUS-> freq band:%s bandcode:%0X rfmodem version:%0X",
		            fband, rfm_msg_ptr[4], rfm_msg_ptr[5]);
							   
                                   

                   TxtBox_User_WrString( radio_status_string );
				   
				   	// Display number of bytes written
		           wsprintf(strDisp, "Received Radio Status from Mobile");
				   m_strDisp += (CString)strDisp + "\r\n";

				   UpdateData(FALSE);

		break;

	    case 0x0E:
                  msgname = "OUTBOUND-NOT-INIT";
                  
                  if( enableTimeoutMessageDisplay == FALSE ) display_the_message = FALSE;                 
		break;

		case 0x0F:
                  msgname = "OUTBOUND-VOICE-UNDETECTED";
		break;

	    case 0x10:

               switch( rfm_msg_ptr[4] )  
			   {
				      case RFM_PROTO_ERR_SOM:

	                  errorcategory = sRFM_PROTO_ERR_SOM; 

					  break;

				      case RFM_PROTO_ERR_LEN_FIELD:

	                  errorcategory = sRFM_PROTO_ERR_LEN_FIELD; 

					  break;

				      case RFM_PROTO_ERR_MSG_LEN_MISMATCH:

	                  errorcategory = sRFM_PROTO_ERR_MSG_LEN_MISMATCH; 

					  break;

				      case RFM_PROTO_ERR_CKSUM:

	                  errorcategory = sRFM_PROTO_ERR_CKSUM; 

					  break;

				      case RFM_PROTO_ERR_SEQUENCE_BAD:

	                  errorcategory = sRFM_PROTO_ERR_SEQUENCE_BAD; 

					  break;

					  case RFM_PROTO_ERR_SECURITYFAIL:

	                  errorcategory = sRFM_PROTO_ERR_SECURITYFAIL;  

					  break;

				      case RFM_PROTO_ERR_UNKNOWNMSG:

	                  errorcategory = sRFM_PROTO_ERR_UNKNOWNMSG;  

					  break;

					  default:

                      errorcategory = "unknown";

					  break;
				  }

                  msgname = "REPORT_ERR_TOCT";
                   
                  error_string.Format("ERROR-> %s category:%0X code:%0X parameter:%0X",
		                               errorcategory, rfm_msg_ptr[4], rfm_msg_ptr[5],rfm_msg_ptr[6]);
                 
                   TxtBox_User_WrString( error_string );

		break;

        /**********************************************/
		/* data send acknowledge case     */
		/**********************************************/
	    case 0x11:

               switch( rfm_msg_ptr[5] )  // data ack error code
			  {
				   case RFM_ERR_NOERROR:
	            if( rfm_msg_ptr[4] == RFM_IN_TSBK ) /* rfm_msg_ptr[4] = opcode */
				{
	                 dataack = " tsbk tx ok";
				}
				else if( rfm_msg_ptr[4] == RFM_IN_PACKET_DATA )
				{
                     dataack = " packet data tx ok";				
					
				}
				else
				{
                     dataack = " dataack bad opcode returned";
				}

				   break;


				   case RFM_ERR_TSBK_TX_INBOUND_BUSY:

	                 dataack = sRFM_ERR_TSBK_TX_INBOUND_BUSY;   

				   break;

				   case RFM_ERR_TSBK_TX_FRAME_NOT_FOUND:

	                 dataack = sRFM_ERR_TSBK_TX_FRAME_NOT_FOUND;   

				   break;

				   case RFM_ERR_TSBK_TX_VALID_SLOT_NOT_FOUND:

	                 dataack = sRFM_ERR_TSBK_TX_VALID_SLOT_NOT_FOUND;   

				   break;

				   case RFM_ERR_PDATA_TX_INBOUND_BUSY:

	                 dataack = sRFM_ERR_PDATA_TX_INBOUND_BUSY;   

				   break;

				   case RFM_ERR_PDATA_TX_FRAME_NOT_FOUND:

	                 dataack = sRFM_ERR_PDATA_TX_FRAME_NOT_FOUND;   

				   break;

				   case RFM_ERR_PDATA_TX_VALID_SLOT_NOT_FOUND:

	                 dataack = sRFM_ERR_PDATA_TX_VALID_SLOT_NOT_FOUND;   

				   break;


				   default:

					 dataack = "unknown error";

				   break;


			  }
                  msgname = "DATA_ACK_TOCT";
                   
                  data_ack_string.Format("data ack-> %s ",dataack);
                 
                  TxtBox_User_WrString( data_ack_string );


		break;

	    case 0x12:
//  UINT8 keyarray[ RFM_KEY_SIZE ];
//  UINT8 checksum;
//} rfm_pro_msg_keyreqack_in_rosbuf_t;
                  msgname = "KEYREQ_ACK";
		break;

	    case 0x13:

                  msgname = "UNLOCKREQ_ACK";
		break;

	    case 0x14:
//  UINT8 radiocmd_enum;      /* the command being acknowledged */
//  UINT8 returnval_msb;      /* optional return value msb */
//  UINT8 returnval_lsb;     /* optional return value lsb */
  /* followed by 0 to 252 bytes of data, depending on command */
  /* checksum follows the data bytes */
 
    
//} rfm_pro_msg_radiocmdack_in_rosbuf_t;
                  msgname = "RADIO_CMD_ACK";
		break;

	    case 0x15:
//  UINT8 modemcmd_enum;      /* the command being acknowledged */
//  UINT8 returnval_msb;      /* optional return value msb */
//  UINT8 returnval_lsb;     /* optional return value lsb */
  
  /* followed by 0 to 252 bytes of data, depending on command */
  /* checksum follows the data bytes */
     
//} rfm_pro_msg_modemcmdack_in_rosbuf_t;
                  msgname = "MODEM_CMD_ACK";
		break;



/*=================================================================*/
/*                                                                 */
/*                   INBOUND modem to CT messages                 */
/*                                                                 */    
/*=================================================================*/
	    case 0x80:
                  msgname = "CHANNEL_INIT";
		break;

	    case 0x81:
                  msgname = "RADIO_STATUS_REQ";
		break;
	    case 0x82:
                  msgname = "IN_TSBK";
		break;

	    case 0x83:
                  msgname = "IN_PACKET_DATA";
		break;

	    case 0x84:
                  msgname = "KEYREQ";
		break;

	    case 0x85:
//  UINT8 keyarray[ RFM_KEY_SIZE ];
//  UINT8 checksum;
//} rfm_pro_msg_unlockreq_in_rosbuf_t;
                  msgname = "UNLOCKREQ";
		break;

	    case 0x86:
                  msgname = "ERROR_ACK";
		break;

	    case 0x87:
                  msgname = "RADIO_CMD";
		break;
		
	    case 0x88:
                  msgname = "MODEM_CMD";
		break;

		default:
                  msgname = "UNKNOWN-MSG";
		break;

}

    // display_the_message is set to FALSE if the message is a 1 second timeout message
    // and if the filter timeout message checkbox is checked.
    // this allows the user to not see those annoying one second timeout messages.
    if(display_the_message ==  TRUE)
    {  
       CString_obj.Format("%s len:%02X seq:%02X opcode:%02X cksum:%02X  full msg:",
		                   msgname,     len,     seq,       opcode,    checksum);

 
       m_strDisp += CString_obj;

       for( int i = 0; i <= (RFMODEM_HDR_SIZE + len); i++)
	   {
    
         CString_obj.Format("%02X ", rfm_msg_ptr[i]);

	     CString_obj.MakeUpper();
	 
         m_strDisp += CString_obj;
	   }

       m_strDisp += appended_msgtext;
	   m_strDisp += "\r\n";

       UpdateData(FALSE);
    }

}
/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnKeyRequestButtonClicked() 
{
    int status;
   
	if( RFModemIF->isSerialTransportConnected() )
	{

      status = RFModemIF->msg_format_and_send(toRadio_KEYREQ, NULL, 0);

	  if(status == ERROR)
	  {
		AfxMessageBox("key request send failed");
	  }
	  else 		
	  {
       TxtBox_User_WrString("key request sent!");
	  
	  }
	}
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}


	
}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   
void CrfmutilDlg::OnUnlockRequestButtonClicked() 
{
    int status;
   
	if( RFModemIF->isSerialTransportConnected() )
	{

      status = RFModemIF->msg_format_and_send(toRadio_UNLOCKREQ, NULL, 0);

	  if(status == ERROR)
	  {
		AfxMessageBox("unlock request send failed");
	  }
	  else 		
	  {
       TxtBox_User_WrString("unlock request sent!");
	  
	  }
	}
	else
	{
      AfxMessageBox("A connection must be opened first!");  
	}


	
}

/*************************************************************************
*
*   CLASS:   CrfmutilDlg
*
*   METHOD:
*
*---------------------------------- PURPOSE ------------------------------
*  
*  
*---------------------------------- SYNOPSIS -----------------------------
*
*                    
*
*   ARGUMENTS :     
*                  
*
*   RETURN VALUE:  none. 
*
*---------------------------- DETAILED DESCRIPTION -----------------------
*   .
*************************************************************************/   

void CrfmutilDlg::checkForFiregroundRegistration(byte * rfm_msg_ptr)
{

    CString	mstrDisp;     
	int nSend; 
	char strDisp[256];
    int opcode = 0;
    mstrDisp = _T(""); 
	
    // structure to hold the fireground ack packet
    rfm_pro_msg_pdbib_t fg_ack_struct;


    opcode = rfm_msg_ptr[3];  // read the rf modem protocol message opcode

 
	if( opcode == toCT_PDH)
	{
		//populate the structure (not your girlfriend Fabio!) here.
        //fg_ack_struct.hdr_octet0 = 0;

	    nSend = RFModemIF->msg_format_and_send(toRadio_PACKET_DATA, &fg_ack_struct, sizeof(rfm_pro_msg_pdbib_t) - 1);
	
		if(nSend == ERROR)
		{
			AfxMessageBox("Fireground ACK tx failed");

		}
		else 		
		{
			// Display number of bytes written
			wsprintf(strDisp, "Sent fireground ack - %d bytes to the Radio", nSend);
					 mstrDisp += (CString)strDisp + "\r\n";

			UpdateData(FALSE);

			TxtBox_User_WrString("Sent Fireground ack to Radio!");		

		}


	}

}

// thread to receive IP data and process it
UINT SOCKETrecvProc(LPVOID pParam)
{
    int status;
	int bytes_received = 0;
    unsigned char last_rxchar;
	BOOL bOpenWrite;
	
	//CObject<-CWnd<-CDialog
    // CWnd * pWndOwner = NULL;				// CWnd of owner Window
    // HWND    m_hWndOwner;				    // Handle to owner Window
    // int flag_SOCKET_Rxthread_start = 0;	// Thread stopped
	
	m_hWndOwner = pWndOwner->GetSafeHwnd();

	// Open a file for writing output
	if(!(bOpenWrite = objWrite.Open("RFMoutput.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite)))
		::PostMessage(m_hWndOwner, WM_DISPLAY, 2,3);	

    /* stay forever in this while loop */
	while(flag_SOCKET_Rxthread_start == 1)
	{
		// read one character at a time and put each one into the receive buffer.
//		nRecv = m_sConnectSocket.Receive(&last_rxchar, rd_size);  rd_size = 1 byte last_rxchar

        //status = RFModemIF->GetBytesOverSerialTransport( &last_rxchar, 1);
          status = RFModemIF->GetRFModemProtocolMessage();

		   // evaluate the message and take any action required.
		   // for example, a key requst ack should result in
		   // saving of the clearkey and generation of the encrypted
		   // deravative.
		   

          if(status != ERROR)
		  {
            //bytes_received = RFModemIF->GetBytesReceived();

            RFModemIF->ProcessRFModemProtocolMessage();
			
			//this line sends a mesage to the parent thread. WM_DISPLAY is an event that
			// causes OnDisplay to be executed.  The last two parameters in the message
			// below (c and nRecv) are passed into OnDisplay as wp and lp (same order)
            ::PostMessage(m_hWndOwner, WM_DISPLAY, last_rxchar, bytes_received);

		//	if(bOpenWrite)
		//		objWrite.Write(&last_rxchar, 1);
		  }
		
		Sleep(30);
	}
	
	if(bOpenWrite)
		objWrite.Close();
	return 0;
}

//**********************************************************
// method to process messages to be displayed
// WPARAM   A value passed as a parameter to a window procedure or 
// callback function: 
// 16 bits on Windows versions 3.0 and 3.1; 32 bits on Win32
// LPARAM   A 32-bit value passed as a parameter to a window procedure or callback function
//**********************************************************
void CrfmutilDlg::OnDisplay(WPARAM wp, LPARAM lp)
{
	int bytes_recvd;
	//int c;
	const int rfm_hdr_and_cksum_len = 5;

	char strDisplayMsg[64];
	bytes_recvd = (int)lp;
	//c = (int)wp;

	//AfxMessageBox("OnDisplay received something");

    //save this character in the buffer, regardless of what it is
	//RxBuffer[rxbuffer_index] = c;


	//check to see if current character is a 7E start of rfm message
//	if(c == 0x7E)
//	{ 
		
		// the 7E can either be a real SOM start of message or part of the data
	    // stream. This will be determined below
//        found_rfm_som++;    
	
	    // this indicates a real som was found (not data imbedded in rf modem message)
//	   if( found_rfm_som == 1)
//	   {
//	     rfm_data_length_this_msg = 0; // reset length 
//	       rfm_msg_total_length = 0;


		    // this indicates the presence of garbage characters ahead of the new message
		    // display them up to the som and the adjust the buffer
//            if(rxbuffer_index > 0)
//			{
			  //int chars_this_line = 0;

			  // display
//              wsprintf(strDisplayMsg,"\r\nReceived %d bytes of garbage",(rxbuffer_index));
//	          m_strDisp += (CString)strDisplayMsg;
//              m_strDisp += "\r\n"; // add carriage return line feed at end

            
              //RxBuffer[rxbuffer_index] = c; //rewrite the som

		      // reset everything
//              found_rfm_som = 1;
//              rxbuffer_index = 0;
//		      rfm_data_length_this_msg = 0;
//	          rfm_msg_total_length = 0;			  

//              UpdateData(FALSE);
//			}
          
//	   }

//	} // end if(c == 0x7E)

    // first or second 7E and reading rf modem protocol length byte  
//	if( ( found_rfm_som > 0 ) && (rxbuffer_index == 1) )
//	{
         //read length
//		 rfm_data_length_this_msg = c;
//		 rfm_msg_total_length = rfm_data_length_this_msg + rfm_hdr_and_cksum_len;
         
//	}

	// COMPLETE RF MODEM MESSAGE WAS RECEIVED
	//if at the end of the message
//	if( (found_rfm_som > 0) && ( rxbuffer_index == (rfm_msg_total_length - 1) )  )
//	{
//           rfm_msg_display(&RxBuffer[0]);
           rfm_msg_display( (unsigned char *)RFModemIF->GetRxBufPtr() );
           //checkForFiregroundRegistration(&RxBuffer[0]);

		   // reset everything
//           found_rfm_som = 0;
//           rxbuffer_index = 0;
//		   rfm_data_length_this_msg = 0;
//	       rfm_msg_total_length = 0;

//	}
//	else
//	{
//      rxbuffer_index++;

//	}

  
//    if( rxbuffer_index > 500 )
//	{
      //runaway pointer dialog box
//      AfxMessageBox("CrfmutilDlg::OnDisplay rxbuffer_index error");
//	}

	UpdateData(FALSE);	
}
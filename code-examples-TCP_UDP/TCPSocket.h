#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TCPSocket.h : header file
//
#include <afxsock.h>

// TCPSocket command target

// global
UINT SOCKETrecvProc(LPVOID pParam);

class TCPSocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	TCPSocket();
	virtual ~TCPSocket();

// Overrides
protected:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TCPSocket)
public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
//	virtual void OnReceive(int nErrorCode);			//	DEBUG CODE
	virtual void OnSend(int nErrorCode);
	virtual CString ErrorDisplay(int);
	virtual void SetParent(CDialog * pWnd);
	
	virtual void LaunchRxThread(CWnd * parent_app_message_handler_ptr); 
	virtual void StopRxThread(void);

	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(TCPSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation

private:
	    //starts the thread responsible for receiving socket data
	    void SOCKETrecvProcLaunch(CWnd * parent_app_message_handler_ptr);
	    
	CDialog *m_pWnd;
        CWnd * pWndOwner;				       // CWnd of owner Window
        HWND    m_hWndOwner;				   // Handle to owner Window
        int flag_SOCKET_Rxthread_start;		   // Thread stopped
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


// how to use this class
// 1. In the class that will use sockets, add #include "TCPSocket.h" 
// 2. Create class attributes TCPSocket m_sListenSocket; and UINT m_hsock;
// 3. Add to message map??: ON_MESSAGE(WM_DISPLAY,  OnDisplay)    // MESSAGE MAP FOR THREAD
// 4. Add this method and call in initialization SOCKETrecvProcLaunch(this);

	//starts the thread responsible for receiving socket data
	//void SOCKETrecvProcLaunch(CWnd * parent_app_message_handler_ptr);
	//CObject<-CWnd<-CDialog
	// CWnd * pWndOwner = NULL;				// CWnd of owner Window
	// HWND    m_hWndOwner;				// Handle to owner Window
	// int flag_SOCKET_Rxthread_start = 0;			// Thread stopped
	// method to start the independent receive thread SOCKETrecvProc
 
	//void CrfmutilDlg::SOCKETrecvProcLaunch(CWnd * parent_app_message_handler_ptr)
	//{
	//	flag_SOCKET_Rxthread_start = 1;	
	//	pWndOwner = parent_app_message_handler_ptr; 	
	//	AfxBeginThread(SOCKETrecvProc, 0, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	//}
	
// thread to receive IP data and process it
//UINT SOCKETrecvProc(LPVOID pParam)
//{
//    int status;
//	int bytes_received = 0;
//    unsigned char last_rxchar;
//	BOOL bOpenWrite;
	
	//CObject<-CWnd<-CDialog
    // CWnd * pWndOwner = NULL;				// CWnd of owner Window
    // HWND    m_hWndOwner;				    // Handle to owner Window
    // int flag_SOCKET_Rxthread_start = 0;	// Thread stopped
	
//	m_hWndOwner = pWndOwner->GetSafeHwnd();

	// Open a file for writing output
//	if(!(bOpenWrite = objWrite.Open("RFMoutput.txt", CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite)))
//		::PostMessage(m_hWndOwner, WM_DISPLAY, 2,3);	

    /* stay forever in this while loop */
//	while(flag_SOCKET_Rxthread_start == 1)
//	{
		// read one character at a time and put each one into the receive buffer.
//		nRecv = m_sConnectSocket.Receive(&last_rxchar, rd_size);  rd_size = 1 byte last_rxchar

        //status = RFModemIF->GetBytesOverSerialTransport( &last_rxchar, 1);
//          status = RFModemIF->GetRFModemProtocolMessage();

		   // evaluate the message and take any action required.
		   // for example, a key requst ack should result in
		   // saving of the clearkey and generation of the encrypted
		   // deravative.
		   

//          if(status != ERROR)
//		  {
            //bytes_received = RFModemIF->GetBytesReceived();

//            RFModemIF->ProcessRFModemProtocolMessage();
			
			//this line sends a mesage to the parent thread. WM_DISPLAY is an event that
			// causes OnDisplay to be executed.  The last two parameters in the message
			// below (c and nRecv) are passed into OnDisplay as wp and lp (same order)
//            ::PostMessage(m_hWndOwner, WM_DISPLAY, last_rxchar, bytes_received);

		//	if(bOpenWrite)
		//		objWrite.Write(&last_rxchar, 1);
//		  }
		
//		Sleep(30);
//	}
	
//	if(bOpenWrite)
//		objWrite.Close();
//	return 0;
//}		
	
	//virtual void SetBytesSent(int numofbytes);
	//virtual int  GetBytesSent(void);
	//virtual void SetBytesReceived(int numofbytes);
	//virtual int  GetBytesReceived(void);	
 //int CRFModem::SendBytesOverSerialTransport( byte * txBuff, int bytes_to_send)
//{
//    int nSend = 0;
//	int returnval = ERROR;
    
//	SetBytesSent(0);

	// Write buffer out through the socket
	//If no error occurs, Send returns the total number of 
	//characters sent. This can be less than the number indicated 
	//by nBufLen. Otherwise,, a value of SOCKET_ERROR is returned, 
	//and a specific error code can be retrieved by calling 
	//GetLastError.
//	nSend = m_sConnectSocket.Send(txBuff, bytes_to_send);
    	
//	if(nSend == SOCKET_ERROR )
//	{
//		returnval = ERROR;
//	}
//	else
//	{

//		SetBytesSent(nSend);
//		returnval = OK; 
//	}
	
//	return returnval;    
//}
    //int GetBytesOverSerialTransport( byte * destbuffer, int bytes_to_get);    
    /* rf modem PC server methods */
    //void SerialTransportWaitonConnection(void);        
    //void SerialTransportLaunchRxThread(CWnd * parent_app_message_handler_ptr);   
    //void CRFModem::SerialTransportStopRxThread(void){  m_sConnectSocket.StopRxThread();}

	/* applicable only to windows */
    //void SerialTransportSetParent(CDialog * CDialog_ptr); 
        	    
    /******************************************/
    /* TCP Transport specific methods         */
    /******************************************/	
    //void SpecifyServerAddress(CString strName);
	//void SpecifyServerPort(int port);
    //void SpecifyRFModemType(rfm_configtype_t config);
	//void SpecifyRFModemSerialType(rfm_serialtype_t platform);
	
    //CMySocket m_errorMsg;				// Used for error msgs	

    //CMySocket m_sListenSocket;
    //CMySocket m_sConnectSocket;			// For Socket reads and writes
    //CMySocket m_udpSocket;				// For udp sockets
    //CWinThread m_socketThread;			// Thread initialization and end
    //int	m_iPort;                        // 4001
    //unsigned int m_hsock;
    //CString	m_strName;                  //m_strName = "192.168.128.1";	Connects to Radio (IP Adress) 127.0.0.1
    //boolean flagSerialTransportOpen;
    
    //int bytes_sent;
    //int bytes_received;
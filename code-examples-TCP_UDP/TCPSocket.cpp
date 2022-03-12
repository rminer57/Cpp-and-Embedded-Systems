// MySocket.cpp : implementation file
//

#include "stdafx.h"
#include "TCPSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// GLOBALS
int flag_SOCKET_Rxthread_start = 0; // Global
const UINT WM_DISPLAY = WM_APP+10;
CWnd* pWndOwner = NULL;				// CWnd of owner Window
HWND    m_hWndOwner;				// Handle to owner Window

/////////////////////////////////////////////////////////////////////////////
// TCPSocket
			
TCPSocket::TCPSocket()
{
	flag_SOCKET_Rxthread_start = 0;
}

TCPSocket::~TCPSocket()
{

}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(TCPSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(TCPSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// TCPSocket member functions

void TCPSocket::LaunchRxThread(CWnd * parent_app_message_handler_ptr)
{
  flag_SOCKET_Rxthread_start = 1; 

}

void TCPSocket::StopRxThread(void)
{
	// Stop Reader thread 
	if(flag_SOCKET_Rxthread_start != 0)
	{
		flag_SOCKET_Rxthread_start = 0;
	}
}

void TCPSocket::SOCKETrecvProcLaunch(CWnd * parent_app_message_handler_ptr)
{
	flag_SOCKET_Rxthread_start = 1;
	
	
	pWndOwner = parent_app_message_handler_ptr;
 	
	//AfxBeginThread(SOCKETrecvProcedure, 0, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
}

// thread to receive IP data and process it
UINT SOCKETrecvProcedure(LPVOID pParam)
{
	int bytes_recieved = 0;
	int rd_size = 1;
	byte last_rxchar;	 
	BOOL bOpenWrite;
	
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
//		nRecv = m_sConnectSocket.Receive(&last_rxchar, rd_size);
//		if(bytes_recieved > 0)
//		{
		
			//this line sends a mesage to the parent thread. WM_DISPLAY is an event that
			// causes OnDisplay to be executed.  The last two parameters in the message
			// below (c and nRecv) are passed into OnDisplay as wp and lp (same order)
//          ::PostMessage(m_hWndOwner, WM_DISPLAY, last_rxchar, bytes_recieved);

//			if(bOpenWrite)
//				objWrite.Write(&last_rxchar, 1);
//		}
		
//		Sleep(30);
//	}
	
//	if(bOpenWrite)
//		objWrite.Close();
	return 0;
}

void TCPSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	if(nErrorCode == 0)
	{
		((CrfmutilDlg *)m_pWnd) ->OnAccept();
		//CAsyncSocket::OnAccept(nErrorCode);
	}
	else
	{
		ErrorDisplay(nErrorCode);
	}
}

void TCPSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
 
	if(nErrorCode == 0)
	((CrfmutilDlg *)m_pWnd) ->OnClose();
	else
	{
		 ErrorDisplay(nErrorCode);	
	}
	//CAsyncSocket::OnClose(nErrorCode);
}

void TCPSocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
//	char testStr[50];
	 
	if(nErrorCode == 0)
	((CrfmutilDlg *)m_pWnd) ->OnConnect();
	else
	{
		ErrorDisplay(nErrorCode);
		//sprintf(testStr,"Error Code on Connect() is %d",nErrorCode); 
		//errormessage = testStr);
	}
	//CAsyncSocket::OnConnect(nErrorCode);
}

// DEBUG CODE
/*void TCPSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	
//	if(nErrorCode == 0)
//	((CSockDlg *)m_pWnd) ->OnReceive();	
//	else
//	{
//		 ErrorDisplay(nErrorCode);
//	}
	//CAsyncSocket::OnReceive(nErrorCode);
}*/

void TCPSocket::SetParent(CDialog * pWnd)
{
			//set the member pointer
		m_pWnd = pWnd;
}

void TCPSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
 
	if(nErrorCode == 0)
	((CrfmutilDlg *)m_pWnd) ->OnSend();
	else
	{
	 ErrorDisplay(nErrorCode);
	}
	//CAsyncSocket::OnSend(nErrorCode);
}


CString TCPSocket::ErrorDisplay(int ErrorCode)
{
	//CrfmutilDlg closeObj;
    CString errormessage;

	switch (ErrorCode) 
	{  
		 case WSAEADDRINUSE: 
             errormessage = "The specified address is already in use.\n";
            break;
         case WSAEADDRNOTAVAIL: 
             errormessage = "The specified address is not available from the local machine.\n";
            break;
         case WSAEAFNOSUPPORT: 
             errormessage = "Addresses in the specified family cannot be used with this socket.\n";
            break;
         case WSAECONNREFUSED: 
             errormessage = "The attempt to connect was forcefully rejected.\n";
            break;
         case WSAEDESTADDRREQ: 
             errormessage = "A destination address is required.\n";
            break;
         case WSAEFAULT: 
             errormessage = "The lpSockAddrLen argument is incorrect.\n";
            break;
         case WSAEINVAL: 
             errormessage = "The socket is already bound to an address.\n";
            break;
         case WSAEISCONN: 
             errormessage = "The socket is already connected.\n";
            break;
         case WSAEMFILE: 
             errormessage = "No more file descriptors are available.\n";
            break;
         case WSAENETUNREACH: 
             errormessage = "The network cannot be reached from this host at this time.\n";
            break;
         case WSAENOBUFS: 
             errormessage = "No buffer space is available. The socket cannot be connected.\n";
            break;
         case WSAENOTCONN: 
             errormessage = "The socket is not connected.\n";
            break;
         case WSAENOTSOCK: 
             errormessage = "The descriptor is a file, not a socket.\n";
            break;
         case WSAETIMEDOUT: 
             errormessage = "The attempt to connect timed out without establishing a connection. \n";
            break;
		 case WSANOTINITIALISED:
			 errormessage = " A successful AfxSocketInit must occur before using this API.";
            break;
		 case WSAENETDOWN:
			 errormessage = " The Windows Sockets implementation detected that the network subsystem failed.";
            break;
		 case  WSAEINPROGRESS:
			 errormessage = "A blocking Windows Sockets call is in progress.";
            break;
		 case  WSAEWOULDBLOCK:
			 errormessage = "The socket is marked as nonblocking and the connection cannot be completed immediately. ";
		    break;	
		 case  WSAESHUTDOWN:
			 errormessage = "The socket has been shut down; it is not possible to call Receive on a socket after ShutDown has been invoked with nHow set to 0 or 2.";
		    break;
		 case  WSAEMSGSIZE:
			 errormessage = "The datagram was too large to fit into the specified buffer and was truncated. ";
		    break;
		 case  WSAECONNABORTED:
			 errormessage = "The virtual circuit was aborted due to timeout or other failure.";
		    break;	
		 case  WSAECONNRESET:
			 errormessage = "The virtual circuit was reset by the remote side. ";
		    break;
		 case  WSAEACCES:
			 errormessage = "The requested address is a broadcast address, but the appropriate flag was not set.";
		    break;
		 case  WSAENETRESET:
			 errormessage = "The connection must be reset because the Windows Sockets implementation dropped it. ";
		    break;
		 case  WSAEOPNOTSUPP:
			 errormessage = "MSG_OOB was specified, but the socket is not of type SOCK_STREAM.";
		    break;
         default:
            TCHAR szError[256];
            wsprintf(szError, "Unknown error: %d. Closing Application", ErrorCode);
            errormessage = szError;
            break;
      }
	  
	//closeObj.OnClose();
	
	return errormessage;
	 
}
  

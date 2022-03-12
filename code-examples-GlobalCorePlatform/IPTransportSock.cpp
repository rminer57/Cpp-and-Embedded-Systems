#include "winsock2.h"
#include <iostream>
#include <fstream>

#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

class NetwrkManager;

#ifdef WIN32

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#pragma comment(lib, "Ws2_32.lib")


#else
// using gcc and minw
#include <unistd.h>     /* for close() */
#endif

//closesocket()

#include "IPTransportSock.h"

int IPTransportSock_Error;

IPTransportSock ** NetwrkManager::m_connectionArray = 0;

void IPTransportSock::DieWithError(char *errorMessage)
{
  IPTransportSock_Error = WSAGetLastError();
  
  // dont print if its this error...WSAECONNABORTED (10053) Software caused connection abort. 
  if( (IPTransportSock_Error == 10053) || (IPTransportSock_Error == 10004) )
  {
  	IPTransportSock_Error = 0; // clear it, if the socket is closed by the client then winsock throws an error, ignore these  	
  }
  else
  {
    cout << errorMessage << "Error code: " << IPTransportSock_Error << endl;
  }
  
}

/*******************************************************************************

*******************************************************************************/
IPTransportSock::IPTransportSock()
: m_clientSock(), m_hostName(0), m_remoteClientName(0),  IPconnection()
{
   m_port = 0;
   IPTransportSock_Error = 0;
   m_echo = false;
   m_ipaddr = "NOCONNECTION";
   m_conntype = NOCONNECTION;
   commonIPTransportSock();
}

/*******************************************************************************

*******************************************************************************/
IPTransportSock::IPTransportSock(int conntype, char * ipaddr, int port)
: m_clientSock(), m_hostName(0), m_remoteClientName(0),  IPconnection()
{
   m_port = port;
   m_echo = false;
   m_ipaddr = ipaddr;
   m_conntype = conntype;
   commonIPTransportSock();
}

IPTransportSock::IPTransportSock( IPconnectionConfig * config )
: m_hostName(0), m_remoteClientName(0), IPconnection()
{
   m_port = 0;
   m_echo = false;
   m_ipaddr = "NOCONNECTION";
   m_conntype = NOCONNECTION;
   commonIPTransportSock();

   if( config != 0)
   {

	 if( config->m_type == TCPCONNECTION)
	 {
	   m_conntype = TCP_CONNECTION;

       m_port = config->m_Port; 

       m_ipaddr = config->m_IPaddress;

	 }
	 if( config->m_type == UDPCONNECTION)
	 {
	   m_conntype = UDP_CONNECTION;

       m_port = config->m_Port; 

       m_ipaddr = config->m_IPaddress;

	 }
   }
}

int IPTransportSock::openConnection(void)
{
   static int status = SUCCESSFUL_RETURN;  // = PASS = 1

   
   unsigned int clntSock = 0; 
   
   if(m_alreadyConnected == false)
   {
     m_alreadyConnected = true;

     if( m_conntype == TCP_CONNECTION )
     {
      status = openTCPClient(&clntSock);

     }
     if( m_conntype == UDP_CONNECTION )
     {
      status = openUDPClient(&clntSock);

     }

   }
   return status;     
}

int IPTransportSock::connectToDevice()
{
   return connectToRemoteServer(m_ipaddr.GetCharPtr(), m_port);
}

void IPTransportSock::commonIPTransportSock(void)
{
	m_hostName = new char[HOSTCLIENTNAMEARRAYSZ];
	m_remoteClientName = new char[HOSTCLIENTNAMEARRAYSZ];
	m_alreadyConnected = false;

        for(int x = 0; x < HOSTCLIENTNAMEARRAYSZ; x++)
        {
          m_hostName[x] = 0;
          m_remoteClientName[x] = 0;          	
        }
        
        IPTransportSock_Error = 0;
        
}



/*******************************************************************************

*******************************************************************************/
IPTransportSock::~IPTransportSock(void)    
{
  delete [] m_hostName;
  delete [] m_remoteClientName;
}

/*******************************************************************************

*******************************************************************************/
int IPTransportSock::openTCPServer(unsigned short servPort) 
{

    int retval = SUCCESSFUL_RETURN;

    m_serverPort = servPort;  /* First arg:  local port */    

#ifdef _WIN32

    // The highest version of Windows Sockets specification that the caller can use. 
    // The high-order byte specifies the minor version number; the low-order byte specifies the major version number.    
    WORD wVersionRequested; // WORD is unsigned short

    WSAData wsaData;

    // A pointer to the WSADATA data structure that is to receive details of the Windows Sockets implementation.    
    LPWSADATA lpWSAData = &wsaData; // same as pointer to WSAData structure
            
    wVersionRequested = MAKEWORD(2,2); // version 2.2 is the latest winsock

    // Initialize WinSock and check the version
    if (WSAStartup( wVersionRequested, &wsaData) != 0)
    {	
	 DieWithError("WSAStartup() failed");
	 retval = FAILED_RETURN; // = FAIL = 0
     return retval;
    }

#endif    
    
    /* Create socket for incoming connections */
    if ((servSock = (unsigned int)socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        DieWithError("socket() failed");
	    retval = FAILED_RETURN; // = FAIL = 0
        return retval;
    } 
    /* Construct local address structure */
    memset(&serverAddr, 0, sizeof(serverAddr));   /* Zero out structure */
    serverAddr.sin_family = AF_INET;                /* Internet address family */
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    serverAddr.sin_port = htons(m_serverPort);      /* Local port */

    /* Bind to the local address */
    if (bind(servSock, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0)
    {
	  DieWithError("bind() failed");
	  retval = FAILED_RETURN; // = FAIL = 0
      return retval;
    }


    /* Mark the socket so it will listen for incoming connections */
    if (listen(servSock, MAXPENDING) < 0)
    {
        DieWithError("listen() failed");
	    retval = FAILED_RETURN; // = FAIL = 0
        return retval;
    }
    else
    {
	    cout << "listening for connection on server port: " << servPort; 
	    cout << endl;   
    }

    return retval;
    
}

int IPTransportSock::openUDPServer(unsigned short servPort)
{
	// code to be done...

    int retval = SUCCESSFUL_RETURN;

    m_serverPort = servPort;  /* First arg:  local port */    

    return retval;   
}

/*******************************************************************************

*******************************************************************************/
int IPTransportSock::openTCPClient(unsigned int * clntSock)
{
   int retval = SUCCESSFUL_RETURN;

#ifdef _WIN32

    // The highest version of Windows Sockets specification that the caller can use. 
    // The high-order byte specifies the minor version number; the low-order byte specifies the major version number.    
    WORD wVersionRequested; // WORD is unsigned short

    WSAData wsaData;

    // A pointer to the WSADATA data structure that is to receive details of the Windows Sockets implementation.    
    LPWSADATA lpWSAData = &wsaData; // same as pointer to WSAData structure
            
    wVersionRequested = MAKEWORD(2,2); // version 2.2 is the latest winsock

    // Initialize WinSock and check the version
    if (WSAStartup( wVersionRequested, &wsaData) != 0)
    {	
	  DieWithError("WSAStartup() failed");
	  retval = FAILED_RETURN; // = FAIL = 0
      return retval;
    }

#endif    
    
    /* Create socket for connecting client to a remote server */
    if ((m_clientSock = (unsigned int)socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        DieWithError("socket() failed");
        retval = FAILED_RETURN;
    }
    else
    {
      *clntSock = m_clientSock;

	  // setup socket for nonblocking mode
      //u_long iMode=1;
      //ioctlsocket(m_clientSock,FIONBIO,&iMode); 
    } 
    
    return retval;
}
int IPTransportSock::openUDPClient(unsigned int * clntSock)
{
   int retval = SUCCESSFUL_RETURN;

#ifdef _WIN32

    // The highest version of Windows Sockets specification that the caller can use. 
    // The high-order byte specifies the minor version number; the low-order byte specifies the major version number.    
    WORD wVersionRequested; // WORD is unsigned short

    WSAData wsaData;

    // A pointer to the WSADATA data structure that is to receive details of the Windows Sockets implementation.    
    LPWSADATA lpWSAData = &wsaData; // same as pointer to WSAData structure
            
    wVersionRequested = MAKEWORD(2,2); // version 2.2 is the latest winsock

    // Initialize WinSock and check the version
    if (WSAStartup( wVersionRequested, &wsaData) != 0)
    {	
	  DieWithError("WSAStartup() failed");
	  retval = FAILED_RETURN; // = FAIL = 0
      return retval;
    }

#endif    
    
    /* Create socket for connecting client to a remote server */
    if ((m_clientSock = (unsigned int)socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        DieWithError("socket() failed");
        retval = FAILED_RETURN;
    }
    else
    {
      *clntSock = m_clientSock;
    } 
    
    return retval;
}


/*******************************************************************************

*******************************************************************************/
int IPTransportSock::connectToRemoteServer(char * servIP, unsigned short servPort)
{
    int retval = SUCCESSFUL_RETURN;

    m_serverPort = servPort;  /* First arg:  local port */    
        
   // Construct the server address structure 
    memset(&m_remoteServerAddr, 0, sizeof(m_remoteServerAddr));     // Zero out structure 
    m_remoteServerAddr.sin_family      = AF_INET;             // Internet address family 
    m_remoteServerAddr.sin_addr.s_addr = inet_addr(servIP);   // Server IP address 
    m_remoteServerAddr.sin_port        = htons(m_serverPort); // Server port 
  
	if( m_conntype == TCP_CONNECTION )
    {
      // Establish the connection to the echo server 
      if (connect(m_clientSock, (struct sockaddr *) &m_remoteServerAddr, sizeof(m_remoteServerAddr)) < 0)
	  {
		DieWithError("connect() to remote server failed");
	    retval = FAILED_RETURN; // = FAIL = 0
	  }

	}

	return retval;
}
/*******************************************************************************

*******************************************************************************/
int IPTransportSock::listenForConnection(unsigned int * clntSock, int blocking)
{
	// find out how to undo this action
    //if(blocking == 0) fcntl(servSock,F_SETFL,0_NONBLOCK | FASYNC)
   int retval = SUCCESSFUL_RETURN;

    for (;;) /* Run forever */
    {
        /* Set the size of the in-out parameter */
        m_remoteClientAddrStructLen = sizeof(remoteClientAddr);

        /* Wait for a client to connect and save the client socket handle in user supplied pointer */
        if ((*clntSock = (unsigned int)accept(servSock, (struct sockaddr *) &remoteClientAddr, &m_remoteClientAddrStructLen)) < 0)
        {                      
            DieWithError("accept() failed");
	        retval = FAILED_RETURN; // = FAIL = 0
        }
        else
        {
          break;
        }      
        
    }
    
	return retval;
}



/*******************************************************************************

*******************************************************************************/
int IPTransportSock::waitForRxMessage(unsigned int socket, int *recvMsgSize, unsigned char * rxbuf = 0, int rxbufsize = 0)
{
      int i;
      int exit = 0;
      int retval = SUCCESSFUL_RETURN;
          
      /* Receive message from client */
      *recvMsgSize = recv(socket, m_rxBuffer, rxbufsize, 0);

      /* zero indicates end of transmission */    
 
      if (*recvMsgSize < 0)
      {
         DieWithError("recv() failed");
    	   retval = FAILED_RETURN;
         return retval;  
      }
      else if( *recvMsgSize == 0)
      {
    	    retval = FAILED_RETURN;
      }                     
      else // if(recvMsgSize > 0)
      {
 
         // copy message     
         for(i = 0; i < *recvMsgSize; i++)
         {
           if(i < rxbufsize) // be sure not to overflow dest buffer
           {
             rxbuf[i] = m_rxBuffer[i]; // make a copy for the caller
           }
         }
 
    	   //printf("\n\rIPTransportSock::waitForRxMessage:  ");
    	   //for(i = 0; i < *recvMsgSize; i++)
    	   //{ 
				    //printf("%02X ", m_rxBuffer[i]  ); 
    	   //}
	       //printf("\n\r\n\r");
	       
         if(m_echo)
         {
          /* Echo message back */
          sendMessage(socket,m_rxBuffer, *recvMsgSize);       	
         }		       
   	
      }


    return retval;    
}
/*******************************************************************************

*******************************************************************************/
int IPTransportSock::receiveData( char * buffer, int lenBuf, int * lenReceived)
{    
	return waitForRxMessage(m_clientSock, lenReceived, (unsigned char *)buffer, lenBuf);
}
/*******************************************************************************

*******************************************************************************/
char * IPTransportSock::getRemoteClientIPAddress(void)
{
  return inet_ntoa(remoteClientAddr.sin_addr);
}
/*******************************************************************************

*******************************************************************************/
char * IPTransportSock::getServerMachineName(void)
{
  gethostname(m_hostName,16); // 16 is buffersize	
  return m_hostName;
  
}
/*******************************************************************************

*******************************************************************************/
char * IPTransportSock::getRemoteClientMachineName(int clntSock)
{
    struct hostent * hp;
    size_t namelength;
	
    hp = gethostbyaddr( (char *)&remoteClientAddr.sin_addr.s_addr,    sizeof(remoteClientAddr.sin_addr.s_addr),AF_INET  );                    
    
    namelength = (int)strlen(hp->h_name);
    	
    for(unsigned int x = 0; x < namelength; x++ )
    {
    	 m_remoteClientName[x] = *(((char *)(hp->h_name)) + x);
    }
    	
  return m_remoteClientName;
}

/*******************************************************************************

*******************************************************************************/
int IPTransportSock::closeConnection(void)
{
   return IPTransportSock::close(m_clientSock);
}

/*******************************************************************************

*******************************************************************************/
int IPTransportSock::close(unsigned int socket)
{
     int retval = SUCCESSFUL_RETURN;
     
     m_alreadyConnected = false;
     
#ifdef _WIN32

#ifndef SD_BOTH
// shutdown both tx and rx
#define SD_BOTH 2
#endif

  // invoke shutdown
     shutdown(socket,SD_BOTH); // signal end of session

     closesocket(socket);
     WSACleanup();  // Cleanup Winsock        
#else
     close(socket);    /* Close client socket */
#endif
     IPTransportSock_Error = 0;
     return retval; 
}

/*******************************************************************************

*******************************************************************************/
int IPTransportSock::sendMessage(unsigned int socket, char * txmsg, int txmsgsize)
{
   int retval = SUCCESSFUL_RETURN;

   if(send(socket, txmsg, txmsgsize, 0) != txmsgsize)
   {
		  DieWithError("connect() to remote server failed");
    	retval = FAILED_RETURN;
   }
   else
   {
    	//printf("\n\rIPTransportSock::sendMessage:  ");
    	//for(unsigned int i = 0; i < txmsgsize; i++)
    	//{ 
				 //printf("%02X ", txmsg[i]  ); 
    	//}
	    //printf("\n\r\n\r");
   	
   }

   return retval; 
}

/*******************************************************************************

*******************************************************************************/
int IPTransportSock::sendData( char * buffer, int len)
{
  int status = sendMessage(m_clientSock, buffer, len);
  return status;

}
/*******************************************************************************

*******************************************************************************/
int IPTransportSock::sendData( char c)
{
  char ch = c;
  return sendMessage(m_clientSock, &ch, 1);
}


/*******************************************************************************

*******************************************************************************/

NetwrkManager::NetwrkManager()
{
  NetwrkManager::m_connectionArray = new IPTransportSock *[NETWRKCONNECTIONS_MAX];
  for(int i = 0; i < NETWRKCONNECTIONS_MAX; i++)
  {
  	NetwrkManager::m_connectionArray[i] = NULL;
  }	
}
/*******************************************************************************

*******************************************************************************/
NetwrkManager::~NetwrkManager()
{
	 delete [] NetwrkManager::m_connectionArray;
}
/*******************************************************************************

*******************************************************************************/
// connType_t  int UDP_CONN = 1, int TCP_CONN = 2 
int NetwrkManager::open( unsigned int * connhandle, connType_t connType){return 1;}
int NetwrkManager::close( unsigned int * connhandle){return 1;}
int NetwrkManager::setParams( unsigned int * connhandle, AtlasString & newparams){return 1;}
int NetwrkManager::getParams( unsigned int * connhandle, AtlasString & curparams){return 1;}
int NetwrkManager::connect( unsigned int * connhandle, char * servIP, unsigned short servPort){return 1;}
int NetwrkManager::listenForConnection( int * connhandle){return 1;}
int NetwrkManager::disconnect( unsigned int * connhandle){return 1;}
int NetwrkManager::send( unsigned int * connhandle, AtlasString & txdata){return 1;}
int NetwrkManager::send( unsigned int * connhandle, char * rxarray, int lenrecvd){return 1;}
int NetwrkManager::send( unsigned int * connhandle, char c){return 1;}
int NetwrkManager::send( unsigned int * connhandle, int txval){return 1;}
int NetwrkManager::send( unsigned int * connhandle, double & txval){return 1;}

int NetwrkManager::recv( unsigned int * connhandle, AtlasString & rxdata){return 1;}
int NetwrkManager::recv( unsigned int * connhandle, char * txarray, int txarraylen){return 1;}
int NetwrkManager::recv( unsigned int * connhandle, char * c){return 1;}
int NetwrkManager::recv( unsigned int * connhandle, int & rxval){return 1;}
int NetwrkManager::recv( unsigned int * connhandle, double & rxval){return 1;}
bool NetwrkManager::isDataAvail( int * connhandle){return 1;}
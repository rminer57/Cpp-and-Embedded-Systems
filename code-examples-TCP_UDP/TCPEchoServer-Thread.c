/*
 *   A TCP per-client thread echo server implemented using the MFC CSocket libaray
 *   Copyright (C) 2001 
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <iostream>     // For cout, cerr
#include <afxsock.h>    // For CSocket 

using namespace std;

const int MAXPENDING = 5;    // Maximum outstanding connection requests

DWORD WINAPI ThreadMain(LPVOID handle);   // Main program of a thread
void DieWithError(char* errorMessage);    // Error handling function
void HandleTCPClient(CSocket& clntSock);  // TCP client handling function

int main(int argc, char* argv[]){

  // Initialize MFC and print an error on failure
  if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0)) {
    DieWithError("Fatal Error: MFC initialization failed");
  }
  // Initialize the AfxSocket
  AfxSocketInit(NULL);

  if (argc != 2) {  // Test for correct number of arguments  
    cerr << "Usage: " << argv[0] << " <Server Port>" << endl;
    exit(1);
  }

  int echoServPort = atoi(argv[1]);  // First arg: local port
  CSocket servSock;                  // Socket descriptor for server
     
  // Create the server socket
  if (!servSock.Create(echoServPort)) {
    DieWithError("servSock.Create() failed");
  }

  // Mark the socket so it will listen for incoming connections
  if (!servSock.Listen(MAXPENDING)) {
    DieWithError("servSock.Listen() failed");
  }

  for(;;) { // Run forever
    CSocket clntSock;                // Socket descriptor for client
    SOCKADDR_IN echoClntAddr;        // Client address
    int clntLen;                     // Length of client address data structure 
   
    // Get the size of the in-out parameter
    clntLen = sizeof(echoClntAddr);

    // Wait for a client to connect
    if (!servSock.Accept(clntSock)) {
      DieWithError("servSock.Accept() failed");
    }

    // ClntSock is connected to a client!

    // Get the client's host name
    if (!clntSock.GetPeerName((SOCKADDR*)&echoClntAddr, &clntLen)) {
      DieWithError("clntSock.GetPeerName() failed");
    }

    cout << "Handling client " << inet_ntoa(echoClntAddr.sin_addr);
    
    // Detach the newly accepted socket and save
    // the SOCKET handle.
    SOCKET handle = clntSock.Detach();

    DWORD threadID;     // Thread ID from CreateThread()

    // After detaching it, it should no longer be
    // used in the context of this thread.
    if (!CreateThread(NULL, 0, ThreadMain, (LPVOID)handle, 0, &threadID)) {
      DieWithError("CreateThread() failed");
    }

    cout << " with thread " << threadID << endl;
  }

  // NOT REACHED

  return 0;
}

DWORD WINAPI ThreadMain(LPVOID handle) {
  CSocket clntSock;    // Socket descriptor for client connection
    
  // Attach the socket object to the socket handle
  // in the context of this thread.
  clntSock.Attach((SOCKET)handle);

  HandleTCPClient(clntSock);
    
  return 0;
}

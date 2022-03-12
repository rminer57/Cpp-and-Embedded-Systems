/*
 *   A TCP echo client implemented using the MFC CSocket libaray
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

const RECVBUFSIZE = 32; // Size of receive buffer

void DieWithError(char* errorMessage); // Error handling function

int main(int argc, char* argv[]) {

  // Initialize MFC and print an error on failure
  if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0)) {
    DieWithError("Fatal Error: MFC initialization failed");
  }
  // Initialize the AfxSocket
  AfxSocketInit(NULL);

  if ((argc < 3 ) || (argc > 4)) { // Test for correct number of arguments
    cerr << "Usage: " << argv[0] << "<echo server IP> <echo word> [<echo port>]\n";
    exit(1);
  }
 
  char* servIP = argv[1];          // First arg: server IP address 
  char* echoString = argv[2];      // Second arg: string to echo

  // Use given port, if any; otherwise, use 7, the well-known port
  // for the echo service 
  UINT echoServPort = (argc == 4)? atoi(argv[3]) : 7; 

  CSocket echoClient;              // Socket descriptor
        
  // Create a reliable, stream socket using TCP
  if (!echoClient.Create()) {
    DieWithError("Create() failed");
  }

  // Establish the connection to the echo server
  if (!echoClient.Connect((LPCSTR)servIP, echoServPort)) {
    DieWithError("Connect() failed");  
  }
          
  // Determine input length
  int echoStringLen = strlen(echoString);
        
  // Send the string to the server
  if (echoClient.Send(echoString, echoStringLen, 0) != echoStringLen) { 
    DieWithError("Send() sent a different number of bytes than expected");
  }

  // Receive the same string back from the echo server
  int totalBytesRcvd = 0;    
  cout << "Received: ";  // Setup to print the echoed string

  char echoBuffer[RECVBUFSIZE]; // Buffer for echo string  

  while (totalBytesRcvd < echoStringLen) {
    int bytesRcvd; // Bytes read in single Receive()   

    // Receive up to the buffer size (minus 1 to leave space
    // for a null terminator) bytes from the sender
    if ((bytesRcvd = echoClient.Receive(echoBuffer, RECVBUFSIZE - 1, 0)) <= 0) {
      DieWithError("Receive() failed or connection closed prematurely");
    }
    // Keep tally of total bytes
    totalBytesRcvd += bytesRcvd; 
    // Terminate the string
    echoBuffer[bytesRcvd] = '\0'; 
    // Print the echo buffer
    cout << echoBuffer;
  }

  cout << endl; // Print a final linefeed

  echoClient.Close(); // Close the connection

  return 0;
}

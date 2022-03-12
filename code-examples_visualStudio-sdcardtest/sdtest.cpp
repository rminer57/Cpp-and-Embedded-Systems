// sdtest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

bool commandHandled = false;
unsigned char hexByte = 0;
unsigned int numOfLoops = 1;
unsigned int loop,yy;
unsigned long blockCounter = 0;
unsigned long blockSize = 512;
unsigned long blockCount = 3;
unsigned long startingBlock = 0;
int i, x;

char * buffer = 0;
char textBuf[100];
bool writeOnly = false;
bool forever = false;
unsigned int blockMatches = 0;
bool blockMatch = false;
double errorPercentage = 0;
unsigned int returnCode = 0;
unsigned int bufSize=0;
bool passed = true;

typedef unsigned short int uint16_t;
typedef unsigned long int uint32_t;
char * destData;
int firstAddr;
int lastAddr;
char c; 

char sdDevice[ 51200 ]; // 100 blocks



void printArray(char * p,char * array)
{
  printf("\r\n%s ",p);

  for( int q = 0; q < 16; q++)
  {
    printf(" %x",array[q]);
  }

  printf("\r\n\r\n");
}


unsigned int readBlock(unsigned long blockCount, unsigned long startBlock, void * dataPtr)
{
   destData = (char *)dataPtr;
   firstAddr = startBlock * 512;
   lastAddr =  (blockCount * 512) - 1;

   for( yy = firstAddr; yy <= lastAddr; yy++)
   {
     *(destData) = sdDevice[yy];
     c = *destData++;
   }

   return 1;
}

unsigned int writeBlock(unsigned long blockCount, unsigned long startBlock, void * dataPtr)
{
   destData = (char *)dataPtr;
   firstAddr = startBlock * 512;
   lastAddr =  firstAddr + 511;

   for( yy = firstAddr; yy <= lastAddr; yy++)
   {
     sdDevice[yy] = *(destData);
     c = *destData++;
   }

   return 1;
}

void myfunc()
{
	    // try to open the card.
	    //if ( g_sdCard->openDevice(NULL) == g_sdCard->PS_SUCCESS )
		//{
		    // get card parameters
		    //if (g_sdCard->getInfo(&blockSize, &blockCount, &writeOnly) == g_sdCard->PS_SUCCESS)
			//{

               //int partSizeInGb = (blockSize * blockCount) / 1000000000;
               //sprintf ( textBuf, "\r\nBlockSize:%D bytes NumOfBlocks:%D PartSize:%D Gbytes \r\n",blockSize, blockCount, partSizeInGb );
               //printf(textBuf); 
		       //unsigned long blockCount = blockCount;
			   char AsciiData = 'A';  // starts with uppercase A

               //if( commandBuf->getParamHexIntAnyLen(3,&startingBlock,0) == false)
 		       //if(commandBuf->getParmHexInt(3, &startingBlock) == false)
			   //{
				  startingBlock = 0;  // use value of one if user didn't enter
				  sprintf ( textBuf, "\r\nNo startblock entered, using 0\r\n" );
                  printf(textBuf);
			   //}

               //if( commandBuf->getParamHexIntAnyLen(4,&blockCount,0) == false)
		       //if(commandBuf->getParmHexInt(4, &blockCount) == false)
			   //{
				  sprintf ( textBuf, "\r\nNumOfBlocks to test not entered, using size of :%i\r\n",blockCount );
				  printf(textBuf);
			   //}

			   char * txbuffer = new char[blockSize + 1]; // blockSize expected is 512
			   char * rxbuffer = new char[blockSize + 1];
			       
			   sprintf ( textBuf, "\n\rstartingBlock:%X blockCount:%X\r\n",startingBlock,blockCount);
               printf(textBuf);

               // **************************************************
               // now loop through the blocks and test each of them
               // **************************************************
			   for(i=startingBlock; i <= blockCount; i++)
			   {
				  // clear the receive buffer to guarantee data is always fresh
				  for(x=0; x < blockSize; x++) rxbuffer[x] = '\0';

 				  AsciiData = 'A'; // loop write value

                  // initialize the tx buffer
			      for (x=0; x < blockSize; x++)
			      {
				     txbuffer[x] = AsciiData++;

                     if( AsciiData > 'Z') AsciiData = 'A';  
			      }

				  txbuffer[blockSize] = '\0'; // terminate with null for easy readback

			      sprintf ( textBuf, "\r\n    Block:%X Writing data...",i );
                  printf(textBuf);

                                           // numBlocks, startBlock, buffer
			      if ( writeBlock(1, i, txbuffer) != 1)
			      {
					sprintf ( textBuf, "\n\rErr: sblast:sd:TESTBLOCK call to LogicalBlockDevice::writeBlock %i returned failure code.  Verify card is present.\r\n",i);
                    printf(textBuf);
					break;

			      }
			      else // write worked so read it back
			      {
				  	sprintf ( textBuf,"Done!  Reading...");
                    printf(textBuf);

                                           // numBlks,start, buffer
			        if( readBlock(1, i, rxbuffer) != 1)
					{
					   sprintf ( textBuf, "\n\rErr: sblast:sd:TESTBLOCK call to LogicalBlockDevice::readBlock %i returned failure code.  Verify card is present.\r\n",i );
                       printf(textBuf);
					   break;
					}
					else
					{

				  	   sprintf ( textBuf, "Done!  Comparing....");
                       printf(textBuf);

					   // compare read buffer to write buffer					   
                       for(x=0; x < blockSize; x++)
					   {
					     
                          if(txbuffer[x] != rxbuffer[x])
						  {
                            passed = false;
							break;
						  }

					   }

					   if(passed == true)
					   {
                            printf(" passed!\n\r");
					   }
					   else
					   {
                            printf(" FAILED! \n\r\n\r");

							printArray("txbuffer:",txbuffer);
							printArray("rxbuffer:",rxbuffer);
							printArray("sdDevice:",sdDevice);
                            printf("\n\r\n\r");
							break;
					   }
					}

			      }

			   }  // end of main test for loop

			   delete []txbuffer;
			   delete []rxbuffer;

            //}
			//else
			//{
              //printf("getInfo failed to read device parameters.  Verify card is present.\r\n");
			//}
		//}
		//else
		//{
			//rDebugger->rdOutputText("Failed to open device access. Verify card is present.\r\n");
		//}
		//commandHandled = true;

}


//rDebugger->rdOutputText
int main(int argc, char* argv[])
{
    //for(int dd = 0; dd < 51200; dd++)  sdDevice[ dd ] = 0;

    //cout << "starting test" << endl;

	//myfunc();


printf("********* SD/MMC card command help ********* \r\n\r\n");
printf("CLOSE - closes card access\r\n");
printf("    Eg. sblast:sd:close \n\r\n\r");

printf("DISPLAYBLOCK:startBlockInHex:endBlockInHex\r\n");
printf("    Eg. sblast:sd:displayblock:0:5n\r");
printf("    Eg. sblast:sd:displayblock:F008:F00B\n\r\n\r");

printf("ERASE:blockNumInHex   erases specified block or whole card if block number is omitted\r\n");
printf("    Eg. sblast:sd:eraseblock:F\\n\r");
printf("    Eg. sblast:sd:eraseblock\n\r\n\r");

printf("GETINFO - displays block size in bytes and number of blocks\r\n");
printf("    Eg. sblast:sd:getinfo \n\r\n\r");

printf("HELP\r\n");
printf("    Eg. sblast:sd:help\n\r\n\r");

printf("LOOP:numOfIterations:blockNumInHex   - performs read/write random data test\r\n");
printf("    Eg. sblast:sd:loop:FOREVER:blockNumInHex\n\r\n\r");
printf("    Eg. sblast:sd:loop:FOREVER:blockNumInHex\n\r\n\r");
printf("    Eg. sblast:sd:loop:FOREVER:blockNumInHex\n\r\n\r");

printf("OFF  - powers down the card\r\n");
printf("    Eg. sblast:sd:off \n\r\n\r");

printf("OPEN - opens (initializes) card for use\r\n");
printf("    Eg. sblast:sd:open \n\r\n\r");

printf("READ:blockNumInHex\r\n");
printf("    Eg. sblast:sd:read:0\n\r");
printf("    Eg. sblast:sd:read:F0AB\n\r\n\r");

printf("TESTBLOCK:startBlockInHex:endBlockInHex\r\n");
printf("    Eg. sblast:sd:testblock:0:5n\r");
printf("    Eg. sblast:sd:testblock:F008:F00B\n\r\n\r");

printf("WRITE:string:blockNumInHex\r\n");
printf("    Eg. sblast:sd:write:hello world:5 \n\r\n\r");


printf("\r\n\r\n");


	//cout << " test done " << endl;
	return 0;
}





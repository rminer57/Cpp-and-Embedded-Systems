#define NUMofRFStates 1
#define RxState 0
#define TxState 1
#define RxSeqID 0
#define TxSeqID 1
#define NUMofSequences 2
#define NUMofComponents 1
#define FRACN_NUMOF_REGISTERS 32
#define UINT8 unsigned char
#define UINT16 unsigned short int
#define UINT32 unsigned int
#define Integer int

// declare forward references so file will compile without
// requiring header files, using visual studio. The class
// can then be moved to Rose RT.

class fractionalNdefault;
class fractionalN;
class sequencer;
class sequencerComponent;
class rfSpiBuffer;
class rfSpiManager;
class IOVirtualSerial;
class sequencerTimer;

UINT32 RxStateImageArray[] = { 0 };
UINT32 TxStateImageArray[] = { 0 };

UINT16 changeToRxStateSequence[] = { 0x0000 };
UINT16 changeToTxStateSequence[] = { 0x0000 };

class fracNSeqTest
{
   public:
           fracNSeqTest(IOVirtualSerial * IOVirtualSerialDevice, sequencerTimer * timer); // constructor
           void execute( unsigned int sequenceID ); // method to execute the test
   private:
           IOVirtualSerial * IOSerialDevice;
   
           // pointer to an array of spiBuffers.
           // the spiBuffer array contains the fracN register
           // images, one per rfState. Each spiBuffer object holds 
           // one default rfState image. The spiBuffer array is initialized
           // and spiBuffers created, by the fractionalNDefault constructor,
           // using the default data passed into the constructor.
           // This example code supports two rfstates: Tx and Rx.
           rfSpiBuffer * * spiBuffers;
           
           // The spiManager is the class used by the fracN
           // class to manage the spiBuffers.
           rfSpiManager * fracNSpiManager;
           
           // fractionalNDefault class is used to hold all the initial data
           // including default register images, required to setup the 
           // fractionalN IC object.   
           fractionalNDefault fracNDefDataObj;
           
           // fractionalNDefault constructor arguments
        
           UINT32 * fracNTemperatureData;
           
           UINT32 * * defaultFractImages;
           
           UINT32 * clockCtrl;
           
           Integer oscilSensitivity;
           
           Integer voltMode;
           
           //fractionalN IC class (driver)
           fractionalN fracN_IC;
           
           // sequencer class
           sequence    theSequencer;

           // array of component pointers           
           sequencerComponent ** components;
           
           sequencerTimer * timerPtr;
           
           UINT16 ** sequencePointersArray;
         
};

fracNSeqTest::fracNSeqTest( IOVirtualSerial * IOVirtualSerialDevice, sequencerTimer * timer )
{
    IOSerialDevice = IOVirtualSerialDevice;
    
    timerPtr = timer;
    
    components = new sequencerComponent * [NUMofComponents];
    
    // temperature compensation data array
    fracNTemperatureData = new UINT32[1];
   
    // default register image arrays, one per each rf state; 
    defaultFractImages = new UINT32 *[ NUMofRFStates ];
    
    defaultFractImages[RxState] = RxStateImageArray;
    
    defaultFractImages[TxState] = TxStateImageArray;
        
    clockCtrl = new UINT32[1];
    
    fracNSpiManager = new rfSpiManager( NUMofRFStates, FRACN_NUMOF_REGISTERS, IOSerialDevice );
    
    spiBuffers = fracNSpiManager ->getSpiBuffers();

    fracNDefDataObj = new fractionalNDefault( fracNTemperatureData, defaultFractImages, clockCtrl, oscilSensitivity, voltMode );

    fractionalN( fracNDefDataObj, spiBuffers, NUMofRFStates );
    
    //
	sequencePointersArray = new UINT16 * [ NUMofSequences ];
    sequencePointersArray[RxSeqID] = changeToRxStateSequence;
    sequencePointersArray[TxSeqID] = changeToTxStateSequence;
    
    theSequencer = new sequencer( (UINT16 *) sequencePointersArray, components, timerPtr );
		
}

fracNSeqTest::execute( unsigned int sequenceID )
{	
   theSequencer->executeSequence( unsigned int sequenceID );
}
#include <iostream.h>
#include <fstream.h>

#include <string.h>
#include <windows.h>

int assemble(istream &in,ostream &out,ostream &log);

//Test routine
int main(int argc, char * argv[])
{
	char *dest;
	char *logFile;
	ifstream file;
	ofstream outFile,log;
	int ret;

    //determine action based on parameters
    switch (argc)
    {
    case 2:
		dest = createName(argv[1],".bin");						//Default ext.
        break;

    case 3:
		dest = argv[2];
        break;

    default:
        cout << "Please supply: Input [output]" << endl;
		return 0;
    }
/*=====>>>*/
	//Open file, get data and assemble
	logFile = createName(argv[1],".map");						//Log file name

	file.open(argv[1]);
	outFile.open(dest,ios::binary | ios::out);					//Open file
	log.open(logFile);											//Open log
 
	log << "Assembling: " << argv[1] << "..." << endl;
	ret = assemble(file,outFile,log);

	//Close streams
	outFile.close();
	file.close();
	log.close();

	return ret;
}


//include the standard header for I/O.  
#include <iostream>
//include the standard header to work with files.  
#include <fstream>
//include the C++17 header for FS operations.  
#include <filesystem>
//include the file we're dealing with.  
#include "FileTrunc.h"
//main function.  
int main(int argc, char* argv[])
{
	//set the current working dir to the dir of the executable using our function and argv[0].  
	std::filesystem::current_path(melsbackslib::FileTrunc(argv[0]));
	//create and open a file named TEST.txt.
	std::cout << "creating " << melsbackslib::FileTrunc(argv[0]) << "/TEST.txt...\n";  
	std::ofstream TESTFILE("TEST.txt");
	//Add text to the file.  
	TESTFILE << "This file will always be in the same dir as the program.  ";
	//close the file
	std::cout << "File made!\n";
	TESTFILE.close();
	//tell the OS that the program executed successfully.  
	return 0;
}

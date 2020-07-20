#include "ini.h"
#include <iostream>

int main(int argc, char* argv[])
{
    melsbackslib::inifile testfile;
    testfile.addgroup("test.ini", "test3");
    testfile.addval("test.ini", "test3", "test", "Melsbackslib is fun!");
    std::cout << testfile.getval("test.ini", "test3", "test") << std::endl;
}
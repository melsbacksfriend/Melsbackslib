#include "ini.h"
#include <iostream>

int main(int argc, char* argv[])
{
    melsbackslib::inifile testfile;
    std::cout << testfile.getval("test.ini", "test", "test") << std::endl;
    std::cout << testfile.getval("test.ini", "test", "test2") << std::endl;
    std::cout << testfile.getval("test.ini", "test2", "test") << std::endl;
    std::cout << testfile.getval("test.ini", "test2", "test2") << std::endl;
}
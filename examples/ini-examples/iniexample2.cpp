#include "ini.h"
#include <iostream>

int main(int argc, char* argv[])
{
    melsbackslib::inifile testfile;
    testfile.setval("test.ini", "test", "test", "C++ rocks!");
}
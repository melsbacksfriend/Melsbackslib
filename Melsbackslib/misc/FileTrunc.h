#ifndef FILETRUNC_H
#define FILETRUNC_H

#include <string>
#include <cstddef>

namespace melsbackslib
{
    std::string FileTrunc(char* cstrin)
    {
        std::string cppstrin = cstrin;
        std::size_t found = cppstrin.rfind('/');
        if (found != std::string::npos)
        {
            cppstrin.erase(cppstrin.begin()+found, cppstrin.end());
        }
        return cppstrin;
    }
}

#endif // FILETRUNC_H

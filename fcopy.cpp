#include <iostream>
#include <fstream>

#include "fcopy.h"

void fileCopy(const std::string& srcFilename, const std::string& dstFilename)
{
    char buffer[4096];

    std::ifstream src(srcFilename, std::ios::in | std::ios::binary);
    if(!src) InputFileOpeningError();

    std::ofstream dst(dstFilename, std::ios::out | std::ios::binary);
    if(!dst) OutputFileOpeningError();

    while(src)
    {
        src.read(buffer, sizeof buffer);

        dst.write(buffer, src.gcount());
    }

    src.close();
    dst.close();
}

void InputFileOpeningError()
{
    throw std::runtime_error("could not open src file");
}

void OutputFileOpeningError()
{
    throw std::runtime_error("could not open dst file");
}
// file.hpp

#pragma once 

#include <fstream>
#include <string_view>
#include <string>
#include <stdexcept>

namespace file {

    enum class Mode {Read, Write, Append};
    
    inline std::fstream open(const std::string_view& path, Mode mode)
    {
        std::ios_base::openmode openmode = std::ios::binary;
        switch (mode)
        {
        case Mode::Read:
            openmode |= std::ios::in;
            break;
        case Mode::Write:
            openmode |= std::ios::out | std::ios::trunc;
            break;
        case Mode::Append:
            openmode |= std::ios::out | std::ios::app;
            break;
        default:
            break;
        }
        
        std::fstream file (path.data(), openmode);

        if (!file.is_open())
        {
            throw std::runtime_error("\nFailed to open file: " + std::string(path));
        }

        return file;
    }
}
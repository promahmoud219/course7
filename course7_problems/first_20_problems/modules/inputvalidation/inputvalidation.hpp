// inputvalidation.hpp

#pragma once

#include <string>

namespace inputvalidation {

    int ReadNumber (std::string message);
    int ReadNumberInRange (std::string message, int min, int max);
    char ReadYesNo (const std::string& message);
    std::string ReadString(const std::string& prompt);
    int ReadPositiveNumber(const std::string& prompt);
    bool AskYesNo(const std::string& prompt);
}

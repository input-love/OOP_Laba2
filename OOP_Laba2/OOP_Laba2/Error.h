#pragma once
#include <string>

class Error {
public:
    Error(const std::string& value);
    std::string what() const;

private:
    std::string _data;

};

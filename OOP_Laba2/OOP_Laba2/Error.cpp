#include "Error.h"

Error::Error(const std::string& value) : _data(value) {}

std::string Error::what() const {
    return _data;
}
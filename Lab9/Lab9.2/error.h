
#pragma once
#include <exception>

class error : public std::exception {
public:
    const char* what() const noexcept override {
        return "An error has occurred.";
    }
};

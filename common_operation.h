#pragma once

#ifndef COMMON_OPERATION_H
#define COMMON_OPERATION_H

#include <string>

class CommonOperation {
 public:
    virtual void operation(std::string &data) = 0;
    virtual ~CommonOperation() {}
};

class Entrance : public CommonOperation {
 public:
    void operation(std::string &data) override;
};

class CreatingNewAccount : public CommonOperation {
 public:
    void operation(std::string &data) override;
};

#endif // COMMON_OPERATION_H

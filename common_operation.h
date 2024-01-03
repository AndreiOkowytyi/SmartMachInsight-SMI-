#pragma once

#ifndef COMMON_OPERATION_H
#define COMMON_OPERATION_H

#include <string>

#include "ui_window_registreation.h"

class CommonOperation {
 public:
    virtual void operation(std::string &data) = 0;
    virtual ~CommonOperation() {}

    void setWindowRegistration(Ui_WindowRegistration *p_winRegistration);

protected:
     Ui_WindowRegistration* p_windowRegistration = nullptr;
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

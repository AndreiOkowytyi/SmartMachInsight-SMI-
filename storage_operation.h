
#ifndef STORAGE_OPERATION_H
#define STORAGE_OPERATION_H

#include <string>

#include "ui_working_window.h"

class StorageOperation {
 public:
    virtual void operation(std::string &data) = 0;
    virtual ~StorageOperation() {}

    void setWorkingWindow(Ui_WorkingWindow *p_worWindow);

 protected:
     Ui_WorkingWindow *p_workingWindow = nullptr;
};

class DataRequest : public StorageOperation {
public:
    void operation(std::string &data) override;
};

#endif // STORAGE_OPERATION_H

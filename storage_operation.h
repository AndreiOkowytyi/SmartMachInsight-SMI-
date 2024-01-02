
#ifndef STORAGE_OPERATION_H
#define STORAGE_OPERATION_H

#include <string>

class StorageOperation {
 public:
    virtual void operation(std::string &data) = 0;
    virtual ~StorageOperation() {}
};

class DataRequest : public StorageOperation {
public:
    void operation(std::string &data) override;
};

#endif // STORAGE_OPERATION_H

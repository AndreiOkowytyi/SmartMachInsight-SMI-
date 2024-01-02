#pragma once

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <vector>
#include <memory>

#include "common_operation.h"
#include "storage_operation.h"

class InterfaceOperations {
 public:
    virtual void operation(std::string &data, const short index) = 0;
    virtual ~InterfaceOperations() {}
};

class InterfaceCommonOperation : public InterfaceOperations {
public:
    InterfaceCommonOperation();
    void operation(std::string &data, const short index) override;

private:
    std::vector<std::unique_ptr<CommonOperation>>m_v_CommonOperation;
};

class InterfaceStorageOperation : public InterfaceOperations {
 public:
    InterfaceStorageOperation();
    void operation(std::string &data, const short index) override;

 private:
    std::vector<std::unique_ptr<StorageOperation>> m_v_StorageOperation;
};


class Operations {
 public:
    Operations();

    void operation(std::vector<std::string>& v_data);

 private:
    std::vector<std::unique_ptr<InterfaceOperations>> m_v_InterfaceOperations;
};


#endif // OPERATIONS_H

#include "operations.h"
#include "communication_protocol.h"

InterfaceCommonOperation:: InterfaceCommonOperation() {

    this->m_v_CommonOperation.push_back(std::make_unique<Entrance>());
    this->m_v_CommonOperation.push_back(std::make_unique<CreatingNewAccount>());
}

void InterfaceCommonOperation::operation(std::string &data, const short index) {

    this->m_v_CommonOperation.at(index)->operation(data);
}

/*
BLOCK
*/

InterfaceStorageOperation::InterfaceStorageOperation() {

    this->m_v_StorageOperation.push_back(std::make_unique<DataRequest>());
}

void InterfaceStorageOperation::operation(std::string &data, const short index) {

    this->m_v_StorageOperation.at(index)->operation(data);
}

/*
BLOCK
*/

Operations::Operations() {

    this->m_v_InterfaceOperations.push_back(std::make_unique<InterfaceCommonOperation>());
    this->m_v_InterfaceOperations.push_back(std::make_unique<InterfaceStorageOperation>());
}

void Operations::operation(std::vector<std::string>& v_data) {

    this->m_v_InterfaceOperations.at(std::stoi(v_data[static_cast<int>

                 (IndexWorkingWithDataComingFromServer::Department)]))->operation(v_data

                            [static_cast<int>(IndexWorkingWithDataComingFromServer::DataComingFromServer)],

                                                    static_cast<int>(IndexWorkingWithDataComingFromServer::Operations));
}

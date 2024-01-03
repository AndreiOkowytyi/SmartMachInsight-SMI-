#include "operations.h"
#include "communication_protocol.h"

InterfaceCommonOperation:: InterfaceCommonOperation() {

    this->m_v_CommonOperation.push_back(std::make_unique<Entrance>());
    this->m_v_CommonOperation.push_back(std::make_unique<CreatingNewAccount>());
}

void InterfaceCommonOperation::operation(std::string &data, const short index) {

    this->m_v_CommonOperation.at(index)->operation(data);
}

void InterfaceCommonOperation::setWindowRegistration(Ui_WindowRegistration *p_winReg) {

    this->m_v_CommonOperation.at(0)->setWindowRegistration(p_winReg);
    this->m_v_CommonOperation.at(1)->setWindowRegistration(p_winReg);
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

void InterfaceStorageOperation::setWorkingWindow(Ui_WorkingWindow *p_workWin) {

    this->m_v_StorageOperation.at(0)->setWorkingWindow(p_workWin);
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

void Operations::setOperationsWindowRegistration(Ui_WindowRegistration *p_winReg) {

    InterfaceCommonOperation *p_commonOperation = dynamic_cast<InterfaceCommonOperation*>(this->m_v_InterfaceOperations.at(0).get());
    if(p_commonOperation != nullptr)p_commonOperation->setWindowRegistration(p_winReg);
}

void Operations::setOperationsWorkingWindow(Ui_WorkingWindow *p_workWin) {

    InterfaceStorageOperation *p_storageOperation = dynamic_cast<InterfaceStorageOperation*>(this->m_v_InterfaceOperations.at(1).get());
    if(p_storageOperation != nullptr) p_storageOperation->setWorkingWindow(p_workWin);
}

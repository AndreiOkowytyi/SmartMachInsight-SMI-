#pragma once

#ifndef COMMUNICATIONPROTOCOL_H
#define COMMUNICATIONPROTOCOL_H

#include <string>
#include <vector>

#define START "START_OF_DATA" // Маркер початку данних.
#define END   "END_OF_DATA"   // Маркер кінець данних.

/*
Індексація, по которій буде відбуватися
робота с данними що надійшли від серверу.
*/

enum class IndexWorkingWithDataComingFromServer {

    Department,          // Індекс відділу           - 0.
    Operations,          // Індекс операції          - 1.
    DataType,            // Індекс типу данних       - 2.
    DataComingFromServer // Індекс данних що прийшли - 3.
};


enum class ReadWrite {

    Read, // Індекс 0 - читання.
    Write // Індекс 1 - запис.
};

/*
Тип данних які відправляються до серверу,
та тип данних які прийшли від серверу.
*/
enum class DataType {

    Text,
    JPG,
    DLL
};


enum class ListOfOperations { // Індекс для операцій що здійснюються на сервері.

    Entrance           // Операція входу.
};

/*
Группа індексів які необхідні для правильного розуміння
зі сторони серверу який запит йому зробити до бази данних.
*/

enum class ImplementingRequestToTheServer {

    CheckingAccountAndClientVersion // Перевірка аккаунту, та версії клієнту.
};


class CommunicationProtocol {
 public:
    // Підготовка до відправки данних до серверу.
    std::string sendingMessages(std::string &users, ListOfOperations operations,
                                 ReadWrite readWrite, ImplementingRequestToTheServer request, DataType type, std::string data);

    std::vector<std::string> receivingMessages(std::string &s_message); // Підготовка данних для читання що получені від серверу.
};

#endif // COMMUNICATIONPROTOCOL_H

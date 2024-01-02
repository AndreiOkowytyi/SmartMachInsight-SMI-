#include "communication_protocol.h"

std::string CommunicationProtocol::sendingMessages(std::string &users, ListOfOperations operations,
					   ReadWrite readWrite, ImplementingRequestToTheServer request,DataType type, 
	                                                                             std::string data) {

	std::string m_sendingMessages = users;

	m_sendingMessages += '/' + std::to_string(static_cast<int>(operations)) + '/' + 
		std::to_string(static_cast<int>(readWrite)) + '/' + std::to_string(static_cast<int>(request))
		        +'/' + std::to_string(static_cast<int>(type)) + '/' + START + '/' + data + '/' + END + '/';

	return m_sendingMessages;
}

std::vector<std::string> CommunicationProtocol::receivingMessages(std::string &s_message) {

	std::vector<std::string> v_dataCommmingToServer;

	std::string temp;

	for (size_t x = 0; x < s_message.size(); ++x) {
	
		if (s_message[x] != '/') temp += s_message[x];
		else {

			if(temp != START && temp != END) v_dataCommmingToServer.push_back(temp);

			temp.clear();
		}
	}
	return v_dataCommmingToServer;
}

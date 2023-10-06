#include "EthernetPacket.h"
#include <stdexcept>
#include "iostream"

using namespace std;

const int PACKET_MIN_LENGTH = 52;
const int CRC_LENGTH = 8;
const int DESTINATION_ADDRESS_START = 16;
const int DESTINATION_ADDRESS_LENGTH = 12;
const int SOURCE_ADDRESS_START = 28;
const int SOURCE_ADDRESS_LENGTH = 12;
const int TYPE_START = 40;
const int TYPE_LENGTH = 4;

EthernetPacket::EthernetPacket(const string& packetData) {

    if (packetData.length() < PACKET_MIN_LENGTH) {
        throw std::runtime_error("Invalid packetData: Insufficient length");
    }
    this->packetData = packetData;

    processPacketData();
}

void EthernetPacket::processPacketData() {
    crc = extractCrcFromData();
    destinationAddress = extractDestinationAddressFromData();
    sourceAddress = extractSourceAddressFromData();
    packetType = extractTypeFromData();
}

string EthernetPacket::extractCrcFromData() const {
    return packetData.substr(packetData.length() - CRC_LENGTH);
}

string EthernetPacket::extractDestinationAddressFromData() const {
    return packetData.substr(DESTINATION_ADDRESS_START, DESTINATION_ADDRESS_LENGTH);
}

string EthernetPacket::extractSourceAddressFromData() const {
    return packetData.substr(SOURCE_ADDRESS_START, SOURCE_ADDRESS_LENGTH);
}

string EthernetPacket::extractTypeFromData() const {
    return packetData.substr(TYPE_START, TYPE_LENGTH);
}

ostream &operator<<(ostream &outStream, EthernetPacket const &ethernetPacket) {
    return ethernetPacket.stringifyPacketData(outStream);
}

ostream &EthernetPacket::stringifyPacketData(ostream &outStream) const {
    outStream << packetData << endl;
    outStream << "CRC: " << crc << endl;
    outStream << "Destination Address: " << destinationAddress << endl;
    outStream << "Source Address: " << sourceAddress << endl;
    outStream << "Type: " << packetType << endl;
    return outStream;
}


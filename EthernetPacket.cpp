#include "EthernetPacket.h"
#include <stdexcept>
#include "iostream"

using namespace std;

EthernetPacket::EthernetPacket(const string packetData) {

    if (packetData.length() < 52) {
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

const string EthernetPacket::extractCrcFromData() const {
    return packetData.substr(packetData.length() - 8);
}

const string EthernetPacket::extractDestinationAddressFromData() const {
    return packetData.substr(16, 12);
}

const string EthernetPacket::extractSourceAddressFromData() const {
    return packetData.substr(28, 12);
}

const string EthernetPacket::extractTypeFromData() const {
    return packetData.substr(40, 4);
}

ostream &operator<<(ostream &outStream, EthernetPacket const &obj) {
    return obj.stringifyPacketData(outStream);
}

ostream &EthernetPacket::stringifyPacketData(ostream &outStream) const {
    outStream << packetData << endl;
    outStream << "CRC: " << crc << endl;
    outStream << "Destination Address: " << destinationAddress << endl;
    outStream << "Source Address: " << sourceAddress << endl;
    outStream << "Type: " << packetType << endl;
    return outStream;
}


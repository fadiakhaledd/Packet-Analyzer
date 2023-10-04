#include "EthernetPacket.h"
#include <stdexcept>
#include "iostream"

using namespace std;

EthernetPacket::EthernetPacket(const string packetData) {

    if (packetData.length() < 52) {
        throw std::runtime_error("Invalid packetData: Insufficient length");
    }
    this->packetData = packetData;
    this->crc = packetData.substr(packetData.length() - 8);
    this->destinationAddress = packetData.substr(16, 12);
    this->sourceAddress = packetData.substr(28, 12);
    this->packetType = packetData.substr(40, 4);

    processPacketData();
}

const std::string &EthernetPacket::getPacketData() const {
    return packetData;
}

void EthernetPacket::setPacketData(const std::string &packetData) {
    this->packetData = packetData;
}

const std::string &EthernetPacket::getDestinationAddress() const {
    return destinationAddress;
}

void EthernetPacket::setDestinationAddress(const std::string &destinationAddress) {
    this->destinationAddress = destinationAddress;
}

const std::string &EthernetPacket::getSourceAddress() const {
    return sourceAddress;
}

void EthernetPacket::setSourceAddress(const std::string &sourceAddress) {
    this->sourceAddress = sourceAddress;
}

const std::string &EthernetPacket::getCrc() const {
    return crc;
}

void EthernetPacket::setCrc(const std::string &crc) {
    this->crc = crc;
}

const std::string &EthernetPacket::getPacketType() const {
    return packetType;
}

void EthernetPacket::setPacketType(const std::string &packetType) {
    this->packetType = packetType;
}

std::string EthernetPacket::getPacketInfo() const {
    std::stringstream stringStream;
    stringStream << "CRC: " << crc << "\n";
    stringStream << "Destination Address: " << destinationAddress << "\n";
    stringStream << "Source Address: " << sourceAddress << "\n";
    stringStream << "Type: " << packetType << "\n";
    return stringStream.str();
}

void EthernetPacket::processPacketData() {

    return;
}

std::ostream &operator<<(ostream &os,  EthernetPacket const &obj) {
    return obj.stringfyPacketData(os);
}

ostream &EthernetPacket::stringfyPacketData(ostream &os) const {
    os << packetData << endl;
    os << "CRC: " << crc << endl;
    os << "Destination Address: " << destinationAddress << endl;
    os << "Source Address: " << sourceAddress << endl;
    os << "Type: " << packetType << endl;
    return os;
}


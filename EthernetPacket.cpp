#include "EthernetPacket.h"
#include <stdexcept>  

EthernetPacket::EthernetPacket(const std::string& packetData) {
    if (packetData.length() < 52) {
        throw std::runtime_error("Invalid packetData: Insufficient length");
    }
    this->packetData = packetData;
    this->crc = packetData.substr(packetData.length() - 8);
    this->destinationAddress = packetData.substr(16, 12);
    this->sourceAddress = packetData.substr(28, 12);
    this->packetType = packetData.substr(40, 4);
}

const std::string& EthernetPacket::getPacketData() const {
    return packetData;
}

void EthernetPacket::setPacketData(const std::string& packetData) {
    this->packetData = packetData;
}

const std::string& EthernetPacket::getDestinationAddress() const {
    return destinationAddress;
}

void EthernetPacket::setDestinationAddress(const std::string& destinationAddress) {
    this->destinationAddress = destinationAddress;
}

const std::string& EthernetPacket::getSourceAddress() const {
    return sourceAddress;
}

void EthernetPacket::setSourceAddress(const std::string& sourceAddress) {
    this->sourceAddress = sourceAddress;
}

const std::string& EthernetPacket::getCrc() const {
    return crc;
}

void EthernetPacket::setCrc(const std::string& crc) {
    this->crc = crc;
}

const std::string& EthernetPacket::getPacketType() const {
    return packetType;
}

void EthernetPacket::setPacketType(const std::string& packetType) {
    this->packetType = packetType;
}

std::string EthernetPacket::getPacketInfo() const {
    std::stringstream ss;
    ss << "CRC: " << crc << "\n";
    ss << "Destination Address: " << destinationAddress << "\n";
    ss << "Source Address: " << sourceAddress << "\n";
    ss << "Type: " << packetType << "\n";
    return ss.str();
}

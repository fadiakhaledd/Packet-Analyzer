#include "EthernetPacket.h"

using namespace std;

const string &EthernetPacket::getPacketData() const {
    return packetData;
}

void EthernetPacket::setPacketData(const string &packetData) {
    EthernetPacket::packetData = packetData;
}

const string &EthernetPacket::getDestinationAddress() const {
    return destinationAddress;
}

void EthernetPacket::setDestinationAddress(const string &destinationAddress) {
    EthernetPacket::destinationAddress = destinationAddress;
}

const string &EthernetPacket::getCrc() const {
    return crc;
}

void EthernetPacket::setCrc(const string &crc) {
    EthernetPacket::crc = crc;
}

const string &EthernetPacket::getPacketType() const {
    return packetType;
}

void EthernetPacket::setPacketType(const string &packetType) {
    EthernetPacket::packetType = packetType;
}

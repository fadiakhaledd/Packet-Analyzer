//
// Created by Fadia khaled on 05/10/2023.
//

#include "PacketFactory.h"
#include "EthernetPacket.h"
#include "EcpriPacket.h"

const int PACKET_TYPE_START = 40;
const int PACKET_TYPE_LENGTH = 4;

EthernetPacket *PacketFactory::getPackedBasedOnType(string const &packetData) {
    string packetType = packetData.substr(PACKET_TYPE_START, PACKET_TYPE_LENGTH);

    if (packetType == "AEFE") {
        return new EcpriPacket(packetData);
    } else {
        return new EthernetPacket(packetData);
    }

}

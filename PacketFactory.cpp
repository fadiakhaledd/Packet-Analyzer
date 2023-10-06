#include "PacketFactory.h"
#include "EthernetPacket.h"
#include "EcpriPacket.h"

const int PACKET_TYPE_OFFSET = 40;
const int PACKET_TYPE_LENGTH = 4;

EthernetPacket *PacketFactory::getPacketBasedOnType(string const &packetData) {
    string packetType = packetData.substr(PACKET_TYPE_OFFSET, PACKET_TYPE_LENGTH);

    if (packetType == "AEFE") {
        return new EcpriPacket(packetData);
    } else {
        return new EthernetPacket(packetData);
    }

}

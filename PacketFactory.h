#ifndef PACKET_ANALYZER_PACKET_FACTORY_H
#define PACKET_ANALYZER_PACKET_FACTORY_H

#include "string"
#include "EthernetPacket.h"

using namespace std;
class PacketFactory {
public:
    static EthernetPacket *getPackedBasedOnType(string const &packetType);
};

#endif //PACKET_ANALYZER_PACKET_FACTORY_H

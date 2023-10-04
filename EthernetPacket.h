#ifndef PACKET_ANALYZER_ETHERNET_PACKET_H
#define PACKET_ANALYZER_ETHERNET_PACKET_H

#include <string>
#include <sstream>

using namespace std;
class EthernetPacket {
protected:
    string packetData;
    string destinationAddress;
    string sourceAddress;
    string crc;
    string packetType;
    virtual void processPacketData();
    virtual ostream &stringifyPacketData(ostream &outStream) const;

public:
    EthernetPacket(const string packetData);
    friend ostream& operator<<(ostream &os, EthernetPacket const &obj);

    const string extractCrcFromData() const;

    const string extractDestinationAddressFromData() const;

    const string extractSourceAddressFromData() const;

    const string extractTypeFromData() const;
};

#endif


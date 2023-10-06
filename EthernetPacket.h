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
    string extractCrcFromData() const;
    string extractDestinationAddressFromData() const;
    string extractSourceAddressFromData() const;
    string extractTypeFromData() const;

public:
    EthernetPacket(const string& packetData);
    virtual ~EthernetPacket() = default;
    friend ostream &operator<<(ostream &os, EthernetPacket const &obj);

};

#endif


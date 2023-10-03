#ifndef PACKET_ANALYZER_ETHERNET_PACKET_H
#define PACKET_ANALYZER_ETHERNET_PACKET_H

#include <string>

using namespace std;

class EthernetPacket {
protected:
    string packetData;
    string destinationAddress;
    string sourceAddress;
    string crc;
    string packetType;

public:
    const string &getPacketData() const;
    void setPacketData(const string &packetData);

    const string &getDestinationAddress() const;
    void setDestinationAddress(const string &destinationAddress);

    const string &getCrc() const;
    void setCrc(const string &crc);

    const string &getPacketType() const;
    void setPacketType(const string &packetType);

    const string &getSourceAddress() const;
    void setSourceAddress(const string &destinationAddress);

    void processPacketData();
};

#endif

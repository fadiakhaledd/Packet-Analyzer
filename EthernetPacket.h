#ifndef PACKET_ANALYZER_ETHERNET_PACKET_H
#define PACKET_ANALYZER_ETHERNET_PACKET_H

#include <string>
#include <sstream>

using namespace std;

extern const int PACKET_MIN_LENGTH;
extern const int CRC_LENGTH;
extern const int DESTINATION_ADDRESS_START;
extern const int DESTINATION_ADDRESS_LENGTH;
extern const int SOURCE_ADDRESS_START;
extern const int SOURCE_ADDRESS_LENGTH;
extern const int TYPE_START;
extern const int TYPE_LENGTH;

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
    EthernetPacket(const string& packetData);
    virtual ~EthernetPacket() = default;
    friend ostream &operator<<(ostream &os, EthernetPacket const &obj);
    string extractCrcFromData() const;
    string extractDestinationAddressFromData() const;
    string extractSourceAddressFromData() const;
    string extractTypeFromData() const;
};

#endif


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
    virtual ostream &stringfyPacketData(ostream &os) const;

public:
    EthernetPacket(const string packetData);

    const string& getPacketData() const;
    void setPacketData(const string& packetData);

    const string& getDestinationAddress() const;
    void setDestinationAddress(const string& destinationAddress);

    const string& getSourceAddress() const;
    void setSourceAddress(const string& sourceAddress);

    const string& getCrc() const;
    void setCrc(const string& crc);

    const string& getPacketType() const;
    void setPacketType(const string& packetType);

    string getPacketInfo() const;

    friend ostream& operator<<(ostream &os, EthernetPacket const &obj);
};

#endif


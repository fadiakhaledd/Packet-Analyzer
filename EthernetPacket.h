#ifndef PACKET_ANALYZER_ETHERNET_PACKET_H
#define PACKET_ANALYZER_ETHERNET_PACKET_H

#include <string>
#include <sstream>

class EthernetPacket {
protected:
    std::string packetData;
    std::string destinationAddress;
    std::string sourceAddress;
    std::string crc;
    std::string packetType;

public:
    EthernetPacket(const std::string& packetData);

    const std::string& getPacketData() const;
    void setPacketData(const std::string& packetData);

    const std::string& getDestinationAddress() const;
    void setDestinationAddress(const std::string& destinationAddress);

    const std::string& getSourceAddress() const;
    void setSourceAddress(const std::string& sourceAddress);

    const std::string& getCrc() const;
    void setCrc(const std::string& crc);

    const std::string& getPacketType() const;
    void setPacketType(const std::string& packetType);

    std::string getPacketInfo() const;

    void processPacketData();
};

#endif
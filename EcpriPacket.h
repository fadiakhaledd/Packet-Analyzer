#ifndef ECPRI_PACKET_H
#define ECPRI_PACKET_H

#include "EthernetPacket.h"
#include <string>

using namespace std;

class EcpriPacket : public EthernetPacket {
protected:
    string concatenationIndicator;
    string messageType;
    string payloadSize;
    string protocolVersion;
    string rtcId;
    string sequenceId;

    const string extractProtocolVersionFromData() const;
    const string extractMessageTypeFromData() const;
    const string extractPayloadSizeFromData() const;
    const string extractRtcIdFromData() const;
    const string extractSequenceIdFromData() const;
    const string extractConcatenationIndicatorFromData() const;
    ostream &stringifyPacketData(ostream &outStream) const;
    void processPacketData();

public:
    EcpriPacket(string packetData);
    friend std::ostream& operator<<(std::ostream &os,EcpriPacket const obj);

};

#endif

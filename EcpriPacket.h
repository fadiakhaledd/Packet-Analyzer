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

    string extractProtocolVersionFromData() const;
    string extractMessageTypeFromData() const;
    string extractPayloadSizeFromData() const;
    string extractRtcIdFromData() const;
    string extractSequenceIdFromData() const;
    string extractConcatenationIndicatorFromData() const;
    ostream &stringifyPacketData(ostream &outStream) const override;
    void processPacketData() override;

public:
    EcpriPacket(const string& packetData);

};

#endif

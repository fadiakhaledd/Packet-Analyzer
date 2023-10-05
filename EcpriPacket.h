#ifndef ECPRI_PACKET_H
#define ECPRI_PACKET_H

#include "EthernetPacket.h"
#include <string>

using namespace std;

extern const int PROTOCOL_VERSION_OFFSET;
extern const int MESSAGE_TYPE_OFFSET;
extern const int MESSAGE_TYPE_LENGTH;
extern const int CONCATENATION_INDICATOR_OFFSET;
extern const int PAYLOAD_SIZE_OFFSET;
extern const int PAYLOAD_SIZE_LENGTH;
extern const int RTC_ID_OFFSET;
extern const int RTC_ID_LENGTH;
extern const int SEQUENCE_ID_OFFSET;
extern const int SEQUENCE_ID_LENGTH;

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

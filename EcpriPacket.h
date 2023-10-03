#ifndef ECPRI_PACKET_H
#define ECPRI_PACKET_H

#include "EthernetPacket.h"
#include <string>

using namespace std; 

class EcpriPacket : public EthernetPacket {
private:
    string concatenationIndicator;
    string messageType;
    string payloadSize;
    string protocolVersion;
    string rtcId;
    string sequenceId;

public:
    const string &getConcatenationIndicator() const;
    void setConcatenationIndicator(const string &concatenationIndicator);

    const string &getMessageType() const;
    void setMessageType(const string &messageType);

    const string &getPayloadSize() const;
    void setPayloadSize(const string &payloadSize);

    const string &getProtocolVersion() const;
    void setProtocolVersion(const string &protocolVersion);

    const string &getRtcId() const;
    void setRtcId(const string &rtcId);

    const string &getSequenceId() const;
    void setSequenceId(const string &sequenceId);
};

#endif

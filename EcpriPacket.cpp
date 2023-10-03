#include "EcpriPacket.h"

using namespace std; 

const string &EcpriPacket::getConcatenationIndicator() const {
    return concatenationIndicator;
}

void EcpriPacket::setConcatenationIndicator(const string &concatenationIndicator) {
    EcpriPacket::concatenationIndicator = concatenationIndicator;
}

const string &EcpriPacket::getMessageType() const {
    return messageType;
}

void EcpriPacket::setMessageType(const string &messageType) {
    EcpriPacket::messageType = messageType;
}

const string &EcpriPacket::getPayloadSize() const {
    return payloadSize;
}

void EcpriPacket::setPayloadSize(const string &payloadSize) {
    EcpriPacket::payloadSize = payloadSize;
}

const string &EcpriPacket::getProtocolVersion() const {
    return protocolVersion;
}

void EcpriPacket::setProtocolVersion(const string &protocolVersion) {
    EcpriPacket::protocolVersion = protocolVersion;
}

const string &EcpriPacket::getRtcId() const {
    return rtcId;
}

void EcpriPacket::setRtcId(const string &rtcId) {
    EcpriPacket::rtcId = rtcId;
}

const string &EcpriPacket::getSequenceId() const {
    return sequenceId;
}

void EcpriPacket::setSequenceId(const string &sequenceId) {
    EcpriPacket::sequenceId = sequenceId;
}

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

void EcpriPacket::processPacketData() {
    EthernetPacket::processPacketData();
    protocolVersion = getProtocolVersionFromData();
    messageType = getmessageTypeFromData();
    concatenationIndicator = getConcatenationIndicatorFromData();
    payloadSize = getPayloadSizeFromData();
    rtcId = getRtcIdFromData();
    sequenceId = getSequenceIdFromData();
}

const string &EcpriPacket::getProtocolVersionFromData() const {
    string protocolVersion = "";
    protocolVersion += packetData[44]; // The first character of the first byte Data field
    return protocolVersion;
}

const string &EcpriPacket::getmessageTypeFromData() const {
    string messageType = "";
    messageType += packetData.substr(46, 48); // The second bytes of Data field
    return messageType;
}

const string &EcpriPacket::getConcatenationIndicatorFromData() const {
    int byte45AsInt = packetData[45] - '0'; // The second character of the first byte of Data field
    int LSBOfByte45 = byte45AsInt & 1;
    string concatenationIndicator = "";
    concatenationIndicator += LSBOfByte45;
    return concatenationIndicator;
}

const string &EcpriPacket::getPayloadSizeFromData() const {
    string payloadSize = "";
    payloadSize += packetData.substr(48, 52); // Bytes 3, 4 of Data field
    return payloadSize;
}

const string &EcpriPacket::getRtcIdFromData() const {
    string rtcId = "";
    rtcId += packetData.substr(52, 56); // Bytes 5, 6 of Data field
    return rtcId;
}

const string &EcpriPacket::getSequenceIdFromData() const {
    string sequenceId = "";
    sequenceId += packetData.substr(56, 60); // Bytes 7, 8 of Data field
    return sequenceId;
}
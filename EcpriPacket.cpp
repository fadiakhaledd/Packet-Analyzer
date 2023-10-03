#include "EcpriPacket.h"

using namespace std;

EcpriPacket::EcpriPacket(string const packetData): EthernetPacket(packetData) {
    processPacketData();
}

const string &EcpriPacket::getConcatenationIndicator() const {
    return concatenationIndicator;
}

const string &EcpriPacket::getMessageType() const {
    return messageType;
}

const string &EcpriPacket::getPayloadSize() const {
    return payloadSize;
}

const string &EcpriPacket::getProtocolVersion() const {
    return protocolVersion;
}

const string &EcpriPacket::getRtcId() const {
    return rtcId;
}

const string &EcpriPacket::getSequenceId() const {
    return sequenceId;
}

void EcpriPacket::processPacketData() {
    EthernetPacket::processPacketData();
    protocolVersion = extractProtocolVersionFromData();
    messageType = extractMessageTypeFromData();
    concatenationIndicator = extractConcatenationIndicatorFromData();
    payloadSize = extractPayloadSizeFromData();
    rtcId = extractRtcIdFromData();
    sequenceId = getSequenceIdFromData();
}

const string &EcpriPacket::extractProtocolVersionFromData() const {
    string protocolVersion = "";
    protocolVersion += packetData[44]; // The first character of the first byte Data field
    return protocolVersion;
}

const string &EcpriPacket::extractMessageTypeFromData() const {
    string messageType = "";
    messageType += packetData.substr(46, 48); // The second bytes of Data field
    return messageType;
}

const string &EcpriPacket::extractConcatenationIndicatorFromData() const {
    int byte45AsInt = packetData[45] - '0'; // The second character of the first byte of Data field
    int LSBOfByte45 = byte45AsInt & 1;
    string concatenationIndicator = "";
    concatenationIndicator += LSBOfByte45;
    return concatenationIndicator;
}

const string &EcpriPacket::extractPayloadSizeFromData() const {
    string payloadSize = "";
    payloadSize += packetData.substr(48, 52); // Bytes 3, 4 of Data field
    return payloadSize;
}

const string &EcpriPacket::extractRtcIdFromData() const {
    string rtcId = "";
    rtcId += packetData.substr(52, 56); // Bytes 5, 6 of Data field
    return rtcId;
}

const string &EcpriPacket::getSequenceIdFromData() const {
    string sequenceId = "";
    sequenceId += packetData.substr(56, 60); // Bytes 7, 8 of Data field
    return sequenceId;
}
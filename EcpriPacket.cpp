#include "EcpriPacket.h"
#include "iostream"

using namespace std;

const int PROTOCOL_VERSION_OFFSET = 44;
const int MESSAGE_TYPE_OFFSET = 46;
const int MESSAGE_TYPE_LENGTH = 2;
const int CONCATENATION_INDICATOR_OFFSET = 45;
const int PAYLOAD_SIZE_OFFSET = 48;
const int PAYLOAD_SIZE_LENGTH = 4;
const int RTC_ID_OFFSET = 52;
const int RTC_ID_LENGTH = 4;
const int SEQUENCE_ID_OFFSET = 56;
const int SEQUENCE_ID_LENGTH = 4;

EcpriPacket::EcpriPacket(string const& packetData) : EthernetPacket(packetData) {
    processPacketData();
}

void EcpriPacket::processPacketData() {
    protocolVersion = extractProtocolVersionFromData();
    messageType = extractMessageTypeFromData();
    concatenationIndicator = extractConcatenationIndicatorFromData();
    payloadSize = extractPayloadSizeFromData();
    rtcId = extractRtcIdFromData();
    sequenceId = extractSequenceIdFromData();
}

string EcpriPacket::extractProtocolVersionFromData() const {
    const int CHAR_COUNT = 1;
    return string(CHAR_COUNT, packetData[PROTOCOL_VERSION_OFFSET]);
}

string EcpriPacket::extractMessageTypeFromData() const {
    return packetData.substr(MESSAGE_TYPE_OFFSET, MESSAGE_TYPE_LENGTH); // The second bytes of Data field;
}

string EcpriPacket::extractConcatenationIndicatorFromData() const {
    int byte45AsInt =
            packetData[CONCATENATION_INDICATOR_OFFSET] - '0'; // The second character of the first byte of Data field
    int LSBOfByte45 = (byte45AsInt & 1);
    return to_string(LSBOfByte45);
}

string EcpriPacket::extractPayloadSizeFromData() const {
    return packetData.substr(PAYLOAD_SIZE_OFFSET, PAYLOAD_SIZE_LENGTH); // Bytes 3, 4 of Data field
}

string EcpriPacket::extractRtcIdFromData() const {
    return packetData.substr(RTC_ID_OFFSET, RTC_ID_LENGTH); // Bytes 5, 6 of Data field;
}

string EcpriPacket::extractSequenceIdFromData() const {
    return packetData.substr(SEQUENCE_ID_OFFSET, SEQUENCE_ID_LENGTH); // Bytes 7, 8 of Data field
}

ostream &EcpriPacket::stringifyPacketData(ostream &outStream) const {
    EthernetPacket::stringifyPacketData(outStream);
    outStream << "Concatenation Indicator: " << concatenationIndicator << endl;
    outStream << "Message Type: " << messageType << endl;
    outStream << "Payload Size: " << payloadSize << endl;
    outStream << "Protocol Version: " << protocolVersion << endl;
    outStream << "RTC ID: " << rtcId << endl;
    outStream << "Sequence ID: " << sequenceId << endl;
    return outStream;
}

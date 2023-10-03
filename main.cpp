#include <iostream>
#include "EthernetPacket.h"
#include "EcpriPacket.h"
#include "PacketAnalyzer.h"

using namespace std;

int main() {

    PacketAnalyzer packetAnalyzer("input_packets.txt", "outPutFile.txt");
    packetAnalyzer.readFromInputFile();

    return 0;
}

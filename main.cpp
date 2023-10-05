#include <iostream>
#include "EthernetPacket.h"
#include "EcpriPacket.h"
#include "PacketAnalyzer.h"

using namespace std;

int main() {

    PacketAnalyzer packetAnalyzer("input_packets.txt", "output_packets.txt");
    packetAnalyzer.readFromInputFile();
    packetAnalyzer.writeToOutputFile();

    return 0;
}

#include <iostream>
#include "EthernetPacket.h"
#include "EcpriPacket.h"
#include "PacketAnalyzer.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    EcpriPacket packet;
    packet.setPacketData("Some data");
    cout << packet.getPacketData() << endl;

    PacketAnalyzer packetAnalyzer;
    packetAnalyzer.ReadInputFile();


    return 0;
}

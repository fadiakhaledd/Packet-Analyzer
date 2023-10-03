#include <iostream>
#include "EthernetPacket.h"
#include "EcpriPacket.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    EcpriPacket packet;
    packet.setPacketData("Some data");
    cout << packet.getPacketData() << endl;

    return 0;
}

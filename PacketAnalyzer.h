#ifndef PACKET_ANALYZER_PACKET_ANALYZER_H
#define PACKET_ANALYZER_PACKET_ANALYZER_H

#include <string>
#include <fstream>
#include "EthernetPacket.h"
#include "EcpriPacket.h"
#include "vector"
#include "iostream"

using namespace std;

class PacketAnalyzer {
protected:
    string inputFileName;
    string outputFileName;
    vector<EthernetPacket*> packetsPointers;
public:

    PacketAnalyzer(string, string);
    void setInputFileName(const string &inputFileName);
    void setOutputFileName(const string &outputFileName);
    void readFromInputFile();
    void writeToOutputFile();

};

#endif

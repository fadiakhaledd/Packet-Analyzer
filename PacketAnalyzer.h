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
    vector <EthernetPacket*> packets;

public:

    PacketAnalyzer(string, string, string);

    const string &getInputFileName() const {
        return inputFileName;
    }

    void setInputFileName(const string &inputFileName) {
        PacketAnalyzer::inputFileName = inputFileName;
    }

    const string &getOutputFileName() const {
        return outputFileName;
    }

    void setOutputFileName(const string &outputFileName) {
        PacketAnalyzer::outputFileName = outputFileName;
    }

    const vector<EthernetPacket *> &getPackets() const {
        return packets;
    }

    void setPackets(const vector<EthernetPacket *> &packets) {
        PacketAnalyzer::packets = packets;
    }

    void parseEthernetPacket(const EthernetPacket& packet);

    void parseECPRIPacket(const EcpriPacket& packet);

    void ReadInputFile();



};



#endif

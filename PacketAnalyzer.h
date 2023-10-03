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
public:

    PacketAnalyzer(string, string);

    const string &getInputFileName() const;

    void setInputFileName(const string &inputFileName);

    const string &getOutputFileName() const;

    void setOutputFileName(const string &outputFileName);

    void parseEthernetPacket(const EthernetPacket& packet);

    void parseECPRIPacket(const EcpriPacket& packet);

    void readFromInputFile();

    void writeToOutputFile();

};

#endif

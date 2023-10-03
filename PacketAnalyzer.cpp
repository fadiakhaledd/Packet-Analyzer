#include "PacketAnalyzer.h"
#include <fstream>

using namespace std;

PacketAnalyzer::PacketAnalyzer(string inputFileName, string outputFileName) {
    setInputFileName(inputFileName);
    setOutputFileName(outputFileName);
}

const string& PacketAnalyzer::getInputFileName() const {
    return inputFileName;
}

void PacketAnalyzer::setInputFileName(const string& inputFileName) {
    this->inputFileName = inputFileName;
}

const string& PacketAnalyzer::getOutputFileName() const {
    return outputFileName;
}

void PacketAnalyzer::setOutputFileName(const string& outputFileName) {
    this->outputFileName = outputFileName;
}

const vector<EthernetPacket*>& PacketAnalyzer::getPackets() const {
    return packets;
}

void PacketAnalyzer::setPackets(const vector<EthernetPacket*>& packets) {
    this->packets = packets;
}

void PacketAnalyzer::parseEthernetPacket(const EthernetPacket& packet) {
    // Parsing logic for Ethernet packets
}

void PacketAnalyzer::parseECPRIPacket(const EcpriPacket& packet) {
    // Parsing logic for ECPRI packets
}
void PacketAnalyzer::readFromInputFile() {
    ifstream inputFileStream(inputFileName, ios::in);
    string line;

    if (!inputFileStream) {
        cerr << "Failed to open input file." << endl;
        return;
    }

    while (getline(inputFileStream, line)) {
        cout << line << endl << endl;
    }

    inputFileStream.close();
}

void PacketAnalyzer::writeToOutputFile() {
    ofstream outputFile(outputFileName, ios::binary);
    if (!outputFile) {
        cerr << "Failed to open output file." << endl;
        return;
    }

    // Write packets to the output file
    for (const EthernetPacket* packet : packets) {
        // Write the packet to the file
        outputFile.write(reinterpret_cast<const char*>(packet), sizeof(EthernetPacket));
    }

    outputFile.close();
}
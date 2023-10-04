#include "PacketAnalyzer.h"
#include <fstream>

using namespace std;

PacketAnalyzer::PacketAnalyzer(string inputFileName, string outputFileName) {
    setInputFileName(inputFileName);
    setOutputFileName(outputFileName);
}

const string &PacketAnalyzer::getInputFileName() const {
    return inputFileName;
}

void PacketAnalyzer::setInputFileName(const string &inputFileName) {
    this->inputFileName = inputFileName;
}

const string &PacketAnalyzer::getOutputFileName() const {
    return outputFileName;
}

void PacketAnalyzer::setOutputFileName(const string &outputFileName) {
    this->outputFileName = outputFileName;
}

void PacketAnalyzer::parseEthernetPacket(const EthernetPacket &packet) {
    // Parsing logic for Ethernet packets
}

void PacketAnalyzer::parseECPRIPacket(const EcpriPacket &packet) {
    // Parsing logic for ECPRI packets
}

void PacketAnalyzer::readFromInputFile() {
    ifstream inputFileStream(inputFileName, ios::in);
    string packetDataInput;

    if (!inputFileStream) {
        cerr << "Failed to open input file." << endl;
        return;
    }

    while (getline(inputFileStream, packetDataInput)) {
        string packetType = packetDataInput.substr(40, 4);
        EthernetPacket *packet;
        if (packetType == "AEFE") {
            packet = new EcpriPacket(packetDataInput);
            cout << *packet;
        } else {
//            packet = new EthernetPacket(packetDataInput);
        }
        break;
    }
    inputFileStream.close();
}

void PacketAnalyzer::writeToOutputFile() {
    ofstream outputFile(outputFileName, ios::out);

    if (!outputFile) {
        cerr << "Failed to open output file." << endl;
        return;
    }


    outputFile.close();
}
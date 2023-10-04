#include "PacketAnalyzer.h"
#include <fstream>

using namespace std;

PacketAnalyzer::PacketAnalyzer(string inputFileName, string outputFileName) {
    setInputFileName(inputFileName);
    setOutputFileName(outputFileName);
}

void PacketAnalyzer::setInputFileName(const string &inputFileName) {
    this->inputFileName = inputFileName;
}

void PacketAnalyzer::setOutputFileName(const string &outputFileName) {
    this->outputFileName = outputFileName;
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
        } else {
            packet = new EthernetPacket(packetDataInput);
        }
        packetsPointers.push_back(packet);
    }
    inputFileStream.close();
}

void PacketAnalyzer::writeToOutputFile() {
    ofstream outputFile(outputFileName, ios::out);

    if (!outputFile) {
        cerr << "Failed to open output file." << endl;
        return;
    }

    int packetsPointersSize = packetsPointers.size();
    for (int index = 0; index < packetsPointersSize; ++index) {
        outputFile << "Packet # " << index << ": " << endl;
        outputFile << *packetsPointers[index] << endl;
        outputFile << "********************************************************************************************"
                      "***************************************************************************************" << endl;
    }
    outputFile.close();
}
#include "PacketAnalyzer.h"
#include <fstream>
#include "PacketFactory.h"

using namespace std;

PacketAnalyzer::PacketAnalyzer(const string& inputFileName, const string& outputFileName) {
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

    EthernetPacket *packetPointer;
    while (getline(inputFileStream, packetDataInput)) {
        packetPointer = PacketFactory::getPackedBasedOnType(packetDataInput);
        packetsPointers.push_back(packetPointer);
    }
    inputFileStream.close();

    packetPointer = 0;
    delete packetPointer;
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
                      "***************************************************************************************\n" << endl;
    }
    outputFile.close();
}

PacketAnalyzer::~PacketAnalyzer() {
    for (EthernetPacket* pointer: packetsPointers) {
        delete pointer;
    }
    packetsPointers.clear();
}

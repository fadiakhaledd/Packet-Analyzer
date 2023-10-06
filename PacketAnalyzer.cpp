#include "PacketAnalyzer.h"
#include <fstream>
#include "PacketFactory.h"

using namespace std;

const int PACKET_MIN_LENGTH = 144;
const int PACKET_MAX_LENGTH = 3052;

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
    try {
        ifstream inputFileStream(inputFileName, ios::in);
        string packetDataInput;

        if (!inputFileStream) {
            throw runtime_error("Failed to open input file.");
        }

        EthernetPacket *packetPointer;
        while (getline(inputFileStream, packetDataInput)) {
            checkPacketLength(packetDataInput);
            packetPointer = PacketFactory::getPackedBasedOnType(packetDataInput);
            packetsPointers.push_back(packetPointer);
        }
        inputFileStream.close();

        packetPointer = 0;
        delete packetPointer;
    }
    catch (exception& error) {
        cout << "Error: " << error.what() << endl;
    }

}

void PacketAnalyzer::writeToOutputFile() {
    try {
        ofstream outputFile(outputFileName, ios::out);

        if (!outputFile) {
            throw runtime_error("Failed to open output file.");
        }

        int packetsPointersSize = packetsPointers.size();
        for (int index = 0; index < packetsPointersSize; ++index) {
            outputFile << "Packet # " << index << ": " << endl;
            outputFile << *packetsPointers[index] << endl;
            outputFile << "********************************************************************************************"
                          "***************************************************************************************\n" << endl;
        }
        outputFile.close();
    } catch (exception& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }
}

void PacketAnalyzer::checkPacketLength(string packetDataInput) {
    if(packetDataInput.size() < PACKET_MIN_LENGTH || packetDataInput.size() > PACKET_MAX_LENGTH){
        throw runtime_error("Insufficient packet data length");
    }
}

PacketAnalyzer::~PacketAnalyzer() {
    for (EthernetPacket* pointer: packetsPointers) {
        delete pointer;
    }
    packetsPointers.clear();
}

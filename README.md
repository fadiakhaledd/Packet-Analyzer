# Packet Analyzer

## Overview

The Packet Analyzer is a software tool designed to read input text files containing Ethernet packets, parse each packet into its individual fields, and save the parsed packets along with their fields to an output text file. This README provides an overview of the project, the input and output formats, instructions on how to run the program, a UML diagram depicting the project's design, and contact information.

## Input Format

- The input text file should contain Ethernet packets, with one packet per line.
- Each line represents the data of a single packet.
- Ethernet packets can either be raw Ethernet frames or Enhanced Common Public Radio Interface (e-CPRI) frames built over Ethernet.
- To identify an e-CPRI frame, the program checks that the Type field is "AEFE."

Sample Input:

02C9D9300000AEFE0000000000000800
02C9D9300000FFFF0000000000000800

vbnet
Copy code

## Output Format

- The program writes the parsed packets to an output text file.
- Each line in the output file represents a parsed packet with its fields.

Sample Output:

Packet Data: 02C9D9300000AEFE0000000000000800
CRC: 00000000
Destination Address: 02C9D9300000
Source Address: AEFE00000000
Type: 00000800
This is an e-CPRI frame.

c
Copy code

## Running the Program

1. Clone or download the project repository.
2. Open the project in your preferred C++ development environment (e.g., Visual Studio Code).
3. Ensure that you have the following header files included:

   ```cpp
   #include <iostream>
   #include "EthernetPacket.h"
   #include "EcpriPacket.h"
   #include "PacketAnalyzer.h"
4. In the main() function of the main program file (e.g., main.cpp), create a PacketAnalyzer instance, specifying the input and output file names:

   int main() {
    PacketAnalyzer packetAnalyzer("input_packets.txt", "outputFile.txt");
    packetAnalyzer.readFromInputFile();
    packetAnalyzer.writeToOutputFile();
    return 0;
}

5. Build and run the program using your C++ development environment.
6. The parsed packets will be saved to the specified output file.
   
##  UML Diagram

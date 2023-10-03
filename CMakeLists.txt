cmake_minimum_required(VERSION 3.26)
project(Packet_Analyzer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Packet_Analyzer main.cpp
        EthernetPacket.h
        EthernetPacket.cpp
        EcpriPacket.cpp
        EcpriPacket.h
        PacketAnalyzer.cpp
        PacketAnalyzer.h)

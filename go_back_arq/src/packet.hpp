#pragma once

#include <vector>
#include <string>

enum class PacketType {
    DATA,
    ACK
};

class Packet {
private:
    PacketType type;
    int seqNum;
    std::vector<int> data;
    std::string timestamp;

public:
    Packet(int seq, std::vector<int> data_, std::string timestamp_) 
        : type(PacketType::DATA), seqNum(seq), data(data_), timestamp(timestamp_) {}

    Packet(int ackNum) : type(PacketType::ACK), seqNum(ackNum) {}
    
    // Return a constant reference to avoid copying the data
    const std::vector<int>& get_packet_data() const {
        return data;
    }

    // Return a constant reference to avoid copying the data
    const std::string& get_packet_timestamp() const {
        return timestamp;
    }

    PacketType get_type() const {
        return type;
    }

    int get_seq_num() const {
        return seqNum; 
    }

};

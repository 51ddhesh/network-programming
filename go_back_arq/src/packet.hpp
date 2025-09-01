#pragma once

#include <vector>
#include <string>

class Packet {
private:
    std::vector<int> data;
    std::string timestamp;

public:
    Packet(std::vector<int> data_, std::string timestamp_) {
        this -> data = data_;
        this -> timestamp = timestamp_;
    }

    std::vector<int> get_packet_data() {
        return this -> data;
    }

    std::string get_packet_timestamp() {
        return this -> timestamp;
    }
};

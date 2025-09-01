#include <iostream>
#include <thread>
#include <algorithm>
#include <string>
#include <vector>
#include "random_.hpp"
#include "values.hpp"
#include "packet.hpp"
#include "utils.hpp"

// function to generate a packet
Packet generatePacket() {
    // init a std::vector of values::WINDOW_SIZE
    std::vector<int> data(values::WINDOW_SIZE);
    // fill the vector with random values from random_.hpp
    for (size_t i = 0; i < values::WINDOW_SIZE; i++) {
        data[i] = random_::getInt(values::MINIMUM_VALUE, values::MAXIMUM_VALUE);
    }
    // get the timestamp for the packet from utils.hpp
    std::string timestamp = getTime();
    // return an object of class Packet
    return Packet(data, timestamp);
}

// Function to print the contents of the packet
void printPacket(Packet packet_) {
    // get the data[] from packet_
    std::vector<int> data = packet_.get_packet_data();
    // get the timestamp from packet_
    std::string timestamp = packet_.get_packet_timestamp();
    // Formatted printing for the object data
    std::cout << '[';
    for (size_t i = 0; i < values::WINDOW_SIZE; i++) {
        std::cout << data[i] << (i == values::WINDOW_SIZE - 1 ? "]" : ", ");
    }
    std::cout << " | [" << timestamp << ']' << std::endl;
}

void test() {
    Packet i = generatePacket();
    printPacket(i);
}

int main() {
    test();
    return 0;
}

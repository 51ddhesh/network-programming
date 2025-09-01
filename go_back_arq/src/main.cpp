#include <iostream>
#include <thread>
#include <algorithm>
#include <string>
#include <vector>
#include "random_.hpp"
#include "values.hpp"
#include "packet.hpp"
#include "utils.hpp"

// Function to generate a packet
std::pair<std::vector<int>, std::string> generatePacket() {
    // Init a std::vector of <int> of values::WINDOW_SIZE
    std::vector<int> data(values::WINDOW_SIZE);
    // fill the vector with random values
    for (size_t i = 0; i < values::WINDOW_SIZE; i++) {
        data[i] = random_::getInt(values::MINIMUM_VALUE, values::MAXIMUM_VALUE);
    }
    // get the current time in [date-month-year HH:MM:SS] format
    std::string timestamp = getTime();
    std::pair<std::vector<int>, std::string> packet = std::make_pair(data, timestamp);
    return packet;
}

void printPacket(std::pair<std::vector<int>, std::string>& packet) {
    std::cout << '[';
    for (size_t i = 0; i < values::WINDOW_SIZE; i++) {
        std::cout << packet.first[i] << (i == values::WINDOW_SIZE - 1 ? "]" : ", ");
    }
    std::cout << " | [" << packet.second << ']' << std::endl;
}

void test() {
    auto i = generatePacket();
    printPacket(i);
}

int main() {
    test();
    return 0;
}

#include <iostream>
#include <thread>
#include <algorithm>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <vector>
#include "random_.hpp"

// namespace to hold constants
namespace values {
    constexpr size_t WINDOW_SIZE = 4;
    constexpr unsigned int MINIMUM_VALUE = 0;
    constexpr unsigned int MAXIMUM_VALUE = 100;
}

// Function to get current time
std::string getTime() {
    // Convert std::chrono::_V2::system_clock::time_point to std::time_t 
    std::time_t t= std::chrono::system_clock::to_time_t(std::chrono::high_resolution_clock::now());
    // 'broken-down' time structure `tm`
    std::tm tm = *std::localtime(&t);
    // output string stream
    std::ostringstream oss;
    // format the time output
    oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
    // return as std::string
    return oss.str();
}

std::pair<std::vector<int>, std::string> generatePacket() {
    std::vector<int> data(values::WINDOW_SIZE);
    for (size_t i = 0; i < values::WINDOW_SIZE; i++) {
        data[i] = random_::getInt(values::MINIMUM_VALUE, values::MAXIMUM_VALUE);
    }
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

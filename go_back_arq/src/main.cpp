#include <iostream>
#include <random>
#include <thread>
#include <chrono>
#include <algorithm>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

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


int main() {
    std::cout << '[' << getTime() << ']' << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}



#pragma once

#include <string>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <queue>
#include <mutex>
#include <condition_variable>
#include "packet.hpp"
#include "values.hpp"
#include "random_.hpp"

class ThreadSafeQueue {
private:
    std::queue<Packet> q;
    std::mutex mtx;
    std::condition_variable cv;

public:
    // Function to push a packet in network queue
    void push(Packet packet) {
        // Lock the mutex before accessing the queue
        std::unique_lock<std::mutex> lock(mtx);
        // Unlocking of mutex is handled by the destructor of std::unique_lock
        q.push(packet);
        // Notify the waiting thread that an item is available
        cv.notify_one();
    }

    Packet pop() {
        // Lock the queue before accessing it
        std::unique_lock<std::mutex> lock(mtx);
        // Wait until the queue is not empty 
        // this lambda prevents spurious wakeups
        cv.wait(lock, [this]{
            return !q.empty();
        });
        Packet packet = q.front();
        q.pop();
        return packet;
    }

};



// Function to get current time
std::string getTime() {
    // Convert std::chrono::_V2::system_clock::time_point to std::time_t 
    std::time_t t = std::chrono::system_clock::to_time_t(std::chrono::high_resolution_clock::now());
    // 'broken-down' time structure `tm`
    std::tm tm = *std::localtime(&t);
    // output string stream
    std::ostringstream oss;
    // format the time output
    oss << std::put_time(&tm, "%d-%m-%Y %H:%M:%S");
    // return as std::string
    return oss.str();
}

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



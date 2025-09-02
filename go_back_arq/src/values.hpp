#pragma once
#include <cstddef>  // for size_t

// namespace to hold constants
namespace values {
    constexpr size_t WINDOW_SIZE = 4;
    constexpr unsigned int MINIMUM_VALUE = 0;
    constexpr unsigned int MAXIMUM_VALUE = 100;
    constexpr int TIMEOUT_MS = 2000;
    // assume 20% probability of a packet being lost
    constexpr double PACKET_LOSS_PROBABILITY = 0.2;
}

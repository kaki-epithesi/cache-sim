#pragma once
#include <atomic>
#include <cstdint>

enum class State : uint8_t {
    Invalid,
    Shared,
    Modified,
};

struct CacheLine {
    std::atomic<State> state;
    std::atomic<uint64_t> tag;

    CacheLine() : state(State::Invalid), tag(0) {}
};

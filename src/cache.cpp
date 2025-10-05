// cache.cpp
#include "cache.h"

Cache::Cache(size_t num_lines) : lines_(num_lines) {}

std::optional<CacheLine*> Cache::find(uint64_t tag) {
    for (auto& line : lines_) {
        if (line.tag == tag && line.state != State::Invalid)
            return &line;
    }
    return std::nullopt;
}

CacheLine* Cache::allocate(uint64_t tag) {
    for (auto& line : lines_) {
        if (line.state == State::Invalid) {
            line.tag = tag;
            line.state = State::Shared;
            return &line;
        }
    }
    return &lines_[0];  // naive: evict first
}

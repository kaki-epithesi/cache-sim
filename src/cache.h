#pragma once
#include <vector>
#include <optional>
#include "cache_line.h"

class Cache {
public:
    explicit Cache(size_t num_lines = 64);

    std::optional<CacheLine*> find(uint64_t tag);
    CacheLine* allocate(uint64_t tag);

private:
    std::vector<CacheLine> lines_;
};

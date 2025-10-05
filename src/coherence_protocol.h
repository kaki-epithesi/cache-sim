#pragma once
#include "cache_line.h"

class CoherenceProtocol {
public:
    static void on_read(CacheLine* line);
    static void on_write(CacheLine* line);
};

#pragma once
#include <thread>
#include "cache.h"
#include "coherence_protocol.h"

class Node {
public:
    Node(int id);
    void run();

private:
    int id_;
    Cache l1_;
};

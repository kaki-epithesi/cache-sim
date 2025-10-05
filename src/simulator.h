#pragma once
#include <vector>
#include "node.h"

class Simulator {
public:
    Simulator(int num_nodes);
    void run();

private:
    std::vector<Node> nodes_;
};

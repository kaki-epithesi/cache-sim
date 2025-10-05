// simulator.cpp
#include "simulator.h"
#include <thread>

Simulator::Simulator(int num_nodes) {
    for (int i = 0; i < num_nodes; ++i)
        nodes_.emplace_back(i);
}

void Simulator::run() {
    std::vector<std::thread> threads;
    for (auto& node : nodes_) {
        threads.emplace_back([&node] { node.run(); });
    }
    for (auto& t : threads) t.join();
}

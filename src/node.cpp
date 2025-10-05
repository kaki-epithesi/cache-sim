#include "node.h"
#include <iostream>

Node::Node(int id) : id_(id), l1_(64) {}

void Node::run() {
    std::cout << "Node " << id_ << " started\n";

    for (int i = 0; i < 1000; ++i) {
        uint64_t addr = i % 16;
        auto tag = addr;

        auto line = l1_.find(tag);
        if (!line.has_value()) {
            line = l1_.allocate(tag);
        }

        if (i % 2 == 0)
            CoherenceProtocol::on_read(*line);
        else
            CoherenceProtocol::on_write(*line);
    }

    std::cout << "Node " << id_ << " finished\n";
}

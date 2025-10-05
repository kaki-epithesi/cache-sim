#include "coherence_protocol.h"

void CoherenceProtocol::on_read(CacheLine* line) {
    if (line->state == State::Invalid)
        line->state = State::Shared;
}

void CoherenceProtocol::on_write(CacheLine* line) {
    line->state = State::Modified;
}

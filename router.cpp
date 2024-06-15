#include "router.h"

Router::~Router() { routingTable_.clear(); }

void Router::send(Packet *pk) {
    for (size_t i = 0; i < routingTable_.size(); i++) {
        if (routingTable_[i].destination == pk->destAddress()) {
            std::cout << "Router #" << this->id()
                      << ": forwarding packet (from: "
                      << pk->srcAddress().toString()
                      << ", to: " << pk->destAddress().toString() << ", "
                      << pk->data().size() << " bytes)" << std::endl;
            routingTable_[i].nextLink->sendData(pk, this);
            return;
        }
    }
    std::cout << "Router #" << this->id()
              << ": no route for packet (from: " << pk->srcAddress().toString()
              << ", to: " << pk->destAddress().toString() << ", "
              << pk->data().size() << " bytes)" << std::endl;
}

void Router::receive(Packet *pk) { send(pk); }


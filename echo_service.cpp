#include "echo_service.h"

void EchoService::dataProcessing(Packet *pk) {
    Packet *newpk = new Packet(pk->destAddress(), pk->srcAddress(), pk->destPort(), pk->srcPort(), pk->data());
    std::cout << "EchoService: received \"" << pk->dataString() << "\" from " << pk->srcAddress().toString() << ":" << pk->srcPort() << ", send reply with same data" << std::endl;
    host_->send(newpk);
}
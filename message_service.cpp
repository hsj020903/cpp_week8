#include "message_service.h"

#define ECHO_PORT 3000

void MessageService::send(std::string message) {
    Packet *packet =
        new Packet(host_->address(), destAddress_, port_, destPort_, message);
    host_->send(packet);
}
void MessageService::dataProcessing(Packet *pk) {
    std::cout << "MessageService: received \"" << pk->dataString()
              << "\" from " << pk->srcAddress().toString() << ":" << pk->srcPort()
              << std::endl;
}
#include "host.h"

Host::~Host(){
    services_.clear();
}

void Host::initialize() { 
    
}

void Host::send(Packet *packet) { 
    std::cout << "Host #" << this->id() << ": sending packet (from: "<< packet->srcAddress().toString() <<", to: " << packet->destAddress().toString() << ", " << packet->data().size() << " bytes)" << std::endl;;
    link_->sendData(packet, this); 
    }

void Host::addService(Service *service) { services_.push_back(service); }

void Host::receive(Packet *pk) {
    for (size_t i = 0; i < services_.size(); i++) {
        if (services_[i]->port() == pk->destPort()) {
            std::cout << "Host #" << this->id() << ": received packet, destination port: " << pk->destPort() << std::endl;
            services_[i]->dataProcessing(pk);
            return;
        }
    }
    std::cout << "Host #" << this->id() << ": no service for packet (from: " << pk->srcAddress().toString()
              << ", to: " << pk->destAddress().toString() << ", "
              << pk->data().size() << " bytes)" << std::endl;;
}
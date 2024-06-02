#include "service.h"

void Service::host_init(Host *host){
    host_ = host;
}

short Service::port(){
    return port_;
}
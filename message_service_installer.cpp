#include "message_service_installer.h"
#define MESSG_PORT 1000
MessageService *MessageServiceInstaller::install(Host *host){
    MessageService *messageService = new MessageService(host, MESSG_PORT, destAddress_, destPort_);
    ServiceInstaller::install(host, messageService);
    return messageService;
}
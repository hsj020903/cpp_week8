#include "service_installer.h"

void ServiceInstaller::install(Host *host, Service *service){
    host->addService(service);
    service->host_init(host);
}

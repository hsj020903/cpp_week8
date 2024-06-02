#ifndef SERVICE_H
#define SERVICE_H

#include "node.h"

class Host;

class Service {
    friend class ServiceInstaller;

  protected:
    // 서비스가 설치된 호스트
    Host *host_;

    // 서비스가 사용하는 포트
    short port_;

    Service(Host *host, int port) : host_(host), port_(port) {}
    
    
    public:
        //호스트 설정
        void host_init(Host *host);

        //포트 리턴
        short port();

        //데이터 처리
        virtual void dataProcessing(Packet *pk)=0;
};


#endif
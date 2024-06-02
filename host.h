#ifndef HOST_H
#define HOST_H

#include "address.h"
#include "packet.h"
#include "service.h"
#include <vector>

class Host : public Node {
    friend class ServiceInstaller;

  private:
    // 호스트의 주소
    Address address_;

    // 설치된 서비스 목록
    std::vector<Service *> services_;

  public:
    // 주소 리턴
    Address address() { return address_; }

    // 생성자
    Host(Address address) : address_(address) {}

    // 소멸자
    virtual ~Host();

    // 호스트와 설치된 서비스를 전부 초기화한다.
    void initialize();

    // 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
    void send(Packet *packet);

    // 받은 패킷을 처리한다
    void receive(Packet *pk);

    // 서비스목록에 추가
    void addService(Service *service);
};

#endif
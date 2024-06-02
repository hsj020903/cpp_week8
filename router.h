#ifndef ROUTER_H
#define ROUTER_H

#include "node.h"
#include <iostream>

struct RoutingEntry {
  public:
    RoutingEntry(Address a, Link *l) : destination(a), nextLink(l) {}
    Address destination; // 노드주소
    Link *nextLink;      // 보낼 주소
};

class Router : public Node {
  protected:
    std::vector<RoutingEntry> routingTable_;

  public:
    ~Router();
    // 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
    void send(Packet *pk);

    // 패킹 처리
    void receive(Packet *pk);
};

#endif
#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "packet.h"
#include <vector>

class Node {
    friend class LinkInstaller;

  private:
    // 자기 아이디
    int id_;

    // 다음아이디
    static int nextId_;

  protected:
    // 연결된 링크
    Link *link_;

  public:
    Node() : id_(nextId_++) {}
    ~Node();
    // 자신의 아이디 리턴
    int id() const { return id_; }

    void addLink(Link *link);
    virtual void send(Packet *pk)=0;
    virtual void receive(Packet *pk)=0;
};

#endif
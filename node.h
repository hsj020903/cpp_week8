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
    Link* links_;

  public:
    Node() : id_(nextId_++) {}
    ~Node();
    // 자신의 아이디 리턴
    int id() const { return id_; }
    void addLink(Link *link);

    //데이터 보내기
     virtual void send(Packet *pk) = 0;

     //받은 데이터 처리
    virtual void receive(Packet *pk) = 0;
};

#endif
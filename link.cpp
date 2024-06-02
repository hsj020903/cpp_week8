#include "link.h"
#include "node.h"

void Link::sendData(Packet *pk, Node* node){
    Node* nextnode = other(node);
    std::cout << "Link: forwarding packet from node #"<< node->id() << ", to node #" << nextnode->id() << std::endl;
    nextnode->receive(pk);
}

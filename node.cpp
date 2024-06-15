#include "node.h"

int Node::nextId_ = 0;

Node::~Node(){}
void Node::addLink(Link *link){
    links_ = link;
}


#include "node.h"

int Node::nextId_ = 0;

Node::~Node(){
    delete link_;
}

void Node::addLink(Link *link){
    link_ = link;
}
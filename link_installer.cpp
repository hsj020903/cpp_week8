#include "link_installer.h"

Link *LinkInstaller::install(Node *a, Node *b) { 
    Link *link = new Link(a, b);
    a->addLink(link);
    b->addLink(link);
    return link; 
    }
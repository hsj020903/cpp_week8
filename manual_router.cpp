#include "manual_router.h"

void ManualRouter::addRoutingEntry(const Address &destination, Link *nextLink) {
    RoutingEntry routingEntry = RoutingEntry(destination, nextLink);
    routingTable_.push_back(routingEntry);
}
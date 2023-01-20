#include "BackendService.h"

void BackendService::update(StatusMonitor* monitor)
{
    if(monitor->isCCAlive()) {
        std::cout << "Cloud Connector OK." << std::endl;
    }
    else {
        std::cout << "Cloud Connector failing state." << std::endl;
    }
}
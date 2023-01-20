#include <iostream>
#include <chrono>
#include <thread>
#include "StatusMonitor.h"
#include "BackendService.h"

int main(int argc, char** argv)
{
    IStatusObserver* service = new BackendService();
    StatusMonitor sm;

    sm.subscribe(service);

    std::this_thread::sleep_for(std::chrono::milliseconds(2500));

    sm.setCC(false);

    std::this_thread::sleep_for(std::chrono::milliseconds(2500));

    sm.setCC(true);

    return 0;
}
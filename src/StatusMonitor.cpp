#include "StatusMonitor.h"

void StatusMonitor::setVC(const bool isAlive)
{
    _isVCAlive = isAlive;
    notify();
}

void StatusMonitor::setDCS(const bool isAlive)
{
    _isDCSAlive = isAlive;
    notify();
}

void StatusMonitor::setCC(const bool isAlive)
{
    _isCCAlive = isAlive;
    notify();
}


bool StatusMonitor::isVCAlive()
{
    return _isVCAlive;
}
bool StatusMonitor::isDCSAlive()
{
    return _isDCSAlive;
}
bool StatusMonitor::isCCAlive()
{
    return _isCCAlive;
}

void StatusMonitor::notify()
{
    for(auto const& obs : v_obs) {
        obs->update(this);
    }
}

void StatusMonitor::subscribe(IStatusObserver* obs)
{
    if(std::find(v_obs.begin(), v_obs.end(), obs) == v_obs.end()) {
        v_obs.push_back(obs);
        std::cout << "Observer added." << std::endl;
    }
    else {
        std::cout << "Observer already subscribed. Nothing to do..." << std::endl;
    }
}
void StatusMonitor::unsubscribe(IStatusObserver* obs)
{
    if(auto it = std::find(v_obs.begin(), v_obs.end(), obs); it != v_obs.end()) {
        v_obs.erase(it);
        std::cout << "Observer removed." << std::endl;
    }
    else {
        std::cout << "Observer not subscribed. Nothing to do..." << std::endl;
    }
}
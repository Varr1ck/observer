#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <IStatusObserver.h>

class IStatusObserver;
class StatusMonitor
{
    private:
        std::vector<IStatusObserver*> v_obs;
        bool _isVCAlive{true};
        bool _isDCSAlive{true};
        bool _isCCAlive{true};

    public:
        void subscribe(IStatusObserver* obs);
        void unsubscribe(IStatusObserver* obs);

        void setVC(bool isAlive);
        void setDCS(bool isAlive);
        void setCC(bool isAlive);

        bool isVCAlive();
        bool isDCSAlive();
        bool isCCAlive();


        void notify();
};
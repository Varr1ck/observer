#pragma once

#include <iostream>
#include "IStatusObserver.h"

class BackendService : public IStatusObserver
{
    private:
        void update(StatusMonitor* monitor) override;
};
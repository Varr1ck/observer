#pragma once

#include "StatusMonitor.h"

class StatusMonitor;
class IStatusObserver
{
    protected:
        virtual void update(StatusMonitor* monitor) = 0;

    friend class StatusMonitor;
};
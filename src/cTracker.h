#pragma once
#include "cLife.h"

#ifndef CTRACKER_H
#define CTRACKER_H

class cTracker : public cLife {
public:
    cTracker(int xpos, int ypos);
    virtual ~cTracker() = default;
    virtual void draw();
    virtual void update();

    static std::string getLifeName() { return { "tracker" }; }
    static cLife* spawn(int x, int y);

protected:
};

#endif // CTRACKER_H
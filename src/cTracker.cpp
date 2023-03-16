#include "cTracker.h"
#include "ofMain.h"

//--------------------------------------------------------------
cTracker::cTracker(int xpos, int ypos)
    : cLife(xpos, ypos)
{
    m_color = ofColor::green;
    m_drawSize = 10;
}

//--------------------------------------------------------------
void cTracker::draw()
{
    if (m_health == 0)
        return;
    ofFill();
    ofSetColor(m_color);
    ofDrawCircle(m_xCentre, m_yCentre, m_drawSize * 0.5);
}

//--------------------------------------------------------------
void cTracker::update()
{
    
}

//--------------------------------------------------------------
cLife* cTracker::spawn(int x, int y)
{
    cTracker* pTracker = new cTracker(x, y);
    pTracker->addPendingHealthChange(1);
    return pTracker;
}

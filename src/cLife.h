#pragma once
#include <string>
#include <vector>
#include <map>
#include "ofMain.h"
#include "iCellQuery.h"

using NeighbourClassMap = std::map<std::string, size_t>;

class cTracker;

class cLife
{
public:   // accessible by any caller
    cLife(int xCentre, int yCentre);
    virtual ~cLife();   
    cLife(const cLife& other);                      // copy constructor
    virtual cLife& operator=(const cLife& other);    // copy assignment
    virtual void setup();
    virtual void reset() { m_health = 0; }
    virtual void destroy();
    virtual void simulate(const std::vector<cLife*>& simNeighbours);
    virtual void applySimulationChanges();
    virtual void draw();
    virtual std::string getName() { return m_name; }
    virtual bool isAlive() { return m_health != 0; }
    virtual int  getHealth() { return m_health;  }
    virtual void setPosition(int x, int y);
    virtual void getPosition(int& x, int& y);
    void setTracker(cTracker* tracker);
    void updateTracker();
    
    // note - each class that derives from cLife should have its own name and spawn()
    static std::string getLifeName() { return mk_LifeName; }
    static cLife* spawn(int x, int y);   

    // used only by the CellMatrix to register the Query interface
    static void setupQuery(iCellQuery& query);

protected:  // accessible by this class and derived classes
    virtual NeighbourClassMap countNeighbours(const std::vector<cLife*>& simNeighbours);
    virtual int interactWithNeighbours(const std::vector<cLife*>& simNeighbours, NeighbourClassMap& neighbourMap);
    virtual int  addPendingHealthChange(int health);

    static const std::string    mk_LifeName;
    static iCellQuery*          msp_query;
    const int   MAX_LIFE{ 1 };
    int         m_health{ 0 };                  // health value. if <=0 it will die.
    int         m_healthChange{ 0 };            // add this amount to health at the end of the update
    std::string m_name{ mk_LifeName };          // name of this life
    int         m_xCentre{ 0 };                 // x/horizontal - centre cell
    int         m_yCentre{ 0 };                 // y/vertical centre of cell
    int         m_drawSize{ 8 };                // size/radius when displayed on screen     
    ofColor     m_color{ ofColor::fireBrick };  // display colour


private:  // accessible by this class only
    cTracker* m_tracker = nullptr;
    //Unused stuff. how far to check for neighbours?
    //  virtual cLife* spawn(int x, int y);
    //  virtual int  getNeighbourThreshold() { return neighbourThreshold; }
    //  const int neighbourThreshold{ 1 };      
};

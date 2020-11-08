#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"

// This part is only relevant for non-Windows users in 2019.
// Windows users has Graph_lib::Arc, Mac don't.
#ifndef WIN32
#include "Graph_lib.hpp"
#endif

using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
    // Disable copying. Disable slicing, etc.
    Emoji(const Emoji&) = delete;
    Emoji& operator=(const Emoji&) = delete;
    
    // Deleting the copy constructor also deletes the default constructor.
    // Emoji needs a default constructor.
    Emoji() {}
    // Emoji() = default; // is an alternative way of achieving the same.
    
    // The pure virtual function that has to be overriden for a deriving class
    // to be instantiable. Every class deriving from Emoji is supposed to
    // attach all its Shapes to a window. This makes the class abstract.
    virtual void attach_to(Graph_lib::Window&) = 0;
    
    // Relevant because Vector_ref can own Emojis and automatically cleans up.
    // Subject will be visited later in the course.
    virtual ~Emoji() {}
};

// A yellow, empty face.
// An abstract class.
class Face : public Emoji
{
    /* TODO:
     *  - add shapes (private)
     *  - make the class abstract
     **/
protected:
    Circle face;
public:
    Face(Point c, int r);
    void attach_to(Graph_lib::Window& win)  override = 0;
    
};

/* TODO:
 *  - declare more emojis.
 **/

class EmptyFace : public Face {
protected:
     Circle e1,e2;
public:
    EmptyFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class SmilingFace : public EmptyFace {
protected:
    Arc smile;
public:
    SmilingFace(Point c, int r) : EmptyFace(c,r), smile{{c.x,c.y+10},r,r-3, 180,360} {}
    void attach_to(Graph_lib::Window&win) override;
};

class SadFace : public EmptyFace {
protected:
    Arc scowl;
public:
    SadFace(Point c, int r) : EmptyFace(c,r), scowl{{c.x,c.y+30},r,r-3, 0,180} {}
    void attach_to(Graph_lib::Window& win) override;
};

class AngryFace : public SadFace {
protected:
    Line frown1;
    Line frown2;
public:
    AngryFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class WinkingFace : public SmilingFace {
protected:
    Arc wink;
public:
    WinkingFace(Point c, int r);
    void attach_to(Graph_lib::Window& win) override;
};

class SurprisedFace : public EmptyFace {
protected:
    Arc mouth;
public:
    SurprisedFace(Point c, int r) : EmptyFace(c,r), mouth{{c.x,c.y+20},20,20,0,360} {}
    void attach_to(Graph_lib::Window& win) override;
};

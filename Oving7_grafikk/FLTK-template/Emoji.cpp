#include "Emoji.hpp"

/*
 * Implement your emojis in this file.
 **/

// A yellow, empty face.
Face::Face(Point c, int r) : face{c,r}
{
    face.set_fill_color(Color::yellow);
    /* TODO:
     *  - add member initializer list
     *  - implement the constructor. I.e. fill color
     **/

    cout << "Not yet implemented\n";
}

void Face::attach_to(Graph_lib::Window& win)
{
    /* TODO:
     *  - attach shapes to window
     **/
    win.attach(face);
}

/* TODO:
 *  - define more emojis.
 **/

EmptyFace::EmptyFace(Point c, int r) : Face(c,r), e1{{c.x-20,c.y-5},10}, e2{{c.x + 20, c.y -5},10} {
 
    e1.set_fill_color(Color::black);
    e2.set_fill_color(Color::black);
}


void EmptyFace::attach_to(Graph_lib::Window &win) {
    Face::attach_to(win);
    win.attach(e1);
    win.attach(e2);
}

void SmilingFace::attach_to(Graph_lib::Window &win) {
    EmptyFace::attach_to(win);
    win.attach(smile);
}


    void SadFace::attach_to(Graph_lib::Window &win) {
        EmptyFace::attach_to(win);
        win.attach(scowl);
    }


    AngryFace::AngryFace(Point c, int r) : SadFace(c,r), frown1{{c.x,c.y-10},{c.x-20,c.y-20}}, frown2{{c.x,c.y-10},{c.x+20,c.y-20}} {
        
    }
    
    void AngryFace::attach_to(Graph_lib::Window &win) {
        SadFace::attach_to(win);
        win.attach(frown1);
        win.attach(frown2);
    }
    
    WinkingFace::WinkingFace(Point c, int r) : SmilingFace(c,r), wink{{c.x + 20, c.y},18,18,0,180} {}
    
    void WinkingFace::attach_to(Graph_lib::Window &win) {
        SmilingFace::attach_to(win);
        win.attach(wink);
        win.detach(e2);
    }
    
    void SurprisedFace::attach_to(Graph_lib::Window &win) {
        EmptyFace::attach_to(win);
        win.attach(mouth);
    }
    
    

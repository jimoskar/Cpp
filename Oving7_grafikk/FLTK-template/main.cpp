#include "Simple_window.h"
#include "Emoji.hpp"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

int main()
{
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/
    Vector_ref<Emoji> emojis;
    
    SmilingFace emoji_1{{100,100}, emojiRadius};
    SurprisedFace emoji_2{{250,100},emojiRadius};
    SadFace emoji_3{{400,100},emojiRadius};
    AngryFace emoji_4{{550,100}, emojiRadius};
    WinkingFace emoji_5{{700,100}, emojiRadius};
    
    
    emojis.push_back(emoji_1);
    emojis.push_back(emoji_2);
    emojis.push_back(emoji_3);
    emojis.push_back(emoji_4);
    emojis.push_back(emoji_5);
    
    for (auto const &e : emojis ) {
        e->attach_to(win);
    }
    
    
	win.wait_for_button();
    
}

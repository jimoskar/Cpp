#include <vector>
#include <iostream>
#include <set>

using namespace std;


void replace(vector<string> &vec, string old, string replacement) {
    for( auto it = vec.begin(); it != vec.end(); ++it) {
        if(*it == old) {
            vec.insert(it, replacement);
            vec.erase(it);
        }
    }
}


int main(int argc, const char * argv[]) {
    
    
    vector<string> vec {"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
    set<string> s{"Lorem", "Ipsum", "Dolor", "Sit", "Amet", "Consectetur"};
    
    
    for( auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    
    for( auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << *it << " ";
    }
    
    for (set<string>::iterator it = s.begin(); it != s.end(); it++ ) {
        cout << *it;
    }
    
    return 0;
}

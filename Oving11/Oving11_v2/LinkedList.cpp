#include "LinkedList.hpp"


namespace LinkedList {
    

    std::ostream & operator<<(std::ostream & os, const Node & node) {
        os << node.value;
        return os;
    }
    
    Node* LinkedList::insert(Node* pos,const std::string &value) {
        if(pos == begin()) {
            head = std::make_unique<Node>(value, std::move(head), nullptr);
            pos->prev = begin();
            
        }
        Node* newNode = new Node{value, move(pos->prev->next),pos->prev};
        pos->prev->next = std::make_unique<Node>(newNode);
        pos->prev = pos->prev->next.get();
        return pos->prev;
    }

    Node* LinkedList::remove(Node *pos) {
        if(pos == begin()) {
            head = move(pos->next);
            head->prev = nullptr;
            return begin();
        }
        Node* ret = pos->getNext();
        pos->next->prev = pos->prev;
        pos->prev->next = move(pos->next);
        
        return ret;
    }
    
    

}

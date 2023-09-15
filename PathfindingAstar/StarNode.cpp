//
// Created by ignacio on 29/5/21.
//

#include "StarNode.h"

StarNode::StarNode(int x_, int y_, bool safe_, int H_){
    x = x_;
    y = y_;
    safe = safe_;
    H = H_;
    parent = NULL;
}

StarNode::StarNode(int x_, int y_, bool safe_, StarNode* parent_){
    x = x_;
    y = y_;
    safe = safe_;
    parent = parent_;
}
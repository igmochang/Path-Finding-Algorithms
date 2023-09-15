//
// Created by ignacio on 29/5/21.
//

#ifndef PATHFINDINGA__STARNODE_H
#define PATHFINDINGA__STARNODE_H
#include <iostream>

class StarNode {
public:


    StarNode(int x_, int y_, bool safe_, StarNode *parent_);

    StarNode(int x_, int y_, bool safe_, int H_);

    StarNode * parent;
    int x;
    int y;
    bool safe;

    int H;
    int G;
    int F;
};


#endif //PATHFINDINGA__STARNODE_H


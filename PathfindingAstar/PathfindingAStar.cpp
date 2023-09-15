//
// Created by ignacio on 29/5/21.
//
#include <stdio.h>
#include <iostream>
#include "PathfindingAStar.h"
#include <algorithm>

struct NodeComparator {
    bool operator ()(StarNode * node1, StarNode * node2){
        return node1->F < node2->F;

    }
};

PathfindingAStar::PathfindingAStar(int maze[N][M], int startX_, int startY_, int goalX_, int goalY_) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            myMaze[i][j] = maze[i][j];
        }
    }

    for (int k = 0; k < N; k++) {
        for (int l = 0; l < M; l++) {
            sol[k][l] = 0;
        }
    }

    for (int m = 0; m < N; m++) {
        for (int n = 0; n < M; n++) {
            matrix[m][n] = new StarNode(n,m,maze[m][n], abs(goalX-n)+ abs(goalY-m));
        }
    }

    startX = startX_;
    startY = startY_;
    goalX = goalX_;
    goalY = goalY_;

    openList.push_back(matrix[startY][startX]);
    matrix[startY][startX]->F = matrix[startY][startX]->H;
}

void PathfindingAStar::printSol(int sol[N][M]){
    for(int i = 0; i < N; i++){
        for (int j = 0; j<M; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool PathfindingAStar::isSafe(int x, int y){
    if (x>=0 && x < M && y >= 0 && y < N && myMaze[y][x] == 1){
        return true;
    } return false;
}

bool PathfindingAStar::findPath(){
    if (!solveUtil(matrix[startY][startX])){
        std::cout << "No hay solucion";
        return false;
    }
    createSol(matrix[goalY][goalX]);
    printSol(sol);
    return true;
}

bool PathfindingAStar::existsInOpenList(StarNode * node_){
    bool found = (std::find(openList.begin(), openList.end(), node_) != openList.end());
    return found;
}

bool PathfindingAStar::existsInClosedList(StarNode * node_){
    bool found = (std::find(closedList.begin(), closedList.end(), node_) != closedList.end());
    return found;
}

void PathfindingAStar::createSol(StarNode * node_){
    sol[node_->y][node_->x] = 1;
    if(node_->parent != NULL){
        createSol(node_->parent);
    }
}

void PathfindingAStar::addNeighbors(StarNode * node_){
    if(isSafe(node_->x-1, node_->y-1)){
        if (!existsInClosedList(matrix[node_->y-1][node_->x-1])){
            int newF = matrix[node_->y-1][node_->x-1]->H + node_->F + 14;
            if (existsInOpenList(matrix[node_->y-1][node_->x-1])){
                if(newF < matrix[node_->y-1][node_->x-1]->F){
                    matrix[node_->y-1][node_->x-1]->F = newF;
                    matrix[node_->y-1][node_->x-1]->parent = node_;
                }
            }
            else{
                openList.push_back(matrix[node_->y-1][node_->x-1]);
                matrix[node_->y-1][node_->x-1]->parent = node_;
                matrix[node_->y-1][node_->x-1]->F = newF;
            }
        }
    }
    if(isSafe(node_->x, node_->y-1)){
        if (!existsInClosedList(matrix[node_->y-1][node_->x])){
            int newF = matrix[node_->y-1][node_->x]->H + node_->F + 10;
            if (existsInOpenList(matrix[node_->y-1][node_->x])){
                if(newF < matrix[node_->y-1][node_->x]->F){
                    matrix[node_->y-1][node_->x]->F = newF;
                    matrix[node_->y-1][node_->x]->parent = node_;
                }
            }
            else{
                openList.push_back(matrix[node_->y-1][node_->x]);
                matrix[node_->y-1][node_->x]->parent = node_;
                matrix[node_->y-1][node_->x]->F = newF;
            }
        }
    }
    if(isSafe(node_->x+1, node_->y-1)){
        if (!existsInClosedList(matrix[node_->y-1][node_->x+1])){
            int newF = matrix[node_->y-1][node_->x+1]->H + node_->F + 14;
            if (existsInOpenList(matrix[node_->y-1][node_->x+1])){
                if(newF < matrix[node_->y-1][node_->x+1]->F){
                    matrix[node_->y-1][node_->x+1]->F = newF;
                    matrix[node_->y-1][node_->x+1]->parent = node_;
                }
            }
            else{
                openList.push_back(matrix[node_->y-1][node_->x+1]);
                matrix[node_->y-1][node_->x+1]->parent = node_;
                matrix[node_->y-1][node_->x+1]->F = newF;
            }
        }
    }
    if(isSafe(node_->x-1, node_->y)){
        if (!existsInClosedList(matrix[node_->y][node_->x-1])){
            int newF = matrix[node_->y][node_->x-1]->H + node_->F + 10;
            if (existsInOpenList(matrix[node_->y][node_->x-1])){
                if(newF < matrix[node_->y][node_->x-1]->F){
                    matrix[node_->y][node_->x-1]->F = newF;
                    matrix[node_->y][node_->x-1]->parent = node_;
                }
            }
            else{
                openList.push_back(matrix[node_->y][node_->x-1]);
                matrix[node_->y][node_->x-1]->parent = node_;
                matrix[node_->y][node_->x-1]->F = newF;
            }
        }
    }
    if(isSafe(node_->x+1, node_->y)){
        if (!existsInClosedList(matrix[node_->y][node_->x+1])){
            int newF = matrix[node_->y][node_->x+1]->H + node_->F + 10;
            if (existsInOpenList(matrix[node_->y][node_->x+1])){
                if(newF < matrix[node_->y][node_->x+1]->F){
                    matrix[node_->y][node_->x+1]->F = newF;
                    matrix[node_->y][node_->x+1]->parent = node_;
                }
            }
            else{
                openList.push_back(matrix[node_->y][node_->x+1]);
                matrix[node_->y][node_->x+1]->parent = node_;
                matrix[node_->y][node_->x+1]->F = newF;
            }
        }
    }
    if(isSafe(node_->x-1, node_->y+1)){
        if (!existsInClosedList(matrix[node_->y+1][node_->x-1])){
            int newF = matrix[node_->y+1][node_->x-1]->H + node_->F + 14;
            if (existsInOpenList(matrix[node_->y+1][node_->x-1])){
                if(newF < matrix[node_->y+1][node_->x-1]->F){
                    matrix[node_->y+1][node_->x-1]->F = newF;
                    matrix[node_->y+1][node_->x-1]->parent = node_;
                }
            }
            else{
                openList.push_back(matrix[node_->y+1][node_->x-1]);
                matrix[node_->y+1][node_->x-1]->parent = node_;
                matrix[node_->y+1][node_->x-1]->F = newF;
            }
        }
    }
    if(isSafe(node_->x, node_->y+1)){
        if (!existsInClosedList(matrix[node_->y+1][node_->x])){
            int newF = matrix[node_->y+1][node_->x]->H + node_->F + 10;
            if (existsInOpenList(matrix[node_->y+1][node_->x])){
                if(newF < matrix[node_->y+1][node_->x]->F){
                    matrix[node_->y+1][node_->x]->F = newF;
                    matrix[node_->y+1][node_->x]->parent = node_;
                }
            }
            else{
                openList.push_back(matrix[node_->y+1][node_->x]);
                matrix[node_->y+1][node_->x]->parent = node_;
                matrix[node_->y+1][node_->x]->F = newF;
            }
        }
    }
    if(isSafe(node_->x+1, node_->y+1)){
        if (!existsInClosedList(matrix[node_->y+1][node_->x+1])){
            int newF = matrix[node_->y+1][node_->x+1]->H + node_->F + 14;
            if (existsInOpenList(matrix[node_->y+1][node_->x+1])){
                if(newF < matrix[node_->y+1][node_->x+1]->F){
                    matrix[node_->y+1][node_->x+1]->F = newF;
                    matrix[node_->y+1][node_->x+1]->parent = node_;
                }
            }
            else{
                openList.push_back(matrix[node_->y+1][node_->x+1]);
                matrix[node_->y+1][node_->x+1]->parent = node_;
                matrix[node_->y+1][node_->x+1]->F = newF;
            }
        }
    }
}

bool PathfindingAStar::solveUtil(StarNode* node_){
    if (node_->x == goalX && node_->y == goalY && node_->safe){
        //sol[node_->y][node_->x] = 1;
        return true;
    }
    else if (openList.empty()){return false;}
    else{
        addNeighbors(node_);
        StarNode * analysed = openList.front();
        openList.pop_front();
        closedList.push_back(analysed);
        openList.sort(NodeComparator());

        if (solveUtil(openList.front())){
            return true;
        }
    }
}
//
// Created by ignacio on 27/5/21.
//

#include <stdio.h>
#include <iostream>
#include "Backtracking.h"


Backtracking::Backtracking(int maze[N][M], int startX_, int startY_, int goalX_, int goalY_) {
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
    startX = startX_;
    startY = startY_;
    goalX = goalX_;
    goalY = goalY_;
}

void Backtracking::printSol(int sol[N][M]){
    for(int i = 0; i < N; i++){
        for (int j = 0; j<M; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

bool Backtracking::isSafe(int maze[N][M], int x, int y){
    if (x>=0 && x < M && y >= 0 && y < N && maze[y][x] == 1){
        return true;
    } return false;
}

bool Backtracking::findPath(int maze[N][M]){
    if (!solveUtil(maze, startX, startY)) {
        std::cout << "No hay solucion";
        return false;
    } return true;
}

bool Backtracking::solveUtil(int maze[N][M], int x, int y){
    if (x == goalX && y == goalY && maze[y][x] == 1){
        sol[y][x] = 1;
        return true;
    }

    /*int ocup[N][M];
    for (int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            ocup[i][j] = maze[i][j];
        }
    }*/

    if (isSafe(maze, x, y)){
        if(sol[y][x] == 1){
            return false;
        }
        sol[y][x] = 1;
        //ocup[x][y] = 0;

        if (solveUtil(maze, x+1, y))
            return true;

        if(solveUtil(maze, x, y + 1))
            return true;

        if (solveUtil(maze, x - 1, y))
            return true;
        if (solveUtil(maze, x, y - 1))
            return true;

        sol[y][x] = 0;
        return false;
    }
    return false;
}
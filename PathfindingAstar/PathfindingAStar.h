//
// Created by ignacio on 29/5/21.
//
/**
 * @file PathfindingAStar.h
 * @author Ignacio Morales
 * @brief Algoritmo de busqueda Pathfinding A star
 * @version 1.0
 * @date 2021-05-29
 */
#ifndef PATHFINDINGA__PATHFINDINGASTAR_H
#define PATHFINDINGA__PATHFINDINGASTAR_H

#include <list>
#include "StarNode.h"

class PathfindingAStar {
public:
    static const int N = 10;
    static const int M = 15;
    /**
     * @brief constructor de clase PathfindingAStar
     * @param maze
     * @param startX_
     * @param startY_
     * @param goalX_
     * @param goalY_
     */
    PathfindingAStar(int maze[N][M], int startX_, int startY_, int goalX_, int goalY_);


    int myMaze[N][M];
    int startX;
    int startY;
    int goalX;
    int goalY;
    int sol[N][M];
    StarNode * matrix[N][M];
    std::list<StarNode*> openList;
    std::list<StarNode*> closedList;
    /**
     * @brief funcion de inicio
     * @return bool segun se encuentro o no un camino
     */
    bool findPath();
    /**
     * @brief funcion auxiliar de findPath
     * @param node_
     * @return bool
     */
    bool solveUtil(StarNode* node_);
    /**
     * @brief se agregan los nodos vecinos a openList
     * @param node_
     */
    void addNeighbors(StarNode *node_);
    /**
     * @brief revisa si un nodo ya existe en openList
     * @param node_
     * @return bool
     */
    bool existsInOpenList(StarNode *node_);
    /**
     * @brief revisa si un espacio es seguro
     * @param x
     * @param y
     * @return bool
     */
    bool isSafe(int x, int y);
    /**
     * @brief crea la matriz sol
     * @param node_
     */
    void createSol(StarNode *node_);
    /**
     * @brief imprime la solucion
     * @param sol
     */
    void printSol(int sol[N][M]);
    /**
     * revisa si un nodo ya existe en closedList
     * @param node_
     * @return
     */
    bool existsInClosedList(StarNode *node_);
};


#endif //PATHFINDINGA__PATHFINDINGASTAR_H

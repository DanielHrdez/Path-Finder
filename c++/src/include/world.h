// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Clase "mundo" para definir el comportamiento y características del entorno del vehiculo

#include "taxi.h"
#include "uber.h"
#include "f_heuristicas.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <random>
#include <time.h>
#include "termcolor.h"

#pragma once

class World {

protected:

    int row;
    int col;
    int size;
    std::vector<std::vector<Cell>> world;

    f_heuristica* heuristica;

public:

    World(); //Constructor por defecto
    World(int, int); //Constructor por tamaño
    explicit World(int, int, int, int); //constructor con tipo de insercion de obstaculos
    explicit World(int, int, int, int, int); //constructor con tipo de heuristica y de insercion de obstaculos
    virtual ~World();//Destructor

    inline int GetRow() {
        return row;
    } //devuelve el numero de filas total

    inline int GetColumn() {
        return col;
    } //devuelve el numero de columnas total

    inline int GetSize() {
        return size;
    }//devuelve el tamaño de la malla

    inline Cell GetCell(int i, int j){
        try{
            return world[i][j];   
        }
        catch(std::exception& e){
            throw e;
        }   
    }

    inline std::vector<std::vector<Cell>>& GetWorld(void){
        return world;
    }//pasa el mundo por referencia

    bool GetWorldValue(int, int); //devuelve el estado booleano de una celda

    void SetRow(int);
    void SetColumn(int);
    void SetSize(int);

    void SetWorldValue(bool, int, int); //establecer el valor booleano de una celda
    void ToggleWorldValue(int, int);
    void SetWorld(std::vector<std::vector<Cell>>&);

    void PrintWorld(void); //imprime la malla sola
    void PrintHorizontalWall(void); //imprime una pared horizontal
    //void Update(std::vector<Vehicle>&); //función que actualiza las casillas donde están las hormigas
    void PrintGrid (Vehicle*);

    bool VehicleOut(Vehicle*);
    void TryPosition(Vehicle*);

    std::pair<std::vector<int>, std::vector<int>> Dijkstra(int);
    std::vector<std::vector<int>> Adjacency_Graph_4();
    std::vector<std::vector<int>> Adjacency_Graph_8();
    int extraer_min(std::vector<int>, std::vector<bool>);



/*     std::vector<Cell> Astar(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal);
    void ReconstruirCamino(std::vector<Cell> &v, Cell actual, Cell I);
    bool IsInSet(const Cell& c, const std::vector<Cell>& s);
    void CambiarHeuristica(bool opt);
    void CaminoMinimo(unsigned int xInicio, unsigned int yInicio, unsigned int xFinal, unsigned int yFinal); */

};
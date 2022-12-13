// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Clase Simulation que define la relacion entre taxi y entorno (clase world)
 
#include <chrono>

#include "world.h"
 
#pragma once

class Simulation {

    private:

    int curr_iter;
    Vehicle* vehicle;
    World *grid;

    public:

    Simulation();
    Simulation(World*, Vehicle*);
    ~Simulation();
    
    int GetCurrIter(void); //devuelve el numero actual de iteraciones

    void SetCurrIter(int);

    void Loop(void);
    void Sort(void);
    void PrintData(void);

    std::vector<int> GetPath(int);
};
// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
//herencia del taxi en la clase uber

#include "vehicle.h"

#pragma once
class Uber: public Vehicle
{

using Vehicle::Vehicle;

virtual void Turn(int nodo, int grid_row, int grid_col) {
    int current = GetRow() + grid_row / 2 + grid_row * (GetColumn() + grid_col / 2);
    if (nodo == current - 1) direction = 1;
    if (nodo == current + grid_row) direction = 2;
    if (nodo == current + 1) direction = 3;
    if (nodo == current - grid_row) direction = 4;
}

virtual void Move(void) {
    if(direction == 1)
        row_pos += -1;
    else if(direction == 2) {
        column_pos += 1;
    }
    else if (direction == 3)
        row_pos += 1;
    else if(direction == 4) {
        column_pos += -1;
    }
    else std::cout << "aquí ha habido un error, direction = " << direction << std::endl;
}
};
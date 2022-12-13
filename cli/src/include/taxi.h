// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
//herencia del vehiculo en la clase taxi

#include "vehicle.h"
#pragma once
class Taxi: public Vehicle
{

using Vehicle::Vehicle;
 
virtual void Turn(int nodo, int grid_row, int grid_col) {
    int current = GetRow() + grid_row / 2 + grid_row * (GetColumn() + grid_col / 2);
    if (nodo == current - 1) direction = 1;
    if (nodo == current - 1 + grid_row) direction = 2;
    if (nodo == current + grid_row) direction = 3;
    if (nodo == current + 1 + grid_row) direction = 4;
    if (nodo == current + 1) direction = 5;
    if (nodo == current + 1 - grid_row) direction = 6;
    if (nodo == current - grid_row) direction = 7;
    if (nodo == current - 1 - grid_row) direction = 8;
}

virtual void Move(void) {
    if(direction == 1)
        row_pos += -1;
    else if(direction == 2) {
        row_pos += -1;
        column_pos += 1;
    }
    else if (direction == 3)
        column_pos += 1;
    else if(direction == 4) {
        row_pos += 1;
        column_pos += 1;
    }
    else if(direction == 5)
        row_pos += 1;
    else if(direction == 6) {
        row_pos += 1;
        column_pos += -1;
    }
    else if(direction == 7)
        column_pos += -1;
    else if(direction == 8) {
        row_pos += -1;
        column_pos += -1;
    }
    else std::cout << "aquí ha habido un error, direction = " << direction << std::endl;

}
};
// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Especificaciones de la clase taxi

#include "include/vehicle.h"
#include "include/world.h"

//Constructores
Vehicle::Vehicle() {
    row_pos = 0;
    column_pos = 0;
    direction = 1;
    destination_row = 4;
    destination_col = 7;
}

Vehicle::Vehicle(int i, int j, int row_destination, int col_destination){
    row_pos = i;
    column_pos = j;
    destination_row = row_destination;
    destination_col = col_destination;
}

//Destructor
Vehicle::~Vehicle(){
}

//Getters y setters
int Vehicle::GetRow(void) {
    return row_pos;
}

int Vehicle::GetColumn(void) {
    return column_pos;
}

int Vehicle::GetDestinationRow(void) {
    return destination_row;
}

int Vehicle::GetDestinationColumn(void) {
    return destination_col;
}

int Vehicle::GetDirection(void) {
    return direction;
}

void Vehicle::SetRow(int row) {
    row_pos = row;
}

void Vehicle::SetColumn(int column) {
    column_pos = column;
}

void Vehicle::SetDirection(int next_direction) {
    direction = next_direction;
}

void Vehicle::Update(World& grid, int nodo) {
    try{
        Turn(nodo, grid.GetRow(), grid.GetColumn());
        grid.ToggleWorldValue(GetRow(), GetColumn());
        grid.SetWorldValue(2, GetRow(), GetColumn());
        Move(); 
    }
    catch (std::exception& e){
        throw e;
    }
}
// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Este programa simula el comportamiento del taxi autonomo en un formto de texto.
// chcp.com 65001 arregla el encoding

#include "include/simulation.h"

int main( void /* int argc, char* argv[]*/ ) {
    int row, col, vehicle_row, vehicle_col, menu, vehicle_type;
    int destination_row, destination_col, obstacle_percentage, obstacle_type = -1, heuristic_type = -1;

    std::cout << "¿Desea el comportamiento por defecto del mundo con matriz 20x20 (0), o personalizar la experiencia (1)?\n";
    std::cout << "Introduzca 0 o 1: ";
    std::cin >> menu;
    while ((menu != 0) && (menu != 1)) {
        std::cout << "¡Eso no era un 1 o un 0! Ojito cuidado. " << std::endl << "Introduzca 0 o 1: ";
        std::cin >> menu;
    }

if (menu == 0) {
    row = 20;
    col = 20;
    obstacle_percentage = 30;
    obstacle_type= 0;
    heuristic_type = 0;
}
else {
    std::cout << "Introduzca el Ancho: ";
    std::cin >> row;
    while (row <= 0) {
        std::cout << "Eso era menor que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el Ancho: " << std:: endl;
        std::cin >> row;
    }

    std::cout << "Introduzca el Alto: ";
    std::cin >> col;
    while (col <= 0) {
        std::cout << "Eso era menor que 0. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el Alto: " << std:: endl;
        std::cin >> col;
    }

    std::cout << "Introduzca el porcentaje de obstaculos (entre 0 y 100): " << std:: endl;
    std::cin >> obstacle_percentage;
    while ((obstacle_percentage < 0) || (obstacle_percentage > 100)) {
        std::cout << "Eso no estaba entre 0 y 100. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca el numero de obstaculos (entre 0 y 100): " << std:: endl;
        std::cin >> obstacle_percentage;
    }

    std::cout << "¿Desea generacion automatica de obstaculos (0), introducirlos manualmente(1) o por fichero(2)?\n";
    std::cout << "Introduzca 0, 1 o 2: ";
    std::cin >> obstacle_type;
    while ((obstacle_type != 0) && (obstacle_type != 1) && (obstacle_type != 2)) {
        std::cout << "¡Eso no era un 1 o un 0! Ojito cuidado. " << std::endl << "Introduzca 0, 1 o 2: ";
        std::cin >> obstacle_type;
    }
    
    std::cout << "¿Desea empleaar una función heurística Manhattan (0), Euclídea (1) o por fichero(2)?\n";
    std::cout << "Introduzca 0, 1 o 2: ";
    std::cin >> heuristic_type;
    while ((heuristic_type != 0) && (heuristic_type != 1) && (heuristic_type != 2)) {
        std::cout << "¡Eso no era un 1 o un 0! Ojito cuidado. " << std::endl << "Introduzca 0, 1 o 2: ";
        std::cin >> heuristic_type;
    }
}

World* pWorld;
pWorld = new World(row, col, obstacle_percentage, obstacle_type);

Vehicle* pvehicle;

std::cout << "¿Coche de 8 o 4 direcciones?: ";
std::cin >> vehicle_type;
while ((vehicle_type != 8) && (vehicle_type != 4)) {
    std::cout << "Elige entre 8 y 4:" << std::endl;
    std::cin >> vehicle_type;
}

std::cout << "Introduzca la coordenada X del taxi: ";
std::cin >> vehicle_row;
while ((vehicle_row < 0) || (vehicle_row > row-1)) {
    std::cout << "Esa coordenada X no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
    std::cout << "Introduzca una coordenada entre " << 0 << " y " << row-1 << std:: endl;
    std::cin >> vehicle_row;
}

std::cout << "Introduzca la coordenada Y del taxi: ";
std::cin >> vehicle_col;
while ((vehicle_col < 0) || (vehicle_col > col-1)) {
    std::cout << "Esa coordenada Y no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
    std::cout << "Introduzca una coordenada entre " << 0 << " y " << col-1 << std:: endl;
    std::cin >> vehicle_col;
}

do {
    std::cout << "Introduzca la coordenada X de destino: ";
    std::cin >> destination_row;
    while ((destination_row <= 0) || (destination_row > row -1)) {
        std::cout << "Esa coordenada X no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca una coordenada entre " << 0 << " y " << row-1 << std:: endl;
    std::cin >> destination_row;
    }

    std::cout << "Introduzca la coordenada Y de destino: ";
    std::cin >> destination_col;
    while ((destination_col <= 0) || (destination_col > col-1)) {
        std::cout << "Esa coordenada Y no está dentro del mundo previamente definido. Ojito Cuidado" << std::endl;
        std::cout << "Introduzca una coordenada entre " << 0 << " y " << col-1 << std:: endl;
        std::cin >> destination_col;
    }
    
} while ((pWorld->GetWorldValue(destination_row, destination_col)) == true); //mientras la direccion de origen esté ocupada por un obstaculo se repite el proceso de instertar direccion de origen


if (vehicle_type == 8) 
    pvehicle = new Taxi(vehicle_row, vehicle_col, destination_row, destination_row);
else 
    pvehicle = new Uber(vehicle_row, vehicle_col, destination_row, destination_row);

Simulation universe(pWorld, pvehicle);
universe.Loop();

return 0;
}

//blanca = false = " "
//negra = true = "X"
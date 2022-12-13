// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Clase vehiculo que contiene las características del vehiculo

class World;

#include <iostream>
#include <stdio.h>
#include <vector>
#include "termcolor.h"

#pragma once

class Vehicle {
protected:
    int row_pos;
    int column_pos;
    int direction;
    int destination_row;
    int destination_col;
    std::vector<bool> sensor;

    virtual void Turn(int, int, int) = 0;

    virtual void Move(void) = 0; //Hace que la hormiga avance su posición una casilla en función de su dirección

    public:

    Vehicle();
    Vehicle(int, int, int, int);
    ~Vehicle();

    int GetRow(void); //devulve la fila en la que se encuentra la hormiga
    int GetColumn(void); //devulve la columna en la que se encuentra la hormiga
    int GetDirection(void); //devuelve la dirección que tiene la hormiga
    int GetDestinationRow(void); //devuelve la fila en la que se encuentrab la direccion de destino del vehiculo
    int GetDestinationColumn(void); //devuelve la columna en la que esta la direccion de destino

    void SetRow(int);
    void SetColumn(int);
    void SetDirection(int);

    virtual void Update(World&, int); //hace el giro y el movimiento en funcion de la casilla

    void PrintDirection(void) {
        std::cout << termcolor::on_blue << ">" << termcolor::reset;
    }
    
   /* void Turn90R(void); //cambia la dirección de la hormiga 90 grados a la derecha
    void Turn90L(void); //cambia la dirección de la hormiga 90 grados a la izquierda

    void Turn45R(void);
    void Turn45L(void); */

};
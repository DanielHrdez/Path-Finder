// AUTHOR: Juan García Santos
// DATE: 04/10/2021
// EMAIL: alu0101325583@ull.edu.es
// VERSION: 4.0
// SUBJECT: AI
// PRACTICE Nº: 1
// Compilation: make
// Execution: ./simulation
// Pequeño struct para representar las celdas

#pragma once

class Cell {
    private:

    bool is_closed_; // Está en closed_list?
    bool is_frontier_; // Está en open_list?

    bool value = false; //libre(false) u ocupado (true)
    char state = ' '; // X pasó por ahí, " " libre, O obstaculo.

    int x; //coordenada x
    int y; //cordenada y

    double f_; // Coste estimado desde nodo inicial a nodo objetivo (g(n) + h(n))
    double h_; // Coste estimado desde este nodo al nodo objetivo
    double g_; // Coste desde el nodo inicial a este nodo

    public:

    Cell(int row = 0, int col = 0) {
        x = row;
        y = col;
    }
    ~Cell() {};

    bool GetValue() const {
        return value;
    }
    char GetState() const {
        return state;
    }

    int GetX() const {
        return x;
    }
    int GetY() const {
        return y;
    }

    bool GetValue() {
        return value;
    }
    char GetState() {
        return state;
    }

    int GetX() {
        return x;
    }
    int GetY() {
        return y;
    }

    void SetValue(bool new_value) {
        value = new_value;
    }
    void SetState(char new_state) {
        state = new_state;
    }

    void SetX(int x_) {
        x = x_;
    }
    void SetY(int y_) {
        y = y_;
    }

};
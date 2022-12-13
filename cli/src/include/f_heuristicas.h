  
#ifndef F_HEURISTICAS_H
#define F_HEURISTICAS_H

#include <cmath>
#include <algorithm>
#include "cell.h"

class f_heuristica
{
public:
    f_heuristica();
    ~f_heuristica();

    virtual int operator()(const Cell&, const Cell&) = 0;
};

//-----------------------DISTANCIA EUCLIDEA-------------------------

class d_euclidea : public f_heuristica
{
public:
    d_euclidea();
    ~d_euclidea();
    int operator()(const Cell& i, const Cell& f) {
        return static_cast<int>(sqrt(pow((i.GetX() - f.GetX()),2) + pow((i.GetY() - f.GetY()), 2)));
    }
};

//-----------------------DISTANCIA RECTILINEA-----------------------

class d_manhattan : public f_heuristica
{
public:
    d_manhattan();
    ~d_manhattan();
    int operator()(const Cell& i, const Cell& f) {
        return static_cast<int>(fabs(static_cast<double>(i.GetX() - f.GetX())) + fabs(static_cast<double>(i.GetY() - f.GetY())));
    }
};

//-----------------------DISTANCIA TCHEBYSEV-----------------------

class d_tchebysev : public f_heuristica
{
public:
    d_tchebysev();
    ~d_tchebysev();
    int operator()(const Cell& i, const Cell& f) {
        return static_cast<int>( std::max( fabs( static_cast<double>( i.GetX() - f.GetX())) , fabs( static_cast<double>( i.GetY() - f.GetY()))));
    }
};

#endif // F_HEURISTICAS_H
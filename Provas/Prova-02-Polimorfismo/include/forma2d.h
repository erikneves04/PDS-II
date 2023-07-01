#ifndef FORMA_2D_H
#define FORMA_2D_H

#include <string>
#include "forma.h"

/**
 * @brief Responsável por representar uma forma 2d.
*/
class Forma2D
    : public Forma
{
    public: 
        /**
         * @brief Retorna a área dessa forma.
        */
        virtual double get_area() = 0;

        /**
         * @brief Retorna a perímetro dessa forma.
        */
        virtual double get_perimetro() = 0;
};

#endif
#ifndef FORMA_3D_H
#define FORMA_3D_H

#include <string>
#include "forma.h"

/**
 * @brief Responsável por representar uma forma 3d.
*/
class Forma3D
    : public Forma
{
    public: 
        /**
         * @brief Retorna o volume dessa forma.
        */
        virtual double get_volume() = 0;
};

#endif
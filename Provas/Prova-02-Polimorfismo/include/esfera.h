#ifndef ESFERA_H
#define ESFERA_H

#include <string>
#include "forma3d.h"

/**
 * @brief Responsável por representar uma esfera.
*/
class Esfera
    : public Forma3D
{
    private:
        int _raio;

    public: 
        /**
         * @brief Construtor responsável por inicializar um esfera.
         * @param cor cor do quadrado.
         * @param raio raio de um circulo.
        */
        Esfera(std::string cor, int raio);

        /**
         * @brief Retorna a cor dessa forma.
        */
        std::string get_cor() override;
        
        /**
         * @brief Retorna o nome dessa forma.
        */
        std::string get_nome() override;

        /**
         * @brief Retorna o volume dessa forma.
        */
        double get_volume() override;
};

#endif
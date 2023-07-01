#ifndef CUBO_H
#define CUBO_H

#include <string>
#include "forma3d.h"

/**
 * @brief Responsável por representar um cubo.
*/
class Cubo
    : public Forma3D
{
    private:
        int _lado;

    public: 
        /**
         * @brief Construtor responsável por inicializar um cubo.
         * @param cor cor do quadrado.
         * @param lado tamanho do lado.
        */
        Cubo(std::string cor, int lado);

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
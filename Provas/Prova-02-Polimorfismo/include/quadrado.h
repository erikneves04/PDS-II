#ifndef QUADRADO_H
#define QUADRADO_H

#include <string>
#include "forma2d.h"

/**
 * @brief Responsável por representar um quadrado.
*/
class Quadrado
    : public Forma2D
{
    private:
        int _lado;

    public: 
        /**
         * @brief Construtor responsável por inicializar um quadrado.
         * @param cor cor do quadrado.
         * @param lado tamanho do lado.
        */
        Quadrado(std::string cor, int lado);

        /**
         * @brief Retorna a cor dessa forma.
        */
        std::string get_cor() override;
        
        /**
         * @brief Retorna o nome dessa forma.
        */
        std::string get_nome() override;

        /**
         * @brief Retorna a área dessa forma.
        */
        double get_area() override;

        /**
         * @brief Retorna a perímetro dessa forma.
        */
        double get_perimetro() override;
};

#endif
#ifndef TRIANGULO_H
#define TRIANGULO_H

#include <string>
#include "forma2d.h"

/**
 * @brief Responsável por representar um triangulo.
*/
class Triangulo
    : public Forma2D
{
    private:
        int _lado_1, _lado_2, _lado_3;

    public: 
        /**
         * @brief Construtor responsável por inicializar um triangulo.
         * @param cor cor do quadrado.
         * @param lado1 primeira arestra.
         * @param lado2 segunda arestra.
         * @param lado3 terceira arestra.
        */
        Triangulo(std::string cor, int lado1, int lado2, int lado3);

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
#ifndef CIRCULO_H
#define CIRCULO_H

#include <string>
#include "forma2d.h"

/**
 * @brief Responsável por representar um circulo.
*/
class Circulo
    : public Forma2D
{
    private:
        int _raio;

    public: 
        /**
         * @brief Construtor responsável por inicializar um circulo.
         * @param cor cor do quadrado.
         * @param raio raio de um circulo.
        */
        Circulo(std::string cor, int raio);

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
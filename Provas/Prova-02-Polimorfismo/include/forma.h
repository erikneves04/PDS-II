#ifndef FORMA_H
#define FORMA_H

#include <string>

/**
 * @brief Responsável por representar uma forma.
*/
class Forma
{
    protected:
        std::string _cor;
        std::string _nome;

    public: 
        /**
         * @brief Retorna a cor dessa forma.
        */
        virtual std::string get_cor() = 0;
        
        /**
         * @brief Retorna o nome dessa forma.
        */
        virtual std::string get_nome() = 0;
};

#endif
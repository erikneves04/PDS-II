#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

/**
 * @brief Classe reponsável por gerir os atributos e métodos comuns a todos os pacotes.
*/
class Package
{
    private:
        std::string _nome;
        std::string _endereco;
    
    protected:
        unsigned int _peso;
        unsigned int _custoPorQuilo;

    public:
        /**
         * @brief Construtor do pacote.
         * @param peso peso do objeto.
         * @param custo por quilo.
         * @param nome nome do destinatário.
         * @param endereco endereço de destino.
        */
        Package(unsigned int peso, unsigned int custoPorQuilo, std::string nome, std::string endereco);
    
        /**
         * @brief Calcula o preço do envio.
         * @return o valor total do despacho.
        */
        virtual double calculate_cost();

        /**
         * @brief Retorna o destinatário desse pacote.
        */
        std::string GetDestinatario();
};

#endif
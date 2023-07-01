#ifndef TWO_DAY_PACKAGES_H
#define TWO_DAY_PACKAGES_H

#include <string>
#include "package.h"

/**
 * @brief Classe reponsável por gerir os atributos e métodos comuns a todos os pacotes entregues em até dois dias.
*/
class TwoDayPackage
    : public Package
{
    private:
        double _taxaFixa;

    public:
        /**
         * @brief Construtor do pacote entregue em até dois dias.
         * @param peso peso do objeto.
         * @param custo por quilo.
         * @param taxaFixa taxa fixa desse serviço.
         * @param nome nome do destinatário.
         * @param endereco endereço de destino.
        */
        TwoDayPackage(unsigned int peso, unsigned int custoPorQuilo, double taxaFixa, std::string nome, std::string endereco);

        /**
         * @brief Calcula o preço do envio considerando a taxa fixa cobrada pelo serviço.
         * @return o valor total do despacho.
        */
        double calculate_cost() override;
};

#endif
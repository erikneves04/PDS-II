#ifndef OVERNIGHT_PACKAGE_H
#define OVERNIGHT_PACKAGE_H

#include <string>
#include "package.h"

/**
 * @brief Classe reponsável por gerir os atributos e métodos comuns a todos os pacotes entregues no dia seguinte.
*/
class OverNightPackage
    : public Package
{
    private:
        double _taxaPorQuilo;

    public:
        /**
         * @brief Construtor do pacote entregue em até dois dias.
         * @param peso peso do objeto.
         * @param custo por quilo.
         * @param taxaPorQuilo taxa cobrada baseada no preço do objeto.
         * @param nome nome do destinatário.
         * @param endereco endereço de destino.
        */
        OverNightPackage(unsigned int peso, unsigned int custoPorQuilo, double taxaPorQuilo, std::string nome, std::string endereco);

        /**
         * @brief Calcula o preço do envio considerando a taxa fixa cobrada por quilo do objeto.
         * @return o valor total do despacho.
        */
        double calculate_cost() override;
};

#endif
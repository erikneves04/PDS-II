#ifndef DESTINATION_PACKAGES_H
#define DESTINATION_PACKAGES_H

#include <map>
#include <string>
#include <vector>
#include "package.h"

/**
 * @brief Classe reponsável por gerenciar os destinatários e seus pacotes.
*/
class DestinationPackages
{
    private:
        std::map<std::string, std::vector<Package*>> _destinatarios;

    public:
        /**
         * @brief Adiciona um novo pacote ao mapa.
         * @param g Um ponteiro para o pacote.
        */
        void add_package(Package* g);

        /**
         * @brief Calcula o custo total do envio de todos os destinatários.
        */
        double custo_total();

        /**
         * @brief Calcula o custo total do envio de um destinatário específico.
         * @param destinatario nome do destinatário buscado.
        */
        double custo_total(std::string destinatario);
};

#endif
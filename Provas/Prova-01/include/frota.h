#ifndef PDS2_FROTA_H
#define PDS2_FROTA_H

#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>

#include "carro.h"

class zero_carros_disponiveis_e {};
class id_ja_existe_e {};

/*
 * A frota simplesmente cuida do nosso comboio. Isto é, podemos adicionar
 * carros para a frota e remover os mesmos alocando para uma corrida.
 * TODO: ALGUMAS (ou TODAS) de suas tarefas aqui:
 *   1. Garantir que exceções são lançadas.
 *   2. Garantir que sempre o primeiro carro cadastrado é o alocado para corrida
 *      caso não esta disponível, passe para o próximo.
 *   3. Ajustar bugs e memory leaks caso existam
 *
 *  Altere o container (ou adicione outros) se necessário
 */
class Frota {
    private:
        std::list<Carro*> _carros;
        std::map<unsigned int, Carro*> _carros_alocados;
    public:
        /*
         * @brief Cadastra um carro novo no sistema.
         * @throws Lança uma exceção se o id informado já for usado por outro carro.
         */
        void cadastrar_carro(std::string cor, unsigned int id);
        
        /*
         * @brief Adiciona um novo carro aos carros da frota
         */
        void adicionar_carro(Carro* carro);
        
        /*
         * @brief Aloca um carro. O carro alocado deve ser aquele que foi
         *        cadastrado mais no passado.
         */
        Carro* alocar_carro();

        /*
         * @brief Limpa todos os carros cadastrados.
         */
        void limpar_carros_cadastrados();
};

#endif
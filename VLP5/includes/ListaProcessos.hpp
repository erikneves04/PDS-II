#ifndef PROCESS_LIST_H
#define PROCESS_LIST_H

#include "Processo.hpp"
#include <vector>

class ListaProcessos
{
    private:
        std::vector<Processo> _processList;
    
        int FindPositionForPriority(int priority);
        Processo RemoveForIndex(int index);

    public:
        ListaProcessos();

        void adicionar_processo(Processo process);
        Processo remover_processo_maior_prioridade();
        Processo remover_processo_menor_prioridade();
        Processo remover_processo_por_id(int id);
        void imprimir_lista();
};

#endif
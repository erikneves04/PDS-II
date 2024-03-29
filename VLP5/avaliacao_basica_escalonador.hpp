#ifndef AVALIACAO_H
#define AVALIACAO_H

#include <iostream>
#include "includes/ListaProcessos.hpp"

using namespace std;

void avaliacao_basica() {
    
    ListaProcessos lista;

    lista.adicionar_processo(Processo(1, "Proc1", 3));
    lista.adicionar_processo(Processo(2, "Proc2", 2));
    lista.adicionar_processo(Processo(3, "Proc3", 1));
    lista.adicionar_processo(Processo(4, "Proc4", 2));
    lista.adicionar_processo(Processo(5, "Proc5", 5));

    lista.imprimir_lista();
    cout << "----------" << endl;

    Processo maior_prioridade = lista.remover_processo_maior_prioridade();
    maior_prioridade.imprimir_dados();
    cout << "----------" << endl;

    lista.imprimir_lista();
    cout << "----------" << endl;

    Processo menor_prioridade = lista.remover_processo_menor_prioridade();
    menor_prioridade.imprimir_dados();
    cout << "----------" << endl;

    lista.imprimir_lista();    
    cout << "----------" << endl;

    Processo processo_id = lista.remover_processo_por_id(1);
    processo_id.imprimir_dados();
    cout << "----------" << endl;

    lista.imprimir_lista();
}

#endif
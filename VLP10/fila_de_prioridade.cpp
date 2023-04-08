#include "includes/fila_de_prioridade.h"

typedef struct No
{
    std::string _nome;
    int _idade;

    No* _proximo;

    No(std::string nome, int idade, No* prox)
    {
        _nome = nome;
        _idade = idade;

        _proximo = prox;
    }
}No;

FilaDePrioridade::FilaDePrioridade()
{
    tamanho_ = 0;
    primeiro_ = nullptr;
}

string FilaDePrioridade::primeiro() const
{
    return primeiro_->_nome;
}

int FilaDePrioridade::tamanho() const
{
    return tamanho_;
}

bool FilaDePrioridade::vazia() const
{
    return tamanho_ == 0;
}

void FilaDePrioridade::RemoverPrimeiro()
{
    if (vazia())
        return;

    tamanho_--;

    No* removido = primeiro_;

    primeiro_ = removido->_proximo;
    removido->_proximo = nullptr;
}

void FilaDePrioridade::Inserir(int p, string s)
{
    No * anterior = nullptr;
    No * atual = primeiro_;
    No * novo_item = new No(s, p, nullptr);

    tamanho_++;

    if (atual == nullptr)
    {
        primeiro_ = novo_item;
        return;
    }

    while (atual != nullptr)
    {

        if (atual->_idade < p)
        {
            if (anterior == nullptr)
            {
                primeiro_ = novo_item;
            }
            else
            {
                anterior->_proximo = novo_item;
            }

            novo_item->_proximo = atual;
            return;
        }

        anterior = atual;
        atual = atual->_proximo;
    }

    anterior->_proximo = novo_item;
}

void FilaDePrioridade::Limpar()
{
    No * atual = primeiro_;

    while (atual != nullptr)
    {
        No * next = atual->_proximo;
        free(atual);
        atual = next;
    }

    tamanho_ = 0;
}
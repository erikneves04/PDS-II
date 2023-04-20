#include "includes/fila.h"

struct No
{
    int chave;
    No *proximo;
};

Fila::Fila()
{
    primeiro_ = nullptr;
    ultimo_ = nullptr;

    tamanho_ = 0;
}

void Fila::Inserir(int k)
{
    No * novoItem = new No();
    novoItem->chave = k;

    if (primeiro_ == nullptr)
    {
        primeiro_ = novoItem;
        ultimo_ = novoItem;
    }
    else
    {
        ultimo_->proximo = novoItem;
        ultimo_ = novoItem;
    }

    tamanho_++;
}

void Fila::RemoverPrimeiro()
{
    ThrowExceptionIfIsEmpty();
    
    No * primeiro = primeiro_;

    primeiro_ = primeiro_->proximo;

    tamanho_--;
    delete(primeiro);

    if (tamanho_ == 0)
        ultimo_ = nullptr;
}

int Fila::primeiro() const
{
    ThrowExceptionIfIsEmpty();
    return primeiro_->chave;
}

int Fila::ultimo() const
{
    ThrowExceptionIfIsEmpty();
    return ultimo_->chave;
}

int Fila::tamanho() const
{
    return tamanho_;
}

void Fila::ThrowExceptionIfIsEmpty() const
{
    if(tamanho_ == 0)
        throw Fila::ExcecaoFilaVazia();
}
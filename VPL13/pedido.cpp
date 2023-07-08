#include "pedido.hpp"


Pedido::~Pedido() {
  for(auto produto : m_produtos)
  {
    delete produto;
  }
}

void Pedido::setEndereco(const std::string& endereco) {
  m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float soma = 0;

  for(auto produto : m_produtos)
  {
    int quantidade = produto->getQtd();
    float valor = produto->getValor();
    soma += (quantidade * valor);
  }

  return soma;
}

void Pedido::adicionaProduto(Produto* p) 
{
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  std::string resumo = "";

  for(auto produto : m_produtos)
  {
    resumo += produto->descricao() + "\n";
  }

  resumo += "Endereco: "+ m_endereco;

  return "Endereco: "+ m_endereco;
}
#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  for(auto pedido : m_pedidos)
  {
    delete pedido;
  }
}

void Venda::adicionaPedido(Pedido* p) {
  std::cout << "entrou " << std::endl;
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  int atual = 1;
  float soma = 0;
  for(auto pedido : m_pedidos)
  {
    std::cout << "Pedido " << atual << std::endl;
    atual++;
    pedido->resumo();
    soma += pedido->calculaTotal();
  }
  
  std::cout << "Total de vendas: R$ " << soma << std::endl;
  std::cout << "Total de pedidos: " << atual << std::endl;
}
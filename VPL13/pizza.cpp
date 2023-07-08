#include "pizza.hpp"

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
   
  std::string borda = (_bordaRecheada) ? " e" : " sem";
  ;
  return ""+std::to_string(m_qtd)+"X Pizza "+_sabor+", "+std::to_string(_pedacos)+borda+" borda recheada";
}

Pizza::Pizza(const std::string& sabor, int pedacos, bool borda_recheada, int qtd, float valor_unitario)
{
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
  _sabor = sabor;
  _pedacos = pedacos;
  _bordaRecheada = borda_recheada;
}
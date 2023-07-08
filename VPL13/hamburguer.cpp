#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
   
  std::string artesanal = (_artesanal) ? " artesanal." : " simples.";
  std::string qtd = std::to_string(m_qtd);

  return qtd+"X Hamburger "+_tipo+artesanal;
}

Hamburguer::Hamburguer(const std::string& tipo, bool artesanal, int qtd, float valor_unitario) 
{
  _tipo = tipo;
  _artesanal = artesanal;
  m_qtd = qtd;
  m_valor_unitario = valor_unitario;
}
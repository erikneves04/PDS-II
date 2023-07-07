#include "doctest.h"

#include "forma.h"
#include "forma2d.h"
#include "quadrado.h"
#include "triangulo.h"
#include "forma3d.h"
#include "cubo.h"
#include "esfera.h"
#include "circulo.h"

#include <string>
#include <math.h>


TEST_CASE("1 - Testando construção de classes derivadas com seus respectivos atributos") {
    //construtores devem setar o nome das formas. Exemplo, ao criar um quadrado, o campo quadrado
    //deve receber o valor "quadrado"
    
    CHECK_NOTHROW(Triangulo("azul", 10, 12, 5)); //construtor com cor, aresta_1, aresta_2 e aresta_3
    CHECK_NOTHROW(Quadrado("verde", 4)); //construtor com cor e tamanho da aresta
    CHECK_NOTHROW(Cubo("verde", 4)); //construtor com cor e tamanho da aresta
    CHECK_NOTHROW(Esfera("verde", 4)); //construtor com cor e raio
    CHECK_NOTHROW(Circulo("verde", 4)); //construtor com cor e raio

}

TEST_CASE("2 - Acessando métodos das classes base") {
    Triangulo t("azul", 6, 7, 8);
    CHECK((abs(t.get_area()-20.3331625676))<0.0001);
    CHECK(t.get_perimetro() == 21);
    
    Quadrado q("verde", 4);
    CHECK(q.get_area() == 16);
    CHECK(q.get_perimetro() == 16);
    
    Cubo c("roxo", 4);
    CHECK(c.get_volume() == 64);
    
    Esfera e("amarelo", 3);

    CHECK(abs(e.get_volume()-113.097)<0.01);
    
    Circulo cr("rosa", 2);
    CHECK(abs(cr.get_area()-12.5664)<0.001);
    CHECK(abs(cr.get_perimetro()-12.5664)<0.001);

}

TEST_CASE("3 - Instanciando objetos com classe base") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);
    
    std::string nome1 = "triangulo";
    std::string nome2 = "quadrado";
    std::string nome3 = "esfera";
    std::string nome4 = "cubo";
    std::string nome5 = "circulo";
    
    Forma *poligono1 = &quadrado;
    Forma *poligono2 = &triangulo;
    Forma *poligono3 = &esfera;
    Forma *poligono4 = &cubo;
    Forma *poligono5 = &circulo;
    
    //checando nomes
    CHECK(nome2.compare(poligono1->get_nome())==0);
    CHECK(nome1.compare(poligono2->get_nome())==0);
    CHECK(nome3.compare(poligono3->get_nome())==0);
    CHECK(nome4.compare(poligono4->get_nome())==0);
    CHECK(nome5.compare(poligono5->get_nome())==0);
    
    //checando cores
    CHECK(poligono1->get_cor().compare("vermelho")==0);
    CHECK(poligono2->get_cor().compare("azul")==0);
    
}

TEST_CASE("4 - Acessando métodos das classes filhas") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);
    
    Forma2D *poligono1 = &quadrado;
    Forma2D *poligono2 = &triangulo;
    Forma3D *poligono3 = &esfera;
    Forma3D *poligono4 = &cubo;
    Forma2D *poligono5 = &circulo;
    
    //checando nomes
    CHECK(poligono1->get_area()==49);
    CHECK((abs(poligono2->get_area()-9.79796))<0.001);
    CHECK(abs(poligono3->get_volume()-113.097)<0.01);
    CHECK(poligono4->get_volume()==8);
    CHECK(abs(poligono5->get_area()-12.5664)<0.001);
}

TEST_CASE("5 - Testando cálculo de área e perímetro para formas geométricas simples") {
    Triangulo t("verde", 5, 12, 13);
    Quadrado q("azul", 8);
    Circulo c("amarelo", 6);

    // Área e perímetro do triângulo de lados 5, 12 e 13
    CHECK(t.get_area() == 30);
    CHECK(t.get_perimetro() == 30);

    // Área e perímetro do quadrado de lado 8
    CHECK(q.get_area() == 64);
    CHECK(q.get_perimetro() == 32);

    // Área e perímetro do círculo de raio 6
    CHECK(abs(c.get_area() - 113.097) < 0.001);
    CHECK(abs(c.get_perimetro() - 37.6991) < 0.001);
}

TEST_CASE("6 - Testando cálculo de volume para formas 3D") {
    Cubo c("roxo", 5);

    // Volume do cubo de lado 5
    CHECK(c.get_volume() == 125);

    // Volume da esfera de raio 4
    Esfera e1("vermelho", 4);
    CHECK(abs(e1.get_volume() - 268.083) < 0.001);

    // Volume da esfera de raio 5
    Esfera e2("vermelho", 5);
    CHECK(abs(e2.get_volume() - 523.5983) < 0.001);
}

TEST_CASE("7 - Testando polimorfismo com objetos da classe base") {
    Triangulo t("azul", 5, 12, 13);
    Quadrado q("verde", 8);
    Circulo c("amarelo", 6);

    Forma2D *forma1 = &t;
    Forma2D *forma2 = &q;
    Forma2D *forma3 = &c;

    // Verificando acesso aos métodos das classes base
    CHECK(forma1->get_area() == 30);
    CHECK(forma2->get_area() == 64);
    CHECK(abs(forma3->get_area() - 113.097) < 0.001);

    // Verificando nomes das formas
    CHECK(forma1->get_nome() == "triangulo");
    CHECK(forma2->get_nome() == "quadrado");
    CHECK(forma3->get_nome() == "circulo");
}

TEST_CASE("8 - Testando polimorfismo com objetos das classes derivadas") {
    Triangulo t("azul", 5, 12, 13);
    Quadrado q("verde", 8);
    Circulo c("amarelo", 6);

    Forma2D *forma1 = &t;
    Forma2D *forma2 = &q;
    Forma2D *forma3 = &c;

    // Verificando acesso aos métodos das classes derivadas
    CHECK(forma1->get_area() == 30);
    CHECK(forma2->get_area() == 64);
    CHECK(abs(forma3->get_area() - 113.097) < 0.001);
}

TEST_CASE("9 - Testando polimorfismo com objetos das classes base e derivadas") {
    Triangulo t("azul", 5, 12, 13);
    Quadrado q("verde", 8);
    Cubo cb("roxo", 5);

    Forma2D *forma1 = &t;
    Forma2D *forma2 = &q;
    Forma3D *forma3 = &cb;

    // Verificando acesso aos métodos das classes base e derivadas
    CHECK(forma1->get_area() == 30);
    CHECK(forma2->get_area() == 64);
    CHECK(forma3->get_volume() == 125);
}

TEST_CASE("10 - Testando acesso a atributos protegidos das classes derivadas") {
    Triangulo t("azul", 6, 7, 8);
    Quadrado q("verde", 4);
    Cubo c("roxo", 4);
    Esfera e("amarelo", 3);
    Circulo cr("rosa", 2);

    // Verificando acesso a atributos protegidos
    CHECK(t.get_cor() == "azul");
    CHECK(q.get_cor() == "verde");
    CHECK(c.get_cor() == "roxo");
    CHECK(e.get_cor() == "amarelo");
    CHECK(cr.get_cor() == "rosa");
}

TEST_CASE("11 - Polimorfismo dos atributos de cor") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);
    
    Forma2D *poligono1 = &quadrado;
    Forma2D *poligono2 = &triangulo;
    Forma3D *poligono3 = &esfera;
    Forma3D *poligono4 = &cubo;
    Forma2D *poligono5 = &circulo;
    
    //checando nomes
    CHECK(poligono1->get_cor() == "vermelho");
    CHECK(poligono2->get_cor() == "azul");
    CHECK(poligono3->get_cor() == "roxo");
    CHECK(poligono4->get_cor() == "rosa");
    CHECK(poligono5->get_cor() == "amarelo");
}

TEST_CASE("12 - Polimorfismo dos atributos de nome") {
    Triangulo triangulo("azul", 7, 5, 4);
    Quadrado quadrado("vermelho", 7);
    Esfera esfera("roxo", 3);
    Cubo cubo("rosa", 2);
    Circulo circulo("amarelo", 2);
    
    Forma2D *poligono1 = &quadrado;
    Forma2D *poligono2 = &triangulo;
    Forma3D *poligono3 = &esfera;
    Forma3D *poligono4 = &cubo;
    Forma2D *poligono5 = &circulo;
    
    //checando nomes
    CHECK(poligono1->get_nome() == "quadrado");
    CHECK(poligono2->get_nome() == "triangulo");
    CHECK(poligono3->get_nome() == "esfera");
    CHECK(poligono4->get_nome() == "cubo");
    CHECK(poligono5->get_nome() == "circulo");
}

TEST_CASE("13 - Polimorfismo pro cálculo de volume") {
    Cubo cubo1("rosa", 2);
    Cubo cubo2("rosa", 3);
    Cubo cubo3("rosa", 4);
    Esfera esfera("roxo", 4);

    Forma3D *poligono1 = &esfera;
    Forma3D *poligono2 = &cubo1;
    Forma3D *poligono3 = &cubo2;
    Forma3D *poligono4 = &cubo3;
    
    CHECK(abs(poligono1->get_volume() - 268.083) < 0.001);

    CHECK(poligono2->get_volume() == 8);
    CHECK(poligono3->get_volume() == 27);
    CHECK(poligono4->get_volume() == 64);
}

TEST_CASE("14 - Calculando área de um triangulo isoceles") {
    Triangulo isoceles("azul", 10, 10, 12);
    CHECK(abs(isoceles.get_area() - 48) < 0.01);
}

TEST_CASE("14 - Calculando área de um triangulo escaleno") {
    Triangulo escaleno("azul", 13, 9, 18);
    CHECK(abs(escaleno.get_area() - 55.4977) < 0.01);
}

TEST_CASE("14 - Calculando área de um triangulo equilatero") {
    Triangulo equilatero("azul", 12, 12, 12);
    CHECK(abs(equilatero.get_area() - 62.35) < 0.01);
}
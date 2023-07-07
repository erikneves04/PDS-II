#include <string>

#include "doctest.h"
#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"
#include "destinationpackages.h"


TEST_CASE("01 - Testando o construtor sem parâmetros") {
    CHECK_NOTHROW(DestinationPackages());
}

TEST_CASE("02 - Testando a inserção de pacotes e o custo total por usuário") {
    Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
    Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
    Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total("Josias") == 15);
    CHECK(pacotes.custo_total("Maria") == 30);
    CHECK(pacotes.custo_total("Carlos") == 25);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("03 - Testando o cálculo de custo total de pacotes") {
    Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
    Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
    Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total() == 70);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("04 - Checando um custo nulo para uma chave não presente no map; e para um map vazio") {
    Package *p1 = new Package(2,5, "Josias", "Alfeneiros");
    Package *p2 = new Package(5,5, "Carlos", "Alfeneiros");
    Package *p3 = new Package(4,5, "Maria", "Alfeneiros");
    Package *p4 = new Package(2,5, "Maria", "Alfeneiros");
    Package *p5 = new Package(1,5, "Josias", "Alfeneiros");
    
    DestinationPackages pacotes;
    DestinationPackages pacotes2;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total("Marcos") == 0);
    CHECK(pacotes2.custo_total()==0);
    
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;
}

TEST_CASE("05 - Inserção de membros de classes derivadas e cálculo de custo polimorficamente") {
    
    Package *p1 = new OverNightPackage(2, 5, 7, "Maria", "Rio");
    Package *p2 = new OverNightPackage(3, 2, 1, "Paulo", "Juazeiro");
    Package *p3 = new TwoDayPackage(5, 2, 4, "Josias", "Juazeiro");
    Package *p4 = new TwoDayPackage(2, 5, 3, "Maria", "Juazeiro");
    Package *p5 = new Package(5, 7, "Paulo", "Juazeiro");

    DestinationPackages pacotes;
    CHECK_NOTHROW(pacotes.add_package(p1));
    CHECK_NOTHROW(pacotes.add_package(p2));
    CHECK_NOTHROW(pacotes.add_package(p3));
    CHECK_NOTHROW(pacotes.add_package(p4));
    CHECK_NOTHROW(pacotes.add_package(p5));
    
    CHECK(pacotes.custo_total("Josias") == 14);
    CHECK(pacotes.custo_total("Maria") == 37);
    CHECK(pacotes.custo_total("Paulo") == 44);
    CHECK(pacotes.custo_total() == 95);
    
    delete static_cast<OverNightPackage*>(p1);
    delete static_cast<OverNightPackage*>(p2);
    delete static_cast<TwoDayPackage*>(p3);
    delete static_cast<TwoDayPackage*>(p4);
    delete p5;
}

TEST_CASE("06 - Testando o cálculo de custo total de pacotes com pacotes de diferentes tipos") {
    Package* p1 = new OverNightPackage(2, 5, 7, "Maria", "Rio");
    Package* p2 = new TwoDayPackage(5, 2, 4, "Josias", "Juazeiro");
    Package* p3 = new Package(3, 4, "Carlos", "Salvador");

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);

    CHECK(pacotes.custo_total("Maria") == 24);
    CHECK(pacotes.custo_total("Josias") == 14);
    CHECK(pacotes.custo_total("Carlos") == 12);
    CHECK(pacotes.custo_total() == 50);

    delete static_cast<OverNightPackage*>(p1);
    delete static_cast<TwoDayPackage*>(p2);
    delete p3;
}

TEST_CASE("07 - Testando o cálculo de custo total com pacote nulo") {
    DestinationPackages pacotes;
    CHECK(pacotes.custo_total() == 0);
}

TEST_CASE("08 - Testando cálculo de total para OverNightPackage") {
    OverNightPackage* p1 = new OverNightPackage(2, 10, 5, "Maria", "Rio"); // 30
    OverNightPackage* p2 = new OverNightPackage(10, 10, 5, "Maria", "Juazeiro"); // 150
    OverNightPackage* p3 = new OverNightPackage(25, 10, 5, "Maria", "Salvador"); // 375
    OverNightPackage* p4 = new OverNightPackage(25, 10, 5, "Jeroen", "Salvador"); // 375

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);

    CHECK(pacotes.custo_total("Maria") == 555);
    CHECK(pacotes.custo_total("Jeroen") == 375);
    CHECK(pacotes.custo_total() == 930);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

TEST_CASE("09 - Testando cálculo de total para TwoDayPackage") {
    TwoDayPackage* p1 = new TwoDayPackage(2, 10, 5, "Maria", "Rio"); // 25
    TwoDayPackage* p2 = new TwoDayPackage(10, 10, 5, "Maria", "Juazeiro"); // 105
    TwoDayPackage* p3 = new TwoDayPackage(25, 10, 5, "Maria", "Salvador"); // 255
    TwoDayPackage* p4 = new TwoDayPackage(25, 10, 5, "Jeroen", "Salvador"); // 255

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);

    CHECK(pacotes.custo_total("Maria") == 385);
    CHECK(pacotes.custo_total("Jeroen") == 255);
    CHECK(pacotes.custo_total() == 640);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

TEST_CASE("10 - Testando cálculo de total para Package") {
    Package* p1 = new Package(2, 10, "Maria", "Rio"); // 20
    Package* p2 = new Package(10, 10, "Maria", "Juazeiro"); // 100
    Package* p3 = new Package(25, 10, "Maria", "Salvador"); // 250
    Package* p4 = new Package(25, 10, "Jeroen", "Salvador"); // 250

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);

    CHECK(pacotes.custo_total("Maria") == 370);
    CHECK(pacotes.custo_total("Jeroen") == 250);
    CHECK(pacotes.custo_total() == 620);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

TEST_CASE("11 - Testando cálculo de total para OverNightPackage usando polimorfismo") {
    Package* p1 = new OverNightPackage(2, 10, 5, "Maria", "Rio"); // 30
    Package* p2 = new OverNightPackage(10, 10, 5, "Maria", "Juazeiro"); // 150
    Package* p3 = new OverNightPackage(25, 10, 5, "Maria", "Salvador"); // 375
    Package* p4 = new OverNightPackage(25, 10, 5, "Jeroen", "Salvador"); // 375

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);

    CHECK(pacotes.custo_total("Maria") == 555);
    CHECK(pacotes.custo_total("Jeroen") == 375);
    CHECK(pacotes.custo_total() == 930);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

TEST_CASE("12 - Testando cálculo de total para TwoDayPackage usando polimorfismo") {
    Package* p1 = new TwoDayPackage(2, 10, 5, "Maria", "Rio"); // 25
    Package* p2 = new TwoDayPackage(10, 10, 5, "Maria", "Juazeiro"); // 105
    Package* p3 = new TwoDayPackage(25, 10, 5, "Maria", "Salvador"); // 255
    Package* p4 = new TwoDayPackage(25, 10, 5, "Jeroen", "Salvador"); // 255

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);
    pacotes.add_package(p3);
    pacotes.add_package(p4);

    CHECK(pacotes.custo_total("Maria") == 385);
    CHECK(pacotes.custo_total("Jeroen") == 255);
    CHECK(pacotes.custo_total() == 640);

    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

TEST_CASE("13 - Custo para usuário que não existe é zero") {
    Package* p1 = new TwoDayPackage(2, 10, 5, "Maria", "Rio"); // 25
    Package* p2 = new TwoDayPackage(25, 10, 5, "Jeroen", "Salvador"); // 255

    DestinationPackages pacotes;
    pacotes.add_package(p1);
    pacotes.add_package(p2);

    CHECK(pacotes.custo_total() == 280);
    CHECK(pacotes.custo_total("Robson") == 0);

    delete p1;
    delete p2;
}

TEST_CASE("14 - Checando construtor dos pacotes") {
    CHECK_NOTHROW(Package(1, 1, "nome", "endereco"));
    CHECK_NOTHROW(TwoDayPackage(1, 1, 1, "nome", "endereco"));
    CHECK_NOTHROW(OverNightPackage(1, 1, 1, "nome", "endereco"));
}

TEST_CASE("15 - Testando cálculo de custo dos pacotes") {
    OverNightPackage *p1 = new OverNightPackage(2, 5, 7, "Maria", "Rio"); // 24
    TwoDayPackage *p2 = new TwoDayPackage(5, 2, 4, "Josias", "Juazeiro"); // 14
    Package *p3 = new Package(5, 7, "Paulo", "Juazeiro"); // 35

    CHECK(p1->calculate_cost() == 24);
    CHECK(p2->calculate_cost() == 14);
    CHECK(p3->calculate_cost() == 35);

    delete p1;
    delete p2;
    delete p3;
}
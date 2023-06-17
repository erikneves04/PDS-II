#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <map>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  for (char c : str) {
        if (c == '-' || c == '+' || c == '.' || !isdigit(c)) {
            return false;
        }
    }

    return true;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
   int sum = 0;
    std::string number;
    
    for (char c : str) {
        if (isdigit(c)) {
            number += c;
        } else if (!number.empty()) {
            sum += std::stoi(number);
            number.clear();
        }
    }
    
    if (!number.empty()) {
        sum += std::stoi(number);
    }
    
    std::cout << sum << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
    std::istringstream iss(str);
    std::string time1, time2;
    int gols1, gols2;

    // Verificar se é possível extrair os quatro campos da linha
    if (!(iss >> time1 >> gols1 >> time2 >> gols2)) {
        return false;
    }

    // Verificar se não há caracteres inválidos nos nomes dos times
    if (time1.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos ||
        time2.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos) {
        return false;
    }

    // Verificar se os gols são números naturais (inteiros positivos)
    if (gols1 < 0 || gols2 < 0) {
        return false;
    }

    // A linha é válida
    return true;
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
    std::istringstream iss(str);
    std::string time1, time2;
    int gols1, gols2;

    // Extrair os quatro campos da linha
    if (!(iss >> time1 >> gols1 >> time2 >> gols2)) {
        std::cout << "Linha inválida" << std::endl;
        return;
    }

    // Verificar o time vencedor ou se houve empate
    if (gols1 > gols2) {
        std::cout << "Vencedor: " << time1 << std::endl;
    } else if (gols2 > gols1) {
        std::cout << "Vencedor: " << time2 << std::endl;
    } else {
        std::cout << "Empate" << std::endl;
    }
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  int count = 0;
    bool isWord = false;

    for (char c : str) {
        if (std::isalpha(c) && !isWord) {
            count++;
            isWord = true;
        } else if (std::isspace(c)) {
            isWord = false;
        }
    }

    std::cout << count << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
    for (char c : str) {
        if (!(std::isalpha(c) || std::isspace(c))) {
            return false;
        }
    }
    
    return true;
}

void InversorDeFrases::processaLinha(const std::string &str) {
    std::istringstream iss(str);
    std::vector<std::string> palavras;
    std::string palavra;

    // Extrair cada palavra da linha
    while (iss >> palavra) {
        palavras.push_back(palavra);
    }

    // Imprimir as palavras em ordem reversa
    for (auto it = palavras.rbegin(); it != palavras.rend(); ++it) {
        std::cout << *it << ' ';
    }

    std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
    size_t startPos = str.find_first_not_of(' ');
    std::string trimmedStr = str.substr(startPos);

    // Verificar o padrão da data
    std::regex pattern("\\d{1,2}/\\d{1,2}/\\d{4}");
    return std::regex_match(trimmedStr, pattern);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // Remover espaços em branco no início da linha
    size_t startPos = str.find_first_not_of(' ');
    std::string trimmedStr = str.substr(startPos);

    // Verificar o padrão da data
    std::regex pattern("\\d{1,2}/\\d{1,2}/\\d{4}");
    if (!std::regex_match(trimmedStr, pattern)) {
        // A linha não possui o padrão de data válido
        return;
    }

    // Extrair o valor do mês
    std::regex monthPattern("\\d{1,2}/(\\d{1,2})/\\d{4}");
    std::smatch match;
    std::regex_search(trimmedStr, match, monthPattern);
    std::string month = match[1].str();

    // Mapa de mês para iniciais
    std::map<std::string, std::string> monthMap = {
        {"01", "Jan"},
        {"02", "Fev"},
        {"03", "Mar"},
        {"04", "Abr"},
        {"05", "Mai"},
        {"06", "Jun"},
        {"07", "Jul"},
        {"08", "Ago"},
        {"09", "Set"},
        {"10", "Out"},
        {"11", "Nov"},
        {"12", "Dez"}
    };

    // Substituir o valor do mês pelas iniciais
    std::string replacedStr = std::regex_replace(trimmedStr, monthPattern, monthMap[month]);

    // Imprimir a linha modificada
    std::cout << replacedStr << std::endl;
}
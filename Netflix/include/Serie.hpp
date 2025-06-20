#ifndef SERIE_HPP
#define SERIE_HPP

#include "Conteudo.hpp"
#include <string>
#include <iostream>

class Serie : public Conteudo {
private:
    int temporadas;
    int episodios;

public:
    // Construtor completo
    Serie(std::string titulo, std::string descricao, std::string genero,
          std::string dataLancamento, std::string classificacao, std::string trailerURL,
          bool ehKids, int temporadas, int episodios);

    // Construtor simplificado (temporadas e episódios como 0 por padrão)
    Serie(std::string titulo, std::string genero, int duracao);

    void exibirDetalhes() const override;

    std::string getTipo() const override;
};

#endif



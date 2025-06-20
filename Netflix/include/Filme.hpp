#ifndef FILME_HPP
#define FILME_HPP

#include "Conteudo.hpp"
#include <string>
#include <iostream>

class Filme : public Conteudo {
private:
    int duracao;

public:
    // Construtor original
    Filme(std::string titulo, std::string descricao, std::string genero,
          std::string dataLancamento, std::string classificacao, std::string trailerURL,
          bool ehKids, int duracao);

    // Construtor simplificado para facilitar carregamento do arquivo
    Filme(std::string titulo, std::string genero, int duracao);

    void exibirDetalhes() const override;

    std::string getTipo() const override;
};

#endif



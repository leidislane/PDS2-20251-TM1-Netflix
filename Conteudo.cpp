#include "Conteudo.hpp"

Conteudo::Conteudo(std::string titulo, std::string descricao, std::string genero,
                   std::string dataLancamento, std::string classificacao, std::string trailerURL, bool ehKids)
    : titulo(titulo), descricao(descricao), genero(genero), dataLancamento(dataLancamento),
      classificacao(classificacao), trailerURL(trailerURL), ehKids(ehKids) {}

Conteudo::~Conteudo() {}

std::string Conteudo::getTitulo() const {
    return titulo;
}

bool Conteudo::isEhKids() const {
    return ehKids;
}


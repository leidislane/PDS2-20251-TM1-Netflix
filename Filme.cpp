#include "Filme.hpp"

// Construtor original
Filme::Filme(std::string titulo, std::string descricao, std::string genero,
             std::string dataLancamento, std::string classificacao, std::string trailerURL,
             bool ehKids, int duracao)
    : Conteudo(titulo, descricao, genero, dataLancamento, classificacao, trailerURL, ehKids),
      duracao(duracao) {}

// Novo construtor simplificado
Filme::Filme(std::string titulo, std::string genero, int duracao)
    : Conteudo(titulo, "", genero, "", "", "", false), duracao(duracao) {}

void Filme::exibirDetalhes() const {
    std::cout << "[Filme] " << titulo << " (" << dataLancamento << ")\n"
              << "Genero: " << genero << ", Classificacao: " << classificacao << "\n"
              << "Descricao: " << descricao << "\n"
              << "Duracao: " << duracao << " min\n";
}

std::string Filme::getTipo() const {
    return "Filme";
}


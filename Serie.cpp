#include "Serie.hpp"

// Construtor completo (já existente)
Serie::Serie(std::string titulo, std::string descricao, std::string genero,
             std::string dataLancamento, std::string classificacao, std::string trailerURL,
             bool ehKids, int temporadas, int episodios)
    : Conteudo(titulo, descricao, genero, dataLancamento, classificacao, trailerURL, ehKids),
      temporadas(temporadas), episodios(episodios) {}

// Novo construtor simplificado
Serie::Serie(std::string titulo, std::string genero, int duracao)
    : Conteudo(titulo, "", genero, "", "", "", false), temporadas(0), episodios(0) {}

// O resto do código permanece igual
void Serie::exibirDetalhes() const {
    std::cout << "[Serie] " << titulo << " (" << dataLancamento << ")\n"
              << "Genero: " << genero << ", Classificacao: " << classificacao << "\n"
              << "Descricao: " << descricao << "\n"
              << "Temporadas: " << temporadas << ", Episodios: " << episodios << "\n";
}

std::string Serie::getTipo() const {
    return "Serie";
}


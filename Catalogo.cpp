#include "Catalogo.hpp"
#include "Filme.hpp"
#include "Serie.hpp"
#include "Conteudo.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

void Catalogo::adicionarConteudo(std::shared_ptr<Conteudo> conteudo) {
    conteudos.push_back(conteudo);
}

void Catalogo::listarConteudos(bool apenasKids) const {
    std::cout << "\n📺 Catálogo de Conteúdos:\n";
    for (const auto& c : conteudos) {
        if (!apenasKids || c->isEhKids()) {
            std::cout << "- " << c->getTitulo() << " [" << c->getTipo() << "]\n";
        }
    }
}

std::shared_ptr<Conteudo> Catalogo::buscarPorTitulo(const std::string& tituloBusca) const {
    for (const auto& c : conteudos) {
        if (c->getTitulo() == tituloBusca) {
            return c;
        }
    }
    return nullptr;
}

const std::vector<std::shared_ptr<Conteudo>>& Catalogo::getConteudos() const {
    return conteudos;
}

void Catalogo::carregarDeArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string tipo;
        if (!std::getline(iss, tipo, ';')) continue;

        if (tipo == "filme") {
            std::string titulo, descricao, genero, dataLancamento, classificacao, trailerURL;
            std::string ehKidsStr;
            int duracao;

            if (std::getline(iss, titulo, ';') &&
                std::getline(iss, descricao, ';') &&
                std::getline(iss, genero, ';') &&
                std::getline(iss, dataLancamento, ';') &&
                std::getline(iss, classificacao, ';') &&
                std::getline(iss, trailerURL, ';') &&
                std::getline(iss, ehKidsStr, ';') &&
                (iss >> duracao)) {

                bool ehKids = (ehKidsStr == "1" || ehKidsStr == "true");

                auto filme = std::make_shared<Filme>(titulo, descricao, genero,
                                                     dataLancamento, classificacao, trailerURL,
                                                     ehKids, duracao);
                adicionarConteudo(filme);
            }
        }
        else if (tipo == "serie") {
            std::string titulo, descricao, genero, dataLancamento, classificacao, trailerURL;
            std::string ehKidsStr;
            int temporadas, episodios;

            if (std::getline(iss, titulo, ';') &&
                std::getline(iss, descricao, ';') &&
                std::getline(iss, genero, ';') &&
                std::getline(iss, dataLancamento, ';') &&
                std::getline(iss, classificacao, ';') &&
                std::getline(iss, trailerURL, ';') &&
                std::getline(iss, ehKidsStr, ';') &&
                (iss >> temporadas) &&
                (iss.ignore(1)) &&
                (iss >> episodios)) {

                bool ehKids = (ehKidsStr == "1" || ehKidsStr == "true");

                auto serie = std::make_shared<Serie>(titulo, descricao, genero,
                                                     dataLancamento, classificacao, trailerURL,
                                                     ehKids, temporadas, episodios);
                adicionarConteudo(serie);
            }
        }
        else {
            std::cerr << "Tipo desconhecido no arquivo: " << tipo << std::endl;
        }
    }
}

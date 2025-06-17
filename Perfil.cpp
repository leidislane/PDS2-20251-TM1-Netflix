#include "Perfil.hpp"
#include <iostream>
#include <algorithm>

Perfil::Perfil(const std::string& nome, const std::string& avatar, bool kidsProfile)
    : nome(nome), avatar(avatar), kidsProfile(kidsProfile) {}

void Perfil::assistir(std::shared_ptr<Conteudo> conteudo, int tempoAssistido) {
    historico.emplace_back(std::move(conteudo), tempoAssistido);
}

void Perfil::adicionarFavorito(std::shared_ptr<Conteudo> conteudo) {
    auto it = std::find_if(favoritos.begin(), favoritos.end(),
        [&](const std::shared_ptr<Conteudo>& c) {
            return c->getTitulo() == conteudo->getTitulo();
        });
    if (it == favoritos.end()) {
        favoritos.push_back(std::move(conteudo));
    }
}

void Perfil::listarHistorico() const {
    std::cout << "Histórico de " << nome << ":\n";
    if (historico.empty()) {
        std::cout << "  (nenhum conteúdo assistido ainda)\n";
        return;
    }
    for (const auto& par : historico) {
        auto& conteudo = par.first;
        int tempo = par.second;
        std::cout << "- " << conteudo->getTitulo() << " (" << tempo << "s assistidos)\n";
    }
}

void Perfil::listarFavoritos() const {
    std::cout << "Favoritos de " << nome << ":\n";
    if (favoritos.empty()) {
        std::cout << "  (nenhum favorito cadastrado)\n";
        return;
    }
    for (const auto& c : favoritos) {
        c->exibirDetalhes();
    }
}

bool Perfil::isKidsProfile() const {
    return kidsProfile;
}

const std::vector<std::pair<std::shared_ptr<Conteudo>, int>>& Perfil::getHistorico() const {
    return historico;
}

std::string Perfil::getNome() const {
    return nome;
}

std::string Perfil::getAvatar() const {
    return avatar;
}

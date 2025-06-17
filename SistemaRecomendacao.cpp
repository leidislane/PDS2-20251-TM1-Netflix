#include "SistemaRecomendacao.hpp"
#include <map>
#include <set>
#include <algorithm>
#include <random>

std::vector<std::shared_ptr<Conteudo>> SistemaRecomendacao::recomendar(
    const Perfil& perfil, 
    const std::vector<std::shared_ptr<Conteudo>>& catalogo) 
{
    std::map<std::string, int> generoCount;
    std::set<std::string> assistidos;

    for (const auto& c : perfil.getHistorico()) {
        generoCount[c.first->getTipo()]++;
        assistidos.insert(c.first->getTitulo());
    }

    std::string favorito = "";
    int maxCount = 0;
    for (const auto& par : generoCount) {
        if (par.second > maxCount) {
            favorito = par.first;
            maxCount = par.second;
        }
    }

    std::vector<std::shared_ptr<Conteudo>> recomendados;
    for (const auto& c : catalogo) {
        if (!perfil.isKidsProfile() || c->isEhKids()) {
            if (c->getTipo() == favorito && assistidos.find(c->getTitulo()) == assistidos.end()) {
                recomendados.push_back(c);
            }
        }
    }

    if (recomendados.empty()) {
        std::vector<std::shared_ptr<Conteudo>> candidatos;
        for (const auto& c : catalogo) {
            if (!perfil.isKidsProfile() || c->isEhKids()) {
                if (assistidos.find(c->getTitulo()) == assistidos.end()) {
                    candidatos.push_back(c);
                }
            }
        }

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(candidatos.begin(), candidatos.end(), g);

        for (size_t i = 0; i < std::min<size_t>(3, candidatos.size()); ++i) {
            recomendados.push_back(candidatos[i]);
        }
    }

    return recomendados;
}

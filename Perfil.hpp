#ifndef PERFIL_HPP
#define PERFIL_HPP

#include <string>
#include <vector>
#include <memory>
#include <utility>
#include "Conteudo.hpp"

class Perfil {
private:
    std::string nome;
    std::string avatar;
    bool kidsProfile;

    std::vector<std::pair<std::shared_ptr<Conteudo>, int>> historico;
    std::vector<std::shared_ptr<Conteudo>> favoritos;

public:
    Perfil(const std::string& nome, const std::string& avatar, bool kidsProfile);

    void assistir(std::shared_ptr<Conteudo> conteudo, int tempoAssistido);
    void adicionarFavorito(std::shared_ptr<Conteudo> conteudo);
    void listarHistorico() const;
    void listarFavoritos() const;

    bool isKidsProfile() const;
    const std::vector<std::pair<std::shared_ptr<Conteudo>, int>>& getHistorico() const;

    std::string getNome() const;
    std::string getAvatar() const;
};

#endif



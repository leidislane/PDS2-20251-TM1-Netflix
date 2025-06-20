#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Perfil.hpp"

class Usuario {
private:
    std::string nome;
    std::string email;
    std::string senha;
    std::vector<Perfil> perfis;

public:
    Usuario(std::string nome, std::string email, std::string senha);

    void adicionarPerfil(const Perfil& perfil);

    std::vector<Perfil>& getPerfis();
    std::string getEmail() const;
    bool autenticar(const std::string& s) const;
};

#endif

#include "Usuario.hpp"

Usuario::Usuario(std::string nome, std::string email, std::string senha)
    : nome(nome), email(email), senha(senha) {}

void Usuario::adicionarPerfil(const Perfil& perfil) {
    if (perfis.size() < 5)
        perfis.push_back(perfil);
    else
        std::cout << "Limite de perfis atingido.\n";
}

std::vector<Perfil>& Usuario::getPerfis() {
    return perfis;
}

std::string Usuario::getEmail() const {
    return email;
}

bool Usuario::autenticar(const std::string& s) const {
    return s == senha;
}


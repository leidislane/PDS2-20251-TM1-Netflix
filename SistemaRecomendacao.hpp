#ifndef SISTEMA_RECOMENDACAO_HPP
#define SISTEMA_RECOMENDACAO_HPP

#include <vector>
#include <memory>
#include "Perfil.hpp"
#include "Conteudo.hpp"

class SistemaRecomendacao {
public:
    std::vector<std::shared_ptr<Conteudo>> recomendar(
        const Perfil& perfil, 
        const std::vector<std::shared_ptr<Conteudo>>& catalogo);
};

#endif // SISTEMA_RECOMENDACAO_HPP


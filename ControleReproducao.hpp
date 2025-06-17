#ifndef CONTROLE_REPRODUCAO_HPP
#define CONTROLE_REPRODUCAO_HPP

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include "Conteudo.hpp"

class ControleReproducao {
private:
    std::unordered_map<std::string, int> progresso;

public:
    void iniciar(std::shared_ptr<Conteudo> conteudo);
    void pausar(std::shared_ptr<Conteudo> conteudo, int tempoAssistido); // <-- Esta função precisa ser implementada!
    void retomar(std::shared_ptr<Conteudo> conteudo);
    int reproduzir(std::shared_ptr<Conteudo> conteudo);
    int getTempoAssistido(const std::shared_ptr<Conteudo>& conteudo) const;
};

#endif

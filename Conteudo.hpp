#ifndef CONTEUDO_HPP
#define CONTEUDO_HPP

#include <string>

class Conteudo {
protected:
    std::string titulo;
    std::string descricao;
    std::string genero;
    std::string dataLancamento;
    std::string classificacao;
    std::string trailerURL;
    bool ehKids;


public:
    Conteudo(std::string titulo, std::string descricao, std::string genero,
             std::string dataLancamento, std::string classificacao, std::string trailerURL, bool ehKids);
    virtual ~Conteudo();

    virtual void exibirDetalhes() const = 0;
    virtual std::string getTipo() const = 0;

    std::string getTitulo() const;
    bool isEhKids() const;
};

#endif

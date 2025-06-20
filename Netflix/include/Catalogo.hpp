#ifndef CATALOGO_HPP
#define CATALOGO_HPP

#include <vector>
#include <memory>
#include <string>

class Conteudo;

class Catalogo {
private:
    std::vector<std::shared_ptr<Conteudo>> conteudos;

public:
    void adicionarConteudo(std::shared_ptr<Conteudo> conteudo);
    void listarConteudos(bool apenasKids = false) const;
    std::shared_ptr<Conteudo> buscarPorTitulo(const std::string& tituloBusca) const;
    const std::vector<std::shared_ptr<Conteudo>>& getConteudos() const;

    // Carrega conteúdo de um arquivo (formato definido por tipo: filme/serie)
    void carregarDeArquivo(const std::string& nomeArquivo);
};

#endif



#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <fstream>
#include <sstream>

#include "Usuario.hpp"
#include "Perfil.hpp"
#include "Catalogo.hpp"
#include "Filme.hpp"
#include "Serie.hpp"
#include "SistemaRecomendacao.hpp"
#include "ControleReproducao.hpp"

// Função para carregar catálogo, chamando o método da classe Catalogo
void carregarCatalogoDeArquivo(Catalogo& catalogo, const std::string& nomeArquivo) {
    catalogo.carregarDeArquivo(nomeArquivo);
}

int main() {
    std::vector<Usuario> usuarios;
    Catalogo catalogo;
    carregarCatalogoDeArquivo(catalogo, "catalogo.txt");

    SistemaRecomendacao sistemaRec;
    ControleReproducao controle;

    while (true) {
        std::cout << "\n=== MENU PRINCIPAL ===\n";
        std::cout << "1. Cadastrar novo usuário\n";
        std::cout << "2. Login\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        int escolha;
        std::cin >> escolha;
        std::cin.ignore();

        if (escolha == 0) break;

        if (escolha == 1) {
            std::string nome, email, senha;
            std::cout << "Digite seu nome: ";
            std::getline(std::cin, nome);
            std::cout << "Digite seu email: ";
            std::getline(std::cin, email);
            std::cout << "Digite sua senha: ";
            std::getline(std::cin, senha);

            // Criar usuário novo e adicionar um perfil padrão (Adulto)
            Usuario novoUsuario(nome, email, senha);
            // Agora é necessário passar nome, avatar e kidsProfile para Perfil
            // Usando "Principal" como nome do perfil e um avatar padrão, e false para adulto
            novoUsuario.adicionarPerfil(Perfil("Principal", "avatar_padrao.png", false));  
            usuarios.push_back(std::move(novoUsuario));

            std::cout << "Usuário cadastrado com sucesso!\n";
        }
        else if (escolha == 2) {
            std::string email, senha;
            std::cout << "Email: ";
            std::getline(std::cin, email);
            std::cout << "Senha: ";
            std::getline(std::cin, senha);

            Usuario* usuarioLogado = nullptr;
            for (auto& u : usuarios) {
                if (u.getEmail() == email && u.autenticar(senha)) {
                    usuarioLogado = &u;
                    break;
                }
            }

            if (!usuarioLogado) {
                std::cout << "Credenciais inválidas.\n";
                continue;
            }

            while (true) {
                std::cout << "\nSelecione um perfil:\n";
                auto& perfis = usuarioLogado->getPerfis();
                for (size_t i = 0; i < perfis.size(); ++i) {
                    std::cout << i + 1 << ". Perfil: " << perfis[i].getNome()
                              << " (" << (perfis[i].isKidsProfile() ? "Kids" : "Adulto") << ")\n";
                }
                std::cout << "0. Logout\nEscolha: ";
                int pEscolha;
                std::cin >> pEscolha;
                std::cin.ignore();

                if (pEscolha == 0) break;
                if (pEscolha < 1 || pEscolha > (int)perfis.size()) {
                    std::cout << "Perfil inválido.\n";
                    continue;
                }

                Perfil& perfil = perfis[pEscolha - 1];
                bool sair = false;

                while (!sair) {
                    std::cout << "\n--- Menu do Perfil ---\n";
                    std::cout << "1. Ver catálogo\n";
                    std::cout << "2. Ver recomendações\n";
                    std::cout << "3. Ver histórico\n";
                    std::cout << "4. Reproduzir conteúdo\n";
                    std::cout << "0. Voltar\n";
                    std::cout << "Escolha: ";
                    int opcao;
                    std::cin >> opcao;
                    std::cin.ignore();

                    switch (opcao) {
                        case 0:
                            sair = true;
                            break;
                        case 1:
                            std::cout << "\n=== Catálogo ===\n";
                            for (const auto& c : catalogo.getConteudos()) {
                                if (!perfil.isKidsProfile() || c->isEhKids())
                                    c->exibirDetalhes();
                            }
                            break;
                        case 2: {
                            std::cout << "\n=== Recomendações ===\n";
                            auto recs = sistemaRec.recomendar(perfil, catalogo.getConteudos());
                            for (const auto& r : recs)
                                r->exibirDetalhes();
                            break;
                        }
                        case 3:
                            perfil.listarHistorico();
                            break;
                        case 4: {
                            std::string titulo;
                            std::cout << "Digite o título para reproduzir: ";
                            std::getline(std::cin, titulo);
                            bool achou = false;
                            for (const auto& c : catalogo.getConteudos()) {
                                if (c->getTitulo() == titulo) {
                                    int tempo = controle.reproduzir(c);
                                    perfil.assistir(c, tempo);
                                    achou = true;
                                    std::cout << "Reprodução encerrada e registrada.\n";
                                    break;
                                }
                            }
                            if (!achou) std::cout << "Conteúdo não encontrado.\n";
                            break;
                        }
                        default:
                            std::cout << "Opção inválida.\n";
                            break;
                    }
                }
            }
        }
        else {
            std::cout << "Opção inválida.\n";
        }
    }

    std::cout << "Encerrando o sistema.\n";
    return 0;
}

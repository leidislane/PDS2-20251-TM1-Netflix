#include <iostream>
#include <string>
#include <memory>
#include <chrono>
#include <unordered_map>
#include "Conteudo.hpp"
#include "ControleReproducao.hpp"

void ControleReproducao::iniciar(std::shared_ptr<Conteudo> conteudo) {
    progresso[conteudo->getTitulo()] = 0;
    std::cout << "▶️ Início da reprodução de \"" << conteudo->getTitulo() << "\".\n";
}

void ControleReproducao::pausar(std::shared_ptr<Conteudo> conteudo, int tempoAssistido) {
    progresso[conteudo->getTitulo()] = tempoAssistido;
    std::cout << "⏸ Reprodução pausada em " << tempoAssistido << " segundos.\n";
}

void ControleReproducao::retomar(std::shared_ptr<Conteudo> conteudo) {
    int tempo = progresso[conteudo->getTitulo()];
    std::cout << "⏯ Retomando \"" << conteudo->getTitulo() << "\" a partir de " << tempo << " segundos.\n";
}

int ControleReproducao::getTempoAssistido(const std::shared_ptr<Conteudo>& conteudo) const {
    auto it = progresso.find(conteudo->getTitulo());
    if (it != progresso.end()) {
        return it->second;
    }
    return 0;
}

int ControleReproducao::reproduzir(std::shared_ptr<Conteudo> conteudo) {
    std::string titulo = conteudo->getTitulo();
    int tempoAssistido = progresso[titulo];

    std::cout << "\n🟢 Reproduzindo: " << titulo << " (a partir de " << tempoAssistido << "s)\n";

    auto inicio = std::chrono::steady_clock::now();

    while (true) {
        std::cout << "\n[1] Pausar\n[2] Sair da reprodução\nEscolha: ";

        int opcao;
        std::cin >> opcao;
        std::cin.ignore();

        auto depoisInput = std::chrono::steady_clock::now();
        auto duracao = std::chrono::duration_cast<std::chrono::seconds>(depoisInput - inicio).count();

        tempoAssistido += static_cast<int>(duracao);
        inicio = depoisInput;

        if (opcao == 1) {
            pausar(conteudo, tempoAssistido);
            return tempoAssistido;
        } else if (opcao == 2) {
            std::cout << "⏹ Saindo da reprodução com " << tempoAssistido << " segundos assistidos.\n";
            return tempoAssistido;
        } else {
            std::cout << "Opção inválida.\n";
        }
    }

    return tempoAssistido;
}

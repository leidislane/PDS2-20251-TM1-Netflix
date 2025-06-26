# Netflix Clone

Projeto desenvolvido como trabalho prático final da disciplina **PDS2 - Programação e Desenvolvimento de Software 2** (UFMG – 2025/1).

#**Integrantes**

- Leidislane Nunes Ribeiro
- Kayky Irã da Silva Costa Martins 
- Yasmin Carvalho Viana
- Thais Aparecida Barbosa 

## 📽️ Descrição do Projeto

O **Netflix Clone** é uma aplicação que simula um sistema de streaming de vídeos (estilo Netflix). Através de uma interface em linha de comando (CLI), usuários podem:

- Criar contas e realizar login;
- Pode criar perfil original e acessar perfil Kids;
- Consultar um catálogo de filmes e séries;
- Catálogo possui filtros para gênero e tipo de conteúdo;
- Iniciar e controlar reprodução de vídeos;
- Armazenar progresso de exibição;
- Recomendações a partir do tipo de conteúdo assistido;
  

O projeto foi construído aplicando os princípios de orientação a objetos (encapsulamento, herança, polimorfismo e abstração), além de boas práticas de modularização e testes automatizados.

---

## 🛠️ Estrutura do Projeto
netflix_clonefinal/
│
├── 📄 Makefile                # Arquivo de automação da compilação
├── 📄 Doxyfile                # Arquivo de configuração para o Doxygen
├── 📄 catalogo.txt            # Lista de conteúdos disponíveis no catálogo
├── 📄 cobertura.css           # Estilo para o relatório de cobertura
│
├── 📁 .vscode/                # Configurações do VS Code
│   ├── c_cpp_properties.json
│   └── settings.json
│
├── 📁 bin/                    # Arquivos binários gerados (executável)
│   └── programa.exe
│
├── 📁 docs/                   # Documentação gerada automaticamente
│   └── html/                   # Documentação em HTML (Doxygen)
│       ├── annotated.html
│       ├── class_catalogo.html
│       ├── class_conteudo.html
│       ├── class_controle_reproducao.html
│       └── ... (outros arquivos HTML, JS, imagens etc.)
│   └── latex/
│
│── 📁 include/               # Contém arquivos .hpp
│
│── 📁 obj/                   # Contém arquivos gcda, gcno e .o
│
│── 📁 src/                   # Contém arquivos .cpp
│
│── 📁 testes/                # Testes de unidade
│
└── 📁 -p/                

---

## 📄 Documentação com Doxygen

- A documentação do código foi gerada com Doxygen e pode ser consultada localmente após rodar: doxygen Doxyfile

- Documentação gerada estará na pasta docs/html/index.html.


## Teste

- Utilizamos o framework Doctest para testes unitários.

- Cobertura de testes foi verificada com gcovr, com mais 30% de cobertura.

- Existem testes para as principais classes do sistema (Usuario, Perfil, Filme, Serie, Catalogo, ControleReproducao, etc).

---

## 🧩 Dificuldades Encontradas

- Estruturar um sistema completo com persistência e interface CLI de forma coesa e reutilizável.

- Garantir cobertura de testes adequada e organização dos testes com Doctest.

- Simular tempo de reprodução para série e filmes.

- Integração de diferentes componentes respeitando o acoplamento e coesão.
  
- Mexer no doxigen para realizar a documentação.


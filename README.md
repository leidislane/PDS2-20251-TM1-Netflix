# Netflix Clone

Projeto desenvolvido como trabalho prático final da disciplina **PDS2 - Programação e Desenvolvimento de Software 2** (UFMG – 2025/1).

#**Integrantes**

Leidislane Nunes Ribeiro
Kayky Irã da Silva Costa Martins 
Yasmin Carvalho Viana
Thais Aparecida Barbosa 

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
netflix_clone/
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
│   └── html/                 # Documentação em HTML (Doxygen)
│       ├── annotated.html
│       ├── class_catalogo.html
│       ├── class_conteudo.html
│       ├── class_controle_reproducao.html
│       └── 
│
└── 📁 -p/                     # Provavelmente criado por engano (erro no Makefile)

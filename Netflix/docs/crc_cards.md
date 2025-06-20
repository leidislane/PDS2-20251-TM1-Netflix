# Cartões CRC – Sistema Netflix

## CRC 1 – Usuário
**Responsabilidades:**  
- Armazenar informações pessoais (nome, e-mail, senha)  
- Fazer login no sistema  
- Gerenciar perfis de usuário  
- Adicionar ou remover títulos da lista de favoritos  
- Consultar histórico de visualizações  
- Receber recomendações personalizadas  

**Colaboradores:**  
- Perfil  
- Sistema de Recomendação  

---

## CRC 2 – Perfil
**Responsabilidades:**  
- Armazenar dados do perfil (nome, avatar, tipo)  
- Exibir catálogo conforme restrições  
- Permitir criação, edição e exclusão de perfis  
- Controlar conteúdo apropriado para perfil Kids  
- Iniciar sessão de visualização  

**Colaboradores:**  
- Catálogo  
- Controle de Reprodução  

---

## CRC 3 – Catálogo
**Responsabilidades:**  
- Armazenar filmes e séries  
- Organizar títulos por categorias  
- Permitir busca por nome, ator ou diretor  
- Exibir detalhes (nome, sinopse, classificação, trailer)  
- Atualizar catálogo em tempo real  

**Colaboradores:**  
- Administrador  
- Perfil  

---

## CRC 4 – Administrador
**Responsabilidades:**  
- Adicionar, editar e excluir títulos do catálogo  
- Fazer upload de imagens e trailers  
- Definir categorias de conteúdo  
- Atualizar informações de filmes e séries  
- Gerenciar permissões de acesso especiais  

**Colaboradores:**  
- Catálogo  
- Sistema de Controle de Acesso  

---

## CRC 5 – Controle de Reprodução
**Responsabilidades:**  
- Iniciar reprodução de conteúdo  
- Pausar, retomar, avançar e retroceder vídeo  
- Salvar ponto de parada  
- Atualizar status do conteúdo  
- Registrar visualizações no histórico  

**Colaboradores:**  
- Histórico de Visualizações  
- Perfil  

---

## CRC 6 – Sistema de Recomendações
**Responsabilidades:**  
- Analisar histórico de visualizações  
- Gerar sugestões personalizadas  
- Atualizar recomendações com base nos novos conteúdos assistidos  
- Armazenar preferências de perfil  
- Exibir lista de recomendações  

**Colaboradores:**  
- Usuário  
- Catálogo  

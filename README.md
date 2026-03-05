# 🎒 Sistema de Inventário – Mochila de Loot

Projeto desenvolvido em linguagem C com foco no uso de *structs, **vetores (listas sequenciais)* e *busca sequencial*, simulando o sistema de inventário inicial de um jogo de sobrevivência.

---

## 🎯 Objetivo

Criar um sistema que permita ao jogador:

* 🔫 Cadastrar itens (armas, munições, kits médicos, ferramentas)
* 🗑️ Remover itens da mochila
* 📜 Listar todos os itens cadastrados
* 🔎 Buscar um item pelo nome

O sistema simula a organização estratégica de recursos no início de uma partida.

---

## 🧠 Conceitos Aplicados

* ✅ Struct como agregador de dados
* ✅ Vetor como lista sequencial
* ✅ Busca sequencial
* ✅ Modularização com funções
* ✅ Manipulação de strings (strcmp, fgets)
* ✅ Passagem por referência com ponteiros
* ✅ Organização e clareza no código

---

## 🏗️ Estrutura do Projeto

### 📌 Struct utilizada

c
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;


Cada item contém:

* 🏷️ Nome
* 🗂️ Tipo
* 🔢 Quantidade

---

## ⚙️ Funcionalidades Implementadas

### ➕ Inserir Item

Permite cadastrar até 10 itens na mochila.

### 🗑️ Remover Item

Remove um item pelo nome informado e reorganiza o vetor.

### 📜 Listar Itens

Exibe todos os itens cadastrados após cada operação.

### 🔎 Buscar Item

Realiza busca sequencial e exibe os dados do item encontrado.

---

## 📦 Limitações do Sistema

* Capacidade máxima de 10 itens
* Busca realizada de forma sequencial (O(n))
* Dados armazenados apenas em memória (não salva em arquivo)

---

## 💻 Como Compilar e Executar

### 🔹 Compilando com GCC

bash
gcc inventario.c -o inventario


### 🔹 Executando

bash
./inventario


No Windows:

bash
inventario.exe


---

## 🖥️ Exemplo de Menu


===== SISTEMA DE INVENTÁRIO =====
1 - Inserir item
2 - Remover item
3 - Listar itens
4 - Buscar item
0 - Sair


---

## 🚀 Melhorias Futuras

* 💾 Persistência de dados em arquivo .txt
* 🔄 Ordenação de itens por tipo
* 📊 Sistema de limite de peso da mochila
* 🧠 Implementação usando lista encadeada
* 🎮 Evoluir para um mini sistema base de RPG

---

## 👨‍💻 Autor

Rodrigo de Jesus Santos

Estudante de Engenharia de Software

---

## 📌 Status do Projeto

✅ Concluído – Versão Acadêmica
🔜 Possível evolução para versão avançada

---

⭐ Se este projeto te ajudou ou inspirou, deixe uma estrela no repositório!

---

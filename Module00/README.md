# Module 00 - Encapsulation

## Visão Geral
Este módulo introduz o conceito fundamental de **Encapsulamento** em Programação Orientada a Objetos (OOP).

### Conceitos-Chave
- **Objeto**: conceito que representa uma "coisa"
- **Instância**: entidade concreta de um objeto
- **Atributos**: variáveis internas de uma instância
- **Métodos**: formas de comunicação com uma instância
- **Encapsulamento**: controle de acesso a atributos e métodos
  - **Private**: acessível apenas pela própria classe (e friends)
  - **Public**: acessível de qualquer lugar

---

## Exercícios

### [Exercise 00: Divide and Conquer](ex00/)
Sistema bancário com encapsulamento adequado.

**Objetivos:**
- Refatorar código sem encapsulamento
- Implementar sistema de contas bancárias
- Aplicar taxa de 5% em depósitos
- Controlar empréstimos baseado em liquidez

**Compilar e executar:**
```bash
cd ex00
make
./bank
```

**Requisitos:**
- ✅ Banco recebe 5% de cada depósito
- ✅ Contas com IDs únicos
- ✅ Atributos privados
- ✅ Banco gerencia contas
- ✅ Empréstimos limitados pela liquidez
- ✅ Getters const por referência

---

### [Exercise 01: I don't know what I'm doing!](ex01/)
Sistema de gráfico ASCII com pontos representados por Vector2.

**Objetivos:**
- Criar estrutura `Vector2` (x, y em float)
- Criar classe `Graph` para plotar pontos
- Exibir gráfico em ASCII art no console
- Aplicar encapsulamento correto

**Compilar e executar:**
```bash
cd ex01
make
./graph
```

**Exemplo de saída (pontos em 0/0, 2/2, 4/2, 2/4):**
```
>& 5 . . . . . .
>& 4 . . X . . .
>& 3 . . . . . .
>& 2 . . X . X .
>& 1 . . . . . .
>& 0 X . . . . .
>& 0 1 2 3 4 5
```

**Requisitos:**
- ✅ Vector2 com x e y encapsulados
- ✅ Graph com size e lista de pontos
- ✅ Adicionar pontos ao gráfico
- ✅ Exibir gráfico no console
- ✅ Decisões de encapsulamento justificáveis

---

## Estrutura do Module00

```
Module00/
├── DivideAndRule.cpp       # Código original (sem encapsulamento)
├── en.subject.pdf          # Subject do módulo
├── README.md               # Este arquivo
├── COMPARISON.md           # Comparação antes/depois
├── CHECKLIST.md            # Checklist de avaliação
├── ex00/                   # Exercício 00: Banco
│   ├── inc/
│   │   ├── Account.hpp
│   │   └── Bank.hpp
│   ├── src/
│   │   ├── Account.cpp
│   │   ├── Bank.cpp
│   │   └── main.cpp
│   └── Makefile
└── ex01/                   # Exercício 01: Graph
    ├── inc/
    │   ├── Vector2.hpp
    │   └── Graph.hpp
    ├── src/
    │   ├── Vector2.cpp
    │   ├── Graph.cpp
    │   └── main.cpp
    └── Makefile
```

---

## Detalhes dos Exercícios

### Exercise 00: Divide and Conquer

#### Classes Implementadas

**Account (Conta)**
```cpp
class Account {
private:
    int _id;        // ID único
    int _value;     // Saldo
    Account(int id); // Construtor privado
    friend class Bank;
public:
    const int& getId() const;
    const int& getValue() const;
};
```

**Bank (Banco)**
```cpp
class Bank {
private:
    int _liquidity;
    std::vector<Account*> _clientAccounts;
    int _nextAccountId;
public:
    Account* createAccount();
    void deleteAccount(int accountId);
    bool deposit(int accountId, int amount);    // Taxa 5%
    bool withdraw(int accountId, int amount);
    bool giveLoan(int accountId, int amount);
    const int& getLiquidity() const;
};
```

#### Decisões de Encapsulamento

1. **Account com construtor privado**
   - Apenas Bank pode criar contas
   - Garante IDs únicos

2. **Friend class**
   - Bank acessa membros privados de Account
   - Não expõe atributos publicamente

3. **Getters por referência const**
   - Eficiência (sem cópias)
   - Segurança (const impede modificação)

---

### Exercise 01: I don't know what I'm doing!

#### Classes Implementadas

**Vector2**
```cpp
class Vector2 {
private:
    float _x;
    float _y;
public:
    Vector2(float x, float y);
    const float& getX() const;
    const float& getY() const;
    void setX(float x);
    void setY(float y);
};
```

**Graph**
```cpp
class Graph {
private:
    Vector2 _size;
    std::vector<Vector2> _points;
    bool _isPointValid(const Vector2& point) const;
public:
    Graph(float width, float height);
    bool addPoint(float x, float y);
    bool addPoint(const Vector2& point);
    void display() const;
    size_t getPointCount() const;
};
```

#### Decisões de Encapsulamento

1. **Vector2 com atributos privados**
   - x e y não podem ser modificados diretamente
   - Setters permitem validação se necessário

2. **Graph com lista privada**
   - Pontos gerenciados internamente
   - Validação de bounds ao adicionar

3. **Método display() público**
   - Interface para visualização
   - Não expõe dados internos

---

## Conceitos de OOP Aplicados

### 1. Encapsulamento
- Atributos privados
- Acesso controlado via getters/setters
- Validações em métodos públicos

### 2. Friend Class
- Relacionamento especial entre classes
- Acesso a membros privados sem exposição pública

### 3. Const Correctness
- Métodos const não modificam objeto
- Referências const impedem modificação

### 4. Validação de Regras de Negócio
- Depósitos/saques validados
- Pontos dentro dos limites do gráfico
- Empréstimos limitados pela liquidez

---

## Como Avaliar

### Perguntas Comuns na Defesa

**Ex00:**
1. Por que Account tem construtor privado?
2. O que é friend class e quando usar?
3. Por que getters por referência?
4. Como garantir IDs únicos?
5. Por que validar operações bancárias?

**Ex01:**
1. Por que x e y são privados?
2. Como você controla a adição de pontos?
3. Por que Vector2 tem setters mas Account não?
4. Como funciona a exibição do gráfico?
5. Que decisões de encapsulamento você fez e por quê?

### Teste de Encapsulamento

Tente acessar atributos privados no main:
```cpp
account->_id = 999;      // ❌ Não compila
vector._x = 100;         // ❌ Não compila
graph._points.clear();   // ❌ Não compila
```

Se não compilar = Encapsulamento funcionando! ✅

---

## Compilação

Ambos exercícios seguem as regras:
- Compilador: `c++`
- Flags: `-Wall -Wextra -Werror -std=c++98`
- Makefile com regras: `all`, `clean`, `fclean`, `re`
- Sem relink desnecessário
- Sem bibliotecas externas ou Boost


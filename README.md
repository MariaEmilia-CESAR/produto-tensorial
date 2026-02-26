**Produto Tensorial em C**

Este projeto implementa o Produto Tensorial entre duas matrizes 2x2 ou 3x3 utilizando alocação dinâmica de memória na linguagem C.

O programa recebe dois arquivos .txt como entrada, cada um contendo uma matriz, calcula o produto tensorial entre elas e gera automaticamente um arquivo de saída com o resultado.

O desenvolvimento foi feito com foco em:

*   Alocação dinâmica de memória
    
*   Modularização do código
    
*   Manipulação de arquivos
    
*   Tratamento de erros
    
*   Liberação correta de memória (sem vazamentos)
    

Funcionamento do Programa
-------------------------

O programa deve ser executado passando exatamente dois arquivos como argumento na linha de comando:

./tensor teste/A.txt teste/B.txt

Formato dos Arquivos de Entrada
-------------------------------

Cada arquivo deve conter apenas números separados por espaço, organizados em formato de matriz.

Exemplo de matriz 2x2:

1 2
3 4

Exemplo de matriz 3x3:

1 2 3
4 5 6
7 8 9

As matrizes devem ser quadradas (2x2 ou 3x3).

Arquivo de Saída
----------------

Após a execução, o programa gera automaticamente o arquivo:

tensor\_mess.out

Esse arquivo contém o resultado do produto tensorial entre as duas matrizes fornecidas.

Conceito Matemático
-------------------

O Produto Tensorial entre duas matrizes A e B é definido da seguinte forma:

Se A possui dimensão m × ne B possui dimensão p × q

Então o resultado A ⊗ B terá dimensão:

(m · p) × (n · q)

O cálculo consiste em multiplicar cada elemento da matriz A por todos os elementos da matriz B, formando uma matriz maior organizada em blocos.

Estrutura do Projeto
--------------------

O projeto está organizado em múltiplos arquivos:

include/matriz.h → definição da estrutura Matriz e protótipos das funções
src/main.c → controle principal do programa
src/matriz.c → implementação das funções de manipulação de matrizes
teste/ → arquivos de exemplo
Makefile → automatiza a compilação

Compilação
----------

O projeto utiliza Makefile.

Para compilar:

make

Para limpar arquivos compilados:

make clean

O executável gerado será chamado:

tensor

Tratamento de Erros
-------------------

O programa realiza verificação para:

*   Número incorreto de argumentos
    
*   Arquivos inexistentes
    
*   Falha na leitura dos dados
    
*   Falha de alocação dinâmica
    

Caso ocorra algum erro, uma mensagem apropriada é exibida no terminal.

Gerenciamento de Memória
------------------------

Toda a memória utilizada é alocada dinamicamente com malloc e liberada com free.

A função responsável por liberar a estrutura da matriz garante que não ocorram vazamentos de memória.

Tecnologias Utilizadas
----------------------

*   Linguagem C
    
*   GCC
    
*   Makefile
    
*   Git
    
*   GitHub
    

Contexto Acadêmico
------------------

Projeto desenvolvido para aplicação prática dos seguintes conceitos:

*   Ponteiros
    
*   Estruturas (struct)
    
*   Alocação dinâmica
    
*   Manipulação de arquivos
    
*   Organização modular em C

# Projeto Final - Gerador de Senhas Aleatórias

Projeto desenvolvido para a disciplina **Laboratório de Programação**, utilizando a linguagem C.

## Descrição

O sistema foi criado com o objetivo de gerar senhas aleatórias de forma personalizada, permitindo que o usuário escolha o tamanho da senha e os tipos de caracteres que deseja utilizar. Além da geração automática, o programa verifica se a senha atende aos critérios mínimos de segurança definidos no projeto e oferece a opção de salvar o resultado em um arquivo texto.

## Objetivo

Desenvolver uma aplicação que utilize conceitos de programação em C, como funções, strings, validação de dados e manipulação de arquivos, para gerar senhas aleatórias mais seguras.

## Funcionalidades

* Definição do tamanho da senha
* Seleção de letras maiúsculas
* Seleção de letras minúsculas
* Seleção de números
* Seleção de símbolos
* Geração automática da senha
* Verificação de força da senha
* Tratamento de entradas inválidas
* Salvamento da senha em arquivo texto

## Tecnologias e Conceitos Utilizados

* Linguagem C
* Funções
* Strings
* Vetores de caracteres
* Estruturas de repetição
* Estruturas condicionais
* Geração de números aleatórios
* Manipulação de arquivos texto para armazenamento das senhas geradas. (`fopen`, `fprintf`, `fclose`)
* Validação de entradas

## Estrutura do Programa

O projeto foi organizado em funções específicas para cada tarefa:

* `MontaCaracteres()` → cria a lista de caracteres permitidos
* `LerOpcaoBinaria()` → valida respostas 0 ou 1
* `LerTamanhoSenha()` → valida o tamanho informado
* `EmbaralhaSenha()` → embaralha os caracteres gerados
* `GeraSenha()` → gera a senha aleatória
* `VerificaSenhaForte()` → verifica os critérios de segurança
* `SalvaArquivo()` → salva a senha em arquivo texto

## Autora

Ana Thereza 



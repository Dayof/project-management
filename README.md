Project Management
=============

[![Build Status](https://travis-ci.org/Dayof/project-management.svg?branch=master)](https://travis-ci.org/Dayof/project-management)

Este projeto foca em desenvolver um gerenciador de projetos em organizações.

### Entidades
- Gerente de Sistema
	- Domínios: Nome, matrícula e senha.
- Gerente de Projeto
	- Domínios: Nome, matrícula, senha e telefone.
- Desenvolvedor
	- Domínios: Nome, matrícula, senha, e-mail e 
			função (analista, projetista ou programador).
- Projeto
	- Domínios: Nome, código, gerente de projeto, desenvolvedores do projeto, 
			data de início, data de término, custo atual, custo previsto e 
			estado.
- Fase
	- Domínios: Data de início, data de término e código de fase.

### Features: 
- Classes de domínios implemetadas;
- Classes de entidades implemetadas;
- Testes unitários para os domínios com por ao menos um caso válido e um caso inválido;
- Testes unitários para as entidades com por ao menos um caso válido e um caso inválido.
- Todos os testes estão passando!

### TODO: 
- Camadas de Apresentação, Negócio e Persistência.

### Executar (Via Code::Blocks)

Abrir arquivo project-management.cbp no Code::Blocks.

### Executar (Via terminal de comando)

``` bash
$ make all
$ ./main
```

### Gerar testes em arquivo

``` bash
$ ./main -r junit -o tests_results.xml
```

### Motivação
Projeto da matéria de Técnicas de Programação 1, professor Fernando Chacon. </br>
Universidade de Brasília (UnB), 2016/2.

### Autoria
Dayanne Fernandes da Cunha - 13/0107191

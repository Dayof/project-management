Project Management
=============

[![Build Status](https://travis-ci.org/Dayof/project-management.svg?branch=master)](https://travis-ci.org/Dayof/project-management)

Este projeto foca em desenvolver um gerenciador de projetos em organizações.

## Diretórios e Informações dos arquivos

| Tipo      | Nome                              	             | Função                          	     |
| --------- | ------------------------------------------------------ | ------------------------------------- |
| Diretório | [include](include)           		  	     | Possui os arquivos de biblioteca	     |
| Diretório | [src](src)                 		  	     | Possui os arquivos de implementação   |
| Diretório | [obj](obj)                  		  	     | Possui os arquivos objetos            |
| Diretório | [html](html)                         		     | Arquivos HTML do Doxygen      	     |
| Diretório | [latex](latex)                         		     | Arquivos Latex do Doxygen	     |
| Arquivo   | [project-management.cbp](project-management.cbp)	     | Arquivo do software para o C::B       |
| Arquivo   | [project-management.layout](project-management.layout) | Arquivo do software para o C::B       |
| Arquivo   | [README.md](README.md)           			     | Instruções gerais do projeto          |
| Arquivo   | [tests_results.xml](tests_results.xml)   		     | Resultados de todos os testes         |
| Arquivo   | [TODO.md](TODO.md)   				     | Alguns TODO para o Trabalho 2	     |
| Arquivo   | [Doxyfile](Doxyfile)   				     | Arquivo de configuração do Doxygen    |
| Arquivo   | [main](main)   				     	     | Arquivo executável do sistema	     |
| Arquivo   | [.travis.yml](.travis.yml)   		     	     | Arquivo de build do Travis	     |
| Arquivo   | [.git](.git)   				     	     | Arquivo de configurações do Git	     |
| Arquivo   | [.gitignore](.gitignore)         		 	     | Arquivos/pastas ignorados pelo Git    |

## Ferramenta de teste utilizada

Biblioteca [Catch](https://github.com/philsquared/Catch) para C++. 
Utiliza-se somente um header catch.hpp para utilizar essa ferramenta.

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

### Convenção de Codificação

- Arquivos: CamelCase.cpp;
- Classes: class CamelCase extends ParentObject;
- Variáveis: variables_underscored;
- Objetos que contém instâncias: camelCase = new CamelCase();
- Chaves de vetores: collection['underscored_keys'];
- Constantes: ALL_CAPS_AND_UNDERSCORED;
- Métodos: camelCase.fooMethod();
- Métodos estáticos: CamelCase::justLikeRegularMethod().

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

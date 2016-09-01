- Bibliotecas
 - Domínios (tipos básicos)
	- Código de projeto, etc.
 - Entidades
	- Gerente de sistema
	- Gerente de projeto
	- Desenvolvedor
	- Projeto
	- etc.
 - Testes de unidade
 - Controladores
	- Controle de UI (TUI, GUI) + Stub
	- Controle de lógica de negócio + Stub
	- Controle de persistência + Stub
 - Telas
 - Builders
 

-> Apresentação :
	- UI (Apt, navegação)
	- Validação (Formato)

--INTERFACE--
  -> Inicialização/Controle
    -> MIUIC
      -> Ctrl IUIC (INTERFACE->ILNIC para NEGOCIO)
  -> Gestão de membros de projeto
    -> MIUGMP
      -> Ctrl IUGMP (INTERFACE-> para NEGOCIO)
  -> Gestão de Projeto
   -> MUIGP
      -> Ctrl IUGP (INTERFACE-> para NEGOCIO)

-> Negócio :
	- Regras de negócio

--INTERFACE--
-> Inicialização/Controle
  -> MLNIC
    -> Ctrl LNIC (INTERFACE->IPER para PERSISTENCIA)
-> Gestão de membros de projeto
  -> MLNGMP
    -> Ctrl LNGMP (INTERFACE->IPER para PERSISTENCIA)
-> Gestão de Projeto
 -> MLNGP
    -> Ctrl LNGP (INTERFACE->IPER para PERSISTENCIA)

-> Persistência :
	- Armazenamento

--INTERFACE--
  -> IPER : MPERS
    -> Ctrl PERS

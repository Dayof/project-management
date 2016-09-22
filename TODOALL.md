- Bibliotecas
 - Domínios (tipos básicos) [OK]
 - Entidades [OK]
	- Gerente de sistema [OK]
	- Gerente de projeto [OK]
	- Desenvolvedor [OK]
	- Projeto [OK]
	- Fase [OK]
 - Testes de unidade [OK]
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

--INTERFACE--
  -> IPER : MPERS
    -> Ctrl PERS

Main calls:
	- Test Entity calls
		- Entity (cpp which calls hpp)
	- Test Domain
		- Domains (cpp which calls hpp)


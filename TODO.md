- Bibliotecas
 - Dom�nios (tipos b�sicos)
	- C�digo de projeto, etc.
 - Entidades [OK]
	- Gerente de sistema [OK]
	- Gerente de projeto [OK]
	- Desenvolvedor [OK]
	- Projeto [OK]
	- Fase [OK]
 - Testes de unidade
 - Controladores
	- Controle de UI (TUI, GUI) + Stub
	- Controle de l�gica de neg�cio + Stub
	- Controle de persist�ncia + Stub
 - Telas
 - Builders


-> Apresenta��o :
	- UI (Apt, navega��o)
	- Valida��o (Formato)

--INTERFACE--
  -> Inicializa��o/Controle
    -> MIUIC
      -> Ctrl IUIC (INTERFACE->ILNIC para NEGOCIO)
  -> Gest�o de membros de projeto
    -> MIUGMP
      -> Ctrl IUGMP (INTERFACE-> para NEGOCIO)
  -> Gest�o de Projeto
   -> MUIGP
      -> Ctrl IUGP (INTERFACE-> para NEGOCIO)

-> Neg�cio :
	- Regras de neg�cio

--INTERFACE--
-> Inicializa��o/Controle
  -> MLNIC
    -> Ctrl LNIC (INTERFACE->IPER para PERSISTENCIA)
-> Gest�o de membros de projeto
  -> MLNGMP
    -> Ctrl LNGMP (INTERFACE->IPER para PERSISTENCIA)
-> Gest�o de Projeto
 -> MLNGP
    -> Ctrl LNGP (INTERFACE->IPER para PERSISTENCIA)

-> Persist�ncia :
	- Armazenamento

--INTERFACE--
  -> IPER : MPERS
    -> Ctrl PERS

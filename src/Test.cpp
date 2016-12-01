/** @file Test.cpp
 *  @brief Arquivo de testes da classes de Domínio e Entidade.
 *
 *  Neste arquivo contém cenários de testes utilizando BDD
 *  (Behavior Driver Development) utilizando a biblioteca de teste
 *  Catch do C++.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#include "catch.hpp"
#include "Domain.hpp"
#include "Entity.hpp"

// TESTES DOS DOMINIOS

SCENARIO("nome eh inicializado", "[name]") {

    GIVEN("string para iniciar o nome") {
        string name_person;

        WHEN( "construtor sem parametro" ) {
            THEN( "o nome nao e atribuido e lanca excecao" ) {
               CHECK_THROWS(Name{});
            }
        }

        WHEN("com valores validos, CASO: Ate 20 caracteres, sendo A-Z e espaco em branco") {
            name_person = "taylor";
            Name* name = new Name(name_person);

            THEN( "o nome e atribuido" ) {
                REQUIRE(name->getName().length() == name_person.length());
            }
        }

         WHEN( "com valores invalidos, CASO 1: Mais de 20 caracteres" ) {
            name_person = "eudhfjrhdjthfkdsddhgjthg";
            THEN( "o nome e atribuido e lanca excecao" ) {
                CHECK_THROWS(Name{name_person});
            }
        }

        WHEN( "com valores invalidos, CASO 2: Com caracteres especiais" ) {
            name_person = "utada|@_@|hikaru  ";
            THEN( "o nome nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Name{name_person});
            }
        }
    }
}

SCENARIO("codigo de projeto e inicializado", "[cod_project]") {

    GIVEN("string para iniciar o codigo de projeto") {
        string cod_project;

        WHEN( "construtor sem parametro" ) {
            ProjectCode* projectCode = new ProjectCode();

            THEN( "o codigo de projeto e atribuido com valor default 'AAAAA'" ) {
               REQUIRE(projectCode->getCodProject() == "AAAAA");
            }
        }

        WHEN("com valores validos, CASO: 5 letras de A-Z") {
            cod_project = "ABCDE";
            ProjectCode* projectCode = new ProjectCode(cod_project);

            THEN( "o codigo de projeto e atribuido" ) {
                REQUIRE(projectCode->getCodProject() == cod_project);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Menos de 5 caracteres" ) {
            cod_project = "MIT";
            THEN( "o codigo de projeto nao e atribuido e lanca excecao"  ) {
                CHECK_THROWS(ProjectCode{cod_project});
            }
        }

        WHEN( "com valores invalidos, CASO 2: Mais de 5 caracteres" ) {
            cod_project = "MITMIT";
            THEN( "o codigo de projeto nao e atribuido e lanca excecao"  ) {
                 CHECK_THROWS(ProjectCode{cod_project});
            }
        }

        WHEN(  "com valores invalidos, CASO 3: Caracteres a-z" ) {
            cod_project = "mitmit";
            THEN( "o codigo de projeto nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(ProjectCode{cod_project});
            }
        }

        WHEN( "com valores invalidos, CASO 4: Caracteres especiais" ) {
            cod_project = "MIT_$";
            THEN( "o codigo de projeto nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(ProjectCode{cod_project});
            }
        }
    }
}

SCENARIO("estado de projeto e inicializado", "[project_state]") {

    GIVEN("inteiro para iniciar o estado de projeto") {
        int project_state;

        WHEN( "construtor sem parametro" ) {
            ProjectState* projectState = new ProjectState();

            THEN( "o estado de projeto e atribuido com valor default '1' " ) {
               REQUIRE(projectState->getProjectState() == 1);
            }
        }

        WHEN( "com valores validos, CASO: 1 digito entre 0-9" ) {
            project_state = 2;
            ProjectState* projectState = new ProjectState(project_state);

            THEN( "o estado de projeto e atribuido" ) {
                REQUIRE(projectState->getProjectState() == project_state);
            }
        }

        WHEN( "com valores invalidos, CASO 1: Mais de 1 digito" ) {
            project_state = 23;
            THEN( "o codigo de projeto nao e atribuido e lanca excecao" ) {
               CHECK_THROWS(ProjectState{project_state});
            }
        }

         WHEN( "com valores invalidos, CASO 2: Valores nao permitidos" ) {
            project_state = 3;
            THEN( "o codigo de projeto nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(ProjectState{project_state});
            }
        }
    }
}

SCENARIO("fase de projeto e inicializado", "[project_phase]") {

    GIVEN("inteiro para iniciar a fase de projeto") {
        int project_phase;

        WHEN( "construtor sem parametro" ) {
            ProjectPhase* projectPhase = new ProjectPhase();

            THEN( "a fase de projeto e atribuida com valor default '1' " ) {
               REQUIRE(projectPhase->getProjectPhase() == 1);
            }
        }

        WHEN( "com valores validos, CASO: 1 digito entre 0-9") {
            project_phase = 2;
            ProjectPhase* projectPhase = new ProjectPhase(project_phase);

            THEN( "a fase de projeto e atribuida" ) {
                REQUIRE(projectPhase->getProjectPhase() == project_phase);
            }
        }

        WHEN( "com valores invalidos, CASO 1: Mais de 1 digito" ) {
            project_phase = 23;
            THEN( "a fase de projeto nao e atribuida e lanca excecao" ) {
               CHECK_THROWS(ProjectPhase{project_phase});
            }
        }

        WHEN( "com valores invalidos, CASO 2: Valores nao permitidos" ) {
            project_phase = 5;
            THEN( "a fase de projeto nao e atribuida e lanca excecao" ) {
                CHECK_THROWS(ProjectPhase{project_phase});
            }
        }
    }
}

SCENARIO("funcao e inicializada", "[role]") {

    GIVEN("inteiro para iniciar a funcao") {
        int role_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "a funcao nao e atribuida e lanca excecao" ) {
               CHECK_THROWS(Role{});
            }
        }

        WHEN( "com valores validos, CASO: 1 digito entre 0-9") {
            role_stub = 3;
            Role* role = new Role(role_stub);

            THEN( "a funcao e atribuida" ) {
                REQUIRE(role->getRole() == role_stub);
            }
        }

        WHEN( "com valores invalidos, CASO 1: Mais de 1 digito" ) {
            role_stub = 23;
            THEN( "a funcao nao e atribuida e lanca excecao" ) {
               CHECK_THROWS(Role{role_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 2: Valores nao permitidos" ) {
            role_stub = 5;
            THEN( "a funcao nao e atribuida e lanca excecao" ) {
                CHECK_THROWS(Role{role_stub});
            }
        }
    }
}

SCENARIO("e-mail e inicializado", "[email]") {

    GIVEN("string para iniciar o e-mail") {
        string email_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "o email nao e atribuido e lanca excecao" ) {
               CHECK_THROWS(Email{});
            }
        }

        WHEN("com valores validos, CASO: Parte local com caracteres validos"
            " seguida de um caracter @ e sub endereco com caracteres validos"
            " com um ponto somente") {
            email_stub = "testing@gmail.com";
            Email* email = new Email(email_stub);

            THEN( "o email e atribuido" ) {
                REQUIRE(email->getEmail() == email_stub);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Sem caracter @" ) {
            email_stub = "Abc.example.com";
            THEN( "o email nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Email{email_stub});
            }
        }

         WHEN( "com valores invalidos, CASO 2: Com mais de um caracter @" ) {
            email_stub = "A@b@c@example.com";
            THEN( "o email nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Email{email_stub});
            }
        }

         WHEN( "com valores invalidos, CASO 3: Nenhum caracter especial"
            " na parte local e permitido sem estar entra aspas") {
            email_stub = "a\"b(c)d,e:f;g<h>i[j\k]l@example.com";
            THEN( "o email nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Email{email_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 4: String entre aspas"
            " precisam estar separadas por pontos ou ser a unica string"
            " da parte local") {
            email_stub = "just\"not\"right@example.com";
            THEN( "o email nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Email{email_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 5: Dois pontos apos o caracter @") {
            email_stub = "john.doe@example..com";
            THEN( "o email nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Email{email_stub});
            }
        }
    }
}

SCENARIO("data e inicializada", "[date]") {

    GIVEN("string para iniciar a data") {
        string date_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "a data nao e atribuida e lanca excecao" ) {
               CHECK_THROWS(Date{});
            }
        }

        WHEN("com valores validos, CASO: formato 1-31/1-12/2016-2050") {
            date_stub = "17/06/2020";
            Date* date = new Date(date_stub);

            THEN( "a data e atribuida" ) {
                REQUIRE(date->getDate() == date_stub);
            }
        }

         WHEN( "com valores invalidos, CASO 1: nenhum valor entre barras" ) {
            date_stub = "///";
            THEN( "a data nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Date{date_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 2: com menos de 3 barras" ) {
            date_stub = "17/062016";
            THEN( "a data nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Date{date_stub});
            }
        }

         WHEN( "com valores invalidos, CASO 3: data com ano superior"
            " a 2050") {
            date_stub = "17/06/2051";
            THEN( "a data nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Date{date_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 4: dia 0") {
            date_stub = "0/06/2016";
            THEN( "a data nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Date{date_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 5: mes maior que 12") {
            date_stub = "17/15/2016";
            THEN( "a data nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Date{date_stub});
            }
        }
    }
}

SCENARIO("telefone e inicializado", "[phone]") {

    GIVEN("string para iniciar o telefone") {
        string phone_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "o telefone nao e atribuido e lanca excecao" ) {
               CHECK_THROWS(Phone{});
            }
        }

        WHEN("com valores validos, CASO: 8 digitos, sendo 0-9") {
            phone_stub = "12345678";
            Phone* phone = new Phone(phone_stub);

            THEN( "o telefone e atribuido" ) {
                REQUIRE(phone->getPhone() == phone_stub);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Mais de 8 digitos" ) {
            phone_stub = "123456789";
            THEN( "o telefone nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Phone{phone_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 2: Menos de 8 digitos" ) {
            phone_stub = "123489";
            THEN( "o telefone nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Phone{phone_stub});
            }
        }

         WHEN( "com valores invalidos, CASO 3: Caracteres nao decimais" ) {
            phone_stub = "1234567t";
            THEN( "o telefone nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Phone{phone_stub});
            }
        }
    }
}

SCENARIO("senha e inicializada", "[password]") {

    GIVEN("string para iniciar a senha") {
        string pass_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "a senha nao e atribuida e lanca excecao" ) {
               CHECK_THROWS(Password{});
            }
        }

        WHEN("com valores validos, CASO: 5 caracteres sem repeticao") {
            pass_stub = "12345";
            Password* pass = new Password(pass_stub);

            THEN( "a senha e atribuida" ) {
                REQUIRE(pass->getPassword() == pass_stub);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Repeticao de caracteres" ) {
            pass_stub = "abccf";
            THEN( "a senha nao e atribuida e lanca excecao" ) {
                CHECK_THROWS(Password{pass_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 2: Menos de 5 caracteres" ) {
            pass_stub = "abs";
            THEN( "a senha nao e atribuida e lanca excecao" ) {
                CHECK_THROWS(Password{pass_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 3: Mais de 5 caracteres" ) {
            pass_stub = "absabs";
            THEN( "a senha nao e atribuida e lanca excecao" ) {
                CHECK_THROWS(Password{pass_stub});
            }
        }
    }
}

SCENARIO("matricula e inicializada", "[registration]") {

    GIVEN("string para iniciar a matricula") {
        string reg_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "a matricula nao e atribuida e lanca excecao" ) {
               CHECK_THROWS(Registration{});
            }
        }

        WHEN("com valores validos, CASO: 5 digitos, sendo de 0-9") {
            reg_stub = "00000";
            Registration* reg = new Registration(reg_stub);

            THEN( "a matricula e atribuida" ) {
                REQUIRE(reg->getRegistration() == reg_stub);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Matricula com valores"
            " nao decimais" ) {
            reg_stub = "ab123";
            THEN( "a matricula nao e atribuida e lanca excecao" ) {
                CHECK_THROWS(Registration{reg_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 2: Menos de 5 digitos" ) {
            reg_stub = "145";
            THEN( "a matricula nao e atribuida e lanca excecao" ) {
                CHECK_THROWS(Registration{reg_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 3: Mais de 5 digitos" ) {
            reg_stub = "678512";
            THEN( "a matricula nao e atribuida e lanca excecao" ) {
                CHECK_THROWS(Registration{reg_stub});
            }
        }
    }
}

SCENARIO("custo e inicializado", "[cost]") {

    GIVEN("string para iniciar o custo") {
        string cost_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "o custo nao e atribuido e lanca excecao" ) {
               CHECK_THROWS(Cost{});
            }
        }

        WHEN("com valores validos, CASO: 0.00") {
            cost_stub = "5.36";
            Cost* cost = new Cost(cost_stub);

            THEN( "o custo e atribuido" ) {
                REQUIRE(cost->getCost() == cost_stub);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Custo com 2 pontos" ) {
            cost_stub = "5..40";
            THEN( "o custo nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Cost{cost_stub});
            }
        }

        WHEN( "com valores invalidos, CASO 2: Custo com caracteres"
            " nao decimais antes ou depois do ponto") {
            cost_stub = "a5.4t0";
            THEN( "o custo nao e atribuido e lanca excecao" ) {
                CHECK_THROWS(Cost{cost_stub});
            }
        }
    }
}

// TESTES DAS ENTIDADES

SCENARIO("gerente de sistema eh inicializado", "[sysmanager]") {

    GIVEN("strings de nome, matricula e senha para iniciar o gerente de sistema") {
        string name_stub, reg_stub, pass_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "o gerente de sistema nao e criado e lanca excecao" ) {
               CHECK_THROWS(SysManager{});
            }
        }

        WHEN("com valores validos, CASO: Construtor e criado se e passado"
            " nome, matricula e senha com valores validos") {
            name_stub = "Day";
            reg_stub = "13010";
            pass_stub = "abcde";

            SysManager* sysManager = new SysManager(name_stub,
                                                    reg_stub,
                                                    pass_stub);

            THEN( "o nome e atribuido ao gerente de sistema" ) {
                REQUIRE(sysManager->getName() == name_stub);
            }

            THEN( "a matricula e atribuida ao gerente de sistema" ) {
                REQUIRE(sysManager->getRegistration() == reg_stub);
            }

            THEN( "a senha e atribuida ao gerente de sistema" ) {
                REQUIRE(sysManager->getPassword() == pass_stub);
            }
        }

         WHEN( "com valores invalidos, CASO: Construtor nao e criado se"
            " e passado nome, matricula ou senha com valores invalidos") {
            name_stub = "Day@";
            reg_stub = "1301A0";
            pass_stub = "abafsfasc1231a";

            THEN( "o gerente de sistema nao e criado e lanca excecao" ) {
                CHECK_THROWS(SysManager sysManager (name_stub,reg_stub,pass_stub));
            }
        }
    }
}

SCENARIO("gerente de projeto eh inicializado", "[projectmanager]") {

    GIVEN("strings de nome, matricula, senha e telefone para iniciar o gerente de projeto") {
        string name_stub, reg_stub, pass_stub, phone_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "o gerente de projeto nao e criado e lanca excecao" ) {
               CHECK_THROWS(ProjectManager{});
            }
        }

        WHEN("com valores validos, CASO 1: Construtor e criado se e passado"
            " nome, matricula e senha com valores validos no minimo") {
            name_stub = "Diana";
            reg_stub = "16000";
            pass_stub = "abcde";

            ProjectManager* projectManager = new ProjectManager(name_stub,
                                                                reg_stub,
                                                                pass_stub);

            THEN( "o nome e atribuido ao gerente de projeto" ) {
                REQUIRE(projectManager->getName() == name_stub);
            }

            THEN( "a matricula e atribuida ao gerente de projeto" ) {
                REQUIRE(projectManager->getRegistration() == reg_stub);
            }

            THEN( "a senha e atribuida ao gerente de projeto" ) {
                REQUIRE(projectManager->getPassword() == pass_stub);
            }
        }

        WHEN( "com valores validos, CASO 2: Construtor criado recebe"
            " telefone com valor valido") {
            name_stub = "Diana";
            reg_stub = "16000";
            pass_stub = "abcde";
            phone_stub = "12345678";

            ProjectManager* projectManager = new ProjectManager(name_stub,
                                                                reg_stub,
                                                                pass_stub);
            projectManager->setPhone(phone_stub);


            THEN( "o telefone e atribuido ao gerente de projeto" ) {
                REQUIRE(projectManager->getPhone() == phone_stub);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Construtor nao e criado se"
            " e passado nome, matricula ou senha com valores invalidos") {
            name_stub = "Day@";
            reg_stub = "16000";
            pass_stub = "abcde";

            THEN( "o gerente de projeto nao e criado e lanca excecao" ) {
                CHECK_THROWS(ProjectManager projectManager (name_stub,reg_stub,pass_stub));
            }
        }

        WHEN( "com valores invalidos, CASO 2: Construtor criado recebe"
            " telefone com valor invalido") {
            name_stub = "Diana";
            reg_stub = "16000";
            pass_stub = "abcde";
            phone_stub = "123456789";

            ProjectManager* projectManager = new ProjectManager(name_stub,
                                                                reg_stub,
                                                                pass_stub);
            THEN( "o telefone e atribuido ao gerente de projeto" ) {
                CHECK_THROWS(projectManager->setPhone(phone_stub););
            }
        }
    }
}

SCENARIO("desenvolvedor eh inicializado", "[developer]") {

    GIVEN("strings de nome, matricula, senha e e-mail, e inteiro de funcao"
        " para iniciar o desenvolvedor") {
        string name_stub, reg_stub, pass_stub, phone_stub, email_stub;
        int role_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "o desenvolvedor nao e criado e lanca excecao" ) {
               CHECK_THROWS(Developer{});
            }
        }

        WHEN("com valores validos, CASO 1: Construtor e criado se e passado"
            " nome, matricula, senha e funcao com valores validos no minimo") {
            name_stub = "Diana";
            reg_stub = "16000";
            pass_stub = "abcde";
            role_stub = ANALIST;

            Developer* dev = new Developer(name_stub, reg_stub, pass_stub, role_stub);

            THEN( "o nome e atribuido ao desenvolvedor" ) {
                REQUIRE(dev->getName() == name_stub);
            }

            THEN( "a matricula e atribuida ao desenvolvedor" ) {
                REQUIRE(dev->getRegistration() == reg_stub);
            }

            THEN( "a senha e atribuida ao desenvolvedor" ) {
                REQUIRE(dev->getPassword() == pass_stub);
            }

             THEN( "a funcao e atribuida ao desenvolvedor" ) {
                REQUIRE(dev->getRole() == role_stub);
            }
        }

        WHEN( "com valores validos, CASO 2: Construtor criado recebe"
            " email com valor valido") {
            name_stub = "Diana";
            reg_stub = "16000";
            pass_stub = "abcde";
            role_stub = ANALIST;
            email_stub = "moz@gmail.com";

            Developer* dev = new Developer(name_stub, reg_stub, pass_stub, role_stub);

            dev->setEmail(email_stub);

            THEN( "o email e atribuido ao desenvolvedor" ) {
                REQUIRE(dev->getEmail() == email_stub);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Construtor nao e criado se"
            " e passado nome, matricula, senha ou funcao com valores invalidos") {
            name_stub = "Day@";
            reg_stub = "16000";
            pass_stub = "abcde";
            role_stub = PROGRAMMER;

            THEN( "o desenvolvedor nao e criado e lanca excecao" ) {
                CHECK_THROWS(Developer dev (name_stub,reg_stub,pass_stub, role_stub));
            }
        }

        WHEN( "com valores invalidos, CASO 2: Construtor criado recebe"
            " e-mail com valor invalido") {
            name_stub = "Diana";
            reg_stub = "16000";
            pass_stub = "abcde";
            role_stub = SOFTWARE_DESIGNER;
            email_stub = "moz@gmail..com";

            Developer* dev = new Developer(name_stub, reg_stub, pass_stub, role_stub);

            THEN( "o telefone e atribuido ao gerente de projeto" ) {
                CHECK_THROWS(dev->setEmail(phone_stub););
            }
        }
    }
}

SCENARIO("projeto eh inicializado", "[project]") {

    GIVEN("strings de nome, codigo, data de inicio, data de termino,"
        " de custo atual, custo previsto, inteiro de estado, classe de gerente de projeto"
        " e desenvolvedores do projeto para iniciar o projeto") {
        string name_stub, code_stub, init_date, end_date, current_cost, estimate_cost;
        vector<Developer> developers;
        ProjectManager* projectManager;
        int state;


        WHEN( "construtor sem parametro" ) {
            THEN( "o projeto nao e criado e lanca excecao" ) {
               CHECK_THROWS(Project{});
            }
        }

        WHEN("com valores validos, CASO 1: Construtor e criado se e passado"
            " no minimo nome, codigo, gerente de projeto, data de inicio e estado"
            " com valores validos") {
            name_stub = "FUCKING PROJECT";
            code_stub = "LOLLO";
            projectManager = new ProjectManager("Sir", "34567", "12345");
            init_date = "13/03/2020";
            state = ACTIVE;

            Project* project = new Project(name_stub,
                                            code_stub,
                                            projectManager,
                                            init_date,
                                            state);

            THEN( "o nome e atribuido ao projeto" ) {
                REQUIRE(project->getName() == name_stub);
            }

            THEN( "o codigo e atribuido ao projeto" ) {
                REQUIRE(project->getCode() == code_stub);
            }

            THEN( "o gerente de projeto e atribuido ao projeto" ) {
                REQUIRE(project->getProjectManager() == projectManager);
            }

             THEN( "a data de inicio e atribuida ao projeto" ) {
                REQUIRE(project->getInitDate() == init_date);
            }

             THEN( "o estado e atribuido ao projeto" ) {
                REQUIRE(project->getState() == state);
            }
        }

        WHEN( "com valores validos, CASO 2: Construtor criado recebe"
            " data de termino com valor valido") {
            name_stub = "FUCKING PROJECT";
            code_stub = "LOLLO";
            projectManager = new ProjectManager("Sir", "34567", "12345");
            init_date = "13/03/2029";
            state = ACTIVE;
            end_date = "13/04/2030";

            Project* project = new Project(name_stub,
                                            code_stub,
                                            projectManager,
                                            init_date,
                                            state);

            project->setEndDate(end_date);

            THEN( "a data de termino e atribuida ao projeto" ) {
                REQUIRE(project->getEndDate() == end_date);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Construtor nao e criado se"
             " e passado nome, codigo, gerente de projeto, data de inicio ou estado"
            " com valores invalidos") {
            name_stub = "FUCKING_PROJECT";
            code_stub = "LOLLO";
            projectManager = new ProjectManager("Sir", "34567", "12345");
            init_date = "13/03/2029";
            state = ACTIVE;

            THEN( "o projeto nao e criado e lanca excecao" ) {
                CHECK_THROWS(Project project (name_stub,
                                            code_stub,
                                            projectManager,
                                            init_date,
                                            state));
            }
        }

        WHEN( "com valores invalidos, CASO 2: Construtor criado recebe"
            " data de termino com valor invalido") {
            name_stub = "FUCKING PROJECT";
            code_stub = "LOLLO";
            projectManager = new ProjectManager("Sir", "34567", "12345");
            init_date = "13/03/2029";
            state = ACTIVE;
            end_date = "13/04/2080";

            Project* project = new Project(name_stub,
                                            code_stub,
                                            projectManager,
                                            init_date,
                                            state);

            THEN( "o projeto nao e criado e lanca excecao" ) {
                CHECK_THROWS(project->setEndDate(end_date););
            }
        }
    }
}

SCENARIO("fase eh inicializada", "[phase]") {

    GIVEN("strings de data de inicio, data de termino,"
        " e inteiro de codigo para iniciar a fase") {
        string init_date, end_date;
        int phase_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "a fase nao e criada e lanca excecao" ) {
               CHECK_THROWS(Phase{});
            }
        }

        WHEN("com valores validos, CASO 1: Construtor e criado se e passado"
            " no minimo data de inicio e codigo com valores validos") {
            init_date = "13/03/2020";
            phase_stub = INIT;

            Phase* phase = new Phase(init_date, phase_stub);

             THEN( "a data de inicio e atribuida a fase" ) {
                REQUIRE(phase->getInitDate() == init_date);
            }

             THEN( "o codigo e atribuido a fase" ) {
                REQUIRE(phase->getPhase() == phase_stub);
            }
        }

        WHEN( "com valores validos, CASO 2: Construtor criado recebe"
            " data de termino com valor valido") {
            init_date = "13/03/2029";
            phase_stub = EXEC;
            end_date = "13/04/2030";

          Phase* phase = new Phase(init_date, phase_stub);

            phase->setEndDate(end_date);

            THEN( "a data de termino e atribuida a fase" ) {
                REQUIRE(phase->getEndDate() == end_date);
            }
        }

         WHEN( "com valores invalidos, CASO 1: Construtor nao e criado se"
             " e passado data de inicio ou codigo com valores invalidos") {
            init_date = "13/03/2059";
            phase_stub = PREPARATION;

            THEN( "a fase nao e criada e lanca excecao" ) {
                CHECK_THROWS(Phase phase(init_date, phase_stub));
            }
        }

        WHEN( "com valores invalidos, CASO 2: Construtor criado recebe"
            " data de termino com valor invalido") {
            init_date = "13/03/2029";
            phase_stub = CLOSURE;
            end_date = "13/04/2080";

            Phase* phase = new Phase(init_date, phase_stub);

            THEN( "a fase nao e criada e lanca excecao" ) {
                CHECK_THROWS(phase->setEndDate(end_date));
            }
        }
    }
}

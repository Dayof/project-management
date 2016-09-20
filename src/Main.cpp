#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Domain.hpp"

SCENARIO("nome eh inicializado", "[name]") {

    GIVEN("string para iniciar o nome") {
        string name_person;

        WHEN( "construtor sem parametro" ) {
            THEN( "o nome nao e atribuido e lanca excecao" ) {
               CHECK_THROWS(Name{});
            }
        }

        WHEN( "com menos de 21 caracteres e com caracteres validos" ) {
            name_person = "taylor";
            Name* name = new Name(name_person);

            THEN( "o nome e atribuido" ) {
                REQUIRE(name->getName().length() == name_person.length());
            }
        }

        WHEN( "com mais de 20 caracteres" ) {
            name_person = "eudhfjrhdjthfkdsddhgjthg";
            THEN( "o nome e atribuido e lanca excecao" ) {
                CHECK_THROWS(Name{name_person});
            }
        }

        WHEN( "com caracteres invalidos" ) {
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

        WHEN( "com menos de 6 caracteres e com caracteres validos" ) {
            cod_project = "MIT";
            ProjectCode* projectCode = new ProjectCode(cod_project);

            THEN( "o codigo de projeto e atribuido" ) {
                REQUIRE(projectCode->getCodProject().length() == cod_project.length());
            }
        }

        WHEN( "com mais de 5 caracteres" ) {
            cod_project = "MITMIT";
            THEN( "o codigo de projeto e atribuido e lanca excecao" ) {
                CHECK_THROWS(ProjectCode{cod_project});
            }
        }

        WHEN( "com caracteres invalidos" ) {
            cod_project = "M I_T";
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

        WHEN( "com menos de 2 digitos e com valores validos" ) {
            project_state = 2;
            ProjectState* projectState = new ProjectState(project_state);

            THEN( "o estado de projeto e atribuido" ) {
                REQUIRE(projectState->getProjectState() == project_state);
            }
        }

        WHEN( "com mais de 1 digito" ) {
            project_state = 23;
            THEN( "o codigo de projeto nao e atribuido e lanca excecao" ) {
               CHECK_THROWS(ProjectState{project_state});
            }
        }

         WHEN( "com valores invalidos" ) {
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

        WHEN( "com menos de 2 digitos e com valores validos" ) {
            project_phase = 2;
            ProjectPhase* projectPhase = new ProjectPhase(project_phase);

            THEN( "a fase de projeto e atribuida" ) {
                REQUIRE(projectPhase->getProjectPhase() == project_phase);
            }
        }

        WHEN( "com mais de 1 digito" ) {
            project_phase = 23;
            THEN( "a fase de projeto nao e atribuida e lanca excecao" ) {
               CHECK_THROWS(ProjectPhase{project_phase});
            }
        }

        WHEN( "com valores invalidos" ) {
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

        WHEN( "com menos de 2 digitos e com valores validos" ) {
            role_stub = 3;
            Role* role = new Role(role_stub);

            THEN( "a funcao e atribuida" ) {
                REQUIRE(role->getRole() == role_stub);
            }
        }

        WHEN( "com mais de 1 digito" ) {
            role_stub = 23;
            THEN( "a funcao nao e atribuida e lanca excecao" ) {
               CHECK_THROWS(Role{role_stub});
            }
        }

         WHEN( "com valores invalidos" ) {
            role_stub = 5;
            THEN( "a funcao nao e atribuida e lanca excecao" ) {
                CHECK_THROWS(Role{role_stub});
            }
        }
    }
}

SCENARIO("e-mail e inicializada", "[email]") {

    GIVEN("string para iniciar o e-mail") {
        string email_stub;

        WHEN( "construtor sem parametro" ) {
            THEN( "o email nao e atribuida e lanca excecao" ) {
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
            date_stub = "17/06/2016";
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

#endif

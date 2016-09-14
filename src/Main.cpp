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

            THEN( "o codigo de projeto e atribuido com valor default 'AAA'" ) {
               REQUIRE(projectCode->getCodProject() == "AAA");
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

            THEN( "o estado de projeto e atribuido com valor default '0' " ) {
               REQUIRE(projectState->getProjectState() == 0);
            }
        }

        WHEN( "com menos de 2 digitos e com caracteres validos" ) {
            project_state = 7;
            ProjectState* projectState = new ProjectState(project_state);

            THEN( "o estado de projeto e atribuido" ) {
                REQUIRE(projectState->getProjectState() == project_state);
            }
        }

        WHEN( "com mais de 1 digito" ) {
            project_state = 23;
            THEN( "o codigo de projeto e atribuido e lanca excecao" ) {
               CHECK_THROWS(ProjectState{project_state});
            }
        }
    }
}

#endif

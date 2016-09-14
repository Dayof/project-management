#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Domain.hpp"

SCENARIO("nome eh inicializado", "[name]") {

    GIVEN("string para iniciar o nome") {
        string name_person;

        WHEN( "com menos de 21 caracteres" ) {
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

        WHEN( "com caracteres validos" ) {
            name_person = "Utada Hikaru";
            Name* name = new Name(name_person);

            THEN( "o nome e atribuido" ) {
                REQUIRE(name->getName().length() == name_person.length());
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

        WHEN( "com menos de 6 caracteres" ) {
            cod_project = "MIT";
            ProjectCode* project_code = new ProjectCode(cod_project);

            THEN( "o codigo de projeto e atribuido" ) {
                REQUIRE(project_code->getCodProject().length() == cod_project.length());
            }
        }

        WHEN( "com mais de 5 caracteres" ) {
            cod_project = "MITMIT";
            THEN( "o codigo de projeto e atribuido e lanca excecao" ) {
                CHECK_THROWS(ProjectCode{cod_project});
            }
        }

        WHEN( "com caracteres validos" ) {
            cod_project = "WOW";
            ProjectCode* project_code = new ProjectCode(cod_project);

            THEN( "o codigo de projeto e atribuido" ) {
                REQUIRE(project_code->getCodProject().length() == cod_project.length());
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

#endif

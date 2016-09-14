#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Domain.hpp"

SCENARIO("nome eh inicializado", "[nome]") {

    GIVEN("string para iniciar o nome") {
        string name_person;

        WHEN( "com menos de 20 caracteres" ) {
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


#endif

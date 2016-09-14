#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Domain.hpp"

SCENARIO("nome eh inicializado", "[nome]") {

    GIVEN("strings para iniciar o nome") {
        string person_name_valid = "taylor";
        string person_name_invalid = "eudhfjrhdjthfkdsddhgjthg";

        WHEN( "com menos de 20 caracteres" ) {
            Name* name = new Name(person_name_valid);

            THEN( "o nome e atribuido e nao lanca excecao" ) {
                REQUIRE(name->getName().length() == person_name_valid.length());
            }
        }

        WHEN( "com mais de 20 caracteres" ) {
            THEN( "o nome e atribuido e lanca excecao" ) {
                CHECK_THROWS(Name{person_name_invalid});
            }
        }
    }
}

#endif

#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Entity.hpp"

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Testing Entities", "[entity]" ) {

    SECTION("Setting SysManager")
    {
        SysManager* sm = new SysManager("1", "1", "1");
        REQUIRE( sm->getPassword() == "2" );
    }

    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
}

#endif

/** @file Main.cpp
 *  @brief Arquivo principal do sistema. Liga as controladoras com as
 *  camadas de apresentação, negócio e persistência.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "Domain.hpp"
#include "Entity.hpp"

int main( int argc, char* const argv[] )
{
  int result_test = Catch::Session().run( argc, argv );



  return result_test;
}

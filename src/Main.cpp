#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "Domain.hpp"
#include "Entity.hpp"

int main( int argc, char* const argv[] )
{
  int result = Catch::Session().run( argc, argv );

  return result;
}

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
#include "Persistence.hpp"

#include <cstdio>
#include <iostream>

int main( int argc, char* const argv[] )
{
    try
    {
        GetProject gp;
        Project* p;
        ProjectCode pc;

        p = gp(pc);

        printf("%s\n", p->getName().c_str());
        printf("%s\n", p->getCode().c_str());
        printf("%s\n", p->getInitDate().c_str());
        printf("%s\n", p->getEndDate().c_str());
        printf("%s\n", p->getCurrCost().c_str());
        printf("%s\n", p->getEstimateCost().c_str());
        printf("%d\n", p->getState());
        printf("%s\n", p->getProjectManager()->getName().c_str());
    }
    catch(PersistenceError& per_err)
    {
        cout << per_err.what() << endl;
    }

}

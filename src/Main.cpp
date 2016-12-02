/** @file Main.cpp
 *  @brief Arquivo principal do sistema. Liga as controladoras com as
 *  camadas de apresentação, negócio e persistência.
 *
 *  @author Dayanne Fernandes
 */

#define CATCH_CONFIG_RUNNER

#include "catch.hpp"
#include "Domain.hpp"
#include "Entity.hpp"
#include "Persistence.hpp"
#include "Business.hpp"
#include "UI.hpp"

#include <cstdio>
#include <iostream>

int main( int argc, char* const argv[] )
{
    int result_test = Catch::Session().run( argc, argv );

    try
    {
        BusShared *busShared = new BusShared();
        UIManageManager *uIManageManager = new UIManageManager(busShared);

        BusManageDev *busManageDev = new BusManageDev();
        UIManageDev *uIManageDev = new UIManageDev(busManageDev);

        BusManageProject *busManageProject = new BusManageProject();
        UIManageProject *uIManageProject = new UIManageProject(busManageProject);

        BusLogin *busLogin = new BusLogin();
        UILoginUser *uILoginUser = new UILoginUser(busLogin);
        uILoginUser->login(uIManageManager, uIManageProject, uIManageDev);
    }
    catch(PersistenceError& per_err)
    {
        cout << per_err.what() << endl;
    }
    catch(exception& domain_err)
    {
        cout << domain_err.what() <<  endl;
    }

    return result_test;
}

/** @file BusStub.hpp
 *  @brief Stub da camada de negócio.
 *
 *  Neste arquivo contém as assinaturas das classes
 *  de Stub da Camada de Negócio.
 *
 *  @author Dayanne Fernandes
 */

#ifndef STUB_BUS_HPP_INCLUDED
#define STUB_BUS_HPP_INCLUDED

#include "IBus.inl"

class BusStubLogin : public IBusLogin
{
public:
    void autenticar();
};

class BusStubShared : public IBusShared
{
public:
    string editPersonalInfo(Registration *reg, Name *name);
    string editPersonalInfo(Registration *reg, Password *pass);
    string editPersonalInfo(Registration *reg, Phone *phone);
    string editPersonalInfo(Registration *reg, Email *email);
    string editPersonalInfo(Registration *reg, Role *role);

    map<string, string> showPersonalInfo(Registration *reqReg, Registration *viewReg);
};

class BusStubManageManager : public IBusManageManager
{
public:
    string regPM(Registration *reg, ProjectManager *projManager);
    string delPM(Registration *reg, ProjectManager *projManager);
};

class BusStubManageDev : public IBusManageDev
{
public:
    string regD(Registration *reg, Developer *dev);
    string delD(Registration *reg, Developer *dev);

    string addDevToProject(Registration *reg, ProjectCode *projCode, Developer *dev);
    string delDevFromProject(Registration *reg, ProjectCode *projCode, Developer *dev);
};

class BusStubManageProject : public IBusManageProject
{
public:
    string regP(Registration *reg, Project *proj);
    string delP(Registration *reg, Project *proj);

    string editProjectInfo(Registration *reg, ProjectCode *projCode, Name *name);
    string editProjectInfo(Registration *reg, ProjectCode *projCode, Date *date, string init_end_date);
    string editProjectInfo(Registration *reg, ProjectCode *projCode, Cost *projCost, string curr_estimate_cost);
    string editProjectInfo(Registration *reg, ProjectCode *projCode, Developer *dev, Registration *oldDev);
    string editProjectInfo(Registration *reg, ProjectCode *projCode, ProjectManager *projManager, Registration *oldProjManager);
    string editProjectInfo(Registration *reg, ProjectCode *projCode,  ProjectState *state);

    map<string, string> showProjectInfo(ProjectCode *projCode);
};

#endif // STUB_BUS_HPP_INCLUDED

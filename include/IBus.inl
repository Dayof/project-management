/** @file IBus.hpp
 *  @brief Interface abstrata da camada de negócio.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#ifndef IBUS_HPP_INCLUDED
#define IBUS_HPP_INCLUDED

#include "Headers.inl"
#include "Domain.hpp"
#include "Entity.hpp"
#include "Persistence.hpp"

class IBusLogin
{
public:
    virtual void autenticar() = 0;
};

class IBusShared
{
public:
    virtual string editPersonalInfo(Registration *reg, Name *name) = 0;
    virtual string editPersonalInfo(Registration *reg, Password *pass) = 0;
    virtual string editPersonalInfo(Registration *reg, Phone *phone) = 0;
    virtual string editPersonalInfo(Registration *reg, Email *email) = 0;
    virtual string editPersonalInfo(Registration *reg, Role *role) = 0;

    virtual map<string, string> showPersonalInfo(Registration *reqReg, Registration *viewReg) = 0;
};

class IBusManageManager
{
public:
    virtual string regPM(Registration *reg, ProjectManager *projManager) = 0;
    virtual string delPM(Registration *reg, ProjectManager *projManager) = 0;
};

class IBusManageDev
{
public:
    virtual string regD(Registration *reg, Developer *dev) = 0;
    virtual string delD(Registration *reg, Developer *dev) = 0;

    virtual string addDevToProject(Registration *reg, ProjectCode *projCode, Developer *dev) = 0;
    virtual string delDevFromProject(Registration *reg, ProjectCode *projCode, Developer *dev) = 0;
};

class IBusManageProject
{
public:
    virtual string regP(Registration *reg, Project *proj) = 0;
    virtual string delP(Registration *reg, Project *proj) = 0;

    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, Name *name) = 0;
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, Date *date, string init_end_date) = 0;
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, Cost *projCost, string curr_estimate_cost) = 0;
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, Developer *dev, Registration *oldDev) = 0;
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, ProjectManager *projManager, Registration *oldProjManager) = 0;
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode,  ProjectState *state) = 0;

    virtual map<string, string> showProjectInfo(ProjectCode *projCode) = 0;
};


#endif // IBUS_HPP_INCLUDED

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

/**
 * \class IBus
 *
 * \brief Classe abstrata controladora da camada de negócio.
 *
 */
class IBus {
public:
    virtual string regPM(Registration *reg, ProjectManager *projManager);
    virtual string delPM(Registration *reg, ProjectManager *projManager);

    virtual string regP(Registration *reg, Project *proj);
    virtual string delP(Registration *reg, Project *proj);

    virtual string regD(Registration *reg, Developer *dev);
    virtual string delD(Registration *reg, Developer *dev);

    virtual string addDevToProject(Registration *reg, ProjectCode *projCode, Developer *dev);
    virtual string delDevFromProject(Registration *reg, ProjectCode *projCode, Developer *dev);

    virtual string editPersonalInfo(Registration *reg, Name *name);
    virtual string editPersonalInfo(Registration *reg, Password *pass);
    virtual string editPersonalInfo(Registration *reg, Phone *phone);
    virtual string editPersonalInfo(Registration *reg, Email *email);
    virtual string editPersonalInfo(Registration *reg, Role *role);

    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, Name *name);
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, Date *date, string init_end_date);
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, Cost *projCost, string curr_estimate_cost);
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, Developer *dev, Registration *oldDev);
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode, ProjectManager *projManager, Registration *oldProjManager);
    virtual string editProjectInfo(Registration *reg, ProjectCode *projCode,  ProjectState *state);

    virtual map<string, string> showPersonalInfo(Registration *reqReg, Registration *viewReg);;

    virtual map<string, string> showProjectInfo(ProjectCode *projCode);
};

#endif // IBUS_HPP_INCLUDED

/** @file IBus.hpp
 *  @brief Interface abstrata da camada de negócio.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#ifndef IBUS_HPP_INCLUDED
#define IBUS_HPP_INCLUDED

#include "Headers.inl"

/**
 * \class IBus
 *
 * \brief Classe abstrata controladora da camada de negócio.
 *
 */
class IBus {
public:
    virtual bool regPM(Registration *reg, ProjectManager *projManager);
    virtual bool delPM(Registration *reg, ProjectManager *projManager);

    virtual bool regP(Registration *reg, Project *proj);
    virtual bool delP(Registration *reg, Project *proj);

    virtual bool regD(Registration *reg, Developer *dev);
    virtual bool delD(Registration *reg, Developer *dev);

    virtual bool editPersonalInfo(ProjectManager *projManager, Name *name);
    virtual bool editPersonalInfo(ProjectManager *projManager, Password *pass);
    virtual bool editPersonalInfo(ProjectManager *projManager, Phone *phone);

    virtual bool editPersonalInfo(Developer *dev, Name *name);
    virtual bool editPersonalInfo(Developer *dev, Password *pass);
    virtual bool editPersonalInfo(Developer *dev, Email *email);
    virtual bool editPersonalInfo(Developer *dev, Role *role);

    virtual bool editProjectInfo(Registration *reg, Project *proj);

    virtual bool showPersonalInfo(Registration *reg);

    virtual bool showProjectInfo(ProjectCode *projCode);
};

#endif // IBUS_HPP_INCLUDED

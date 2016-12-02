/** @file IUI.hpp
 *  @brief Interface abstrata da Camada de Apresentação.
 *
 *  @author Dayanne Fernandes
 */

#ifndef IUI_HPP_INCLUDED
#define IUI_HPP_INCLUDED

#include "Headers.inl"
#include "Domain.hpp"
#include "Entity.hpp"
#include "Business.hpp"

class IUIManageManager
{
protected:
    IBusShared *busShared;
public:
    IUIManageManager(IBusShared *busShared){this->busShared = busShared;} ;
    ~IUIManageManager(){delete this->busShared;};
    virtual void run()=0;
};

class IUIManageDev
{
protected:
    IBusManageDev *busManageDev;
public:
    IUIManageDev(IBusManageDev *busManageDev){this->busManageDev = busManageDev;} ;
    ~IUIManageDev(){delete this->busManageDev;};
    virtual void run()=0;
};

class IUIManageProject
{
protected:
    IBusManageProject *busManageProject;
public:
    IUIManageProject(IBusManageProject *busManageProject){this->busManageProject = busManageProject;} ;
    ~IUIManageProject(){delete this->busManageProject;};
    virtual void run()=0;
};

class IUILoginUser
{
protected:
    IBusLogin *busLogin;
public:
    IUILoginUser(IBusLogin *busLogin){this->busLogin = busLogin;} ;
    ~IUILoginUser(){delete this->busLogin;};
    virtual void login(IUIManageManager *uIManageManager, IUIManageProject *uIManageProject, IUIManageDev *uIManageDev) = 0;
};

#endif // IUI_HPP_INCLUDED

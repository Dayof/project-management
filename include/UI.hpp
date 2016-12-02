/** @file UI.hpp
 *  @brief Biblioteca de Métodos da Camada de Apresentação.
 *
 *  Neste arquivo contém as assinaturas a serem
 *  implementadas da Camada de Apresentaçào.
 *
 *  @author Dayanne Fernandes
 */

#ifndef UI_HPP_INCLUDED
#define UI_HPP_INCLUDED

#include "IUI.inl"

class UILoginUser : public IUILoginUser
{
public:
    UILoginUser(IBusLogin *busLoginInst) : IUILoginUser(busLoginInst) {};
    void login(IUIManageManager *uIManageManager, IUIManageProject *uIManageProject, IUIManageDev *uIManageDev);
};

class UIManageManager : public IUIManageManager
{
public:
    UIManageManager(IBusShared *busSharedInst) : IUIManageManager(busSharedInst) {};
    void run();
};

class UIManageDev : public IUIManageDev
{
public:
    UIManageDev(IBusManageDev *busManageDevInst) : IUIManageDev(busManageDevInst) {};
    void run();
};

class UIManageProject : public IUIManageProject
{
public:
    UIManageProject(IBusManageProject *busManageProjectInst) : IUIManageProject(busManageProjectInst) {};
    void run();
};

#endif // UI_HPP_INCLUDED

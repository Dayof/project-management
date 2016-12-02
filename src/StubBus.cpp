/** @file StubBus.cpp
 *  @brief Implementação do stub da camada de negócio.
 *
 *  Neste arquivo contém as implementações das
 *  assinaturas dos métodos abstratos da interface
 *  de negócio.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#include "StubBus.hpp"
#include "Persistence.hpp"

string StubBus::regPM(Registration *reg, ProjectManager *projManager){
    try{
        CheckType checkType;
        CreateUser addProjMan;

        if(checkType(*reg) == CheckType::SYS)
            addProjMan(*projManager);
        else return "ERRO: Somente Gerenciador de Sistema pode inserir Gerente de Projeto.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }

    return "OK";
}

string StubBus::delPM(Registration *reg, ProjectManager *projManager){
    try{
        CheckType checkType;
        DeleteUser delProjManager;
        ProjectsFrom projsFromProjManager;
        list<Registration> regs;
        Registration regPM;

        regPM.setRegistration(projManager->getRegistration());

        regs = projsFromProjManager(regPM);

        for(auto i : regs)
        {
            if(i.getState() == ACTIVE)
                return "ERRO: Existe projeto ativo vinculado ao Gerente de Projeto, logo, não é possível descartá-lo do sistema.";
        }

        if(checkType(*reg) == CheckType::SYS)
        {
            if(proj)
                delProjManager(*projManager->getRegistration());
        }
        else return "ERRO: Somente Gerenciador de Sistema pode remover Gerente de Projeto.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }

    return "OK";
}

string StubBus::regP(Registration *reg, Project *proj){
    try{
        CheckType checkType;
        AddProject addProj;
        ProjectManager projManager;
        GetUser getUser;
        ProjectsFrom projsFromProjManager;
        list<Registration> regs;

        if(checkType(*reg) == CheckType::PRJ)
            if(regs.size() < 5)
            {
                regs = projsFromProjManager(*reg);
                getUser(*reg, projManager);
                proj->setProjectManager(&projManager);
                addProj(*proj);
            }
            else return "ERRO: Gerenciador de Projeto já gerencia 5 projetos, não é possível adicionar mais um projeto para este gerente auxiliar.";
        else return "ERRO: Somente Gerenciador de Projeto pode registrar Projeto.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }

    return "OK";
}

string StubBus::delP(Registration *reg, Project *proj){
    try{
        CheckType checkType;
        DeleteProject dellProj;

        if(checkType(*reg) == CheckType::PRJ)
            dellProj(*proj->getCode());
        else return "ERRO: Somente Gerenciador de Projeto pode remover Projeto.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }

    return "OK";
}

string StubBus::regD(Registration *reg, Developer *dev){
    try{
        CheckType checkType;
        CreateUser createDev;

        if(checkType(*reg) == CheckType::PRJ)
            createDev(*dev);
        else return "ERRO: Somente Gerenciador de Projeto pode registrar Desenvolvedor.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }

    return "OK";
}

string StubBus::delD(Registration *reg, Developer *dev){
    try{
        CheckType checkType;
        DeleteUser delDev;

        if(checkType(*reg) == CheckType::PRJ)
            createDev(*dev->getRegistration());
        else return "ERRO: Somente Gerenciador de Projeto pode registrar Projeto.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }

    return "OK";
}

string StubBus::editPersonalInfo(Registration *reg, Name *name){
    try{
        CheckType checkType;
        EditUser editUser;
        GetUser getUser;

        ProjectManager newProjManager;
        Developer newDev;

        if(checkType(*reg) == CheckType::PRJ)
        {
            getUser(*reg, newProjManager);
            newProjManager.setName(name->getName());
            editUser(newProjManager);
        }
        else if(checkType(*reg) == CheckType::DEV)
        {
            getUser(*reg, newDev);
            newDev.setName(name->getName());
            editUser(newDev);
        }
        else return "ERRO: Somente Gerenciador de Projeto ou Desenvolvedor pode editar informações pessoais.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editPersonalInfo(Registration *reg, Password *pass){
    try{
        CheckType checkType;
        EditUser editUser;
        GetUser getUser;

        ProjectManager newProjManager;
        Developer newDev;

        if(checkType(*reg) == CheckType::PRJ)
        {
            getUser(*reg, newProjManager);
            newProjManager.setPassword(pass->getPassword());
            editUser(newProjManager);
        }
        else if(checkType(*reg) == CheckType::DEV)
        {
            getUser(*reg, newDev);
            newDev.setPassword(pass->getPassword());
            editUser(newDev);
        }
        else return "ERRO: Somente Gerenciador de Projeto ou Desenvolvedor pode editar informações pessoais.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editPersonalInfo(Registration *reg, Phone *phone){
    try{
        CheckType checkType;
        EditUser editUser;
        GetUser getUser;

        ProjectManager newProjManager;

        if(checkType(*reg) == CheckType::PRJ)
        {
            getUser(*reg, newProjManager);
            newProjManager.setPhone(phone->getPhone());
            editUser(newProjManager);
        }
        else return "ERRO: Somente Gerenciador de Projeto pode editar telefone pessoal.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editPersonalInfo(Registration *reg, Email *email){
    try{
        CheckType checkType;
        EditUser editUser;
        GetUser getUser;

        Developer newDev;

        if(checkType(*reg) == CheckType::DEV)
        {
            getUser(*reg, newDev);
            newDev.setEmail(email->getEmail());
            editUser(newDev);
        }
        else return "ERRO: Somente Desenvolvedor pode editar e-mail pessoal.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editPersonalInfo(Registration *reg, Role *role){
    try{
        CheckType checkType;
        EditUser editUser;
        GetUser getUser;
        Developer newDev;

        if(checkType(*reg) == CheckType::DEV)
        {
            getUser(*reg, newDev);
            newDev.setRole(role->getRole());
            editUser(newDev);
        }
        else return "ERRO: Somente Desenvolvedor pode editar função própria.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editProjectInfo(Registration *reg, ProjectCode *projCode, Name *name){
    try{
        CheckType checkType;
        GetProject getProj;
        EditProject editProj;
        Project newProj;

        if(checkType(*reg) == CheckType::PRJ)
        {
            newProj = getProj(*projCode);

            if(newProj->getProjectManager()->getRegistration() == reg->getRegistration())
            {
                newProj->setName(name->getName());
                editProj(newProj);
            }
            else return "ERRO: O Gerente de Projeto só pode alterar projetos que ele gerencia.";
        }
        else return "ERRO: Somente Gerente de Projeto pode editar dados de projeto.";

    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editProjectInfo(Registration *reg, ProjectCode *projCode, Date *init_date){
    try{
        CheckType checkType;
        GetProject getProj;
        EditProject editProj;
        Project newProj;

        if(checkType(*reg) == CheckType::PRJ)
        {
            newProj = getProj(*projCode);

            if(newProj->getProjectManager()->getRegistration() == reg->getRegistration())
            {
                newProj->setInitDate(init_date->getDate());
                editProj(newProj);
            }
            else return "ERRO: O Gerente de Projeto só pode alterar projetos que ele gerencia.";

        }
        else return "ERRO: Somente Gerente de Projeto pode editar dados de projeto.";

    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editProjectInfo(Registration *reg, ProjectCode *projCode, Date *end_date){
    try{
        CheckType checkType;
        GetProject getProj;
        EditProject editProj;
        Project newProj;

        if(checkType(*reg) == CheckType::PRJ)
        {
            newProj = getProj(*projCode);

            if(newProj->getProjectManager()->getRegistration() == reg->getRegistration())
            {
                newProj->setEndDate(end_date->getDate());
                editProj(newProj);
            }
            else return "ERRO: O Gerente de Projeto só pode alterar projetos que ele gerencia.";

        }
        else return "ERRO: Somente Gerente de Projeto pode editar dados de projeto.";

    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editProjectInfo(Registration *reg, ProjectCode *projCode, Cost *current_cost){
    try{
        CheckType checkType;
        GetProject getProj;
        EditProject editProj;
        Project newProj;

        if(checkType(*reg) == CheckType::PRJ)
        {
            newProj = getProj(*projCode);

            if(newProj->getProjectManager()->getRegistration() == reg->getRegistration())
            {
                newProj->setCurrCost(current_cost->getCost());
                editProj(newProj);
            }
            else return "ERRO: O Gerente de Projeto só pode alterar projetos que ele gerencia.";

        }
        else return "ERRO: Somente Gerente de Projeto pode editar dados de projeto.";

    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editProjectInfo(Registration *reg, ProjectCode *projCode, Cost *estimate_cost){
    try{
        CheckType checkType;
        GetProject getProj;
        EditProject editProj;
        Project newProj;

        if(checkType(*reg) == CheckType::PRJ)
        {
            newProj = getProj(*projCode);

            if(newProj->getProjectManager()->getRegistration() == reg->getRegistration())
            {
                newProj->setEstimateCost(estimate_cost->getEstimateCost());
                editProj(newProj);
            }
            else return "ERRO: O Gerente de Projeto só pode alterar projetos que ele gerencia.";

        }
        else return "ERRO: Somente Gerente de Projeto pode editar dados de projeto.";

    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editProjectInfo(Registration *reg, ProjectCode *projCode, Developer *dev, Registration *oldDevReg){
    try{
        CheckType checkType;
        GetProject getProj;
        Project newProj;
        AddToProject addToProject;
        RemoveFromProject delFromProj;
        ProjectCode oldCode, newCode;
        GetUser getUser;
        Developer oldDev;

        if(checkType(*reg) == CheckType::PRJ)
        {
            newProj = getProj(*projCode);

            if(newProj->getProjectManager()->getRegistration() == reg->getRegistration())
            {
                getUser(*oldDevReg, oldDev);
                delFromProj(*projCode, oldDev);
                addToProject(*projCode, *dev);
            }
            else return "ERRO: O Gerente de Projeto só pode alterar projetos que ele gerencia.";

        }
        else return "ERRO: Somente Gerente de Projeto pode editar dados de projeto.";

    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editProjectInfo(Registration *reg, ProjectCode *projCode, ProjectManager *projManager,  Registration *oldProjManagerReg){
    try{
        CheckType checkType;
        GetProject getProj;
        Project newProj;
        AddToProject addToProject;
        RemoveFromProject delFromProj;
        GetUser getUser;
        ProjectManager oldProjManager;

        if(checkType(*reg) == CheckType::PRJ)
        {
            newProj = getProj(*projCode);

            if(newProj->getProjectManager()->getRegistration() == reg->getRegistration())
            {
                getUser(*oldProjManagerReg, oldProjManager);
                delFromProj(*projCode, oldProjManager);
                addToProject(*projCode, *projManager);
            }
            else return "ERRO: O Gerente de Projeto só pode alterar projetos que ele gerencia.";

        }
        else return "ERRO: Somente Gerente de Projeto pode editar dados de projeto.";

    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

string StubBus::editProjectInfo(Registration *reg, ProjectCode *projCode,  ProjectState *state){
    try{
        CheckType checkType;
        GetProject getProj;
        EditProject editProj;
        Project newProj;

        if(checkType(*reg) == CheckType::PRJ)
        {
            newProj = getProj(*projCode);

            if(newProj->getProjectManager()->getRegistration() == reg->getRegistration())
            {
                newProj->setState(state->getState());
                editProj(newProj);
            }
            else return "ERRO: O Gerente de Projeto só pode alterar projetos que ele gerencia.";

        }
        else return "ERRO: Somente Gerente de Projeto pode editar dados de projeto.";

    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }
    catch (exception& domain_err) {
        return domain_err.what();
    }

    return "OK";
}

map<string, string> StubBus::showPersonalInfo(Registration *reqReg, Registration *viewReg){
    try{
        GetUser getUser;
        Developer dev;
        ProjectManager projManager;
        SysManager sysManager;
        map<string, string> info;

        if(checkType(*viewReg) == CheckType::SYS)
        {
            getUser(*viewReg, sysManager);
            info['name']=sysManager.getName();
            info['reg']=sysManager.getRegistration();
        }
        else if(checkType(*viewReg) == CheckType::PRJ)
        {
            getUser(*viewReg, projManager);
            info['name']=projManager.getName();
            info['reg']=projManager.getRegistration();
            info['phone']=projManager.getPhone();
        }
        else if(checkType(*reg) == CheckType::DEV)
        {
            getUser(*viewReg, dev);
            info['name']=dev.getName();
            info['reg']=dev.getRegistration();
            info['email']=dev.getEmail();
            info['role']=dev.getRole();
        }
        else return "ERRO: Tipo de entidade incorreta.";

        if(reqReg->getRegistration() == viewReg->getRegistration())
        {
                if(checkType(*viewReg) == CheckType::SYS)
                    info['pass']=sysManager.getPassword();
                if(checkType(*viewReg) == CheckType::PRJ)
                    info['pass']=projManager.getPassword();
                if(checkType(*reg) == CheckType::DEV)
                    info['pass']=dev.getPassword();
        }
    }
    catch (PersistenceError per_err) {
        return info['error'] = per_err.what();
    }
    catch (exception& domain_err) {
        return info['error'] = domain_err.what();
    }

    return info;
}

map<string, string> StubBus::showProjectInfo(ProjectCode *projCode){
    try{
        Project proj;
        GetProject getProj;
        map<string, string> info;
        vector<Developer> allDevs;
        stringstream dev;
        string devs;

        proj = getProj(*projCode);
        info['name']=projCode.getName();
        info['projcode']=projCode.getCode();
        info['initdate']=projCode.getInitDate();
        info['enddate']=projCode.getEndDate();
        info['currentcost']=projCode.getCurrCost();
        info['estimatecost']=projCode.getEstimateCost();

        allDevs = projCode.getAllDevelopers();
        for(auto i : allDevs)
            dev << i.getRegistration() << " ";
        }
        devs = dev.str();

        info['developers']=devs;
        info['projmanager']=projCode.getProjectManager()->getRegistration;
        info['state']=projCode.getState();

    }
    catch (PersistenceError per_err) {
        return info['error'] = per_err.what();
    }
    catch (exception& domain_err) {
        return info['error'] = domain_err.what();
    }

    return info;
}

string StubBus::addDevToProject(Registration *reg, ProjectCode *projCode, Developer *dev){
    try{
        CheckType checkType;
        AddToProject addProjMan;
        CountDevelopers qtDev;
        Registration regDev;
        ProjectsFrom projsFromDev;
        list<Registration> regs;

        regs = projsFromDev(*reg);

        regDev.setRegistration = dev->getRegistration();

        if(qtDev(*projCode) < 10)
        {
            if(regs.size() < 10)
            {
                if(checkType(*reg) == CheckType::PRJ)
                    AddToProject(*projCode, *dev);
                else return "ERRO: Somente Gerenciador de Sistema pode associar Gerente de Projeto a algum projeto.";
            }
            else return "ERRO: Desenvolver já está vinculado a 10 projetos, não é possível adicioná-lo a mais um projeto.";
        }
        else return "ERRO: Projeto com limite máximo de 10 desenvolvedores.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }

    return "OK";
}

string StubBus::delDevFromProject(Registration *reg, ProjectCode *projCode, Developer *dev){
    try{
        CheckType checkType;
        RemoveFromProject delFromProj;
        CountDevelopers qtDev;
        ProjectsFrom projsFromDev;
        list<Registration> regs;
        Registration regDev;

        regDev.setRegistration(dev->getRegistration());

        regs = projsFromDev(regDev);

        for(auto i : regs)
        {
            if(i.getState() == ACTIVE)
                return "ERRO: Existe projeto ativo vinculado ao desenvolvedor, logo, não é possível descartá-lo do sistema.";
        }

        if(qtDev(*projCode) > 0)
        {
            if(checkType(*reg) == CheckType::PRJ)
                delFromProj(*projCode, *dev);
            else return "ERRO: Somente Gerenciador de Sistema pode associar Gerente de Projeto a algum projeto.";
        }
        else return "ERRO: Não existe nenhum desenvolvedor a ser removido do projeto.";
    }
    catch (PersistenceError per_err) {
        return per_err.what();
    }

    return "OK";
}

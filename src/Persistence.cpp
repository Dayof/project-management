#include "Persistence.hpp"

PersistenceError::PersistenceError()
{
    this->message = "Erro desconhecido no banco de dados.";
}

PersistenceError::PersistenceError(string message)
{
    this->message = message;
}

string PersistenceError::what()
{
    return this->message;
}

Project* GetProject::operator()(ProjectCode& pc) throw (PersistenceError, exception)
{
    Project* p;
    ProjectManager* pm;
    GetUser getUser;

    this->SQLquery << "select * from Project where code=";
    this->SQLquery << pc.getCodProject();

    this->run();

    Registration r(returnMap["manager"]);

    if(returnMap.empty())
        throw PersistenceError("O projeto não existe.");

    getUser(r, *pm);

    p = new Project(
        returnMap["name"],
        returnMap["code"],
        pm,
        returnMap["initDate"],
        stoi(returnMap["state"])
    );
    p->setEndDate(returnMap["endDate"]);
    p->setCurrCost(returnMap["currCost"]);
    p->setEstimateCost(returnMap["estCost"]);

    return p;
}

void EditProject::operator()(Project& p) throw (PersistenceError)
{
    this->SQLquery  << " update Project set"
                    << " name='" << p.getName() << "',"
                    << " manager='" << p.getProjectManager()->getRegistration() << "',"
                    << " initDate='" << p.getInitDate() << "',"
                    << " state=" << p.getState() << ","
                    << " endDate='" << p.getEndDate() << "',"
                    << " currCost='" << p.getCurrCost() << "',"
                    << " estCost='" << p.getEstimateCost() << "',"
                    << " where code='" << p.getCode() << "',";

    this->run();
}

void AddProject::operator()(Project& p) throw (PersistenceError)
{
    this->SQLquery  << " insert into Project values"
                    << " ("
                    << "'" << p.getName() <<"',"
                    << "'" << p.getProjectManager()->getRegistration() <<"',"
                    << "'" << p.getInitDate() <<"',"
                    << p.getState() <<","
                    << "'" << p.getEndDate() <<"',"
                    << "'" << p.getCurrCost() <<"',"
                    << "'" << p.getEstimateCost() << "',"
                    << "'" << p.getCode()  << "')";

    this->run();
}

void DeleteProject::operator()(ProjectCode& p) throw (PersistenceError)
{
    this->SQLquery  << "delete from Project where code='" << p.getCodProject() << "'";

    this->run();
}

void AddToProject::operator()(ProjectCode& p, Developer& d) throw (PersistenceError)
{
    this->SQLquery  << "insert into Jobs values ("
                    << "'" << d.getRegistration() << "',"
                    << "'" << p.getCodProject() << "')";

    this->run();
}

void AddToProject::operator()(ProjectCode& p, ProjectManager& m) throw (PersistenceError)
{
    this->SQLquery << "update Projects set "
                   << "manager='" << m.getRegistration() << "' "
                   << "where code='" << p.getCodProject() << "'";

    this->run();
}

void RemoveFromProject::operator()(ProjectCode& p, Developer& d) throw (PersistenceError)
{
    this->SQLquery << "remove from Jobs where "
                    << "dev='" << d.getRegistration() << ", "
                    << "project='" << p.getCodProject() << "'";

    this->run();
}

int CountDevelopers::operator()(ProjectCode& p) throw (PersistenceError)
{
    this->SQLquery << "select count(*) from Project where code='" << p.getCodProject() << "'";
    this->run();

    if(returnMap.empty())
        throw PersistenceError();

    return stoi(returnMap["count(*)"]);
}

void GetUser::operator()(Registration& r, Developer& d) throw (PersistenceError)
{
    this->SQLquery << "select from Developer where registration='" << r.getRegistration() << "'";

    if(returnMap.empty())
        throw PersistenceError("O desenvolvedor não existe");

    d = Developer(
        returnMap["name"],
        returnMap["registration"],
        returnMap["password"],
        stoi(returnMap["role"])
    );

    d.setEmail(returnMap["email"]);
}

void GetUser::operator()(Registration& r, ProjectManager& d) throw (PersistenceError)
{
    this->SQLquery << "select from ProjectManager where registration='" << r.getRegistration() << "'";

    if(returnMap.empty())
        throw PersistenceError("O gerente não existe");

    d = ProjectManager(
        returnMap["name"],
        returnMap["registration"],
        returnMap["password"]
    );

    d.setPhone(returnMap["phone"]);
}

void GetUser::operator()(Registration& r, SysManager& d) throw (PersistenceError)
{
    this->SQLquery << "select from SysManager where registration='" << r.getRegistration() << "'";

    if(returnMap.empty())
        throw PersistenceError("O gerente não existe");

    d = SysManager(
        returnMap["name"],
        returnMap["registration"],
        returnMap["password"]
    );
}

void EditUser::operator()(Developer& d) throw (PersistenceError)
{
    this->SQLquery  << "update Developer set "
                    << "name='" << d.getName() << "',"
                    << "password='" << d.getPassword() << "',"
                    << "role=" << d.getRole() << ","
                    << "email='" << d.getEmail() << "'"
                    << "where registration='" << d.getRegistration() << "'";

    this->run();
}

void EditUser::operator()(ProjectManager& p) throw (PersistenceError)
{
    this->SQLquery  << "update ProjectManager set "
                    << "name='" << p.getName() << "',"
                    << "password='" << p.getPassword() << "',"
                    << "phone='" << p.getPhone() << "'"
                    << "where registration='" << p.getRegistration() << "'";

    this->run();
}

CheckType::TYPE CheckType::operator()(Registration& r) throw (PersistenceError)
{
    this->SQLquery  << "select type from RegType where registration='" << r.getRegistration() << "'";

    this->run();

    if(returnMap.empty())
        throw PersistenceError("Usuario nao existe.");

    switch(stoi(returnMap["type"]))
    {
        case CheckType::DEV:
            return CheckType::DEV;
        case CheckType::PRJ:
            return CheckType::PRJ;
        case CheckType::SYS:
            return CheckType::SYS;
    }
    return CheckType::DEV;
}

void CreateUser::operator()(ProjectManager& p) throw (PersistenceError)
{
    this->SQLquery  << "insert into ProjectManager values ("
                    << "'" << p.getName() << "',"
                    << "'" << p.getRegistration() << "',"
                    << "'" << p.getPassword() << "',"
                    << "'" << p.getPhone() << "'";

    this->run();
}

void CreateUser::operator()(Developer& p) throw (PersistenceError)
{
    this->SQLquery  << "insert into Developer values ("
                    << "'" << p.getName() << "',"
                    << "'" << p.getRegistration() << "',"
                    << "'" << p.getPassword() << "',"
                    << p.getRole() << ","
                    << "'" << p.getEmail() << "'";

    this->run();
}

void DeleteUser::operator()(Registration& r) throw (PersistenceError)
{
    CheckType ct;

    if(ct(r) == CheckType::DEV)
        this->SQLquery << "remove from Developer";
    else if(ct(r) == CheckType::PRJ)
        this->SQLquery << "remove from ProjectManager";
    else
        this->SQLquery << "remove from SystemManager";
}

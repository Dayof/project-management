/** @file PersStub.cpp
 *  @brief Implementação da Classe de Stub da Persisência do sistema.
 *
 *  Neste arquivo contém as implementações dos
 *  stubs da Interface de Persistência.
 *  Serve para simular a persistência dos dados para
 *  para que o sistema possa continuar o fluxo sem
 *  necessariamente conter uma conexão com um banco de dados.
 *
 *  @author Dayanne Fernandes
 */

#include "PersStub.hpp"

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

    p = new Project(
        "Arroba",
        "AAAAA",
        "00001",
        "02/12/1993",
        1)
    );
    p->setEndDate("03/11/2007");
    p->setCurrCost("8000");
    p->setEstimateCost("10000");

    return p;
}

void EditProject::operator()(Project& p) throw (PersistenceError) {}
void AddProject::operator()(Project& p) throw (PersistenceError){}
void DeleteProject::operator()(ProjectCode& p) throw (PersistenceError){}
void AddToProject::operator()(ProjectCode& p, Developer& d) throw (PersistenceError){}

void AddToProject::operator()(ProjectCode& p, ProjectManager& m) throw (PersistenceError){}

void RemoveFromProject::operator()(ProjectCode& p, Developer& d) throw (PersistenceError){}

void RemoveFromProject::operator()(ProjectCode& p) throw (PersistenceError){}

int CountDevelopers::operator()(ProjectCode& p) throw (PersistenceError)
{
    return 7;
}

void GetUser::operator()(Registration& r, Developer& d) throw (PersistenceError)
{
    d = Developer(
        "Dayanne",
        "00002",
        "a7938",
        1)
    );

    d.setEmail("day@d.dd");
}

void GetUser::operator()(Registration& r, ProjectManager& d) throw (PersistenceError)
{
    d = ProjectManager(
        "Natalia",
        "00001",
        "a7938"
    );
    d.setPhone("99999999");
}

void GetUser::operator()(Registration& r, SysManager& d) throw (PersistenceError)
{
    d = SysManager(
        "Diana",
        "00003",
        "a7938"
    );
}

void EditUser::operator()(Developer& d) throw (PersistenceError){}
void EditUser::operator()(ProjectManager& p) throw (PersistenceError){}

CheckType::TYPE CheckType::operator()(Registration& r) throw (PersistenceError)
{
    return CheckType::DEV;
}

void CreateUser::operator()(ProjectManager& p) throw (PersistenceError){}

void CreateUser::operator()(Developer& p) throw (PersistenceError){}

void DeleteUser::operator()(Registration& r) throw (PersistenceError){}

list<ProjectCode> ProjectsFrom::operator()(Registration& r) throw (PersistenceError)
{
    list<ProjectCode> lr;

    for(int i=0; i<4; ++i)
    {
        ProjectCode nr(string("AAAA").push_back('A'+i));
        lr.push_back(nr);
    }

    return lr;
}

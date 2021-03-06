/** @file Persistence.hpp
 *  @brief Arquivo de configuração da camada de persistência.
 *
 *  Este arquivo contém toda a lógica de acesso
 *  ao banco de dados, tornando transparente suas
 *  transações para a camada de negócio.
 *
 *  @author Dayanne Fernandes
 */

#ifndef PERSISTENCE_INCLUDED
#define PERSISTENCE_INCLUDED

#include <string>
#include <list>
#include <sstream>
#include <map>
#include <vector>

#include "Domain.hpp"
#include "Entity.hpp"

#include "IPers.inl"

using namespace std;

class GetProject : public IPersistence
{
public:
    Project* operator()(ProjectCode&) throw (PersistenceError, exception);
};

class EditProject : public IPersistence
{
public:
    void operator()(Project&) throw (PersistenceError);
};

class AddProject : public IPersistence
{
public:
    void operator()(Project&) throw (PersistenceError);
};

class DeleteProject : public IPersistence
{
public:
    void operator()(ProjectCode&) throw (PersistenceError);
};

class AddToProject : public IPersistence
{
public:
    void operator()(ProjectCode&, Developer&) throw (PersistenceError);
    void operator()(ProjectCode&, ProjectManager&) throw (PersistenceError);
};

class RemoveFromProject : public IPersistence
{
public:
    void operator()(ProjectCode&, Developer&) throw (PersistenceError);
    void operator()(ProjectCode&) throw (PersistenceError);
};

class CountDevelopers : public IPersistence
{
public:
    int operator()(ProjectCode&) throw (PersistenceError);
};

class GetUser : public IPersistence
{
public:
    void operator()(Registration&, Developer*) throw (PersistenceError);
    void operator()(Registration&, ProjectManager*) throw (PersistenceError);
    void operator()(Registration&, SysManager*) throw (PersistenceError);
};

class EditUser : public IPersistence
{
public:
    void operator()(Developer*) throw (PersistenceError);
    void operator()(ProjectManager*) throw (PersistenceError);
};

class CheckType : public IPersistence
{
public:
    enum TYPE {
        DEV, PRJ, SYS
    };

    TYPE operator()(Registration&) throw (PersistenceError);
};

class CreateUser : public IPersistence
{
public:
    void operator()(ProjectManager&) throw (PersistenceError);
    void operator()(Developer&) throw (PersistenceError);
};

class DeleteUser : public IPersistence
{
public:
    void operator()(Registration&) throw (PersistenceError);
};

class ProjectsFrom : public IPersistence
{
public:
    list<ProjectCode> operator()(Registration&) throw (PersistenceError);
};

#endif

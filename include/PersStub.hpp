/** @file PersStub.hpp
 *  @brief Arquivo de stub de configuração da camada de persistência.
 *
 *  Este arquivo contém stubs das
 *  transações para a camada de negócio.
 *
 *  @author Dayanne Fernandes
 */

#ifndef PERSISTENCE_STUB_INCLUDED
#define PERSISTENCE_STUB_INCLUDED

#include <string>
#include <list>
#include <sstream>
#include <map>
#include <vector>

#include "Domain.hpp"
#include "Entity.hpp"

#include "IPers.inl"

using namespace std;

class PersistenceStub
{
};

class GetProject : public PersistenceStub
{
public:
    Project* operator()(ProjectCode&) throw (PersistenceError, exception);
};

class EditProject : public PersistenceStub
{
public:
    void operator()(Project&) throw (PersistenceError);
};

class AddProject : public PersistenceStub
{
public:
    void operator()(Project&) throw (PersistenceError);
};

class DeleteProject : public PersistenceStub
{
public:
    void operator()(ProjectCode&) throw (PersistenceError);
};

class AddToProject : public PersistenceStub
{
public:
    void operator()(ProjectCode&, Developer&) throw (PersistenceError);
    void operator()(ProjectCode&, ProjectManager&) throw (PersistenceError);
};

class RemoveFromProject : public PersistenceStub
{
public:
    void operator()(ProjectCode&, Developer&) throw (PersistenceError);
    void operator()(ProjectCode&) throw (PersistenceError);
};

class CountDevelopers : public PersistenceStub
{
public:
    int operator()(ProjectCode&) throw (PersistenceError);
};

class GetUser : public PersistenceStub
{
public:
    void operator()(Registration&, Developer&) throw (PersistenceError);
    void operator()(Registration&, ProjectManager&) throw (PersistenceError);
    void operator()(Registration&, SysManager&) throw (PersistenceError);
};

class EditUser : public PersistenceStub
{
public:
    void operator()(Developer&) throw (PersistenceError);
    void operator()(ProjectManager&) throw (PersistenceError);
};

class CheckType : public PersistenceStub
{
public:
    enum TYPE {
        DEV, PRJ, SYS
    };

    TYPE operator()(Registration&) throw (PersistenceError);
};

class CreateUser : public PersistenceStub
{
public:
    void operator()(ProjectManager&) throw (PersistenceError);
    void operator()(Developer&) throw (PersistenceError);
};

class DeleteUser : public PersistenceStub
{
public:
    void operator()(Registration&) throw (PersistenceError);
};

class ProjectsFrom : public PersistenceStub
{
public:
    list<ProjectCode> operator()(Registration&) throw (PersistenceError);
};

#endif

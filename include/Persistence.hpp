/** @file Persistence.hpp
 *  @brief Arquivo de configuração da camada de persistência.
 *
 *  Este arquivo contém toda a lógica de acesso
 *  ao banco de dados, tornando transparente suas
 *  transações para a camada de negócio.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#ifndef PERSISTENCE_INCLUDED
#define PERSISTENCE_INCLUDED

#include <string>
#include <list>
#include <sstream>

#include "Domain.hpp"
#include "Entity.hpp"

#include "IPers.inl"

using namespace std;

class GetProject : public IPersistence
{
    Project* operator()(ProjectCode&) throw (PersistenceError);
};

class EditProject : public IPersistence
{
    void operator()(Project&) throw (PersistenceError);
};

class AddProject : public IPersistence
{
    void operator()(Project&) throw (PersistenceError);
};

class DeleteProject : public IPersistence
{
    void operator()(ProjectCode&) throw (PersistenceError);
};

class AddToProject : public IPersistence
{
    void operator()(ProjectCode&, Developer&) throw (PersistenceError);
    void operator()(ProjectCode&, ProjectManager&) throw (PersistenceError);
};

class RemoveFromProject : public IPersistence
{
    void operator()(ProjectCode&, Developer&) throw (PersistenceError);
    void operator()(ProjectCode&, ProjectManager&) throw (PersistenceError);
};

class GetUser : public IPersistence
{
    void operator()(Registration&, Developer&) throw (PersistenceError);
    void operator()(Registration&, ProjectManager&) throw (PersistenceError);
    void operator()(Registration&, SysManager&) throw (PersistenceError);
};

#endif

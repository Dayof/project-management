/** @file Entity.cpp
 *  @brief Implementação das Entidades do sistema.
 *
 *  Neste arquivo contém as implementações das
 *  assinaturas dos métodos das classes de entidade.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#include "Entity.hpp"
#include "Domain.hpp"

/**
 * Este é um método construtor de gerente de sistema
 *  que passa os valores recebido para os métodos setters
 *  dos domínios.
 */
SysManager::SysManager(string name,
                    string registration,
                    string password)
{
    setName(name);
    setRegistration(registration);
    setPassword(password);
}

void SysManager::setName(string name_str)
{
    Name* name;
    try{ name = new Name(name_str); }
    catch (exception& err) { throw err.what(); return; }
    this->name = name;

}

void SysManager::setRegistration(string reg_str)
{
    Registration* registration;
    try{ registration = new Registration(reg_str); }
    catch (exception& err) { throw err.what(); }
    this->registration = registration;

}

void SysManager::setPassword(string pass_str)
{
    Password* pass;
    try{ pass = new Password(pass_str); }
    catch (exception& err) { throw err.what(); }
    this->password = pass;

}

/**
 * Este é um método construtor de gerente de projeto
 *  que passa os valores recebido para os métodos setters
 *  dos domínios.
 */
ProjectManager::ProjectManager(string name,
                              string registration,
                              string password)
{
    setName(name);
    setRegistration(registration);
    setPassword(password);
}

void ProjectManager::setName(string name_str)
{
    Name* name;
    try{ name = new Name(name_str); }
    catch (exception& err) { throw err.what(); }
    this->name = name;

}

void ProjectManager::setRegistration(string reg_str)
{
    Registration* registration;
    try{ registration = new Registration(reg_str); }
    catch (exception& err) { throw err.what(); }
    this->registration = registration;

}

void ProjectManager::setPassword(string pass_str)
{
    Password* pass;
    try{ pass = new Password(pass_str); }
    catch (exception& err) { throw err.what(); }
    this->password = pass;
}

void ProjectManager::setPhone(string phone_str)
{
    Phone* phone;
    try{ phone = new Phone(phone_str); }
    catch (exception& err) { throw err.what(); }
    this->phone = phone;
}

/**
 * Este é um método construtor de desenvolvedor
 *  que passa os valores recebido para os métodos setters
 *  dos domínios.
 */
Developer::Developer(string name,
                      string registration,
                      string password,
                      int role)
{
    setName(name);
    setRegistration(registration);
    setPassword(password);
    setRole(role);
}

void Developer::setName(string name_str)
{
    Name* name;
    try{ name = new Name(name_str); }
    catch (exception& err) { throw err.what(); }
    this->name = name;

}

void Developer::setRegistration(string reg_str)
{
    Registration* registration;
    try{ registration = new Registration(reg_str); }
    catch (exception& err) { throw err.what(); }
    this->registration = registration;

}

void Developer::setPassword(string pass_str)
{
    Password* pass;
    try{ pass = new Password(pass_str); }
    catch (exception& err) { throw err.what(); }
    this->password = pass;
}

void Developer::setRole(int role_int)
{
    Role* role;
    try{ role = new Role(role_int); }
    catch (exception& err) { throw err.what(); }
    this->role = role;
}

void Developer::setEmail(string email_str)
{
    Email* email;
    try{ email = new Email(email_str); }
    catch (exception& err) { throw err.what(); }
    this->email = email;
}

/**
 * Este é um método construtor de projeto
 *  que passa os valores recebido para os métodos setters
 *  dos domínios.
 */
Project::Project(string name,
                string code,
                ProjectManager* projectManager,
                string init_date,
                int state)
{
    setName(name);
    setCode(code);
    setProjectManager(projectManager);
    setInitDate(init_date);
    setState(state);
}

void Project::setName(string name_str)
{
    Name* name;
    try{ name = new Name(name_str); }
    catch (exception& err) { throw err.what(); }
    this->name = name;

}

void Project::setCode(string code_str)
{
    ProjectCode* code;
    try{ code = new ProjectCode(code_str); }
    catch (exception& err) { throw err.what(); }
    this->code = code;

}

void Project::setInitDate(string init_date_str)
{
    Date* init_date;
    try{ init_date = new Date(init_date_str); }
    catch (exception& err) { throw err.what(); }
    this->init_date = init_date;
}

void Project::setEndDate(string end_date_str)
{
    Date* end_date;
    try{ end_date = new Date(end_date_str); }
    catch (exception& err) { throw err.what(); }
    this->end_date = end_date;
}

void Project::setState(int state_int)
{
    ProjectState* state;
    try{ state = new ProjectState(state_int); }
    catch (exception& err) { throw err.what(); }
    this->state = state;
}

void Project::setCurrCost(string currCost)
{
    Cost* cost;
    try{ cost = new Cost(currCost); }
    catch (exception& err) { throw err.what(); }
    this->current_cost = currCost;
}

void Project::setEstimateCost(string estimateCost)
{
    Cost* cost;
    try{ cost = new Cost(estimateCost); }
    catch (exception& err) { throw err.what(); }
    this->estimate_cost = estimate_cost;
}

/**
 * Este é um método construtor de fase
 *  que passa os valores recebido para os métodos setters
 *  dos domínios.
 */
Phase::Phase(string init_date, int phase)
{
    setInitDate(init_date);
    setPhase(phase);
}

void Phase::setInitDate(string init_date_str)
{
    Date* init_date;
    try{ init_date = new Date(init_date_str); }
    catch (exception& err) { throw err.what(); }
    this->init_date = init_date;
}

void Phase::setEndDate(string end_date_str)
{
    Date* end_date;
    try{ end_date = new Date(end_date_str); }
    catch (exception& err) { throw err.what(); }
    this->end_date = end_date;
}

void Phase::setPhase(int phase_int)
{
    ProjectPhase* projectPhase;
    try{ projectPhase = new ProjectPhase(phase_int); }
    catch (exception& err) { throw err.what(); }
    this->phase = projectPhase;
}

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
    name = new Name(name_str);
    this->name = name;
}

void SysManager::setRegistration(string reg_str)
{
    Registration* registration;
    registration = new Registration(reg_str);
    this->registration = registration;

}

void SysManager::setPassword(string pass_str)
{
    Password* pass;
    pass = new Password(pass_str);
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
    name = new Name(name_str);
    this->name = name;

}

void ProjectManager::setRegistration(string reg_str)
{
    Registration* registration;
    registration = new Registration(reg_str);
    this->registration = registration;

}

void ProjectManager::setPassword(string pass_str)
{
    Password* pass;
    pass = new Password(pass_str);
    this->password = pass;
}

void ProjectManager::setPhone(string phone_str)
{
    Phone* phone;
    phone = new Phone(phone_str);
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
    name = new Name(name_str);
    this->name = name;

}

void Developer::setRegistration(string reg_str)
{
    Registration* registration;
    registration = new Registration(reg_str);
    this->registration = registration;

}

void Developer::setPassword(string pass_str)
{
    Password* pass;
    pass = new Password(pass_str);
    this->password = pass;
}

void Developer::setRole(int role_int)
{
    Role* role;
    role = new Role(role_int);
    this->role = role;
}

void Developer::setEmail(string email_str)
{
    Email* email;
    email = new Email(email_str);
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
                int state,
                string currCost,
                string estimateCost)
{
    setName(name);
    setCode(code);
    setProjectManager(projectManager);
    setInitDate(init_date);
    setState(state);
    setEstimateCost(estimateCost);
    setCurrCost(currCost);
}

void Project::setName(string name_str)
{
    Name* name;

    name = new Name(name_str);
    this->name = name;
}

void Project::setCode(string code_str)
{
    ProjectCode* code;

    code = new ProjectCode(code_str);
    this->code = code;
}

void Project::setInitDate(string init_date_str)
{
    Date* init_date;

    init_date = new Date(init_date_str);
    this->init_date = init_date;
}

void Project::setEndDate(string end_date_str)
{
    Date* end_date;

    end_date = new Date(end_date_str);
    this->end_date = end_date;
}

void Project::setState(int state_int)
{
    ProjectState* state;

    state = new ProjectState(state_int);
    this->state = state;
}

void Project::setCurrCost(string currCost)
{
    Cost* cost;

    if(stof(currCost) <= stof(this->estimate_cost->getCost()))
        cost = new Cost(currCost);
    else throw invalid_argument("ERRO: Custo atual maior que o custo estimado;");
    this->current_cost = cost;
}

void Project::setEstimateCost(string estimateCost)
{
    Cost* cost;

    cost = new Cost(estimateCost);
    this->estimate_cost = cost;
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
    init_date = new Date(init_date_str);
    this->init_date = init_date;
}

void Phase::setEndDate(string end_date_str)
{
    Date* end_date;
    end_date = new Date(end_date_str);
    this->end_date = end_date;
}

void Phase::setPhase(int phase_int)
{
    ProjectPhase* projectPhase;
    projectPhase = new ProjectPhase(phase_int);
    this->phase = projectPhase;
}

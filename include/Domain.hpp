#ifndef DOMAIN_HPP_INCLUDED
#define DOMAIN_HPP_INCLUDED

#include "Headers.hpp"

/**
 * \class ProjectCode
 *
 * \brief Domínio de Código de Projeto
 *
 * Este domínio só permite entradas de exatamente
 * cinco caracteres de A-Z e a-z.
 *
 */

class ProjectCode {
private:
    string cod_project;
public:
    /** Construtor do Código de Projeto
     *  O construtor tem valor default de "AAAAA"
     */
    ProjectCode(string cod_project="AAAAA");

    /** Método setter do domínio de Código de Projeto
     *  @param cod_project uma string que recebe o codigo do projeto
     */
    void setCodProject(string cod_project);

    /** Método getter do domínio de Código de Projeto
     *  @return o codigo do projeto
     */
    string getCodProject() const {return this->cod_project;};
};

class ProjectState {
private:
    int project_state;
public:
    ProjectState(int project_state=1);

    void setProjectState(int project_state);
    int getProjectState() const {return this->project_state;};
};

class ProjectPhase {
private:
    int project_phase;
public:
    ProjectPhase(int project_phase=1);

    void setProjectPhase(int project_phase);
    int getProjectPhase() const {return this->project_phase;};
};

class Role {
private:
    int role;
public:
    Role(int role=0);

    void setRole(int role);
    int getRole() const {return this->role;};
};

class Name {
private:
    string name;
public:
    Name(string name="");

    void setName(string name);
    string getName() const {return this->name;};
};

class Email {
private:
    string email;
public:
    Email(string email="");

    void setEmail(string email);
    string getEmail() const {return this->email;};
};

class Date {
private:
    string date;
public:
    Date(string date="");

    void setDate(string date);
    string getDate() const {return this->date;};
};

class Phone {
private:
    string phone;
public:
    Phone(string phone="");

    void setPhone(string phone);
    string getPhone() const {return this->phone;};
};

class Password {
private:
    string password;
public:
    Password(string password="");

    void setPassword(string password);
    string getPassword() const {return this->password;};
};

class Registration {
private:
    string reg;
public:
    Registration(string reg="");

    void setRegistration(string reg);
    string getRegistration() const {return this->reg;};
};

class Cost {
private:
    string cost;
public:
    Cost(string cost="");

    void setCost(string cost);
    string getCost() const {return this->cost;};
};

#endif // DOMAIN_HPP_INCLUDED

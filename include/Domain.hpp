#ifndef DOMAIN_HPP_INCLUDED
#define DOMAIN_HPP_INCLUDED

#include "Headers.hpp"

class ProjectCode {
private:
    string cod_project;
public:
    ProjectCode(string cod_project="AAAAA");

    void setCodProject(string cod_project);
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

#endif // DOMAIN_HPP_INCLUDED

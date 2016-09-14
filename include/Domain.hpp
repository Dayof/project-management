#ifndef DOMAIN_HPP_INCLUDED
#define DOMAIN_HPP_INCLUDED

#include "Headers.hpp"

class ProjectCode {
private:
    string cod_project;
public:
    ProjectCode(string cod_project="AAA");

    void setCodProject(string cod_project);
    string getCodProject() const {return this->cod_project;};
};

class ProjectState {
private:
    int project_state;
public:
    ProjectState(int project_state=0);

    void setProjectState(int project_state);
    int getProjectState() const {return this->project_state;};
};

class ProjectPhase {
private:
    int project_phase;
public:
    ProjectPhase(int project_phase=0);

    void setProjectPhase(int project_phase);
    int getProjectPhase() const {return this->project_phase;};
};

class Name {
private:
    string name;
public:
    Name(string name="");

    void setName(string name);
    string getName() const {return this->name;};
};

#endif // DOMAIN_HPP_INCLUDED

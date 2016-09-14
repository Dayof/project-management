#ifndef DOMAIN_HPP_INCLUDED
#define DOMAIN_HPP_INCLUDED

#include "Headers.hpp"

class Name {
private:
    string name;
public:
    Name(string name="Crazy Person");

    void setName(string name);
    string getName() const {return this->name;};
};

class ProjectCode {
private:
    string cod_project;
public:
    ProjectCode(string cod_project="AAA");

    void setCodProject(string cod_project);
    string getCodProject() const {return this->cod_project;};
};

#endif // DOMAIN_HPP_INCLUDED

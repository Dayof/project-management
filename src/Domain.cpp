#include "Domain.hpp"

ProjectCode::ProjectCode(string cod_project)
{
  setCodProject(cod_project);
}

void ProjectCode::setCodProject(string cod_project)
{
    if(cod_project.length() <= 5 && cod_project.length()>0)
        this->cod_project=cod_project;
    else throw invalid_argument("Codigo invalido. Tente algum codigo com no"
        "maximo 5 caracteres.");

    for(int i=0; i<cod_project.length(); ++i)
    {
        if((cod_project[i] >= 65 && cod_project[i] <= 90) ||
            (cod_project[i] >= 95 && cod_project[i] <= 122))
            this->cod_project=cod_project;
        else throw invalid_argument("Nome invalido. Tente algum codigo"
        "com caracteres entre A-Z.");
    }
}

ProjectState::ProjectState(int project_state)
{
  setProjectState(project_state);
}

void ProjectState::setProjectState(int project_state)
{
    if(project_state <= 9 && project_state>=0)
        this->project_state=project_state;
    else throw invalid_argument("Estado invalido. Tente algum codigo com no"
        "maximo 1 digito.");
}

ProjectPhase::ProjectPhase(int project_phase)
{
  setProjectPhase(project_phase);
}

void ProjectPhase::setProjectPhase(int project_phase)
{
    if(project_phase <= 9 && project_phase>=0)
        this->project_phase=project_phase;
    else throw invalid_argument("Fase invalida. Tente algum numero com no"
        "maximo 1 digito.");
}

Role::Role(int role)
{
  setRole(role);
}

void Role::setRole(int role)
{
    if(role <= 9 && role>0)
        this->role=role;
    else throw invalid_argument("Funcao invalida. Tente algum numero com no"
        "maximo 1 digito.");
}


Name::Name(string name)
{
  setName(name);
}

void Name::setName(string name)
{
    if(name.length() <= 20 && name.length()>0) this->name=name;
    else throw invalid_argument("Nome invalido. Tente algum nome com no"
        "maximo 20 caracteres.");

    for(int i=0; i<name.length(); ++i)
    {
        if((name[i] >= 65 && name[i] <= 90) ||
            (name[i] >= 95 && name[i] <= 122) ||
            (name[i] == 32)) this->name=name;
        else throw invalid_argument("Nome invalido. Tente algum nome"
        "com caracteres entre A-Z ou espaco em branco.");
    }
}

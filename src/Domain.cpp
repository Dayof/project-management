#include "Domain.hpp"

Name::Name(string name)
{
  setName(name);
}

void Name::setName(string name)
{
    if(name.length() <= 20) this->name=name;
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

ProjectCode::ProjectCode(string cod_project)
{
  setCodProject(cod_project);
}

void ProjectCode::setCodProject(string cod_project)
{
    if(cod_project.length() <= 5) this->cod_project=cod_project;
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

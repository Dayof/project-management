#include "Domain.hpp"

ProjectCode::ProjectCode(string cod_project)
{
  setCodProject(cod_project);
}

void ProjectCode::setCodProject(string cod_project)
{
    if(cod_project.length() <= 5 && cod_project.length()>0)
        this->cod_project=cod_project;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum codigo com no"
        "maximo 5 caracteres.");

    for(int i=0; i<cod_project.length(); ++i)
    {
        if((cod_project[i] >= 65 && cod_project[i] <= 90) ||
            (cod_project[i] >= 95 && cod_project[i] <= 122))
            this->cod_project=cod_project;
        else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum codigo"
        "com caracteres entre A-Z.");
    }
}

ProjectState::ProjectState(int project_state)
{
  setProjectState(project_state);
}

void ProjectState::setProjectState(int project_state)
{
    if(project_state==1  || project_state==2)
        this->project_state=project_state;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum codigo com no"
        "maximo 1 digito, sendo 1 para 'Ativo' e 2 para 'Inativo'.");
}

ProjectPhase::ProjectPhase(int project_phase)
{
  setProjectPhase(project_phase);
}

void ProjectPhase::setProjectPhase(int project_phase)
{
    if(project_phase <= 4 && project_phase>=1)
        this->project_phase=project_phase;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum numero com no"
        "maximo 1 digito, sendo 1 para 'Iniciacao', 2 'Preparacao', 3 'Execucao' e"
        " 4 para 'Encerramento'.");
}

Role::Role(int role)
{
  setRole(role);
}

void Role::setRole(int role)
{
    if(role <= 3 && role>0)
        this->role=role;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum numero com no"
        "maximo 1 digito, sendo 1 para 'Analista', 2 'Projetista' e 3 para 'Programador'.");
}

Name::Name(string name)
{
  setName(name);
}

void Name::setName(string name)
{
    if(name.length() <= 20 && name.length()>0) this->name=name;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum nome com no"
        "maximo 20 caracteres.");

    for(int i=0; i<name.length(); ++i)
    {
        if((name[i] >= 65 && name[i] <= 90) ||
            (name[i] >= 95 && name[i] <= 122) ||
            (name[i] == 32)) this->name=name;
        else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum nome"
        "com caracteres entre A-Z ou espaco em branco.");
    }
}

Email::Email(string email)
{
  setEmail(email);
}

void Email::setEmail(string email)
{
    bool valid_email = regex_match(email,
    regex("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9]+$") );

    if(valid_email && email.length()>0) this->email=email;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum e-mail"
    " no formato RFC.");
}

Date::Date(string date)
{
  setDate(date);
}

void Date::setDate(string date)
{
    bool valid_date = regex_match(date,
    regex("^(0[1-9]|[12][0-9]|3[01])([- /.])(0[1-9]|1[012])([- /.])201[0-6]|20[234]\d|2050$") );

    if(valid_date && date.length()>0) this->date=date;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente alguma data"
    " no formato 1-31/1-12/2016-2050.");
}

Phone::Phone(string phone)
{
  setPhone(phone);
}

void Phone::setPhone(string phone)
{
    if(phone.length()<9 && phone.length()>0) this->phone=phone;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum telefone"
    " com 8 digitos, sendo o digito decimal de 0-9.");
}





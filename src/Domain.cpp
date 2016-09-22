#include "Domain.hpp"

ProjectCode::ProjectCode(string cod_project)
{
  setCodProject(cod_project);
}

void ProjectCode::setCodProject(string cod_project)
{
    bool valid_cod = regex_match(cod_project,
    regex("^[A-Z]{5}$") );

    if(valid_cod) this->cod_project=cod_project;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum codigo com"
        " 5 caracteres do tipo A-Z .");
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
        " maximo 1 digito, sendo 1 para 'Ativo' e 2 para 'Inativo'.");
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
        " maximo 1 digito, sendo 1 para 'Iniciacao', 2 'Preparacao', 3 'Execucao' e"
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
        " maximo 1 digito, sendo 1 para 'Analista', 2 'Projetista' e 3 para 'Programador'.");
}

Name::Name(string name)
{
  setName(name);
}

void Name::setName(string name)
{

    bool valid_name = regex_match(name,
    regex("^[a-zA-Z ]*$") );

    if(valid_name && name.length() <= 20 && name.length()>0) this->name=name;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum nome com no"
        " maximo 20 caracteres.");
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
    regex("^(0[1-9]|[12][0-9]|3[01])([- /.])(0[1-9]|1[012])([- /.])(201[6-9]|20[234][0-9]|2050)$") );

    if(valid_date) this->date=date;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente alguma data"
    " no formato 1-31/1-12/2016-2050.");
}

Phone::Phone(string phone)
{
  setPhone(phone);
}

void Phone::setPhone(string phone)
{
    bool valid_phone = regex_match(phone,
    regex("^[0-9]{8}$") );

    if(valid_phone) this->phone=phone;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum telefone"
    " com 8 digitos, sendo o digito decimal de 0-9.");
}

Password::Password(string password)
{
  setPassword(password);
}

void Password::setPassword(string password)
{
    char temp;
    int j;

    if(password.length() == 5) this->password=password;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum nome com "
        "5 caracteres.");

    for(j=0; j<password.length(); ++j)
    {
        temp=password[j];
        for(int i=j+1; i<password.length(); ++i)
        {
            if(temp==password[i]) throw invalid_argument("ERRO: ENTRADA INVALIDA. "
            "Tente algum nome com 5 caracteres sem repeticao.");
        }
    }
}

Registration::Registration(string reg)
{
  setRegistration(reg);
}

void Registration::setRegistration(string reg)
{
    bool valid_reg = regex_match(reg,
    regex("^[0-9]{5}$") );

    if(valid_reg) this->reg=reg;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente alguma matricula"
        " com 5 digitos de 0-9.");
}

Cost::Cost(string cost)
{
  setCost(cost);
}

void Cost::setCost(string cost)
{
    bool valid_cost = regex_match(cost,
    regex("^[+-]?(?=[.]?[0-9])[0-9]*(?:[.][0-9]*)?(?:[Ee][+-]?[0-9]+)?$") );

    if(valid_cost) this->cost=cost;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum custo"
        " do formato 0.00 .");
}


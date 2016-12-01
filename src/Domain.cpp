/** @file Domain.cpp
 *  @brief Implementação dos Domínios do sistema.
 *
 *  Neste arquivo contém as implementações das
 *  assinaturas do métodos construtores, getters
 *  e setters das classes de domínio.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#include "Domain.hpp"

/**
 * Este é um método construtor de código de projeto
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
ProjectCode::ProjectCode(string cod_project)
{
  setCodProject(cod_project);
}

/**
 * Método setter de código de projeto que valida o
 *  parâmetro recebido usando regex para captar exatamente
 *  5 caracteres de A-Z. Caso o contrário é emitido exceção.
 */
void ProjectCode::setCodProject(string cod_project)
{
    bool valid_cod = regex_match(cod_project,
    regex("^[A-Z]{5}$") );

    if(valid_cod) this->cod_project=cod_project;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum codigo com"
        " 5 caracteres do tipo A-Z .");
}

/**
 * Este é um método construtor de estado de projeto
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
ProjectState::ProjectState(int project_state)
{
  setProjectState(project_state);
}

/**
 * Método setter de estado de projeto que valida o
 *  parâmetro recebido checando se é 1 para estado Ativo ou
 *  2 para estado Inativo. Caso o contrário é emitido exceção.
 */
void ProjectState::setProjectState(int project_state)
{
    if(project_state==1  || project_state==2)
        this->project_state=project_state;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum codigo com no"
        " maximo 1 digito, sendo 1 para 'Ativo' e 2 para 'Inativo'.");
}

/**
 * Este é um método construtor de fase de projeto
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
ProjectPhase::ProjectPhase(int project_phase)
{
  setProjectPhase(project_phase);
}

/**
 * Método setter de estado de projeto que valida o
 *  parâmetro recebido checando se é 1 para Iniciação,
 *  2 para Preparação, 3 para Execução e 4 para Encerramento.
 *  Caso o contrário é emitido exceção.
 */
void ProjectPhase::setProjectPhase(int project_phase)
{
    if(project_phase <= 4 && project_phase>=1)
        this->project_phase=project_phase;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum numero com no"
        " maximo 1 digito, sendo 1 para 'Iniciação', 2 'Preparacao', 3 'Execução' e"
        " 4 para 'Encerramento'.");
}

/**
 * Este é um método construtor de função
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
Role::Role(int role)
{
  setRole(role);
}

/**
 * Método setter de função que valida o
 *  parâmetro recebido checando se é 1 para Analista,
 *  2 para Projetista e 3 para Programador.
 *  Caso o contrário é emitido exceção.
 */
void Role::setRole(int role)
{
    if(role <= 3 && role>0)
        this->role=role;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum numero com no"
        " maximo 1 digito, sendo 1 para 'Analista', 2 'Projetista' e 3 para 'Programador'.");
}

/**
 * Este é um método construtor de nome
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
Name::Name(string name)
{
  setName(name);
}

/**
 * Método setter de nome que valida o
 *  parâmetro recebido usando regex para captar no máximo
 *  20 caracteres compostos de letras de A-Z, a-z ou
 *  espaços em branco. Caso o contrário é emitido exceção.
 */
void Name::setName(string name)
{

    bool valid_name = regex_match(name,
    regex("^[a-zA-Z ]*$") );

    if(valid_name && name.length() <= 20 && name.length()>0) this->name=name;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA."
    " Tente algum nome com no maximo 20 caracteres.");
}

/**
 * Este é um método construtor de e-mail
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
Email::Email(string email)
{
  setEmail(email);
}

/**
 * Método setter de e-mail que valida o
 *  parâmetro recebido checando se está no formato de email
 *  definido em RFC. Caso o contrário é emitido exceção.
 */
void Email::setEmail(string email)
{
    bool valid_email = regex_match(email,
    regex("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9]+$") );

    if(valid_email && email.length()>0) this->email=email;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum e-mail"
    " no formato RFC.");
}

/**
 * Este é um método construtor de data
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
Date::Date(string date)
{
  setDate(date);
}

/**
 * Método setter de data que valida o
 *  parâmetro recebido checando se está nos formatos
 *  (01-31)/(01-12)/(2016-2050), (01-31)-(01-12)-(2016-2050),
 *  (01-31).(01-12).(2016-2050), (01-31) (01-12) (2016-2050).
 *  Caso o contrário é emitido exceção.
 */
void Date::setDate(string date)
{
    bool valid_date = regex_match(date,
    regex("^(0[1-9]|[12][0-9]|3[01])([- /.])(0[1-9]|1[012])([- /.])(201[6-9]|20[234][0-9]|2050)$") );

    if(valid_date) this->date=date;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente alguma data"
    " no formato 1-31/1-12/2016-2050.");
}

/**
 * Este é um método construtor de telefone
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
Phone::Phone(string phone)
{
  setPhone(phone);
}

/**
 * Método setter de telefone que valida o
 *  parâmetro recebido usando regex para captar exatamente
 *  8 dígitos de 0 a 9. Caso o contrário é emitido exceção.
 */
void Phone::setPhone(string phone)
{
    bool valid_phone = regex_match(phone,
    regex("^[0-9]{8}$") );

    if(valid_phone) this->phone=phone;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum telefone"
    " com 8 digitos, sendo o digito decimal de 0-9.");
}

/**
 * Este é um método construtor de senha
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
Password::Password(string password)
{
  setPassword(password);
}

/**
 * Método setter de senha que valida o
 *  parâmetro recebido usando regex para captar exatamente
 *  5 caracteres quaisquer sem repetição.
 *  Caso o contrário é emitido exceção.
 */
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

/**
 * Este é um método construtor de matrícula
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
Registration::Registration(string reg)
{
  setRegistration(reg);
}

/**
 * Método setter de senha que valida o
 *  parâmetro recebido usando regex para captar exatamente
 *  5 dígitos de 0 a 9. Caso o contrário é emitido exceção.
 */
void Registration::setRegistration(string reg)
{
    bool valid_reg = regex_match(reg,
    regex("^[0-9]{5}$") );

    if(valid_reg) this->reg=reg;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente alguma matricula"
        " com 5 digitos de 0-9.");
}

/**
 * Este é um método construtor de custo
 *  que passa o valor recebido para o método setter
 *  do atributo.
 */
Cost::Cost(string cost)
{
  setCost(cost);
}

/**
 * Método setter de custo que valida o
 *  parâmetro recebido usando regex para captar exatamente
 *  valores do formato 0.00. Caso o contrário é emitido exceção.
 */
void Cost::setCost(string cost)
{
    bool valid_cost = regex_match(cost,
    regex("^[+-]?(?=[.]?[0-9])[0-9]*(?:[.][0-9]*)?(?:[Ee][+-]?[0-9]+)?$") );

    if(valid_cost) this->cost=cost;
    else throw invalid_argument("ERRO: ENTRADA INVALIDA. Tente algum custo"
        " do formato 0.00 .");
}

/** @file Domain.hpp
 *  @brief Biblioteca de Domínios do sistema.
 *
 *  Neste arquivo contém os cabeçalhos das classes
 *  de domínio.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#ifndef DOMAIN_HPP_INCLUDED
#define DOMAIN_HPP_INCLUDED

#include "Headers.hpp"

/**
 * \class ProjectCode
 *
 * \brief Domínio de Código de Projeto
 *
 * Este domínio só permite entradas de exatamente
 * 5 caracteres de A-Z e a-z.
 *
 */
class ProjectCode {
private:
    /**
     *  Variavel para armazenar o codigo de projeto.
     */
    string cod_project;
public:
    /**
     * Construtor do Código de Projeto.
     *  O construtor tem valor default de "AAAAA".
     *  @param cod_project uma string que recebe o codigo do projeto.
     */
    ProjectCode(string cod_project="AAAAA");

    /**
     * Método setter do domínio de Código de Projeto.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param cod_project uma string que recebe o codigo do projeto.
     */
    void setCodProject(string cod_project);

    /**
     * Método getter do domínio de Código de Projeto.
     *  @return o codigo do projeto validado.
     */
    string getCodProject() const {return this->cod_project;};
};

/**
 * \class ProjectState
 *
 * \brief Domínio de Estado de Projeto
 *
 * Este domínio só permite entradas de exatamente
 * 1 dígito, sendo 1 para estado Ativo e 2 para
 * estado Inativo.
 *
 */
class ProjectState {
private:
    /**
     *  Variavel para armazenar o estado de projeto.
     */
    int project_state;
public:
    /**
     * Construtor do Estado de Projeto.
     *  O construtor tem valor default de 1, ou seja, estado Ativo
     *  assim que é iniciado.
     *  @param project_state um inteiro que recebe o estado de projeto.
     */
    ProjectState(int project_state=1);

    /**
     * Método setter do domínio de Estado de Projeto.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param project_state um inteiro que recebe o estado de projeto.
     */
    void setProjectState(int project_state);
    /**
     * Método getter do domínio de Estado de Projeto.
     *  @return o estado de projeto validado.
     */
    int getProjectState() const {return this->project_state;};
};

/**
 * \class ProjectPhase
 *
 * \brief Domínio de Código de Fase de Projeto
 *
 * Este domínio só permite entradas de exatamente
 * 1 dígito, sendo 1 para Iniciação, 2 para Preparação,
 * 3 para Execução e 4 para Encerramento.
 *
 */
class ProjectPhase {
private:
    /**
     *  Variavel para armazenar o código da fase de projeto.
     */
    int project_phase;
public:
    /**
     * Construtor do Código de Fase de Projeto.
     *  O construtor tem valor default de 1, ou seja, fase de
     *  Iniciação.
     *  @param project_phase um inteiro que recebe o código
     *  de fase de projeto.
     */
    ProjectPhase(int project_phase=1);

    /**
     * Método setter do domínio de Código de Fase de Projeto.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param project_phase um inteiro que recebe o código
     *  de fase de projeto.
     */
    void setProjectPhase(int project_phase);
    /**
     * Método getter do domínio de Código de Fase de Projeto.
     *  @return o código de fase de projeto validado.
     */
    int getProjectPhase() const {return this->project_phase;};
};

/**
 * \class Role
 *
 * \brief Domínio de Função
 *
 * Este domínio só permite entradas de exatamente
 * 1 dígito, sendo 1 para Analista, 2 para Projetista
 * e 3 para Programador.
 *
 */
class Role {
private:
    /**
     *  Variavel para armazenar a função.
     */
    int role;
public:
    /**
     * Construtor com parâmetro da Função.
     *  @param role um inteiro que recebe o código de
     *  de referência à função do desenvolvedor.
     */
    Role(int role);
    /**
     * Construtor sem parâmetro da Função.
     *  Assinatura para lançar exceção caso nenhum parâmetro seja passado.
     */
    Role(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe o codigo "
    " da função.");};

    /**
     * Método setter do domínio de Função.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param role um inteiro que recebe o código
     *  de referência à função do desenvolvedor.
     */
    void setRole(int role);
    /**
     * Método getter do domínio de Função.
     *  @return o código validado de referência à função do desenvolvedor.
     */
    int getRole() const {return this->role;};
};

/**
 * \class Name
 *
 * \brief Domínio de Nome
 *
 * Este domínio só permite entradas com no máximo
 *  20 caracteres compostos de letras de A-Z, a-z ou
 *  espaços em branco.
 *
 */
class Name {
private:
    /**
     *  Variavel para armazenar o nome.
     */
    string name;
public:
    /**
     * Construtor com parâmetro do Nome.
     *  @param name uma string que recebe o nome.
     */
    Name(string name);
    /**
     * Construtor sem parâmetro do Nome.
     *  Assinatura para lançar exceção caso nenhum parâmetro seja passado.
     */
    Name(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe o nome.");};


    /**
     * Método setter do domínio de Nome.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param name uma string que recebe o nome.
     */
    void setName(string name);
    /**
     * Método getter do domínio de Nome.
     *  @return o nome validado.
     */
    string getName() const {return this->name;};
};

/**
 * \class Email
 *
 * \brief Domínio de E-mail
 *
 * Este domínio só permite entradas no formato de email
 *  definido em RFC.
 *
 */
class Email {
private:
    /**
     *  Variavel para armazenar o email.
     */
    string email;
public:
    /**
     * Construtor com parâmetro do E-mail.
     *  @param email uma string que recebe o e-mail.
     */
    Email(string email);
    /**
     * Construtor sem parâmetro do E-mail.
     *  Assinatura para lançar exceção caso nenhum parâmetro seja passado.
     */
    Email(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe o e-mail.");};

    /**
     * Método setter do domínio de E-mail.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param email uma string que recebe o e-mail.
     */
    void setEmail(string email);
    /**
     * Método getter do domínio de E-mail.
     *  @return o e-mail validado.
     */
    string getEmail() const {return this->email;};
};

/**
 * \class Date
 *
 * \brief Domínio de Data
 *
 * Este domínio só permite entradas nos formatos
 *  (01-31)/(01-12)/(2016-2050), (01-31)-(01-12)-(2016-2050),
 *  (01-31).(01-12).(2016-2050), (01-31) (01-12) (2016-2050).
 *  Ele é utilizado nas entidades para data de início de
 *  projeto/fase e data de término de projeto/fase.
 *
 */
class Date {
private:
    /**
     *  Variavel para armazenar a data.
     */
    string date;
public:
    /**
     * Construtor com parâmetro da Data.
     *  @param date uma string que recebe a data.
     */
    Date(string date);
    /**
     * Construtor sem parâmetro da Data.
     *  Assinatura para lançar exceção caso nenhum parâmetro seja passado.
     */
    Date(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe a data.");};

    /**
     * Método setter do domínio da Data.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param date uma string que recebe a data.
     */
    void setDate(string date);
    /**
     * Método getter do domínio da Data.
     *  @return a data validada.
     */
    string getDate() const {return this->date;};
};

/**
 * \class Phone
 *
 * \brief Domínio de Telefone
 *
 * Este domínio só permite entradas de exatamente
 *  8 dígitos de 0 a 9.
 *
 */
class Phone {
private:
    /**
     *  Variavel para armazenar o telefone.
     */
    string phone;
public:
    /**
     * Construtor com parâmetro do Telefone.
     *  @param phone uma string que recebe o telefone.
     */
    Phone(string phone);
    /**
     * Construtor sem parâmetro do Telefone.
     *  Assinatura para lançar exceção caso nenhum parâmetro seja passado.
     */
    Phone(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe o telefone.");};

    /**
     * Método setter do domínio de Telefone.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param phone uma string que recebe o telefone.
     */
    void setPhone(string phone);
    /**
     * Método getter do domínio de Telefone.
     *  @return o telefone validado.
     */
    string getPhone() const {return this->phone;};
};

/**
 * \class Password
 *
 * \brief Domínio de Senha
 *
 * Este domínio só permite entradas de exatamente
 *  5 caracteres quaisquer sem repetição.
 *
 */
class Password {
private:
    /**
     *  Variavel para armazenar a senha.
     */
    string password;
public:
    /**
     * Construtor com parâmetro da Senha.
     *  @param password uma string que recebe a senha.
     */
    Password(string password);
    /**
     * Construtor sem parâmetro da Senha.
     *  Assinatura para lançar exceção caso nenhum parâmetro seja passado.
     */
    Password(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe a senha.");};

    /**
     * Método setter do domínio de Senha.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param password uma string que recebe a senha.
     */
    void setPassword(string password);
    /**
     * Método getter do domínio de Senha.
     *  @return a senha validada.
     */
    string getPassword() const {return this->password;};
};

/**
 * \class Registration
 *
 * \brief Domínio de Matrícula
 *
 * Este domínio só permite entradas de exatamente
 *  5 dígitos de 0 a 9.
 *
 */
class Registration {
private:
    /**
     *  Variavel para armazenar a Matrícula.
     */
    string reg;
public:
    /**
     * Construtor com parâmetro da Matrícula.
     *  @param reg uma string que recebe a matrícula.
     */
    Registration(string reg);
    /**
     * Construtor sem parâmetro da Matrícula.
     *  Assinatura para lançar exceção caso nenhum parâmetro seja passado.
     */
    Registration(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe a matrícula.");};

    /**
     * Método setter do domínio de Matrícula.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param reg uma string que recebe a matrícula.
     */
    void setRegistration(string reg);
    /**
     * Método getter do domínio de Matrícula.
     *  @return a matrícula validada.
     */
    string getRegistration() const {return this->reg;};
};

/**
 * \class Cost
 *
 * \brief Domínio de Custo
 *
 * Este domínio só permite entradas com o formato
 *  0.00. Ele é utilizado nas entidades para custo_atual
 *  e custo_previsto.
 *
 */
class Cost {
private:
    /**
     *  Variavel para armazenar o valor de Custo.
     */
    string cost;
public:
    /**
     * Construtor com parâmetro do Custo.
     *  @param cost uma string que recebe o custo.
     */
    Cost(string cost);
    /**
     * Construtor sem parâmetro do Custo.
     *  Assinatura para lançar exceção caso nenhum parâmetro seja passado.
     */
    Cost(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe o custo.");};

    /**
     * Método setter do domínio de Custo.
     *  Ele valida o valor recebido e atribui se for correto.
     *  @param cost uma string que recebe o custo.
     */
    void setCost(string cost);
    /**
     * Método getter do domínio de Custo.
     *  @return o custo validado.
     */
    string getCost() const {return this->cost;};
};

#endif // DOMAIN_HPP_INCLUDED

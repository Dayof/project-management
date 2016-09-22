/** @file Entity.hpp
 *  @brief Biblioteca de Entidades do sistema.
 *
 *  Neste arquivo contém os cabeçalhos das classes
 *  de entidades.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include "Headers.hpp"

/**
 * \class SysManager
 *
 * \brief Entidade de Gerente de Sistema
 *
 * Esta entidade possui domínios de nome, matríćula
 *  e senha.
 */
class SysManager {
private:
    string name, registration, password;
public:
  SysManager(string name, string registration, string password);
  SysManager(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe nome,"
    " matricula e senha do gerente de sistema.");};

  void setName(string name);
  string getName() const {return this->name;};

  void setRegistration(string registration);
  string getRegistration() const {return this->registration;};

  void setPassword(string password);
  string getPassword() const {return this->password;};
};

/**
 * \class ProjectManager
 *
 * \brief Entidade de Gerente de Projeto
 *
 * Esta entidade possui domínios de nome, matríćula,
 *  senha e telefone.
 */
class ProjectManager {
private:
  string name, registration, password, phone;
public:
    ProjectManager (string name,
                string registration,
                string password);
    ProjectManager(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe nome,"
    " matricula e senha do gerente de projeto.");};

  void setName(string name);
  string getName() const {return this->name;};

  void setRegistration(string registration);
  string getRegistration() const {return this->registration;};

  void setPassword(string password);
  string getPassword() const {return this->password;};

  void setPhone(string phone);
  string getPhone() const {return this->phone;};
};

/**
 * \class Developer
 *
 * \brief Entidade de Desenvolvedor
 *
 * Esta entidade possui domínios de nome, matríćula,
 *  senha, e-mail e função, e.g. Analista, Projetista
 *  ou Programador.
 */
class Developer {
private:
    string name, registration, password, email;
    int role;
public:
  Developer (string name,
            string registration,
            string password,
            int role);
    Developer(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe nome,"
    " matricula, senha e funcao do desenvolvedor.");};

  void setName(string name);
  string getName() const {return this->name;};

  void setRegistration(string registration);
  string getRegistration() const {return this->registration;};

  void setPassword(string password);
  string getPassword() const {return this->password;};

  void setEmail(string email);
  string getEmail() const {return this->email;};

  void setRole(int role);
  char getRole() const {return this->role;};
};

/**
 * \class Project
 *
 * \brief Entidade de Projeto
 *
 * Esta entidade possui domínios de nome, código de projeto,
 *  data de início, data de término, custo atual, custo previsto
 *  estado do projeto, e.g. ativo ou inativo e entidades de
 *  de gerente de projeto e desenvolvedores.
 */
class Project {
private:
    string name, code, init_date, end_date, current_cost, estimate_cost;
    vector<Developer> developers;
    ProjectManager* projectManager;
    int state;
public:
    Project (string name,
            string code,
            ProjectManager* projectManager,
            string init_date,
            int state);
    Project(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe nome,"
    " codigo, gerente de projeto, data de inicio e estado do projeto.");};

  void setName(string name);
  string getName() const {return this->name;};

  void setCode(string code);
  string getCode() const {return this->code;};

  void setInitDate(string init_date);
  string getInitDate() const {return this->init_date;};

  void setEndDate(string end_date);
  string getEndDate() const {return this->end_date;};

    void setCurrCost(string current_cost);
  string getCurrCost() const {return this->current_cost;};

  void setEstimateCost(string estimate_cost);
  string getEstimateCost() const {return this->estimate_cost;};

   void setState(int state);
  int getState() const {return this->state;};

  void setProjectManager(ProjectManager* projectManager) {this->projectManager = projectManager;};
  ProjectManager* getProjectManager() const {return this->projectManager;};

  void addDev(string reg);
  void removeDev(string reg);
  vector<Developer> getAllDevelopers();
};

/**
 * \class Phase
 *
 * \brief Entidade de Fase
 *
 * Esta entidade possui domínios de data de início,
 *  data de término e código de fase para indicar fase de
 *  Iniciação, Preparação, Execução e Encerramento.
 */
class Phase {
private:
    string init_date, end_date;
    int phase;
public:
  Phase (string init_date, int phase);
  Phase(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe  data de inicio "
    " e codigo da fase.");};

  void setInitDate(string init_date);
  string getInitDate() const {return this->init_date;};

  void setEndDate(string end_date);
  string getEndDate() const {return this->end_date;};

    void setPhase(int phase);
  int getPhase() const {return this->phase;};

};

#endif // ENTITY_HPP_INCLUDED

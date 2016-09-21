#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED

#include "Headers.hpp"

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

class Phase {
private:
  char phase;
  string init_date, end_date;
public:
  ~Phase ();
  Phase (char phase=INIT,
        string init_date="00/00/0000",
        string end_date="30/12/2000");

  void setPhase(char phase){this->phase = phase;};
  char getPhase() const {return this->phase;};

  void setInitDate(string init_date){this->init_date = init_date;};
  string getInitDate() const {return this->init_date;};

  void setEndDate(string){this->end_date = end_date;};
  string getEndDate() const {return this->end_date;};
};

class Project {
private:
  string name, cod, init_date, end_date;
  ProjectManager projectManager;
  vector<Developer> developers;
  float current_cost, estimate_cost;
  char state;
  Phase phase;
public:
  Project (string name="",
          string cod="000",
          string init_date="00/00/0000",
          string end_date="30/12/2000",
          char phase=INIT);

  void setName(string name){this->name = name;};
  string getName() const {return this->name;};

  void setCod(string cod){this->cod = cod;};
  string getCod() const {return this->cod;};

  void setInitDate(string init_date){this->init_date = init_date;};
  string getInitDate() const {return this->init_date;};

  void setEndDate(string){this->end_date = end_date;};
  string getEndDate() const {return this->end_date;};

  void setProjectManager(ProjectManager pM){this->projectManager = pM;};
  ProjectManager getProjectManager() const {return this->projectManager;};

  void setCurrCost(float current_cost){this->current_cost = current_cost;};
  float getCurrCost() const {return this->current_cost;};

  void setEstimateCost(float ec){this->estimate_cost = ec;};
  float getEstimateCost() const {return this->estimate_cost;};

  void setState(char state){this->state = state;};
  char getState() const {return this->state;};

  void setPhase(Phase phase){this->phase = phase;};
  Phase getPhase() const {return this->phase;};

  void addDev(Developer);
  vector<Developer> getDev();
};

#endif // ENTITY_HPP_INCLUDED

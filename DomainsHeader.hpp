#ifndef DOMAINS_AND_ENTITY_HEADER
#define DOMAINS_AND_ENTITY_HEADER

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <exception>

using namespace std;

#define ACTIVE 1
#define INACTIVE 2

#define INIT 1
#define PREPARATION 2
#define EXEC 3
#define CLOSURE 4

#define ANALIST 1
#define MANAGER 2
#define DEVELOPER 3

class SysManager {
private:
    string name, registration, password;
public:
  ~SysManager ();
  SysManager ();
  SysManager(string name="",
            string registration="000",
            string password="123456");

  void setName(string name){this->name = name;};
  string getName() const {return this->name;};

  void setRegistration(string registration){this->registration = registration;};
  string getRegistration() const {return this->registration;};

  void setPassword(string password){this->password = password;};
  string getPassword() const {return this->password;};
};

class Phase {
private:
  char phase;
  string init_date, end_date;
public:
  ~Phase ();
  Phase ();
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

class ProjectManager {
private:
  string name, registration, password, phone;
public:
  ~ProjectManager ();
  ProjectManager ();
  ProjectManager (string name="",
                  string registration="000",
                  string password="123456",
                  string phone="99999999");

  void setName(string name){this->name = name;};
  string getName() const {return this->name;};

  void setRegistration(string registration){this->registration = registration;};
  string getRegistration() const {return this->registration;};

  void setPassword(string password){this->password = password;};
  string getPassword() const {return this->password;};

  void setPhone(string phone){this->phone = phone;};
  string getPhone() const {return this->phone;};
};

class Developer {
private:
    string name, registration, password, email;
    char role;
public:
  ~Developer ();
  Developer ();
  Developer (string name="",
            string registration="000",
            string password="123456",
            string email="x@y.z");

  void setName(string name){this->name = name;};
  string getName() const {return this->name;};

  void setRegistration(string registration){this->registration = registration;};
  string getRegistration() const {return this->registration;};

  void setPassword(string password){this->password = password;};
  string getPassword() const {return this->password;};

  void setEmail(string email){this->email = email;};
  string getEmail() const {return this->email;};

  void setRole(char role){this->role = role;};
  char getRole() const {return this->role;};
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
  ~Project ();
  Project ();
  Project (string name="",
          string cod="000",
          string init_date="00/00/0000",
          string end_date="30/12/2000");

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

#endif

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

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
  SysManager ();
  ~SysManager ();
};

class Phase {
private:
  char phase;
  string init_date, end_date;
public:
  Phase ();
  ~Phase ();
};

class ProjectManager {
private:
  string name, registration, password, phone;
public:
  ProjectManager ();
  ~ProjectManager ();
};

class Developer {
private:
    string name, registration, password, email;
    char role;
public:
  Developer ();
  ~Developer ();
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
  Project ();
  ~Project ();

};

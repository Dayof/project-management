#include "Entity.hpp"

SysManager::SysManager(string name, string registration, string password)
{
  this->name = name;
  this->registration = registration;
  this->password = password;
}

Phase::Phase(char phase, string init_date, string end_date)
{
  this->phase = phase;
  this->init_date = init_date;
  this->end_date = end_date;
}

ProjectManager::ProjectManager(string name,
                              string registration,
                              string password,
                              string phone)
{
  this->name = name;
  this->registration = registration;
  this->password = password;
  this->phone = phone;
}

Developer::Developer(string name,
                    string registration,
                    string password,
                    string email)
{
  this->name = name;
  this->registration = registration;
  this->password = password;
  this->email = email;
}

// //TODO
// Project::Project(string name,
//                 string cod,
//                 string init_date,
//                 string end_date,
//                 char phase)
// {
//   this->name = name;
//   this->cod = cod;
//   this->init_date = init_date;
//   this->end_date = end_date;
//   this->phase = phase;
// }

// //TODO
// void Project::addDev(Developer dev)
// {
//
// };
//
// //TODO
// vector<Developer> Project::getDev()
// {
//
// }


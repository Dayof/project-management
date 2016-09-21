#include "Entity.hpp"
#include "Domain.hpp"

SysManager::SysManager(string name,
                    string registration,
                    string password)
{
    setName(name);
    setRegistration(registration);
    setPassword(password);
}

void SysManager::setName(string name_str)
{
    Name* name;
    try{ name = new Name(name_str); }
    catch (exception& err) { throw err.what(); return; }
    this->name = name->getName();

}

void SysManager::setRegistration(string reg_str)
{
    Registration* registration;
    try{ registration = new Registration(reg_str); }
    catch (exception& err) { throw err.what(); }
    this->registration = registration->getRegistration();

}

void SysManager::setPassword(string pass_str)
{
    Password* pass;
    try{ pass = new Password(pass_str); }
    catch (exception& err) { throw err.what(); }
    this->password = pass->getPassword();

}

ProjectManager::ProjectManager(string name,
                              string registration,
                              string password)
{
    setName(name);
    setRegistration(registration);
    setPassword(password);
}

void ProjectManager::setName(string name_str)
{
    Name* name;
    try{ name = new Name(name_str); }
    catch (exception& err) { throw err.what(); }
    this->name = name->getName();

}

void ProjectManager::setRegistration(string reg_str)
{
    Registration* registration;
    try{ registration = new Registration(reg_str); }
    catch (exception& err) { throw err.what(); }
    this->registration = registration->getRegistration();

}

void ProjectManager::setPassword(string pass_str)
{
    Password* pass;
    try{ pass = new Password(pass_str); }
    catch (exception& err) { throw err.what(); }
    this->password = pass->getPassword();
}

void ProjectManager::setPhone(string phone_str)
{
    Phone* phone;
    try{ phone = new Phone(phone_str); }
    catch (exception& err) { throw err.what(); }
    this->phone = phone->getPhone();
}

Phase::Phase(char phase, string init_date, string end_date)
{
  this->phase = phase;
  this->init_date = init_date;
  this->end_date = end_date;
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


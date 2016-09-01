#include "DomainsHeader.hpp"

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
};

SysManager::SysManager(string name, string registration, string password)
{
  this->name = name;
  this->registration = registration;
  this->password = password;
}

int main ()
{
  try
  {
    myexception *me = new myexception();
    //throw *me;
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }

  SysManager* sm = new SysManager("josef", "001", "pass_secure");
  cout << sm->getName() << endl;

  return 0;
}

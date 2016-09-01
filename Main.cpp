#include "DomainsHeader.hpp"

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "My exception happened";
  }
};

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

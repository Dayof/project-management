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
    throw *me;
  }
  catch (exception& e)
  {
    cout << e.what() << '\n';
  }

  return 0;
}

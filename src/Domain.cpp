#include "Domain.hpp"

Name::Name(string name)
{
  setName(name);
}

void Name::setName(string name)
{
    if(name.length() <= 20) this->name=name;
    else throw invalid_argument("Nome invalido. Tente algum nome com no maximo 5 caracteres.");
}

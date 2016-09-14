#include "Domain.hpp"

Name::Name(string name)
{
  setName(name);
}

void Name::setName(string name)
{
    if(name.length() <= 20) this->name=name;
    else throw invalid_argument("Nome invalido. Tente algum nome com no"
        "maximo 5 caracteres.");

    for(int i=0; i<name.length(); ++i)
    {
        if((name[i] >= 65 && name[i] <= 90) ||
            (name[i] >= 95 && name[i] <= 122) ||
            (name[i] == 32)) this->name=name;
        else throw invalid_argument("Nome invalido. Tente algum nome"
        "com caracteres entre A-Z ou espaco em branco.");
    }
}

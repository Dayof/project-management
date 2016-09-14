#ifndef DOMAIN_HPP_INCLUDED
#define DOMAIN_HPP_INCLUDED

#include "Headers.hpp"

class Name {
private:
    string name;
public:
    Name(string name="");

    void setName(string name);
    string getName() const {return this->name;};
};

#endif // DOMAIN_HPP_INCLUDED

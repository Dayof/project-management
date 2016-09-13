#ifndef DOMAIN_HPP_INCLUDED
#define DOMAIN_HPP_INCLUDED

#include "Headers.hpp"

class Name {
private:
    string name;
public:
    Name(string name="");

    void setName(string name);
    string getName() const;
}

#endif // DOMAIN_HPP_INCLUDED

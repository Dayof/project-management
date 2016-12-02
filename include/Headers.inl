/** @file Headers.hpp
 *  @brief Arquivos de bibliotecas em comum
 *  dos arquivos de entidade e domínio.
 *
 *  Neste arquivo contém os includes de
 *  bibliotecas gerais do C++ como também
 *  para validar os domínios, como a de regex.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#ifndef HEADERS_HPP_INCLUDED
#define HEADERS_HPP_INCLUDED

/* -- Includes -- */

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <exception>
#include <stdexcept>
#include <regex>
#include <map>
#include <sstream>

/* -- Definições -- */

/* Definição para estado de projeto */
#define ACTIVE 1
#define INACTIVE 2

/* Definição para código de fase de projeto */
#define INIT 1
#define PREPARATION 2
#define EXEC 3
#define CLOSURE 4

/* Definição para função */
#define ANALIST 1
#define SOFTWARE_DESIGNER 2
#define PROGRAMMER 3

using namespace std;

#endif // HEADERS_HPP_INCLUDED

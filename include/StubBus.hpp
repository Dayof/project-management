/** @file StubBus.hpp
 *  @brief Stub da camada de negócio.
 *
 *  @author Dayanne Fernandes
 *  @bug Sem bug conhecido.
 */

#ifndef STUB_BUS_HPP_INCLUDED
#define STUB_BUS_HPP_INCLUDED

#include "Headers.inl"

/**
 * \class StubBus
 *
 * \brief Classe que herda a interface de negócio.
 *
 */
class StubBus :public IBus {
private:
    Persistence *pers;
public:
    StubBus(Persistence *pers){ this->pers = pers; };
    StubBus(){throw invalid_argument("ERRO: ENTRADA INCOMPLETA. Passe camada de persistência no construtor.");};
};

#endif // STUB_BUS_HPP_INCLUDED

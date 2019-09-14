#ifndef EQ_H
#define EQ_H

#include "common.h"
#include "term.h"

enum typeOfEq { Equality, Inequality };

class Eq
{
public:
    Eq(const Term &lhs, const typeOfEq type, const Term &rhs);

    Term lhs() const;
    Term rhs() const;
    typeOfEq type() const;

private:
    Term m_lhs;
    Term m_rhs;
    typeOfEq m_type;
};

#endif // EQ_H

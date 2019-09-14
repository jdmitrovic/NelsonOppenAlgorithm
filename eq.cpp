#include "eq.h"

Eq::Eq(const Term &lhs, const typeOfEq type, const Term &rhs) :
    m_lhs(lhs), m_type(type), m_rhs(rhs)
{

}

Term Eq::lhs() const
{
    return m_lhs;
}

Term Eq::rhs() const
{
    return m_rhs;
}

typeOfEq Eq::type() const
{
    return m_type;
}

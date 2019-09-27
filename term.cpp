#include "term.h"

#include <iterator>

BaseTerm::BaseTerm()
{

}

VariableTerm::VariableTerm(Variable var)
    : BaseTerm(), m_var{var}
{
    
}

bool VariableTerm::hasVariable(const Variable &var) const
{
    return var == m_var;
}

bool VariableTerm::hasTermInFstLayer(const Term &t) const
{
    return false;
}

bool VariableTerm::equalTo(const Term &t) const
{
    const VariableTerm *vt = dynamic_cast<const VariableTerm*>(t.get());

    if(vt)
        return vt->m_var == m_var;
    else
        return false;
}

FunctionTerm::FunctionTerm(FunctionSymbol symbol, std::vector<Term> terms)
  : BaseTerm(), m_symbol{symbol}, m_terms{terms}
{
 
}

bool FunctionTerm::hasVariable(const Variable &var) const
{
    for(const Term &t: m_terms){
        if(t->hasVariable(var))
            return true;
    }

    return false;
}

bool FunctionTerm::hasTermInFstLayer(const Term &t) const
{
    for(const Term &i : m_terms)
        if(i == t)
            return true;

    return false;
}

bool FunctionTerm::equalTo(const Term &t) const
{
    const FunctionTerm *ft = dynamic_cast<const FunctionTerm*>(t.get());

    if(ft)
        return ft->m_symbol == m_symbol && ft->m_terms == m_terms;
    else
        return false;
}

std::vector<Term> FunctionTerm::terms() const
{
    return m_terms;
}

FunctionSymbol FunctionTerm::symbol() const
{
    return m_symbol;
}

bool operator==(const Term &lhs, const Term &rhs)
{
    return lhs->equalTo(rhs);
}

std::ostream &operator<<(std::ostream &out, const Term &t)
{
    return t->print(out);
}


std::ostream &VariableTerm::print(std::ostream &out) const
{
    return out << m_var;
}

std::ostream &FunctionTerm::print(std::ostream &out) const
{
  if (m_terms.empty())
  {
    return out << m_symbol;
  }
  else
  {
    out << m_symbol << "(";
    for (auto first = m_terms.cbegin(), last = m_terms.cend(); first + 1 != last; ++first)
    {
      (*first)->print(out);
      out << ", ";
    }
    m_terms.back()->print(out);
    return out << ")";
  }
}

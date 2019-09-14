#ifndef TERM_H
#define TERM_H

#include "common.h"
#include <memory>

class BaseTerm;
using Term = std::shared_ptr<BaseTerm>;

class BaseTerm
{
public:
    BaseTerm();

    virtual bool hasVariable(const Variable var) const = 0;
    virtual bool hasTermInFstLayer(const Term &t) const = 0;
    virtual bool equalTo(const Term &t) const = 0;
};

bool operator==(const Term &lhs, const Term &rhs);

class VariableTerm : public BaseTerm
{
public:
    VariableTerm(Variable var);

    bool hasVariable(const Variable &var) const;
    bool hasTermInFstLayer(const Term &t) const;
    bool equalTo(const Term &t) const;

private:
    Variable m_var;
};

class FunctionTerm : public BaseTerm
{
public:
    FunctionTerm(FunctionSymbol &symbol, std::vector<Term> terms);

    bool hasVariable(const Variable &var) const;
    bool hasTermInFstLayer(const Term &t) const;
    bool equalTo(const Term &t) const;

    std::vector<Term> terms() const;

    FunctionSymbol symbol() const;

private:
    FunctionSymbol m_symbol;
    std::vector<Term> m_terms;
};

#endif // TERM_H

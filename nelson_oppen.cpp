#include "nelson_oppen.h"

EqClassMap nelsonOppen(std::vector<Eq> equalities, std::unordered_set<Term> T)
{
    EqClassMap E;
//    std::unordered_set<Term> T;
    for(const Eq &e : equalities){
        E.insert(std::make_pair(e.lhs(), e.lhs()));
        E.insert(std::make_pair(e.rhs(), e.rhs()));

        T.insert(e.lhs());
        T.insert(e.rhs());
    }

    for(const Eq &e : equalities){
        if(e.type() == Inequality)
            continue;

        merge(E, T, e.lhs(), e.rhs());
    }

    return E;
}

void merge(EqClassMap &E, std::unordered_set<Term> &T, const Term &l, const Term &r)
{
    std::vector<Term> usingL;
    std::vector<Term> usingR;

    for(const Term &t : T){
        if(t->hasTermInFstLayer(l))
            usingL.push_back(t);
        if(t->hasTermInFstLayer(r))
            usingR.push_back(t);
    }

    Term rClass = E[r];
    Term lClass = E[l];

    for(auto const &c : E){
        if(c.second == rClass)
            E[c.first] = lClass;
    }

    for(const Term &t1 : usingL){
        for(const Term &t2 : usingR){
            if(E[t1] != E[t2] && congruent(E, t1, t2))
                merge(E, T, t1, t2);
        }
    }

}

bool congruent(EqClassMap &E, const Term &t1, const Term &t2)
{
    const FunctionTerm *ft1 = dynamic_cast<const FunctionTerm *>(t1.get());
    const FunctionTerm *ft2 = dynamic_cast<const FunctionTerm *>(t2.get());

    if(!ft1 || !ft2 || ft1->symbol() != ft2->symbol() || ft1->terms().size() != ft2->terms().size())
        return false;

    std::vector<Term> terms1 = ft1->terms();
    std::vector<Term> terms2 = ft2->terms();
    unsigned size = terms1.size();

    for(unsigned i = 0; i < size; ++i){
        if(E[terms1[i]] != E[terms2[i]])
            return false;
    }

    return true;
}

#ifndef NELSON_OPPEN_H
#define NELSON_OPPEN_H

#include "common.h"
#include "term.h"
#include "eq.h"
#include <unordered_map>
#include <vector>
#include <unordered_set>

using EqClassMap = std::unordered_map<Term, Term>;

EqClassMap nelsonOppen(std::vector<Eq> equalities);
void merge(EqClassMap &E, std::unordered_set<Term> &T, const Term &l, const Term &r);
bool congruent(EqClassMap &E, const Term &t1, const Term &t2);

#endif // NELSON_OPPEN_H

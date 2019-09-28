#ifndef NELSON_OPPEN_H
#define NELSON_OPPEN_H

#include "common.h"
#include "term.h"
#include "eq.h"
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <iostream>

using EqClassMap = std::unordered_map<Term, Term>;

void printNelsonOppen(std::vector<Eq> tmp, std::unordered_set<Term> t = {});
EqClassMap nelsonOppen(std::vector<Eq> equalities, std::unordered_set<Term> T = std::unordered_set<Term>());
void merge(EqClassMap &E, std::unordered_set<Term> &T, const Term &l, const Term &r);
bool congruent(EqClassMap &E, const Term &t1, const Term &t2);

#endif // NELSON_OPPEN_H

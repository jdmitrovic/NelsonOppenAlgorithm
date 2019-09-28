#include <iostream>
#include "eq.h"
#include "nelson_oppen.h"
#include "term.h"
#include <iterator>
#include <unordered_set>

int main(int argc, char *argv[])	
{
	// E = { f(x, y) = x, f(y, x) = y }	

	// dokazati da se f(f(x, y), f(y, x)) = x moze izvesti iz pocetnog skupa jednakosti

	
    Term x = std::make_shared<VariableTerm>("x");
    Term y = std::make_shared<VariableTerm>("y");

    Term f1 = std::make_shared<FunctionTerm>("f", std::vector<Term> {x, y});
    Term f2 = std::make_shared<FunctionTerm>("f", std::vector<Term> {y, x});
    Term f3 = std::make_shared<FunctionTerm>("f", std::vector<Term> {f1, f2});

	Eq e1 = Eq(f1, Equality, x);
	Eq e2 = Eq(f2, Equality, y);
	//Eq e3 = Eq(f3, Equality, x);
	
	auto tmp1 = std::vector<Eq> {e1, e2};
	auto t1 = std::unordered_set<Term> {x, y, f1, f2, f3};	
	printNelsonOppen(tmp1, t1);


	// EUF
	// ∀x, y ((y = f(x) ⋀ x = g(y)) => (x = g(f(x))))

	// ispitujemo nezadovoljivost negacije
	
	// y = f(x) /\ x = g(y) /\ x != g(f(x))
	
	// E = { y = f(x), x = g(y), x != g(f(x)) }

	Term f4 = std::make_shared<FunctionTerm>("f", std::vector<Term> {x});
	Term g1 = std::make_shared<FunctionTerm>("g", std::vector<Term> {y});
	Term gf1 = std::make_shared<FunctionTerm>("g", std::vector<Term> {f4});
	
	Eq e4 = Eq(y, Equality, f4);
	Eq e5 = Eq(x, Equality, g1);
	Eq e6 = Eq(x, Inequality, gf1);
		
	auto tmp2 = std::vector<Eq> {e4, e5, e6};
	printNelsonOppen(tmp2);
	
	// E = { y = f(x), x = g(y) }
	// T = { x, y, f(x), g(y), g(f(x)) }

	auto tmp3 = std::vector<Eq> {e4, e5};
	auto t3 = std::unordered_set<Term> {x, y, f4, g1, gf1};	
	printNelsonOppen(tmp3, t3);

 
    return 0;
}

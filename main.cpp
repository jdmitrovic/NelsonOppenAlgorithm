#include <iostream>
#include "eq.h"
#include "nelson_oppen.h"
#include "term.h"
#include <iterator>
#include <unordered_set>

using namespace std;

int main(int argc, char *argv[])
{
	Term x = make_shared<VariableTerm>("x");
	Term y = make_shared<VariableTerm>("y");

	Term f1 = make_shared<FunctionTerm>("f", vector<Term> {x, y});
	Term f2 = make_shared<FunctionTerm>("f", vector<Term> {y, x});

	Term f3 = make_shared<FunctionTerm>("f", vector<Term> {f1, f2});


	Eq e1 = Eq(f1, Equality, x);
	Eq e2 = Eq(f2, Equality, y);

	Eq e3 = Eq(f3, Equality, x);

	EqClassMap cm = nelsonOppen(vector<Eq> {e1, e2, e3});


	for(auto const &c : cm){
        	std::cout << '{' << c.first << ',' << ' ' << c.second << '}' << std::endl;
    	}

	return 0;
}

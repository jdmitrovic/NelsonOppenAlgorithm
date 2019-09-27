#include <iostream>
#include "eq.h"
#include "nelson_oppen.h"
#include "term.h"
#include <iterator>
#include <unordered_set>

int main(int argc, char *argv[])
{
    Term x = std::make_shared<VariableTerm>("x");
    Term y = std::make_shared<VariableTerm>("y");

    Term f1 = std::make_shared<FunctionTerm>("f", std::vector<Term> {x, y});
    Term f2 = std::make_shared<FunctionTerm>("f", std::vector<Term> {y, x});

    Term f3 = std::make_shared<FunctionTerm>("f", std::vector<Term> {f1, f2});


	Eq e1 = Eq(f1, Equality, x);
	Eq e2 = Eq(f2, Equality, y);

	Eq e3 = Eq(f3, Equality, x);

    auto tmp = std::vector<Eq> {e1, e2, e3};
    EqClassMap cm = nelsonOppen(tmp);
    std::unordered_set<Term> classes;

    for(auto &i : cm)
        classes.insert(i.second);

    bool first_term;

    for(auto &i : classes){
        first_term = true;
        std::cout << '{';

        for(auto &j : cm){
            if(j.second == i){
                if(!first_term)
                    std::cout << ", ";

                std::cout << j.first;
                first_term = false;
            }
        }

        std::cout << '}' << std::endl;
    }

//    for(auto const &c : cm){
//            std::cout << '{' << c.first << ',' << ' ' << c.second << '}' << std::endl;
//    }

    return 0;
}

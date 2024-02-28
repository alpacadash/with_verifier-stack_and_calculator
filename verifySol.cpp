#include "verifySol.hpp"

#include <string>
#include <unordered_map>

bool verifySolution(const std::string& addend1, const std::string& addend2,
                    const std::string& result,
                    const std::unordered_map<char, unsigned>& mapping) {
    // TODO: Implement

    int a = 0;
    int b = 0;
    int c = 0;

    for(char ch : addend1){
        a = a*10 + mapping.at(ch);

    }



    for(char ch : addend2){
        b = b*10 + mapping.at(ch);

    }



    for(char ch : result){
        c = c*10 + mapping.at(ch);

    }

    return (a+b == c);  // FYI, this stub is not a correct solution.
}

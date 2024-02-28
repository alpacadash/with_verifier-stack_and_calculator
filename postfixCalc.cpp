#include "postfixCalc.hpp"

#include "LinkedListStack.hpp"
#include <iostream>
#include <cctype>

unsigned postfixCalculator(const std::vector<std::string>& entries) {
    // TODO: Implement Function
    LinkedListStack<unsigned int> list;

    for(size_t i = 0; i < entries.size(); i++){
        if(entries[i] != "+" && entries[i] != "-" && entries[i] != "*" && entries[i] != "/"){
                list.push(std::stoul(entries[i]));
            }
        else{
                unsigned int num1 = list.top();
                list.pop();
                unsigned int num2 = list.top();
                list.pop();
                if(entries[i] == "+"){
                    list.push(num1 + num2);
                }
                else if(entries[i] == "-"){
                    if(num1 >= num2){
                        list.push(num1 - num2);
                    }
                    else{
                        list.push(num2 - num1);
                    }
                }
                else if(entries[i] == "*"){
                    list.push(num1*num2);
                }
                else if(entries[i] == "/"){
                    list.push(num1/num2);
                }
            }
    }
    if(list.size() != 1){
            throw(CannotEvaluateException("Error"));
    }
    return list.top();  // stub, not the correct answer

}

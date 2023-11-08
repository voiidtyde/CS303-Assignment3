#include "ExpressionManager.h"
#include <stack>
#include <iostream>
#include <map>

namespace MyNamespace {

// Function to check if a character is one of the supported parentheses
bool isParenthesis(char c) {
    return (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']');
}

// Function to check if a pair of characters forms a valid opening-closing parenthesis pair
bool arePair(char opening, char closing) {
    return ((opening == '(' && closing == ')') || 
            (opening == '{' && closing == '}') || 
            (opening == '[' && closing == ']'));
}

// Constructor for the ExpressionManager class
ExpressionManager::ExpressionManager() {
    // Constructor implementation (if needed)
}

// Function to check if an expression has balanced parentheses
bool ExpressionManager::isBalancedParentheses(const std::string& expression) {
    std::stack<char> parenthesesStack;

    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            parenthesesStack.push(c); // Push opening parentheses onto the stack
        } else if (c == ')' || c == '}' || c == ']') {
            if (parenthesesStack.empty() || !arePair(parenthesesStack.top(), c)) {
                return false; // Unmatched closing parenthesis or stack is empty
            }
            parenthesesStack.pop(); // Pop a matched opening parenthesis
        }
    }

    return parenthesesStack.empty(); // If the stack is empty, all parentheses are matched
}

// Function to convert an infix expression to postfix
std::string ExpressionManager::infixToPostfix(const std::string& infix) {
    // Define operator precedence using a map
    std::map<char, int> precedence;
    precedence['+'] = precedence['-'] = 1;
    precedence['*'] = precedence['/'] = precedence['%'] = 2;

    std::string postfix;
    std::stack<char> operators;

    for (char c : infix) {
        if (c == ' ' || isParenthesis(c)) {
            continue; // Ignore spaces and parentheses
        } else if (isdigit(c) || isalpha(c)) {
            if (!postfix.empty() && !isspace(postfix.back())) {
                postfix += ' ';
            }
            postfix += c; // Output operands with spaces
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
            while (!operators.empty() && operators.top() != '(' && precedence[c] <= precedence[operators.top()]) {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                postfix += ' ';
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Pop the opening parenthesis
        }
    }

    while (!operators.empty()) {
        postfix += ' ';
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

} // namespace MyNamespace

#ifndef MYNAMESPACE_EXPRESSION_MANAGER_H
#define MYNAMESPACE_EXPRESSION_MANAGER_H

#include <string>

namespace MyNamespace {

class ExpressionManager {
public:
    // Constructor for the ExpressionManager class
    ExpressionManager();

    // Function to check if an expression has balanced parentheses
    bool isBalancedParentheses(const std::string& expression);

    // Function to convert an infix expression to postfix
    std::string infixToPostfix(const std::string& infixExpression);
};

} // namespace MyNamespace

#endif // MYNAMESPACE_EXPRESSION_MANAGER_H

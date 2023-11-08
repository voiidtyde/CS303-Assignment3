#ifndef MYNAMESPACE_EXPRESSION_MANAGER_H
#define MYNAMESPACE_EXPRESSION_MANAGER_H

#include <string>

namespace MyNamespace {

class ExpressionManager {
public:
    ExpressionManager();

    bool isBalancedParentheses(const std::string& expression);
    std::string infixToPostfix(const std::string& infixExpression);
};

} // namespace MyNamespace

#endif // MYNAMESPACE_EXPRESSION_MANAGER_H
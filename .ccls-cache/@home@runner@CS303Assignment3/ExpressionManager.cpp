#include "ExpressionManager.h"
#include <stack>
#include <iostream>
#include <map>

namespace MyNamespace {

bool isParenthesis(char c) {
    return (c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']');
}

bool arePair(char opening, char closing) {
    return ((opening == '(' && closing == ')') || 
            (opening == '{' && closing == '}') || 
            (opening == '[' && closing == ']'));
}

ExpressionManager::ExpressionManager() {
    // Constructor implementation (if needed)
}


  bool ExpressionManager::isBalancedParentheses(const std::string& expression) {
      std::stack<char> parenthesesStack;

      for (char c : expression) {
          if (c == '(' || c == '{' || c == '[') {
              parenthesesStack.push(c);
          } else if (c == ')' || c == '}' || c == ']') {
              if (parenthesesStack.empty() || !arePair(parenthesesStack.top(), c)) {
                  return false;
              }
              parenthesesStack.pop();
          }
      }

      return parenthesesStack.empty();
  }

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

#include "ExpressionManager.h"
#include "Queue.h"
#include <iostream>
#include <string>

using namespace std;
using namespace MyNamespace;

int main() {
  // Test the Expression Manager 
    ExpressionManager expressionManager;

    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    // Check if the entered infix expression has balanced parentheses
    if (expressionManager.isBalancedParentheses(infixExpression)) {
        // If balanced, convert infix expression to postfix and display it
        string postfixExpression = expressionManager.infixToPostfix(infixExpression);
        cout << "Postfix expression: " << postfixExpression << endl;
    } else {
        // If unbalanced, report the expression as invalid
        cout << "Invalid expression. Parentheses are not balanced." << endl;
    }


  // Test the queue
  Queue<int> intQueue;

  // Enqueue elements
  intQueue.enqueue(1);
  intQueue.enqueue(2);
  intQueue.enqueue(3);

  // Check if the queue is empty
  if (!intQueue.isEmpty()) {
      // Get the front element
      std::cout << "Front element: " << intQueue.front() << std::endl;

      // Dequeue elements
      while (!intQueue.isEmpty()) {
          std::cout << "Dequeue: " << intQueue.dequeue() << std::endl;
      }
  } else {
      std::cout << "Queue is empty." << std::endl;
  }

    return 0;
}



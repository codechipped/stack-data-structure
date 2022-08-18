#include "Stack.h"
#include <iostream>
#include <string>

template <typename T> void PrintStack(const Stack<T> &stack) {
  for (size_t i = 0; i < stack.Size(); i++) {
    std::cout << stack[i] << std::endl;
  }

  std::cout << "----------------------\n";
}
int main(int argc, char const *argv[]) {
  Stack<std::string> stack;
  stack.push("Test 1");
  stack.push("Test 2");
  stack.push("Test 3");
  stack.push("Test 4");
  if (!stack.Empty()) {
    std::cout << "Stack has " << std::to_string(stack.Size()) << " elements."
              << std::endl;
    PrintStack(stack);
  }
  std::cout << "Popped: " << stack.Pop() << std::endl;
  return 0;
}
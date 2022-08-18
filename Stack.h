#pragma once
#include <stdio.h>
#include <utility>

template <typename T> class Stack {
public:
  Stack() { ReAlloc(2); };

  void push(const T &value) {
    if (m_Size >= m_Capacity)
      ReAlloc(m_Capacity +
              m_Capacity / 2); // increase the capacity by half the current size

    m_Data[m_Size] = value;
    m_Size++;
  }

  // return the value from specific index T[index]
  const T &operator[](size_t index) const {
    /* TODO: Should implement a catch here in case the index exceeds m_Size */

    return m_Data[index];
  }

  // returns last item on the stack
  T pop() {
    m_Size--;
    return m_Data[m_Size];
  }

  // return size of stack
  size_t size() const { return m_Size; }

  // retun if the stack is empty
  bool empty() const { return m_Size <= 0; }

private:
  // this allows the data struct to be dynamic in size
  void ReAlloc(size_t newCapacity) {

    T *newBlock = new T[newCapacity];

    // make sure new size isn't lower than current size
    if (newCapacity < m_Size)
      m_Size = newCapacity;

    // move all of the elements
    for (size_t i = 0; i < m_Size; i++)
      newBlock[i] = std::move(m_Data[i]);

    // delete the old
    delete[] m_Data;

    m_Data = newBlock;
    m_Capacity = newCapacity;
  };

private:
  T *m_Data = nullptr;
  size_t m_Size = 0;
  size_t m_Capacity = 0;
};

// #include <iostream>

// class Stack {
// private:
//   // struct for data
//   struct Data {
//     auto value;
//   };
//   // An array to store the data
//   Data *dataArr;
//   // track last element
//   int top_of_stack;
//   // track size of stack
//   int stack_size;

// public:
//   Stack() {
//     // initialize variables
//     top_of_stack = 0;
//     stack_size = 0;
//     dataArr = new Data[100];
//   };

//   // Add a new item to the stack
//   void push(int arg) {

//     dataArr[top_of_stack].value = arg;
//     top_of_stack++;
//     stack_size++;
//   };
//   // Remove an item from the stack
//   auto pop() {
//     if (empty()) {
//       // returning empty struct if stack is empty
//       return;
//     }

//     // reduce stack and stack_size
//     top_of_stack--;
//     stack_size--;

//     // return value but account for reducing the stack stack_size
//     return dataArr[top_of_stack + 1];
//   };

//   // check if empty
//   bool empty() { return stack_size == 0; };

//   // return stack_size of the stack
//   int size() { return stack_size; };

//   // memory cleanup
//   ~Stack() { delete[] dataArr; }
// };
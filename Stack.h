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

public:
  ~Stack() { delete[] m_Data; }
};
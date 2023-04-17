// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
    T* arr;
    int head, tail;
    int count;
    
 public:
  TPQueue() : head(0), tail(0), count(0) { arr = new T[size]; }
  bool IsEmpty() const {
    return count == 0;
  }
  bool IsFull() const {
    return size == count;
  }
  const T& pop() {
    if (IsEmpty()) {
      throw std::string("Empty!");
    } else {
      count--;
      return arr[first++ % size];
    }
  }
  void Push() {
    if (IsFull()) {
      throw std::string("Full!");
    } else {
      int len = tail;
      arr[tail % size] = value;
      T temp = arr[len % size];
      while (arr[len % size].prior > arr[(len - 1) % size].prior && len > head) {
	temp = arr[len % size];
	arr[len % size] = arr[(len - 1) % size];
	arr[(len - 1) % size] = temp;
	len--;
      }
      count++;
      tail++;
    }
  }
  ~TPQueue() {
    delete[] arr;
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_

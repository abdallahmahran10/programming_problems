#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H
#include <mutex>
#include <condition_variable>
#include "common.h"

// A threadsafe-queue.
template <class T>
class SafeQueue
{
public:
  SafeQueue(void)
    : q()
    , m()
    , c()
  {}

  ~SafeQueue(void)
  {}

  // Add an element to the queue.
  void enqueue(T t)
  {
    std::lock_guard<std::mutex> lock(m);
    q.push(t);
    c.notify_one();
  }

  T dequeue(void)
  {
    std::unique_lock<std::mutex> lock(m);
    T val = q.front();
    q.pop();
    c.notify_one();
    return val;
  }

//  void pop(void)
//  {
//    std::unique_lock<std::mutex> lock(m);
//    q.pop();
//    c.notify_one();
//  }

  int size()
  {
      std::lock_guard<std::mutex> lock(m);
      int s = q.size();
      return s;
  }

  int empty()
  {
      std::lock_guard<std::mutex> lock(m);
      bool empty = q.empty();
      return empty;
  }

private:
  queue<T> q;
  mutable std::mutex m;
  std::condition_variable c;
};
#endif // SAFEQUEUE_H

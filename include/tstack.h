// Copyright 2021 NNTU-CS

template<typename T, int size>
class TStack {
 private:
    T arr[100];
    int t;

 public:
    TStack(): t(-1) { }
    T get() const {
      return arr[t];
    }
    bool isEmpty() const {
      return t == -1;
    }
    bool isFull() const {
      return t == size - 1;
    }
    void pop() {
      if (t >= 0)
        t--;
      }
    void push(T item) {
       if (t < size - 1)
         arr[++t] = item;
       }
};
#endif  // INCLUDE_TSTACK_H_

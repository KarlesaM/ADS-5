template<typename T, int size>
class TStack {
 private:
  T arr[100];
  int t;

 public:
  TStack() : t(-1) { }
  bool isEmpty() const {
    return t == -1;
  }
  bool isFull() const {
    return t == size - 1;
  }
  void push(T value) {
  if (isFull())
    throw "Full!";
  else
    arr[++t] = value;
  }
  T get() const {
    return arr[t];
  }
  void pop() {
    if (!isEmpty())
      --t;
    else
      throw "Empty!";
  }
};
#endif  // INCLUDE_TSTACK_H_

// Copyright 2021 NNTU-CS

#include <map>
#include "tstack.h"

int priority(char ch) {
  switch (ch) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
  }
  return -1;
}

bool isDigit(std::string pref) {
  for (size_t a = 0; a < pref.size(); ++a) {
    if (pref[a] < '0' || pref[a] > '9')
      return false;
  }
  return true;
}

std::string infx2pstfx(std::string inf) {
  // добавьте код
  return std::string("");
  TStack <char, 100> itstack;
  std::string res;
  for (size_t a = 0; a < inf.size(); a++) {
    if ((priority(inf[a]) == -1) && (priority(inf[a]) != 1)) {
      if (!res.empty() && priority(inf[a - 1]) != -1) {
        res.push_back(' ');
      }
      res.push_back(inf[a]);
    } else if ((priority(inf[a]) > priority(itstack.get()))
               || (itstack.isEmpty()) || (priority(inf[a]) == 0)) {
      itstack.push(inf[a]);
    } else {
      if (priority(inf[a]) == 1) {
        while (priority(itstack.get()) != 0) {
          res.push_back(' ');
          res.push_back(itstack.get());
          itstack.pop();
        }
        itstack.pop();
      } else {
        while (priority(itstack.get()) >= priority(inf[a])) {
          res.push_back(' ');
          res.push_back(itstack.get());
          itstack.pop();
        }
        itstack.push(inf[a]);
      }
    }
  }
  while (!itstack.isEmpty()) {
    res.push_back(' ');
    if (priority(itstack.get()) != 0) {
      res.push_back(itstack.get());
    }
    itstack.pop();
  }
  return res;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
int eval(std::string post) {
  TStack <int, 100> ptstack;
  std::string temp;
  int op1 = 0;
  int op2 = 0;
  size_t start = 0, end = 0;
  for (size_t a = 0; a < post.size(); ++a) {
    if (post[a] == ' ' || a == post.size()-1) {
      end = a;
      if (a == post.size() - 1)
        end++;
      temp = post.substr(start, end - start);
      start = end + 1;
      if (isDigit(temp)) {
        ptstack.push(std::stoi(temp));
      } else {
        oper2 = ptstack.get();
        ptstack.pop();
        oper1 = ptstack.get();
        ptstack.pop();
        if (temp == "+")
          ptstack.push(oper1 + oper2);
        else if (temp == "-")
          ptstack.push(oper1 - oper2);
        else if (temp == "*")
          ptstack.push(oper1 * oper2);
        else if (temp == "/")
          ptstack.push(oper1 / oper2);
      }
    }
  }
  return ptstack.get();
}

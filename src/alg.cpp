// Copyright 2021 NNTU-CS
#include <map>
#include "tstack.h"

int prior(char total) {
    if (total == '*' || total == '/') {
        return 2;
    } else if (total == '+' || total == '-') {
        return 1;
    } else {
        return 0;
    }
}

std::string infx2pstfx(std::string inf) {
    std::string result = "";
    TStack<char, 100> st;
    for (int a = 0; a < inf.length(); a++) {
        char b = inf[a];
        if (b >= '0' && b <= '9') {
            result += b;
            result += ' ';
        } else if (b == '(') {
            st.push(b);
        } else if (b == ')') {
            while (st.top() != '(') {
                result += st.pop();
                result += ' ';
            }
            st.pop();
        } else {
            while (!st.isEmpty() && prior(b) <= prior(st.top())) {
                result += st.pop();
                result += ' ';
            }
            st.push(b);
        }
    }
    while (!st.isEmpty()) {
        result += st.pop();
        result += ' ';
    }
    result = result.substr(0, result.length() - 1);
    return result;
}

int charConv(char b) {
    switch (b) {
        case '1': return 1; break;
        case '2': return 2; break;
        case '3': return 3; break;
        case '4': return 4; break;
        case '5': return 5; break;
        case '6': return 6; break;
        case '7': return 7; break;
        case '8': return 8; break;
        case '9': return 9; break;
        default: return 0; break;
    }
}

int eval(std::string post) {
    std::string post1 = post;
    int count = 0;
    for (int a = 0; a < post.length(); a++) {
        if (post[a] == ' ') {
            continue;
        } else {
            post1[count] = post[a];
            count++;
        }
    }
    TStack<char, 100> st;
    for (int a = 0; a < post1.length(); a++) {
        char b = post1[a];
        if (b == ' ') {
            break;
        } else if (b >= '0' && b <= '9') {
            st.push(charConv(b));
        } else {
            int num1 = st.pop();
            int num2 = st.pop();
            if (b == '+') {
                st.push(num2 + num1);
            } else if (b == '-') {
                st.push(num2 - num1);
            } else if (b == '/') {
                st.push(num2 / num1);
            } else if (b == '*') {
                st.push(num2 * num1);
            }
        }
    }
    return st.top();
}

//
// Created by Evgeniya Zemlyanaya on 25.05.2022.
//


template <class T> class Stack {
    int top;
    T* st;

public:
    Stack();
    Stack(int);
    void push(T k);
    T pop();
    T peek();
    bool isEmpty();
};


template <class T> Stack<T>::Stack() { top = -1; }

template <class T> Stack<T>::Stack(int n) {
    top = -1;
    st = new T[n];
}

template <class T> void Stack<T>::push(T k) {
    top++;
    st[top] = k;
}

template <class T> bool Stack<T>::isEmpty(){
    return top == -1;
}

template <class T> T Stack<T>::pop() {
    return st[top--];
}

template <class T> T Stack<T>::peek() {
    return st[top];
}


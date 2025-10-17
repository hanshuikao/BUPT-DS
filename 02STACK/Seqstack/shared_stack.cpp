//共享栈————》 一个数组，左部分为栈1，右边为栈2。初始top1 = -1; top2 = size 是为了保证top指向最后一个节点

#include <iostream>
using namespace std;
template <class T>
class SharedStack{
    public:
        SharedStack(int size) : stacksize(size), top1(-1), top2(size) {   // 构造函数时候写SharedStack s(5)
            data = new T[stacksize];    
        }
        ~SharedStack(){
            delete[] data;
        }
        void Push1(T x);   //  左进
        void Push2(T x);
        T Pop1();   //左出
        T Pop2();
        T Get1();
        T Get2();     
        bool Empty1();
        bool Empty2();
        bool full();
    private:
        int stacksize;
        int top1;
        int top2;
        T *data;
};

int main (){
    try{
        SharedStack<int> stack(10);
        stack.Push1(5);
        stack.Push1(4);
        stack.Push1(3);
        stack.Push1(2);
        stack.Push1(1);
        stack.Push2(10);
        stack.Push2(9);
        stack.Push2(8);
        stack.Push2(7);
        stack.Push2(6);
        for (int i = 0; i < 5; i++){
            int e = stack.Pop1();
            cout << e ;
        }
        for (int i = 0; i < 5; i++){
            int e = stack.Pop2();
            cout << e ;
        }
    }
    // 用catch捕获抛出的异常（这里异常是const char*类型的字符串）
    catch (const char* errorMsg) {
        cout << "Error: " << errorMsg << endl;  // 打印异常信息（这里会输出"overflow"）
    }
}

template <class T>
void SharedStack<T> :: Push1(T x){
    if (full()) throw "overflow";
    data[++top1] = x;
}

template <class T>
void SharedStack<T> :: Push2(T x){
    if (full()) throw "overflow";
    data[--top2] = x;
}

template<class T>
T SharedStack<T> :: Get1(){
    if (Empty1()) throw "underflow";
    return data[top1];
}

template <class T>
T SharedStack<T> :: Get2(){
    if (Empty2()) throw "underflow";
    return data[top2];
}

template <class T>
bool SharedStack<T> :: full(){
    if (top1 + 1 == top2)   return true;
    return false;
}

template <class T>
T SharedStack<T> :: Pop1(){
    if (Empty1()) throw "underflow";
        return data[top1--];
}

template <class T>
T SharedStack<T> :: Pop2(){
    if (Empty2()) throw "underflow";  
        return data[top2++];
}

template <class T>
bool SharedStack<T> :: Empty1(){
    if (top1 == -1) return true;
    return false;
}

template <class T>
bool SharedStack<T> :: Empty2(){
    if (top2 == stacksize) return true;
    return false;
}
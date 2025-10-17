#include <iostream>
using namespace std;
const int maxsize = 2;
template <class T>
class SeqStack {   //创建顺序栈
    public:
        SeqStack(){top = -1;}   //表示top指向栈顶元素
        void Push(T x);
        T Pop();
        T GetTop();
        bool isEmpty();
    private:
        T data[maxsize];   //定义数组
        int top;        //定义顶部指针
};

template <class T>
void SeqStack<T> :: Push (T x){
    if (top >= maxsize - 1) throw "overflow";
    data[++top] = x;
}

template <class T>
T SeqStack<T> :: Pop (){
    if (isEmpty())  throw "underflow";
    return data[top--];
}

template <class T>
T SeqStack<T> :: GetTop(){
    if (isEmpty())  throw "underflow";
    return data[top];
}

template <class T>
bool SeqStack<T> :: isEmpty(){
    if (top == - 1) return true;
    else return false;
}

int main(){
    try {
        SeqStack<int> Sqstack_test1;
        Sqstack_test1.Push(10);
        Sqstack_test1.Push(20);
        Sqstack_test1.Push(30);
        int e;
        for (int i = 0; i < 3; i++) {
            e = Sqstack_test1.GetTop();
            Sqstack_test1.Pop();
            cout << e << endl;
        }
    }
    // 用catch捕获抛出的异常（这里异常是const char*类型的字符串）
    catch (const char* errorMsg) {
        cout << "Error: " << errorMsg << endl;  // 打印异常信息（这里会输出"overflow"）
    }
    return 0;
}



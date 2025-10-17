#include <iostream>
using namespace std;
template <class T>
struct LinkStackNode{
    T data;
    struct LinkStackNode<T> *next;
};

template <class T>
class LinkStack{
    public:
        LinkStack(){top = NULL;}
        ~LinkStack();
        void Push(T x);
        T Pop();
        T Get();
        void LinkPrintf(LinkStack &s);    // 用于打印链表
        void Merge(LinkStack &s1, LinkStack &s2); // 合并两个链表
        LinkStackNode<T>* GetTop(LinkStack &s);  // 用于获取对象的指针 
    private:
       LinkStackNode<T> *top;
};

int main(){
    LinkStack<int> ls1;
    LinkStack<int> ls2;
    ls1.Push(1);
    ls1.Push(2);
    ls1.Push(3);
    ls1.Push(4);
    ls2.Push(5);
    ls2.Push(6);
    ls2.Push(7);
    ls2.Push(8);
    //如果下面的print不用&那么，再打印的时候就会浅拷贝一个指针s指向同一个top
    //假设s.top = 0x1200  ls2.top = 0x1200 
    //再printf调用完后会进行s的析构，会按照8 7 6 5 一个一个进行内存释放。
    //此时0x1200位置存储的值已经被释放成随机垃圾数
    ls2.LinkPrintf(ls2);
    ls1.LinkPrintf(ls1);
    cout << endl;
    // LinkStackNode<int> *test = ls1.GetTop(ls1);
    //LinkStackNode<int> *test2 = ls2.GetTop(ls2);
    //cout << "top2:" << test -> data << "   top1:" << test2 -> data << endl;
    cout << "top2:" << ls2.Get() << "   top1:" << ls1.Get() << endl; 
    ls2.Merge(ls1, ls2);    
    ls2.LinkPrintf(ls2);
}
template <class T>
void LinkStack<T> :: Push(T x){
    LinkStackNode<T> *snew = new  LinkStackNode<T>;
    snew -> data = x;
    snew -> next = top;
    this -> top = snew;
}

template <class T>
T LinkStack<T> :: Pop(){
    if (top == NULL)   throw "underflow";
    LinkStackNode<T> *pnew = this -> top;
    this -> top = pnew -> next;
    T e = pnew -> data;
    delete pnew;
    return e;
}

template <class T>
T LinkStack<T> :: Get(){
    if (top == NULL)    throw "underflow";
    return top -> data;
}

template <class T>  // s2的最后一个结点指向top1即可,为了让输出为 8-1 的逆序
void LinkStack<T> :: Merge(LinkStack &s1, LinkStack &s2){
    LinkStackNode<T> *p = s2.top;  // 之前犯了一个错误，就是我这里用的是s2.GetTop(s2) 但观察GetTop会发现他没用&,所以只是传入了复制变量，而没有真正把类似s的整个指针链进行修改
    while(p -> next) {
        p = p -> next;
    }
    p -> next = s1.top;
    // s1.top = NULL;   //以免再调用merge函数的析构函数后我们释放内存的时候。
    // s2和s1会同时释放他们共有的内存，可能导致内存崩溃 
}

template <class T>
LinkStackNode<T>* LinkStack<T> :: GetTop(LinkStack &s){
    LinkStackNode<T> *p = s.top;
    return p;
}

template <class T>
void LinkStack<T> :: LinkPrintf(LinkStack &s){
    LinkStackNode<T> *pnew = s.top;
    while (pnew){
        cout << pnew -> data;
        pnew = pnew -> next;
    }
}

template <class T>
LinkStack<T> :: ~LinkStack(){
    while(top){
        LinkStackNode<T> *t = top;
        top = top -> next;
        delete t;
    }
}
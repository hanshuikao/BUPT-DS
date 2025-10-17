#include <iostream>
using namespace std;

template <class T>
struct LinkQueueNode{
    T data;
    LinkQueueNode<T> *next;
};

template <class T>
class LinkQueue{
    public:
        LinkQueue(){front = rear = new LinkQueueNode<T>;}
        ~LinkQueue();
        void LinkEnqueue(T x);  //进队
        T LinkDequeue();        //出队
        T GetFirst();           //表头元素
        T GetRear();            //队尾元素
        int GetLength();        //队长度
        void LinkQueuePrint();  //打印链队 
        bool Empty();     
    private:
        LinkQueueNode<T> *front;
        LinkQueueNode<T> *rear;
};

int main(){
    LinkQueue<int> q;
    q.LinkEnqueue(1);
    q.LinkEnqueue(2);
    q.LinkEnqueue(3);
    q.LinkEnqueue(4);
    q.LinkEnqueue(5);
    q.LinkEnqueue(6);
    q.LinkEnqueue(7);
    q.LinkEnqueue(8);

    q.LinkQueuePrint();
    cout <<"    length: " << q.GetLength() << "     first: " << q.GetFirst() << "     rear: " << q.GetRear() << endl;
    //12345678      length:8     first:1     rear:8

    cout << "out: "<< q.LinkDequeue() << endl;  //out: 1
    q.LinkEnqueue(9);
    q.LinkQueuePrint();
    cout <<"    length: " << q.GetLength() << "     first: " << q.GetFirst() << "     rear: " << q.GetRear() << endl;
    //23456789      length:8     front:2     rear:9

    LinkQueue<char> q2;
    q2.LinkEnqueue('a');
    q2.LinkEnqueue('b');
    q2.LinkEnqueue('c');
    q2.LinkEnqueue('d');
    q2.LinkEnqueue('e');
    q2.LinkEnqueue('f');
    q2.LinkEnqueue('g');
    q2.LinkEnqueue('h');

    q2.LinkQueuePrint();
    cout <<"    length: " << q2.GetLength() << "     first: " << q2.GetFirst() << "     rear: " << q2.GetRear() << endl;
    //abcdefg      length:8     first:a     rear:h

    cout << "out: "<< q2.LinkDequeue() << endl;  //out: 1
    q2.LinkEnqueue('i');
    q2.LinkQueuePrint();
    cout <<"    length: " << q2.GetLength() << "     first: " << q2.GetFirst() << "     rear: " << q2.GetRear() << endl;
    //bcdefghi      length:8     front:b     rear:i
    
}

template <class T>
LinkQueue<T> :: ~LinkQueue(){
    while (front){
        LinkQueueNode<T> *pnew = front -> next;
        delete front;
        front = pnew;
    }
}

template <class T>
void LinkQueue<T> :: LinkEnqueue(T x){              // 尾插法
    LinkQueueNode<T> * pnew = new LinkQueueNode<T>;
    pnew -> data = x;
    pnew -> next = NULL;
    rear -> next = pnew;
    rear = pnew;
}

template <class T>
T LinkQueue<T> :: LinkDequeue(){
    if (Empty())    throw " underflow";
    LinkQueueNode<T> *pnew = front -> next;
    T e = pnew -> data;
    front -> next = pnew -> next;
    return e;
}

template <class T>
T LinkQueue<T> :: GetFirst(){
    LinkQueueNode<T> *pnew = front -> next;
    return pnew -> data;
}

template <class T>
T LinkQueue<T> :: GetRear(){
    return rear -> data;
}

template <class T>
int LinkQueue<T> :: GetLength(){
    int count = 0;
    LinkQueueNode<T> *tp = front;
    while (tp -> next){
        count++;
        tp = tp -> next;
    }
    return count;
}

template <class T>
void LinkQueue<T> :: LinkQueuePrint(){
    LinkQueueNode<T> *p = front -> next;
    while (p){
        cout << p -> data;
        p = p -> next;
    }
}

template <class T> 
bool LinkQueue<T> :: Empty(){
    if (front == rear)   return true;
    return false;
}


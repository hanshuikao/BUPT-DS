#include <iostream>
using namespace std;
const int maxsize = 8;
template <class T>
class SqQueue{
    public:
        SqQueue(){front = rear = 0;}
        ~SqQueue();
        void EnQueue(T x);          //O(1)      
        T DeQueue();                //O(1)      
        T GetFront();               //O(1)      
        bool Empty();               //O(1)      
        bool Full();                //O(1)      
        int GetLength();            //O(1)      
        void SqQueue_Printf();      //O(N)      
        
        // int rearnumber = rear;
        // int frontnumber = front;
        // 如果想用这个来返回front和rear是不行的，因为他只会再创建对象的时候让他等于front与rear的初始值
        // 后续不再跟随他们变化。所以这里rearnumber和frontnumber永远 = 0；
        int getfrontnumber(){return front;}
        int getrearnumber(){return rear;}
    private:
        T data[maxsize];
        int front;
        int rear;
};
int main (){
    SqQueue<int> q1;
    q1.EnQueue(1);
    q1.EnQueue(2);
    q1.EnQueue(3);
    q1.EnQueue(4);
    q1.EnQueue(5);
    q1.EnQueue(6);
    q1.EnQueue(7);
    q1.SqQueue_Printf();            // 1234567
    cout << "   fontnumber:" << q1.getfrontnumber() << "   rearnumber:" << q1.getrearnumber() << "    length:" << q1.GetLength() << endl;  //rearnumber = 7  队伍长7      
    int outdata = q1.DeQueue();         // 23456
    q1.EnQueue(8);                  //234568
    q1.SqQueue_Printf();
    cout <<  "  the out element:" << outdata << "   fontnumber:" << q1.getfrontnumber() << "   rearnumber:" << q1.getrearnumber() << "  the new length: " << q1.GetLength() << endl;
}

template <class T>
SqQueue<T> :: ~SqQueue(){

}

template <class T>
void SqQueue<T> :: EnQueue(T x){
   if (Full()) throw "overflow";
   data[rear] = x;
   rear = (rear + 1) % maxsize;
}

template <class T>
T SqQueue<T> :: DeQueue(){
    if (Empty())    throw "underflow";
    T e = data[front];
    front = (front + 1) % maxsize;  //保证循环队列
    return e;
}

template <class T>
T SqQueue<T> :: GetFront(){
    if(Empty()) throw "the queue is empty";
    return data[front];
}   

template <class T>
bool SqQueue<T> :: Empty(){
    if (front == rear)  return true;
    return false;
}

template <class T>
int SqQueue<T> :: GetLength(){
    return (rear + maxsize - front) % maxsize;
}

template <class T>
bool SqQueue<T> :: Full(){
    if((rear + maxsize - front) % maxsize == maxsize - 1)
        return true;
    return false;
}

template <class T>
void SqQueue<T> :: SqQueue_Printf(){
    // for (int i = front; i < rear ; i++){
    //     cout << data[i];
    // } 这里做不到循环之后rear < front
    if (front < rear){
        for (int i = front; i < rear; i++){
            cout << data[i];
        }   //  没经历循环
    }else if (front == rear)    throw "underflow";  // 队空
    else {
        for (int i = front; i < rear + maxsize; i++){
            cout << data[i % maxsize];
        }
    }   //循环状态
}
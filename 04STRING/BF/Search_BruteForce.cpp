#include <iostream>
using namespace std;
const int maxsize = 1024;
template <class T>
class SeqString{
    public:
        SeqString(T s[]){
            while (s[len] != '\0')  len++;
            for (int i  = 0; i < len; i++){
                st[i] = s[i];
            }
            st[len] = '\0';
        };
        ~SeqString();
        int Search_BF(SeqString<T> st1, SeqString<T> st2);    // BF算法检测子串,返回完全匹配的第一个位置
        void Print();  // 打印存储的串
    private:
        T st[maxsize];  // 存储串
        int point = 0;      // 存储目标匹配位置
        int len = 0;        // 存储串的长度
}; 


int main(){ 
    char s[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g','\0'};
    char t[4] = {'e', 'f', 'g','\0'};
    char t2[4] = {'a', 'b', 'v','\0'};
    //如果上面不加'\0' 那么就不知道什么时候结束，则len会一直增加知道碰到一个随机的'\0‘才会结束
    SeqString<char> main_S(s);  //主串
    SeqString<char> point_S(t);  //子串
    SeqString<char> point_S2(t2);

    main_S.Print(); 
    cout << "    ";
    point_S.Print();
    cout << "   t to s:" << main_S.Search_BF(main_S, point_S) << endl;
    // abcdefg   efg   to to s:5

    main_S.Print(); 
    cout << "    ";
    point_S2.Print();
    cout << "   t2 to s:" << main_S.Search_BF(main_S, point_S2);
    // abcdefg   abv  t2 to s: -1
}


template <class T>
SeqString<T> :: ~SeqString(){

}

template <class T>
int SeqString<T> :: Search_BF(SeqString<T> st1, SeqString<T> st2){
    while((st2.point < st2.len) && (st1.point < st1.len)){
        if(st1.st[st1.point] == st2.st[st2.point]){
            st1.point++;
            st2.point++;
        }else{
            st1.point = st1.point - st2.point + 1;
            st2.point = 0;
        }
    }
    if(st2.point == st2.len){
        st1.point = st1.point - st2.point;
        return st1.point + 1;   //给用户好的体验，给出的答案是从1开始计数
    }
    if (st1.point == st1.len)  return 4848;
    return -1;
}

template <class T>
void SeqString<T> :: Print(){
    for (int i = 0; i < len; i++){
        cout << st[i];
    }
}
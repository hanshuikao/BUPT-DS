#include <iostream>
using namespace std;
const int maxsize = 1024;

// 递归解决
template <class T>  
class KMP_Recursion{
    public:
        KMP_Recursion(T s[]){                                
            while (s[len] != '\0')  len++;
            for (int i = 0; i < len; i++){
                str[i] = s[i];
            }                                                //传入字符串
        };                                
        ~KMP_Recursion();
        void Print();                                        //打印字符串
        void Plus( KMP_Recursion &MT, KMP_Recursion &S);     //合并模式串T和主串S ： T # S
        void GetNext(KMP_Recursion &TS, int next[]);         //计算合并后每一个位置pi值，存入到next数组
        int counter_Num(int next[16], int Tnum);                       //遍历next。返回完全匹配的起始元素下标  
        // int len_num = len;                    老问题了，这样只会记录len的初始值0后续不会随他改变               //用于记录子串的长度  
        int Getnum(){return len;}                           //用于纠正上面的len_num 恒等于0
    private :
        T str[maxsize];                                      //存储字符串
        int len = 0;                                         //计算长度
        int point;                                           //匹配的位置
};


int main(){
        char s[12] = {'h', 'u', 'a', 'n', 'g', 's', 'h', 'i', 'k', 'a', 'i', '\0'};
        char t[4] = {'s', 'h', 'i','\0'};
        int next[16];
        KMP_Recursion<char> S(s);
        KMP_Recursion<char> T(t);
        int Tnum = T.Getnum();
        cout << "T string:    ";
        T.Print();
        cout <<"    S string:    ";
        S.Print();
        cout << endl;

        T.Plus(T,S);
        cout << "afer merge: ";
        T.Print();
        cout << endl;

        T.GetNext(T, next);
        int num_after = T.Getnum();
        cout << "after num:  ";
        for (int i = 0; i < num_after; i++)    cout << next[i];
        cout << "the counter number is: " << T.counter_Num(next, Tnum) << endl;
}

template <class T>
KMP_Recursion<T> :: ~KMP_Recursion(){} 

template <class T>
void KMP_Recursion<T> :: Print(){                                           //打印字符串
    for (int i = 0; i < len; i++)   cout << str[i];
}     

template <class T>
void KMP_Recursion<T> :: Plus( KMP_Recursion &MT, KMP_Recursion &S){         //合并模式串T和主串S ： T # S
    MT.str[MT.len] = '#';
    for (int i = 0; i < S.len; i++)    MT.str[i + MT.len + 1] = S.str[i];
    MT.len += S.len + 1;
}     

template <class T>
void KMP_Recursion<T> :: GetNext(KMP_Recursion &TS, int next[]){            //计算合并后每一个位置pi值，存入到next数组
    next[0] = 0;
    int temp_len = 0;
    for (int i = 1; i < TS.len; i++){
        while ((temp_len > 0) && (TS.str[i] != TS.str[temp_len])){
            temp_len = next[temp_len - 1];
        }
        if (TS.str[temp_len] == TS.str[i])   temp_len++;
        next[i] = temp_len;
    }
    
}      

template <class T>
int KMP_Recursion<T> :: counter_Num(int next[16], int Tnum){                              //遍历next。返回完全匹配的起始元素下标    
    for (int i = 0; i < 16; i++){
        if (next[i] == Tnum) {
            return (i - Tnum + 1 - Tnum);                                                    // 便于用户观察，所以加1
        }
    }
    return -1;
}         
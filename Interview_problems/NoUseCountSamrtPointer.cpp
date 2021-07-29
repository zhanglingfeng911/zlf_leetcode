//
// Created by zlf on 2021/4/7.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


template<typename T>
class SmartPointer
{
private:
    T *mptr;
public:
    SmartPointer(T* ptr= nullptr):mptr(ptr){}
    ~SmartPointer()
    {
        if (mptr)
        {
            delete mptr;
            mptr= nullptr;
        }
    }
    SmartPointer( SmartPointer<T>&&rhs)
    {
        if (rhs.mptr)
        {
            mptr=rhs.mptr;
            rhs.mptr= nullptr;
        }
    }

    SmartPointer& operator=(SmartPointer<T>&&rhs)
    {
        if (this==&rhs)
        {
            return *this;
        }
        if (rhs.mptr)
        {
            mptr=rhs.mptr;
            rhs.mptr= nullptr;
        }
        return *this;
    }


    T& operator*(){return *mptr;}
    T* operator->(){return mptr;}



};


int main() {

    SmartPointer<int>sp1=new int(2);
    SmartPointer<int>sp2=move(sp1);
    SmartPointer<int>sp3;
    sp3=move(sp2);

    cout<<*sp3<<endl;
//    cout<<*sp1<<endl;
    return 0;
}
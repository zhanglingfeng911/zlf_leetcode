//
// Created by zlf on 2021/4/6.
//

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 50;
const ll mod = 1e9 + 7;


class shared_usecount {
private:
    int use_count;
public:
    shared_usecount(int _count = 1) : use_count(_count) {}

    void addRefCnt() { ++use_count; }

    int delRefCnt() { return --use_count; }

    int get_count() { return use_count; }
};

template<typename T>
class mySamrtPointer {
private:
    T *mptr;
    shared_usecount *m_shared_usecount;
public:
    mySamrtPointer(T *ptr = nullptr) : mptr(ptr) {
        if (ptr) {
            m_shared_usecount = new shared_usecount(1);
        } else {
            m_shared_usecount = new shared_usecount(0);
        }

    }

    ~mySamrtPointer() {
        if (mptr && ((m_shared_usecount->delRefCnt())) == 0) {
            delete mptr;
            mptr = nullptr;
            delete m_shared_usecount;
            m_shared_usecount = nullptr;
            cout << "~desc" << endl;
        }
    }

    mySamrtPointer(const mySamrtPointer<T> &rhs) {
        if (rhs.mptr) {
            mptr = rhs.mptr;
            m_shared_usecount = rhs.m_shared_usecount;
            m_shared_usecount->addRefCnt();
        }
    }

    mySamrtPointer &operator=(const mySamrtPointer<T> &rhs) {
        if (this == &rhs) {
            return *this;
        }
        if (mptr) {
            if (m_shared_usecount->delRefCnt() == 0) {
                delete mptr;
                mptr = nullptr;
                delete m_shared_usecount;
                m_shared_usecount = nullptr;
            }

        }

        mptr = rhs.mptr;
        m_shared_usecount = rhs.m_shared_usecount;
        m_shared_usecount->addRefCnt();
        return *this;
    }

    T *operator->() {
        if (mptr) {
            return mptr;

        }

    }


    T &operator*() {
        if (mptr) {
            return *mptr;

        }
    }

    int getUseCount() {
        if (mptr) {
            return m_shared_usecount->get_count();
        }
    }

};

int main() {
    int *p = new int (2);
    mySamrtPointer<int> sp1(p);
    mySamrtPointer<int> sp2(p);
    cout<<sp1.getUseCount()<<endl;
    cout<<sp2.getUseCount()<<endl;
    return  0;

}

int main01() {

    mySamrtPointer<int> sp1 = new int(1);
    mySamrtPointer<int> sp2(sp1);
    mySamrtPointer<int> sp3;
    sp3 = sp2;
    cout << sp3.getUseCount() << endl;
    *sp3 = 20;
    cout << *sp1 << endl;
    cout << *sp2 << endl;
    return 0;
}
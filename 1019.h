#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

//Student class 實作
class Student
{
public:
    Student();
    Student(int stud_id, const char* stud_name);
    ~Student() {};

    int SetID(int stud_id);
    int SetName(const char* stud_name);
    int GetID();
    char* GetName();
    void Print();

private:
    int ID;
    char* name;
};


//Queue 實作
template<class T>
class Queue
{
public:
    Queue();
    ~Queue();
    Queue(int MaxQueueSize);

    bool IsEmpty();

    T& Front();
    T Rear();
    void Push(T& element);
    void Pop();

private:
    T* queue_elements;
    int front;
    int rear;
    int capacity;
};

template <class T>
inline Queue<T>::Queue()
{
    this->capacity = 3;
    queue_elements = new T[capacity];
    front = 0; //計算Pop次數，以得到front的座標
    rear = -1; //初始化rear指標為-1，表示佇列是空的
}

template <class T>
Queue<T>::Queue(int capacity)
{
    this->capacity = capacity;
    queue_elements = new T[capacity];
    front = 0; //計算Pop次數，以得到front的座標
    rear = -1; //初始化rear指標為-1，表示佇列是空的
}

template <class T>
Queue<T>::~Queue()
{
    delete[] queue_elements; //delete堆疊內存
}

template <class T>
bool Queue<T>::IsEmpty()
{
    if (rear - front == -1) //若成立，代表剛Pop出rear那一格的東西，即empty。
    {
        front = 0;
        rear = -1;
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void Queue<T>::Push(T& element)
{
    if (rear == capacity - 1 && front==0) //若成立，表示rear在最後一格，且front在第一格，佇列已滿
    {
        throw std::runtime_error("佇列已滿，無法推進元素");
    }
    else if (rear == capacity - 1) //若成立，表示rear到底，但front前面還有空。
    {
        for (int i = front;i <= capacity-1;i++) 
        {
            queue_elements[i - front] = queue_elements[i]; //所以要把整個佇列往前移front格
        }
    }
    else
    {
        queue_elements[++rear] = element; //推進元素並更新rear指標
    }
}

template <class T>
void Queue<T>::Pop()
{
    if (IsEmpty()) //若為empty，則在IsEmpty()把front跟rear重製
    {
        throw std::runtime_error("堆疊是空的，無法彈出元素");
    }

    front += 1; //計算Pop次數，同時表示front座標
    cout << "已 Pop 出 Front 之成員!" << endl;
}

template <class T>
T& Queue<T>::Front()
{
    return queue_elements[front];
}

template <class T>
T Queue<T>::Rear()
{
    return queue_elements[rear];
}



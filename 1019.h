#pragma once
#include <iostream>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

//Student class ��@
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


//Queue ��@
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
    front = 0; //�p��Pop���ơA�H�o��front���y��
    rear = -1; //��l��rear���Ь�-1�A��ܦ�C�O�Ū�
}

template <class T>
Queue<T>::Queue(int capacity)
{
    this->capacity = capacity;
    queue_elements = new T[capacity];
    front = 0; //�p��Pop���ơA�H�o��front���y��
    rear = -1; //��l��rear���Ь�-1�A��ܦ�C�O�Ū�
}

template <class T>
Queue<T>::~Queue()
{
    delete[] queue_elements; //delete���|���s
}

template <class T>
bool Queue<T>::IsEmpty()
{
    if (rear - front == -1) //�Y���ߡA�N���Pop�Xrear���@�檺�F��A�Yempty�C
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
    if (rear == capacity - 1 && front==0) //�Y���ߡA���rear�b�̫�@��A�Bfront�b�Ĥ@��A��C�w��
    {
        throw std::runtime_error("��C�w���A�L�k���i����");
    }
    else if (rear == capacity - 1) //�Y���ߡA���rear�쩳�A��front�e���٦��šC
    {
        for (int i = front;i <= capacity-1;i++) 
        {
            queue_elements[i - front] = queue_elements[i]; //�ҥH�n���Ӧ�C���e��front��
        }
    }
    else
    {
        queue_elements[++rear] = element; //���i�����ç�srear����
    }
}

template <class T>
void Queue<T>::Pop()
{
    if (IsEmpty()) //�Y��empty�A�h�bIsEmpty()��front��rear���s
    {
        throw std::runtime_error("���|�O�Ū��A�L�k�u�X����");
    }

    front += 1; //�p��Pop���ơA�P�ɪ��front�y��
    cout << "�w Pop �X Front ������!" << endl;
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



// 1019_11125114.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
using namespace std;
#include"1019.h"

int main()
{
    //Student class 實作
    Student Eric;
    const char* name = "Eric";
    Eric.SetID(11125114);
    Eric.SetName(name);
    int a = Eric.GetID();
    char* b = Eric.GetName();
    cout << a << endl;
    cout << b << endl;
    Eric.Print();

    //create 3 Student class by DMA
    Student* Eric_ck = new Student(11125114, "Eric");
    Student* Liang = new Student(11141346, "Liang");
    Student* Peng = new Student(11225228, "Peng");

    //Queue class 實作 (T = int)
    Queue<int> Number;
    int aa = 1, bb = 2, cc = 3;
    Number.Push(aa); 
    Number.Push(bb);
    Number.Push(cc);
    int front = Number.Front();
    int rear = Number.Rear();
    cout << "front:" << front << endl; 
    cout << "rear:" << rear << endl; 
    Number.Pop(); 
    int new_front= Number.Front();
    cout << "new front:" << new_front << endl; 

    //Queue class 實作 (T = Student, Student 為 class)
    Queue<Student> Student_Queue;
    Student_Queue.Push(*Eric_ck); //Push 3 students
    Student_Queue.Push(*Liang);
    Student_Queue.Push(*Peng);
    cout << "show the front student:" << endl; 
    Student_Queue.Front().Print(); //Show the front student
    cout << "show the rear student:" << endl; 
    Student_Queue.Rear().Print(); //Show the rear student
    Student_Queue.Pop();//Pop
    cout << "show the new front student:" << endl; 
    Student_Queue.Front().Print(); //Show the front student

    return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

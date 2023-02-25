#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Func()
{
    cout << "START FUNC " << this_thread::get_id() << endl;
    for(size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tFunc\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    cout << "END MAIN " << this_thread::get_id() << endl;
}

void FuncWithParams(int t1, int t2)
{
    cout << "START FUNC WITH PARAMS " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(t1));
    for(size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tFunc\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    this_thread::sleep_for(chrono::milliseconds(t2));
    cout << "END FUNC WITH PARAMS " << this_thread::get_id() << endl;
}


int main()
{
    setlocale(LC_ALL, "ru");

    cout << "START MAIN" << endl;

    thread th1(Func);
    thread th2(FuncWithParams, 1000, 2000);
    thread th3(FuncWithParams, 1000, 1500);

    for (size_t i=0; i<10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "END MAIN" << endl;
    th1.join();
    th2.join();
    th3.join(); 
    return 0;
}
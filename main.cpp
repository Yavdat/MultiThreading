#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Func()
{
    for(size_t i = 0; i < 10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tFunc\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    cout << "START MAIN" << endl;

    thread th1(Func);
    thread th2(Func);
    thread th3(Func);

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
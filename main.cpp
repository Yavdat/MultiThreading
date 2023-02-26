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

void FuncWithRefParam(int &num)
{
    cout << "START FUNC WITH REF PARAM " << this_thread::get_id() << endl;

    for(size_t i = 0; i < 10; i++)
    {
        num = num + i;
        cout << "ID потока = " << this_thread::get_id() << "\tFunc\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
    }
    this_thread::sleep_for(chrono::milliseconds(4000));
    cout << "END FUNC WITH REF PARAM  " << this_thread::get_id() << endl;
}

int FuncWithReturningValue(int num)
{
    int result;
    cout << "START FUNC WITH RETURNING VALUE " << this_thread::get_id() << endl;

    num = num * 2;
    cout << "ID потока = " << this_thread::get_id() << "\tFunc\t" << "numX2 = " << num << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));

    cout << "START FUNC WITH RETURNING VALUE " << this_thread::get_id() << endl;
    return num;
}

class MyClass
{
private:
    /* data */
public:
    MyClass(/* args */);
    ~MyClass();

    void Work()
    {
        cout << "START FUNC WORK " << this_thread::get_id() << endl;

        cout << "ID потока = " << this_thread::get_id() << "\tFunc\t" << "WORK " << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));

        cout << "END FUNC WORK " << this_thread::get_id() << endl;
    }

    void WorkWithPar1(string par1)
    {
        cout << "START FUNC WorkWithPar1 " << this_thread::get_id() << endl;

        cout << "ID потока = " << this_thread::get_id() << "\tFunc\t" << "WORK with par1=" << par1 << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));

        cout << "END FUNC WorkWithPar1 " << this_thread::get_id() << endl;
    }

    int WorkWithPar1AndRetVal(int par1)
    {
        cout << "START FUNC WORK with returning VAL" << this_thread::get_id() << endl;
        
        cout << "ID потока = " << this_thread::get_id() << "\tFunc\t" << "WORK with par1=" << par1 << " and Return par1 * 2 = " << par1*2 << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));

        par1 = par1 * 2;

        cout << "END FUNC WORK with returning VAL " << this_thread::get_id() << endl;
        return par1;
    }
};

MyClass::MyClass(/* args */)
{
}

MyClass::~MyClass()
{
}



int main()
{
    setlocale(LC_ALL, "ru");

    cout << "START MAIN" << endl;

    int num = 5;

    int result;

    // thread th1(Func);
    // thread th2(FuncWithParams, 1000, 2000);
    // thread th3(FuncWithRefParam, std::ref(num));
    // thread th4([&result](){result = FuncWithReturningValue(10);});
    
    MyClass m;
    string par1 = "params";
    int par2 = 5; 
    thread th5([&](){m.Work();});
    thread th6(&MyClass::WorkWithPar1, m, par1);
    thread th7([&](){result = m.WorkWithPar1AndRetVal(par2);});
    

    for (size_t i=0; i<10; i++)
    {
        cout << "ID потока = " << this_thread::get_id() << "\tmain\t" << i << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "END MAIN" << endl;
    // th1.join();
    // th2.join();
    // th3.join(); 
    // th4.join();
    th5.join();
    th6.join();
    th7.join();
    cout << "NUM = " << num << endl;
    return 0;
}
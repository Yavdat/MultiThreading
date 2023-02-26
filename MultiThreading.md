## MultiThreading C++
### Объект thread
>thread th(Func); - вызываем функцию в отдельном потоке  
th.detach(); - отвязываем отдельный поток от главного потока  
th.join(); - привязываем, и теперь главный поток будет дожидаться завершения дочернего потока  

### Передача данных через параметры функции потоку
>void FuncWithParams(int par1, int par2)  
thread th(FuncWithParams, par1, par2)

### Передача и возврат результата из потока с помощью ссылки
>void FuncWithRefParam(int &refPar)  
thread th(FuncWithRefParam, std::ref(num)) - без использования std::ref возникнет ошибка

### Использование анонимной функции и возврат результата из потока
>int FuncWithReturningValue(int num)  
int result;   
thread th4([&result](){result = FuncWithReturningValue(10);});

### Потоки и методы класса
>MyClass m;  
string par1 = "params";  
int par2 = 5;
int result;    
thread th5([&](){m.Work();});  
thread th6(&MyClass::WorkWithPar1, m, par1);  
thread th7([&](){result = m.WorkWithPar1AndRetVal(par2);});  

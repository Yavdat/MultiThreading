## MultiThreading C++
### Объект thread
thread th(Func); - вызываем функцию в отдельном потоке  
th.detach(); - отвязываем отдельный поток от главного потока  
th.join(); - привязываем, и теперь главный поток будет дожидаться завершения дочернего потока  

### Передача данных через параметры функции потоку
void FuncWithParams(int par1, int par2)  
thread th(FuncWithParams, par1, par2)

### Передача и возврат результата из потока с помощью ссылки
void FuncWithRefParam(int &refPar)  
thread th(FuncWithRefParam, std::ref(num)) - без использования std::ref возникнет ошибка




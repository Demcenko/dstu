#include <QCoreApplication>
#include <iostream> // для можливості виводу повідомлень в консоль - cout

#include <deque> //двостороння черга (послідовний контейнер)
#include <queue> //звичайна черга
#include <stack> //стек
using namespace std; //стандартна бібліотека шаблонів 

// 1. Перебір елементів двосторонньої черги за допомогою ітераторів 
void DEQUE()
{
    deque<int>d; //оголошення двосторонньої черги, де типи елементів - int
    deque<int>::iterator it1; //оголошення ітератора для двосторонньої черги
    deque<int>::reverse_iterator it2; // оголошення ітератора з зворотньою напрямком для двосторонньої черги 
    for(int i=1; i<=10; ++i)
    {
        d.push_back(i); //додавання елементів в кінець черги (елементи від 1 до 10)
    }
    it1=d.begin(); //повертає ітератор, який встановлено на перший елемент черги
    *it1=800; //заміна значення першого елемента черги на 800 (було значення 1, яке ми записали через for)

    //перебір елементів черги з початку до кінця (в прямому порядку)
    for (it1=d.begin();it1!=d.end(); ++it1)
    {
        //виведення значення елемента через ітератор за допомогою оператора виводу cout
        cout<<*it1<<endl;
    }
    cout<<"------------------------"<<endl;
    //перебір елементів черги з кінця до початку (в зворотньому порядку)
    for (it2=d.rbegin(); it2!=d.rend(); ++it2)
    {
        // d.rend() - повертає ітератор, який встановлено на останній елемент черги (позиція перед першим елементом)
        cout<<*it2<<endl;
    }

}

// 2. Списки та їх сортування
void LIST()
{
    list<int> L; //оголошення списку, де типи елементів - int
    list<int>::const_iterator i; //оголошення ітератора для списку
    L.push_back(5); //додавання елементів в кінець списку
    L.push_back(2); 
    L.push_back(4);

    L.sort(); //сортування списку за зростанням значень елементів
    for (i=L.begin(); i!=L.end(); ++i)
        //L.begin() - повертає ітератор, який встановлено на перший елемент списку
        //L.end() - повертає ітератор, який встановлено на останній елемент списку
        cout<<*i<<" ";	// виведення значень елементів списку за допомогою оператора виводу cout (було значення 5, 2, 4, а результатом сортування буде значення 2, 4, 5)
    cout<<endl; //перехід на новий рядок
    cout<<"------------------------------"<<endl;
    L.sort(::greater<int>()); //сортування списку за спаданням значень елементів 
    for(i=L.begin(); i!=L.end(); ++i)
        cout<<*i<<" ";	// виведення значень елементів списку за допомогою оператора виводу cout (було значення 2, 4, 5, а результатом сортування буде значення 2, 4, 5)
    cout<<endl;
}

// 3. Вектори та доступ до елементів в них через вказівники ("указатели")
void VECTOR()
{
    vector<int> v; //оголошення вектора, де типи елементів - int
    vector<int>::pointer p; //оголошення вказівника для вектора. Можна і отримати значення (зчитати його), і зманити значення
    vector<int>::const_pointer cp; //оголошення константного вказівника для вектора. Можна тільки отримати значення (зчитати його)
    v.reserve(10); //резервування пам'яті для вектора за допомогою оператора reserve
    for (int i=1; i<=10; ++i)
    {
        v.push_back(i); //додавання елементів в кінець вектора
    }
    p=v.data(); //повертає адресу першого елемента вектора у звичайний вказівник
    *p=800; //зміна значення першого елемента вектора
    cp=v.data(); //повертає адресу першого елемента вектора у константний вказівник
    for (int j=0, c=v.size(); j<c; ++j,++cp)
    //v.size() - повертає кількість елементів в векторі
    cout<<*cp<<" "; //виводимо результат у консоль - 800 2 3 4 5 6 7 8 9 10
    cout<<endl;
}

// 4. Черга з пріорітетом
void PRIORITY_QUEUE()
{
    priority_queue<int> q1, q2; //оголошення двох черг з пріорітетом
    q1.push(1); q1.push(2); //додавання елементів в чергу (в кінець)
    q2.push(3); q2.push(4);

    cout<<q1.top()<<endl;  //top() - повертає значення елемента черги з найбільшим пріорітетом (найбільше значення). У першій черзі виведеться 2
    cout<<q2.top()<<endl; //Найбільший пріорітет другої черги - виведеться 4
    q1.swap(q2); //перестановка черг місцями (у першу чергу записуються елементи другої черги, а у другу чергу - елементи першої)
    cout<<q1.top()<<endl; //Найбільший пріорітет першої черги - виведеться 4
    cout<<q2.top()<<endl; //Найбільший пріорітет другої черги - виведеться 2
    q1.pop(); //pop() - видалення елемента з найбільшим пріорітетом (найбільше значення). Тобто з першої черги видаляється елемент 4
    cout<<q1.top()<<endl; //тепер найбільший пріорітет першої черги - виведеться 3
    if(q1.empty()) //empty() - повертає true, якщо черга порожня
    {
        cout<<"priority_queue is empty"<<endl;
    }
    else
    {
        cout<<q1.size()<<endl; //1
        //size() - повертає кількість елементів в черзі
    }
}

// 5. Звичайна черга
void QUEUE()
{
    queue<int> q1, q2; //оголошення двох черг
    q1.push(1); q1.push(2); //додавання елементів в чергу (в кінець)
    q2.push(3); q2.push(4);

    cout<<q1.front()<<endl;  //front() - повертає значення першого елемента черги
    cout<<q2.front()<<endl;	
    q1.swap(q2); //перестановка черг місцями (у першу чергу записуються елементи другої черги, а у другу чергу - елементи першої)
    cout<<q1.front()<<endl; //3
    cout<<q2.front()<<endl; //1
    q1.pop(); //pop() - видалення першого елемента черги
    cout<<q1.front()<<endl;	//4
    if(q1.empty()) //empty() - повертає true, якщо черга порожня
    {
        cout<<"queue is empty"<<endl;
    }
    else
    {
        cout<<q1.size()<<endl;	//1
        //size() - повертає кількість елементів в черзі
    }
}

// 6. Стек
void STACK()
{
    stack<int> s1, s2; //оголошення двох стеків
    s1.push(1); s1.push(2); //додавання елементів в стек (у стеках записуються елементи з кінця в початок, тобто в результаті виведення елементів ми побачимо 2, 1, а не 1, 2)
    s2.push(3); s2.push(4);

    cout<<s1.top()<<endl;  //top() - посилання на едемент, який знаходиться у вершині стеку, тобто лежить першим, але був покладений останнім. У першому стеку виведеться 2
    cout<<s2.top()<<endl; // аналогічний елемент другого стеку - виведеться 4 - його поклали останнім, він є вершиною стеку, першим елементом 
    s1.swap(s2); //перестановка стеків місцями 
    cout<<s1.top()<<endl; // вершина першого стеку - виведеться 4
    if(s1.empty()) //empty() - повертає true, якщо стек порожній
    {
        cout<<"stack is empty"<<endl;
    }
    else
    {
        cout<<s1.size()<<endl;	//1
        //size() - повертає кількість елементів в черзі
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // виклик створених функцій по черзі (можна закоментувати, щоб було зручніше, та викликати по одній функції)
//    DEQUE();
//    LIST();
//    VECTOR();
//    PRIORITY_QUEUE();
//    QUEUE();
    STACK();

    return a.exec();
}






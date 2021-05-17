/* 17. На основі контейнера vector побудувати стеки цілих чисел та символьних рядків. 
Виконати операції занесення елемента у стек, вилучення значення з вершини стеку,
виведення усіх значень стеку на екран, визначення кількості елементів стеку. */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
class STACK {
private:
    vector<T> stack; 

public:
    void push(T item)
    {
        stack.insert(stack.begin(), item);
    }
    void delet()
    {
        stack.erase(stack.begin());
    }
    int count()
    {
        if (stack.empty())
            cout << endl << "Stack is empty.";
        else
            return stack.size();
    }
    void Print()
    {
        cout << "Stack: " << endl;
        if (stack.size() == 0)
            cout << "is empty." << endl;

        for (int i = 0; i < stack.size(); i++)
        {
            cout << "Item[" << i << "] = " << stack[i] << endl;
        }
        cout << endl;
    }
    ~STACK()
    {
        stack.clear();
    }

    friend ifstream& operator >>(ifstream& input, STACK& st)
    {
        int size;
        input >> size;
        T item;
        for (int i = 0; i < size; i++)
        {
            input >> item;
            st.push(item);
        }
        return input;
    }

    friend ofstream& operator <<(ofstream& output, STACK& st)
    {
        int size = st.stack.size();
        output << size << endl;
        for (int i = 0; i < size; i++)
            output << st.stack[i] << endl;
        return output;
    }
};

int main(void)
{
    STACK <int> chysl;
    STACK <string> sentence;
    int x;
    string p;
    string type;
    for (int i = 0; i < 100; i++)
    {
        cout << "\t" << "Enter item: ";
        cin >> x;
        if (x == 0)
            break;
        chysl.push(x);
    }
    chysl.Print();
    cout << "Count: " << chysl.count() << endl;
    chysl.delet();
    cout << endl << "int data after deleting the first item:" << endl;
    chysl.Print();
    chysl.~STACK();
    for (int i = 0; i < 100; i++)
    {
        cout << "\t" << "Enter item: ";
        cin >> p;
        if (p[0] == '\\')
            break;
        sentence.push(p);
    }
    sentence.Print();
    cout << "Count: " << sentence.count() << endl;
    sentence.delet();
    cout << endl << "string data after deleting the first item:" << endl;
    sentence.Print();
    sentence.~STACK();
    
    STACK <int> chysl_f;
    ifstream inf("D:\\Data int.txt");
    inf >> chysl_f;
    chysl_f.Print();
    cout << "Count: " << chysl_f.count() << endl;
    chysl_f.delet();
    cout << endl << "int data after deleting the first item:" << endl;
    chysl_f.Print();
    chysl_f.~STACK();

    /*ofstream outf("D:\\Data int.txt");
    outf << endl << "int data after deleting the first item:";
    chysl_f.delet();
    outf << chysl_f;*/
    system("pause");
    return 0;
} 
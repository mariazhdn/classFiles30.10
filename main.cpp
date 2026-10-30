#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    fstream inout("Text.txt", ios::in | ios::out | ios::app); // app - до запись
        
    char buff[100];
    cin.getline(buff, 100);

    inout << buff << endl;

    inout.seekg(0, ios::beg); // begin - на начало перемещаем

    char read[100];
    while (!inout.eof()) // пока не достишнет конца файла
    {
        inout.getline(read, 100);
        cout << read << endl;
    }

    inout.close();
}
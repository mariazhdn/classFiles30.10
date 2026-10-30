#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file("Text.txt", ios::in | ios::out);

    if (!file.is_open())
    {
        cout << "Error! File could not be opened!" << endl;
        return 1;
    }

    int lineCount = 0;
    int wordCount = 0;
    char buff[256];

    file.seekg(0, ios::beg);

    while (!file.eof())
    {
        file.getline(buff, 256);

        lineCount++;

        bool inWord = false;
        for (int i = 0; buff[i] != '\0'; i++)
        {
            if (buff[i] != ' ')
            {
                if (!inWord)
                {
                    inWord = true;
                    wordCount++;
                }
            }
            else
            {
                inWord = false;
            }
        }

        if (file.eof()) { break; }
    }

    cout << "Total lines: " << lineCount << endl;
    cout << "Total words: " << wordCount << endl;

    file.close();

    return 0;
}
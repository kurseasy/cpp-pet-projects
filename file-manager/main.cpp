#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string filename = "output.txt";
    string text;

    cout << "Введите текст для записи в файл: ";
    getline(cin, text);

    // Запись в файл
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << text;
        outFile.close();
        cout << "Текст сохранён в " << filename << endl;
    } else {
        cout << "Ошибка открытия файла для записи.\n";
        return 1;
    }

    // Чтение из файла
    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        cout << "Прочитано из файла:\n";
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Ошибка открытия файла для чтения.\n";
    }

    return 0;
}

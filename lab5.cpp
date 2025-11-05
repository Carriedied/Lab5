#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <random>
#include <sstream>

using namespace std;

bool Palindrom(const string& s);
bool IsValidPassword(const string& password);
int StringLength(const char* str);
string EncryptDecrypt(const string& text, int n);
void GenerateRandomNames(int count);
void SearchEngine();
void RunTask1();
void RunTask2();
void RunTask3();
void RunTask4();
void RunTask5();
void RunTask6();

int main()
{
    setlocale(LC_ALL, "rus");

    int choice;

    while (true) 
    {
        cout << "\n=== Меню заданий ===" << endl;
        cout << "1. Проверка на палиндром" << endl;
        cout << "2. Проверка пароля" << endl;
        cout << "3. Вычисление длины строки" << endl;
        cout << "4. Шифровка/дешифровка" << endl;
        cout << "5. Случайные имена и фамилии" << endl;
        cout << "6. Поисковая система" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите задание (0-6): ";
        cin >> choice;

        cin.ignore();

        switch (choice) 
        {
            case 1:
                RunTask1();
                break;

            case 2:
                RunTask2();
                break;

            case 3:
                RunTask3();
                break;

            case 4:
                RunTask4();
                break;

            case 5:
                RunTask5();
                break;

            case 6:
                RunTask6();
                break;

            case 0:
                cout << "Выход из программы." << endl;
                return 0;

            default:
                cout << "Неверный выбор. Пожалуйста, введите число от 0 до 6." << endl;
        }
    }

    return 0;
}

void RunTask1() 
{
    cout << "\n=== Задание 1: Проверка на палиндром ===" << endl;

    cout << "Введите строку: ";

    string input;

    getline(cin, input);

    if (Palindrom(input)) 
    {
        cout << "Строка \"" << input << "\" является палиндромом." << endl;
    }
    else 
    {
        cout << "Строка \"" << input << "\" не является палиндромом." << endl;
    }
}

void RunTask2() 
{
    cout << "\n=== Задание 2: Проверка пароля ===" << endl;

    cout << "Введите пароль: ";

    string password;

    getline(cin, password);

    if (IsValidPassword(password)) 
    {
        cout << "Пароль \"" << password << "\" корректен!" << endl;
    }
    else 
    {
        cout << "Пароль \"" << password << "\" не соответствует требованиям." << endl;
    }
}

void RunTask3() 
{
    cout << "\n=== Задание 3: Вычисление длины строки ===" << endl;

    cout << "Введите строку: ";

    string input;

    getline(cin, input);

    const char* cstr = input.c_str();

    int length = StringLength(cstr);

    cout << "Длина строки \"" << input << "\" равна " << length << "." << endl;
}

void RunTask4() 
{
    cout << "\n=== Задание 4: Шифровка/дешифровка ===" << endl;

    cout << "Введите текст: ";

    string text;

    getline(cin, text);

    int shift;

    cout << "Введите сдвиг (целое число): ";
    cin >> shift;

    string encrypted = EncryptDecrypt(text, shift);

    cout << "Результат: " << encrypted << endl;
}

void RunTask5() 
{
    cout << "\n=== Задание 5: Случайные имена и фамилии ===" << endl;

    int count;

    cout << "Введите количество людей для генерации: ";
    cin >> count;

    if (count <= 0) 
    {
        cout << "Количество должно быть положительным числом." << endl;

        return;
    }

    GenerateRandomNames(count);
}

void RunTask6() 
{
    cout << "\n=== Задание 6: Поисковая система ===" << endl;

    SearchEngine();
}

bool Palindrom(const string& s) 
{
    string cleanStr = "";

    for (char c : s) 
    {
        if (isalpha(c)) 
        {
            cleanStr += tolower(c);
        }
    }

    string reversedStr = cleanStr;

    reverse(reversedStr.begin(), reversedStr.end());

    return cleanStr == reversedStr;
}

bool IsValidPassword(const string& password) 
{
    int n = password.length(), minLengthPass = 8, maxLengthPass = 14, countTypes = 3;

    if (n < minLengthPass || n > maxLengthPass)
    {
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasOther = false;

    for (char c : password) 
    {
        int code = static_cast<int>(c);

        if (code < 33 || code > 126) 
        {
            return false;
        }

        if (c >= 'A' && c <= 'Z') 
        {
            hasUpper = true;
        }
        else if (c >= 'a' && c <= 'z') 
        {
            hasLower = true;
        }
        else if (c >= '0' && c <= '9') 
        {
            hasDigit = true;
        }
        else 
        {
            hasOther = true;
        }
    }

    int count = 0;

    if (hasUpper) 
        count++;

    if (hasLower) 
        count++;

    if (hasDigit) 
        count++;

    if (hasOther) 
        count++;

    return count >= countTypes;
}

int StringLength(const char* str) 
{
    int length = 0;

    while (str[length] != '\0') 
    {
        length++;
    }

    return length;
}

string EncryptDecrypt(const string& text, int n) 
{
    string result = "";

    for (char c : text) 
    {
        if (c >= 'a' && c <= 'z') 
        {
            int shifted = (c - 'a' + n) % 26;

            if (shifted < 0) 
                shifted += 26;

            result += static_cast<char>('a' + shifted);
        }
        else if (c >= 'A' && c <= 'Z') 
        {
            int shifted = (c - 'A' + n) % 26;

            if (shifted < 0)
                shifted += 26;

            result += static_cast<char>('A' + shifted);
        }
        else 
        {
            result += c;
        }
    }
    return result;
}

void GenerateRandomNames(int count) 
{
    vector<string> names = { "Александр", "Мария", "Иван", "Елена", "Дмитрий", "Анна", "Сергей", "Ольга", "Андрей", "Наталья" };
    vector<string> surnames = { "Иванов", "Петров", "Сидоров", "Козлов", "Волков", "Смирнов", "Попов", "Лебедев", "Новиков", "Морозов" };

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> nameDist(0, names.size() - 1);
    uniform_int_distribution<> surnameDist(0, surnames.size() - 1);

    cout << "Сгенерированные имена и фамилии:" << endl;

    for (int i = 0; i < count; ++i) 
    {
        string randomName = names[nameDist(gen)];
        string randomSurname = surnames[surnameDist(gen)];

        cout << randomName << " " << randomSurname << endl;
    }
}

void SearchEngine() 
{
    int n;

    cout << "Введите количество строк: ";
    cin >> n;

    cin.ignore();

    if (n <= 0) 
    {
        cout << "Количество строк должно быть положительным." << endl;
        return;
    }

    vector<string> data(n);

    cout << "Введите строки:" << endl;

    for (int i = 0; i < n; ++i) 
    {
        getline(cin, data[i]);
    }

    string query;

    cout << "Введите поисковый запрос: ";

    getline(cin, query);

    cout << "\nРезультаты поиска:" << endl;

    bool found = false;

    for (const string& line : data) 
    {
        if (line.find(query) != string::npos) 
        {
            cout << line << endl;
            found = true;
        }
    }

    if (!found) 
    {
        cout << "Совпадений не найдено." << endl;
    }
}

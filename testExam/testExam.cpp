#include <iostream>
#include <string>
#include <fstream>

#define num 13




using namespace std;

void findString(string str, string word) {
    int size = str.length();
    int size2 = word.length();
    bool flag;
    for (int i = 0; i < size; i++) {
        flag = true;
        if (str[i] == word[0]) {
            for (int j = 0; j < size2; j++) {
                cout << str[i + j] << endl;
                if (word[j] != str[i + j]) {
                    flag = false;
                    break;
                }
            }
            if (flag == true) break;
            
        }
    }
    if (flag) cout << "YES";
    else cout << "NO";
}

void isNum(int* array, int number) {
    int size;
    size = _msize(array) / sizeof(array[0]); // ?
    bool flag = false;
    for (int i = 0; i < size; i++) {
        if (array[i] == number) flag = true;
        break;
            
        
    }
    if (flag) cout << "Num is in array" << endl;
    else cout << "Num isn't in array" << endl;
}

int* chet(int* array) {
    int size;
    size = _msize(array) / sizeof(array[0]); // ?
    int* buf = new int[size];
    int c = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) buf[c++] = array[i];
    }
    return buf;
    
}

void delElem(int* &array, int index) {
    int size;
    size = _msize(array) / sizeof(array[0]);
    int* buf = new int[size - 1];
    for (int i = 0; i < index; i++) {
        buf[i] = array[i];
    }

    for (int i = 0; i < index; i++) {
        buf[i] = array[i];
    }
    for (int i = index + 1; i < size; i++) {
        buf[i - 1] = array[i];
    }
    delete[] array;
    array = buf;
}

void delElem(int**& array, int index) {
    int size1 = _msize(array) / sizeof(array[0]);
    int** buf = new int*[size1 - 1];

    for (int i = 0; i < index; i++) {
        buf[i] = array[i];
    }

    for (int i = 0; i < index; i++) {
            buf[i] = array[i];
    }

    for (int i = index + 1; i < size1; i++) {
            buf[i - 1] = array[i];

    }

    delete[] array[index];
    delete[] array;
    array = buf;
}

void showArray(int* array) {
    int size;
    size = _msize(array) / sizeof(array[0]);
    for (int i = 0; i < size; i++) cout << array[i] << " ";
}

void showArray(int** array) {
    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            cout << array[i][j] << "  ";

        }
        cout << endl;
    }
}

int main()
{
#if num == 1
    // 1
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a >= b && a >= c && a >= d) cout << a;
    else if (b >= a && b >= c && b >= d) cout << b;
    else if (c >= a && c >= b && c >= d) cout << c;
    else cout << d;
#elif num == 2

    // 2
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    for (int i = a; i >= b; i--) cout << i << " ";
#elif num == 3
    // 3
    int size;
    int num = 5;
    cin >> size;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << num++ << "  ";
        }
        cout << endl;
    }
#elif num == 4

    // 4
    char s;
    cin >> s;
    if (65 <= s && s <= 90) cout << "Данный символ заглавная латинская группа. (YES)" << endl;
    else cout << "Данный символ не заглавная латинская группа. (NO)" << endl;

#elif num == 5
    // 5
    int array[8];
    for (int i = 0; i < 8; i++) array[i] = i;

    for (int i = 0; i < 8; i++) cout << array[i] << " ";

#elif num == 67

    //6 7
    srand(time(NULL));
    int const size = 2;
    int max, min;

    cin >> max >> min;
    int array[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i][j] = min + rand() % max - min + 1;
        }
    }


    float sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << array[i][j] << "  ";
            sum += array[i][j];
        }
        cout << endl;
    }

    cout << sum / (size * size) << endl;
     
    int maxNum = array[0][0];
    int minNum = array[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] > maxNum) maxNum = array[i][j];
            if (array[i][j] < minNum) minNum = array[i][j];
        }
    }
    cout << "Max - " << maxNum << "  " << "Min - " << minNum << endl;

#elif num == 8
    
    //8
    int* array = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int num;
    cin >> num;
    isNum(array, num);
#elif num == 9
    //9
    int* array = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    chet(array);
#elif num == 10
    //10
    int* array = new int[10]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    showArray(array);
    cout << endl;
    int index;
    cin >> index;
    delElem(array, index - 1);
    showArray(array);
#elif num == 11
    //11
    int** array = new int*[3];
    int index;
    for (int i = 0; i < 3; i++) {
        array[i] = new int[3]{};
    }
    showArray(array);
    cin >> index;
    delElem(array, index - 1);
    showArray(array);
    
#elif num == 12
    //12
    ifstream in("text.txt");
    string str;
    int numString;
    cin >> numString;
    int nums = 0;
    if (in.is_open()) {
        while (getline(in, str)) {
            if (nums++ == numString - 1) {
                cout << str << endl;
                break;
            }
        }
    }
    else cout << "Ошибка" << endl;
    in.close();

#elif num == 13
    //13
    string str = "Hello, what's your name?";
    string word;
    cin >> word;
    findString(str, word);
    
    

#endif
}

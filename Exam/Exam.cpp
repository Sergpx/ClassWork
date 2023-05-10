#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

#define random(min, max) min + rand() % (max - min + 1); 

#define task 6

using namespace std;

int fileCounter(string path);
int** createArray(int size1, int size2);
void showArray(int** array);
void delRow(int**& array, int index);
void arrayUnion(int**& array1, int* array2, int index);
void showArray(int* array);
void delElem(int*& array, int index);
void delElem(int**& array, int index);
void delMinElem(int**& array);
int findWord(string text, string word);
int fileCounter(string path);



void copy(int**& array1, int**& array2) {
    int size1 = _msize(array1) / sizeof(array1[0]);
    int size2 = _msize(array1[0]) / sizeof(array1[0][0]);
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            array2[i][j] = array1[i][j];
        }
    }
}

int** createArray(int size1, int size2) {
    int** array = new int* [size1];
    for (int i = 0; i < size1; i++) {
        array[i] = new int[size2];
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            array[i][j] = random(1, 9);
        }
    }
    return array;
}

void showArray(int** array) {
    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void delRow(int** &array, int index) {
    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);
    int** buf = new int*[size2];
    for (int i = 0; i < size1; i++) {
        buf[i] = new int[size2-1];
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < index; j++) buf[i][j] = array[i][j];
        for (int j = index + 1; j < size2; j++) buf[i][j - 1] = array[i][j];
    }

    delete[] array;
    array = buf;
}

void arrayUnion(int**& array1, int* array2, int index) {
    int size1 = _msize(array1) / sizeof(array1[0]);
    int size2 = _msize(array1[0]) / sizeof(array1[0][0]);
    int size3 = _msize(array2) / sizeof(array2[0]);
    if (index >= size1) cout << "Error" << endl;
    else {
        int** buf = new int* [size1 + 1];
        for (int i = 0; i < index; i++) {
            buf[i] = array1[i];
        }
        buf[index] = array2;
        for (int i = index + 1; i < size1 + 1; i++) {
            buf[i] = array1[i - 1];
        }
        delete[] array1;
        array1 = buf;
    }
    
}

void showArray(int* array) {
    int size1 = _msize(array) / sizeof(array[0]);
    for (int i = 0; i < size1; i++) {
        cout << array[i] << " ";
    }
}

void delElem(int* &array, int index) {
    int size1 = _msize(array) / sizeof(array[0]);
    int* buf = new int[size1 - 1];
    for (int i = 0; i < index; i++) {
        buf[i] = array[i];
    }
    for (int i = index + 1; i < size1; i++) {
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
    for (int i = index + 1; i < size1; i++) {
        buf[i - 1] = array[i];
    }

    delete[] array;
    array = buf;
}

void delMinElem(int**& array) {
    int size1 = _msize(array) / sizeof(array[0]);
    int size2 = _msize(array[0]) / sizeof(array[0][0]);
    int min = array[0][0];
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (array[i][j] < min) min = array[i][j];
        }
    }
    int index;
    for (int i = 0, flag; i < size1; i++) {
        flag = true;
        for (int j = 0; j < size2; j++) {
            if (array[i][j] == min) {
                index = i;
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    delElem(array, index);



}

int findWord(string text, string word) {
    for (int i = 0, flag; i < text.length(); i++) {
        if (text[i] == word[0]){
            flag = true;
            for (int j = 0; j < word.length(); j++) {
                if (word[j] != text[i + j]) {
                    flag = false;
                    break;
                }
                
            }
            if (flag) return i;
        }
    }
    return -1;
}


int fileCounter(string path) {
    fstream in(path);
    int count = 0;
    if (in.is_open()) {
        string str;
        while (getline(in, str)) {
            count += str.length();
        }
        in.close();
        return count;
    }
    else cout << "Не удалось открыть файл" << endl;
    return count; // можно -1


}

int main()
{
    setlocale(LC_ALL, "RU_ru");
    srand(time(NULL));

#if task == 1:
    float a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a + b + c + d) / 4;

#elif task == 2:

    for (int i = 0; i <= 40; i+=2) {
        cout << i << " ";
    }

#elif task == 3:
    int n;
    cout << "Укажите размер: ";
    cin >> n;
    if (n <= 0) cout << "Размер должен быть больше 0";
    else {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
#elif task == 4:
    int n;
    cout << "Введите число: ";
    cin >> n;
    if (n < 0) n = -n;

    int count = 0;
    while (n >= 1) {
        n /= 10;
        count++;
    }
    cout << count;

#elif task == 5:
    const int SIZE = 10;
    int min, max;

    cin >> min >> max;

    if (max < min) swap(max, min);

    int array[SIZE];
    for (int i = 0; i < SIZE; i++) {
        array[i] = random(min, max);
        cout << array[i] << " "; // для теста
    }
    

#elif task == 6:
    int size1 = 3;
    int size2 = 3;
    int** array = createArray(size1, size2);
    showArray(array);
    cout << endl;

    int summa = 0;
    int column = 0;

    for(int j = 0; j < size2; j++) {
        summa += array[0][j];
    }
    int max = summa;

    for (int i = 1; i < size1; i++) {
        summa = 0;
        for (int j = 0; j < size2; j++){
            summa += array[i][j];
        }
        if (summa > max) {
            max = summa;
            column = i;
        }
    }

    cout << column + 1;

#elif task == 7:
    int size1 = 4;
    int size2 = 4;
    int** array1 = createArray(size1, size2);
    int** array2 = new int* [size1];
    for (int i = 0; i < size1; i++) {
        array2[i] = new int[size2];
    }

    showArray(array1);
    cout << endl;
    showArray(array2);
    cout << endl;

    copy(array1, array2);
    showArray(array1);
    cout << endl;
    showArray(array2);


#elif task == 8:
    int size = 10;
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = random(1, 10);
    }
    showArray(array);
    int index;
    cout << endl;
    cin >> index;
    if (index < 1 || index > size) cout << "Ошибка";
    else {
        delElem(array, index - 1);
        cout << endl;
        showArray(array);
    }

#elif task == 9:
    int size1 = 3;
    int size2 = 3;

    int** array = new int* [size1];
    for (int i = 0; i < size1; i++) {
        array[i] = new int[size2];
}

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            array[i][j] = random(1, 9);
        }
    }

    showArray(array);
    cout << endl;

    int* array2 = new int[size2];
    for (int i = 0; i < size2; i++) {
        array2[i] = random(1, 10);
    }

    showArray(array2);
    cout << endl << "----------" << endl;
    int index;
    cin >> index;
    if (index < 1 || index > size1) cout << "Ошибка" << endl;
    else {
        arrayUnion(array, array2, index-1);
    }
    showArray(array);

#elif task == 10:

    int size1 = 4;
    int size2 = 4;

    int** array = new int* [size1];
    for (int i = 0; i < size1; i++) {
        array[i] = new int[size2];
    }

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            array[i][j] = random(1, 9);
        }
    }
    showArray(array);
    int index;
    cin >> index;
    if (index < 1 || index > size2) cout << "Ошибка" << endl;
    else {
        delRow(array, index - 1);
        
    }
    cout << endl;
    showArray(array);

#elif task == 11:
    int** array = createArray(4, 4);
    showArray(array);
    delMinElem(array);
    cout << endl;
    showArray(array);

#elif task == 12:
    string text = "Love history histo";
    string word = "his";

    cout << findWord(text, word);

#elif task == 13:
    string path("text.txt");
    cout << fileCounter(path);

#elif task == 14:
    
struct Auto {
    string color = "No color";
    string model = "Unknown model";
};

    Auto car1 = { "Red", "MG3" };
    Auto car2 = { "White", "Corola" };
    Auto car3 = { "Black", "Elantra" };

    Auto cars[3];
    cars[0] = car1;
    cars[1] = car2;
    cars[2] = car3;

    for (int i = 0; i < 3; i++) {
        cout << "Color: " << cars[i].color << " Model: " << cars[i].model << endl;
    }

#endif
}

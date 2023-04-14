#include "param.h"

//создание поля
char** createField(int size) {
    char** field = new char* [size];
    for (int i = 0; i < size; i++) {
        field[i] = new char[size];
        for (int j = 0; j < size; j++) {
            field[i][j] = '~';
        }
    }
    return field;
}

//рендер поля
void render(char** field, int** snake, int* fruit) {
    system("cls");
    for (int i = 0; i < MARGIN; i++) cout << endl;

    int size = _msize(field[0]);
    int sizeSnake = _msize(snake) / sizeof(snake[0]);
    field[snake[0][0]][snake[0][1]] = char(2);
    for (int i = 1; i < sizeSnake; i++) {
        field[snake[i][0]][snake[i][1]] = 'o';
    }

    field[fruit[0]][fruit[1]] = char(253);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MARGIN; j++) cout << "\t    ";
        for (int j = 0; j < size; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

int** createSnake(int size) {
    int** snake = new int* [size];
    for (int i = 0; i < size; i++) {
        snake[i] = new int[2];
    }
    return snake;
}

void setPosition(int** snake, int y, int x) {
    int size = _msize(snake) / sizeof(snake[0]);
    for (int i = 0; i < size; i++, y++) {
        snake[i][0] = y;
        snake[i][1] = x;
    }
}

void setPosition(int* fruit, int** snake) {
    while (true) {
        int y = random(0, SIZE_FIELD / 2);
        int x = random(0, SIZE_FIELD / 2);
        int size = _msize(snake) / sizeof(snake[0]);
        bool flag = true;
        for (int i = 0; i < size; i++) {
            if (snake[i][0] == y && snake[i][0] == x) {
                flag = false;
                break;
            }
        }
        if (flag) {
            fruit[0] = x;
            fruit[1] = y;
            break;
        }
    }
}

bool unions(int** snake, int* fruit) {
    int size = _msize(snake) / sizeof(snake[0]);
    for (int i = 0; i < size; i++) {
        if (snake[i][0] == fruit[0] && snake[i][0] == fruit[1]) {
            return false;
            
        }
    }
    return true;
}

int main()
{
    srand(time(NULL));
    char** field = createField(SIZE_FIELD);
    int** snake = createSnake(MIN_SIZE_SNAKE);
    int* fruit = new int[2];
    

    setPosition(snake, SIZE_FIELD / 2, SIZE_FIELD / 2);
    setPosition(fruit, snake);

    render(field, snake, fruit);
    
}


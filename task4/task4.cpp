// task4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int** newMatrix(int** matrix, int& rows, int& cols) {
    if (cols == 1) 
    {
        cout << "Недопустимое количество строк. (PS rows > 1)" << endl;
        return 0;
    }

    int tempCols = 0;
    int** newArr = new int* [rows];
    if (cols % 2 == 0)
    {
        tempCols = cols / 2;
    }
    if (cols % 2 != 0)
    {
        tempCols = (cols - 1) / 2;
    }
    for (int i = 0; i < rows; i++)
    {
            newArr[i] = new int[tempCols];
    }
        //if (cols % 2 != 0)
        //{
        //    for (int i = 0; i < rows; i++)
        //    {
        //        realloc(newArr[i], ((cols - 1) / 2) * sizeof(int));
        //    }
        //    tempCols = (cols - 1) / 2;
        //}
        //if (cols % 2 == 0)
        //{
        //    for (int i = 0; i < rows; i++)
        //    {
        //        realloc(newArr[i], (cols/2) * sizeof(int));
        //    }
        //    tempCols = cols / 2;
        //}

        int iterator = 0;
        for (int i = 0; i < rows; i++)
        {
            iterator = 0;
            
            for(int j = 0; j < cols; j++)
            {
                if (j % 2 != 0)
                {
                    newArr[i][iterator] = matrix[i][j];
                    iterator++;
                }
            }
        }

        return newArr;

    
}

void PrintMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        cout << "Row " << (i + 1) << ": ";
        for (int j = 0; j < cols; j++) {
            cout << "\t" << matrix[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

void fillArray(int** matrix, int rows, int cols, int k)
{
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = j+k;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    int rows;
    int cols;
    cout << "Введите количество строк (rows): ";
    cin >> rows;
    cout << "Введите количество колонок (cols): ";
    cin >> cols;
    int** arr = new int* [rows];
    //for (int i = 0; i < rows; i++)
    //{
    //    arr[i] = new int[cols];
    //}

    //for (int i = 0; i < rows; i++)
    //{
    //    for (int j = 0; j < cols; j++)
    //    {
    //        arr[i][j] = j;
    //    }
    //}

    fillArray(arr, rows, cols, 1);

    if (rows > 1 && cols > 1)
    {
        PrintMatrix(arr, rows, cols);
    }

    int** newArr = newMatrix(arr, rows, cols);

    int newArrCols = 0;
    if (cols % 2 != 0)
    {
        newArrCols = (cols - 1) / 2;
    }
    else
    {
        newArrCols = cols / 2;
    }
    if (rows > 1 && cols > 1)
    {
        PrintMatrix(newArr, rows, newArrCols);
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] newArr[i];
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#include <iostream>

using namespace std;

class File
{
public:
    int size, lines, grade;
    File(int size, int lines, int grade) : size(size), lines(lines), grade(grade) {}
};

int max(short a, short b)
{
    return a >= b ? a : b;
}

int main()
{
    int N;
    int S;
    int L;
    File **files;
    cin >> N;
    cin >> S;
    cin >> L;
    files = new File *[N];
    for (int i = 0; i < N; i++)
    {
        int size;
        cin >> size;
        int lines;
        cin >> lines;
        int grades;
        cin >> grades;
        files[i] = new File(size, lines, grades);
    }

    int ***matDP = new int **[N + 1];
    for (int i = 0; i <= N; i++)
    {
        matDP[i] = new int *[S + 1];
        for (int j = 0; j <= S; j++)
        {
            matDP[i][j] = new int[L + 1];
            for (int k = 0; k <= L; k++)
            {
                matDP[i][j][k] = 0;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            for (int k = 1; k <= L; k++)
            {
                if (j < files[i - 1]->size || k < files[i - 1]->lines)
                {
                    matDP[i][j][k] = matDP[i - 1][j][k];
                }
                else
                {
                    matDP[i][j][k] = max(matDP[i - 1][j][k], matDP[i - 1][j - files[i - 1]->size][k - files[i - 1]->lines] + files[i - 1]->grade);
                }
            }
        }
    }

    cout << matDP[N][S][L] << "\t";

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= S; j++)
        {
            delete[] matDP[i][j];
        }

        delete[] matDP[i];
    }

    delete[] matDP;
    return 0;
}
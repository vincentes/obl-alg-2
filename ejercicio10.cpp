#include <iostream>

using namespace std;

class File
{
public:
  short size, lines, grade;
  File(short size, short lines, short grade) : size(size), lines(lines), grade(grade) {}
};

short max(short a, short b)
{
  return a >= b ? a : b;
}
  
int main()
{
    short N;
    short S;
    short L;
    File **files;
    cin >> N;
    cin >> S;
    cin >> L;
    cout << "N: " << N << " S: " << S << " L: " << L << endl;
    files = new File *[N];
    for(short i = 0; i < N; i++) {
        // Peso1
        short size;
        cin >> size;
        // Peso2
        short lines;
        cin >> lines;
        // Valor
        short grades;
        cin >> grades;
        files[i] = new File(size, lines, grades);
    }

  // Inicializo matriz y casos de borde

    cout << "Initializing matrix" << endl;
    short ***matDP = new short **[N];
    for (short i = 0; i < N; i++)
    {
        matDP[i] = new short*[S + 1];
        for(short j = 0; j <= S; j++) {
            matDP[i][j] = new short[L + 1];
            matDP[i][j][0] = 0;
        }
    }

    cout << "Initializing initial values" << endl;
    for (short j = 1; j <= S; j++)
    {
        for(short k = 1; k <= L; k++) {
            if(j < files[0]->size &&  k < files[0]->lines) {
                // No hay espacio
                cout << "No space found." << endl;
                matDP[0][j][k] = 0;
            } else {
                // Si hay espacio
                cout << "Found space." << endl;
                matDP[0][j][k] = files[0]->grade;
            }
        }
    }


    cout << "Starting iterative process" << endl;

    for (short i = 1; i < N; i++)
    {
        for (short j = 1; j <= S; j++)
            {
                for(short k = 0; k <= L; k++) {
                    if(files[j - 1]->size  <= j && files[k - 1]->lines <= k) {
                        // No hay espacio
                        cout << "IP. No space found." << endl;
                        matDP[i][j][k] = matDP[i][j - 1][k];
                    } else {
                        // Si hay espacio
                        cout << "IP. Found space. i: " << i << " j: " << j << " k: " << k << endl;
                        cout << "First term " << matDP[i - 1][j - 1][k - files[i]->lines] + files[i - 1]->grade << endl;
                        cout << "SECOND TERM " << matDP[i][j - 1][k] << endl;
                        matDP[i][j][k] = max(matDP[i - 1][j - 1][k - files[i]->lines] + files[i - 1]->grade, matDP[i][j - 1][k]);
                    }
                }
            }
    }

    cout << "DONE" << endl;

    cout << "\t";
    for (short j = 0; j <= N; j++)
    {
        cout << j << "\t";
    }
    cout << endl;

    for (short i = 0; i < N; i++)
    {
        cout << files[i]->size << "," << files[i]->lines << "\t";
        for (short j = 0; j <= S; j++)
        {
            for(short k = 0; k <= L; k++) {
                cout << matDP[i][j][k] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
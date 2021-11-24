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
    for(int j = 1; j <= S; j++) {
        for(int k = 1; k <= L; k++) {
            matDP[0][j][k] = (j < files[0]->size) ? 0 : files[0]->grade;
        }
    }

    for (int i = 1; i < N; i++) {
        for(int j = 1; j <= S; j++) {
            for (int k = 1; k <= L; k++) {
                if(j < files[i]->size || k < files[i]->lines) {
                    // cout << "IP. No space found." << endl;
                    matDP[i][j][k] = matDP[i - 1][j][k]; 
                } else {
                    // cout << "IP. Found space. i: " << i << " j: " << j << " k: " << k << endl;
                    // cout << "Size " << files[i]->size << endl;
                    // cout << "j - files[i]->size = " << j - files[i]->size << endl;
                    // cout << "k - files[i]->lines = " << k - files[i]->lines;
                    // cout << "First term " << matDP[i - 1][j - files[i]->size][k - files[i]->lines] + files[i]->grade << endl;
                    // cout << "SECOND TERM " << matDP[i - 1][j][k] << endl;
                    matDP[i][j][k] = max(matDP[i - 1][j][k], matDP[i - 1][j - files[i]->size][k - files[i]->lines] + files[i]->grade);
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


    cout << matDP[N - 1][S][L] << "\t";
   
    return 0;
}
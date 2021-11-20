#include <iostream>
#include "tads/list.cpp"

using namespace std;


class CellData
{
public:
    int i;
    int j;
    int pass;
    CellData(int i, int j) {
        this->i = i;
        this->j = j;
        this->pass = 0;
    }

    CellData(int i, int j, int pass) {
        this->i = i;
        this->j = j;
        this->pass = pass;
    }
};

int ifNotTop(int m, int n, int i, int j) {
    cout << "IS TOP: " << !(i == 0) << endl; 
    return !(i == 0);
}

int ifNotBottom(int m, int n, int i, int j) {
    return !(i == m - 1);
}

int ifNotLeft(int m, int n, int i, int j) {
    return !(j == 0);
}

int ifNotRight(int m, int n, int i, int j) {
    return !(j == n - 1);
}


int bfs(int m, int n, int** matrix, Lista<CellData*>* positives, int negatives) {
    cout << "BFS" << endl;
    CellData* cell = new CellData(-1, -1, -1);
    while(positives->largo() != 0 && negatives > 0) {
        cell = positives->obtenerPpio();
        positives->borrarPpio();

        if(ifNotBottom(m, n, cell->i, cell->j) && matrix[cell->i + 1][cell->j] < 0) {
            matrix[cell->i + 1][cell->j] = -matrix[cell->i + 1][cell->j];
            negatives--;
            positives->insertarFin(new CellData(cell->i + 1, cell->j, cell->pass + 1));
        }
        

        if(ifNotTop(m, n, cell->i, cell->j) && matrix[cell->i - 1][cell->j] < 0) {
            matrix[cell->i - 1][cell->j] = -matrix[cell->i - 1][cell->j];
            negatives--;
            positives->insertarFin(new CellData(cell->i - 1, cell->j, cell->pass + 1));
        } 
        
        if(ifNotLeft(m, n, cell->i, cell->j) && matrix[cell->i][cell->j - 1] < 0) {
            matrix[cell->i][cell->j - 1] = -matrix[cell->i][cell->j - 1];
            negatives--;
            positives->insertarFin(new CellData(cell->i, cell->j - 1, cell->pass + 1));
        }

        if(ifNotRight(m, n, cell->i, cell->j) && matrix[cell->i][cell ->j + 1] < 0) {
            matrix[cell->i][cell->j + 1] = -matrix[cell->i][cell->j + 1];
            negatives--;
            positives->insertarFin(new CellData(cell->i, cell->j + 1, cell->pass + 1));
        }
    }

    return cell->pass + 1;
}

int main() {
    Lista<CellData*>* positives = new Lista<CellData*>();
    int M, N;
    cin >> M;
    cin >> N;
    int negatives = 0;
    int** matrix = new int*[M];
    for(int i = 0; i < M; i++) {
        matrix[i] = new int[N];
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] < 0) {
                negatives++;
            } else if(matrix[i][j] > 0) {
                positives->insertarFin(new CellData(i, j));
            }
        }
    }

    cout << bfs(M, N, matrix, positives, negatives) << endl;
}
#include <iostream>
#include "string.h"
#define INF 99999

using namespace std;

class Arista
{
public:
  int costo;
  bool existe;

  Arista() : costo(0), existe(false) {}
  Arista(int costo) : costo(costo), existe(true) {}
};

class Grafo
{

private:
  Arista ***mat;
  int tope;
  int cant;
  int **vertices;
  bool esDirigido;

  int obtenerHueco()
  {
    for (int i = 0; i < tope; i++)
    {
      if (!vertices[i])
      {
        return i;
      }
    }
    return -1;
  }

  int obtenerPrimerVerticeNoNull()
  {
    for (int i = 0; i < tope; i++)
    {
      if (vertices[i])
      {
        return i;
      }
    }
    return -1;
  }

  int posVertice(int v)
  {
    for (int i = 0; i < tope; i++)
    {
      if (vertices[i] && *(vertices[i]) == v)
      {
        return i;
      }
    }
    return -1;
  }

  int verticeNoVisDeMenorDist(int *dist, bool *vis)
  {
    int posMin = -1, min = INF;
    for (int i = 0; i < tope; i++)
    {
      if (!vis[i] && dist[i] < min)
      {
        min = dist[i];
        posMin = i;
      }
    }
    return posMin;
  }

public:
  Grafo(int tope, bool esDirigido)
  {
    this->tope = tope;
    this->cant = 0;
    this->esDirigido = esDirigido;

    this->vertices = new int *[tope];
    for (int i = 0; i < tope; this->vertices[i++] = NULL)
      ;

    this->mat = new Arista **[tope];
    if (esDirigido)
    {
      for (int i = 0; i < tope; i++)
      {
        this->mat[i] = new Arista *[tope];
        for (int j = 0; j < tope; j++)
        {
          this->mat[i][j] = new Arista();
        }
      }
    }
    else
    {
      for (int i = 0; i < tope; i++)
      {
        this->mat[i] = new Arista *[tope];
      }
      for (int i = 0; i < tope; i++)
      {
        for (int j = i; j < tope; j++)
        {
          this->mat[i][j] = this->mat[j][i] = new Arista();
        }
      }
    }
  }

  ~Grafo()
  {
    for (int i = 0; i < tope; i++)
    {
      delete vertices[i];
    }
    delete[] vertices;

    if (esDirigido)
    {
      for (int i = 0; i < tope; i++)
      {
        for (int j = 0; j < tope; j++)
        {
          delete mat[i][j];
        }

        delete[] mat[i];
      }
    }
    else
    {
      for (int i = 0; i < tope; i++)
      {
        for (int j = i; j < tope; j++)
        {
          delete mat[i][j];
        }

        delete[] mat[i];
      }
    }
    delete[] mat;
  }

  void  insertarVertice(int v)
  {

    int pos = obtenerHueco();
    vertices[pos] = new int(v);
    cant++;
  }

  // Pre: existeVertice(vOri) && existeVertice(vDes)
  void insertarArista(int vOri, int vDes, int costo)
  {
    int posOri = posVertice(vOri);

    int posDes = posVertice(vDes);
    mat[posOri][posDes]->costo = costo;
    mat[posOri][posDes]->existe = true;
  }

  // Pre: existeVertice(vOri) && existeVertice(vDes)
  void borrarArista(int vOri, int vDes)
  {
    int posOri = posVertice(vOri);
    int posDes = posVertice(vDes);
    mat[posOri][posDes]->existe = false;
  }

  bool existeVertice(int v)
  {
    return posVertice(v) != -1;
  }

  int prim(bool cubrirTodasLasComponentes)
  {
    int total = 0;
    // Agarro cualquier vertice
    int pos = obtenerPrimerVerticeNoNull();

    // Inicializo visitados
    bool *vis = new bool[cant];
    for (int i = 0; i < tope; vis[i++] = false)
      ;

    // Asigno como visitado el primer vertice que agarre
    vis[pos] = true;

    // Repito V veces
    for (int k = 0; k < cant; k++)
    {
      // posI = i en donde esta el minimo
      // posJ = j en donde esta el minimo
      // minimo = el minimo
      int posI = -1, posJ = -1, minimo = INF;
      // Recorro matriz de adyacencia
      for (int i = 0; i < tope; i++)
      {
        // El vertice esta visitado?
        if (vis[i])
        {
          // Recorro adyacencia a vertice visitado
          for (int j = 0; j < tope; j++)
          {
            // Si el vector conexo no fue visitiado, existe, y existe una relacion, y el costo es menor
            if (!vis[j] && vertices[j] && mat[i][j]->existe && mat[i][j]->costo < minimo)
            {
              // Mi candato pasa a ser i -> j, con un nuevo minimo
              posI = i;
              posJ = j;
              minimo = mat[i][j]->costo;
            }
          }
        }
      }

      // Si se encontro un nuevo paso
      if (posI != -1)
      {
        total += minimo;
        vis[posJ] = true;
      }
    }

    bool connected = true;
    for (int i = 0; i < tope; i++) {
      if(!vis[i]) {
        connected = false;
      }
    }
      

    delete[] vis;

    if(!connected) {
      return -1;
    }

    return total;
  }
};


int main() {
    int V;
    cin >> V;
    Grafo* graph = new Grafo(V, false);
    int E;
    cin >> E;
    for (int i = 0; i < E; i++) {
        std::string origin;
        cin >> origin;
        std::string destination;
        cin >> destination;
        std::string weight;
        cin >> weight;
        if(!graph->existeVertice(stoi(origin))) {
          graph->insertarVertice(stoi(origin));
        }

        if(!graph->existeVertice(stoi(destination))) {
          graph->insertarVertice(stoi(destination));
        }
        graph->insertarArista(stoi(origin), stoi(destination), stoi(weight));
    }

    cout << graph->prim(false) << endl;
}
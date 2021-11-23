#include "iostream"
#define INF 999999
using namespace std;

class Archivo
{
public:
    int tamano, lineas, puntaje;
    Archivo(int tamano, int lineas, int puntaje) : tamano(tamano), lineas(lineas), puntaje(puntaje) {}
};

void entrega(Archivo **&archivos, int N, int archivoActual, int S, int L, int puntajeActual, int *&solActual, int &puntajeOptimo)
{
    if (archivoActual == N)
    {
        if (puntajeActual > puntajeOptimo)
        {
            puntajeOptimo = puntajeActual;
        }
    }
    else
    {
        // No uso al archivo actual
        entrega(archivos, N, archivoActual + 1, S, L, puntajeActual, solActual, puntajeOptimo);
        // Intento usar al archivo actual
        Archivo *archivo = archivos[archivoActual];
        if (archivo->tamano <= S && archivo->lineas <= L)
        {
            solActual[archivoActual]++;
            S -= archivo->tamano;
            L -= archivo->lineas;
            puntajeActual += archivo->puntaje;
            entrega(archivos, N, archivoActual + 1, S, L, puntajeActual, solActual, puntajeOptimo);
            solActual[archivoActual]--;
        }
    }
}

int main()
{
    int N, S, L, t, l, p;
    Archivo **archivos;
    cin >> N;
    archivos = new Archivo *[N];
    cin >> S;
    cin >> L;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        cin >> l;
        cin >> p;
        archivos[i] = new Archivo(t, l, p);
    };
    int *solActual = new int[N];
    for (int i = 0; i < N; solActual[i] = 0, i++)
        ;
    int puntajeOptimo = -1;

    entrega(archivos, N, 0, S, L, 0, solActual, puntajeOptimo);

    cout << puntajeOptimo << endl;
    delete archivos;
    return 0;
}
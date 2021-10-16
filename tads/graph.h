#ifndef CPP_LAB_GRAPH_H
#define CPP_LAB_GRAPH_H

class Arista
{
public:
    bool existe;
    int origen;
    int destino;

    Arista() : existe(false) {}
    Arista() : existe(true) {}
    Arista(int origen, int destino) : existe(true), origen(origen), destino(destino) {}

    friend bool operator<(const Arista &a, const Arista &b);
    friend bool operator==(const Arista &a, const Arista &b);
};


class Grafo {

private:
    Arista ***mat;
    int tope;
    int cant;
    int **vertices;
    bool esDirigido;

}

#endif //CPP_LAB_GRAPH_H

//
// Created by Vicente Bermudez on 11/11/21.
//


template <class T>
class NodoLista
{
public:
  NodoLista<T> *sig;
  T dato;

  NodoLista(T dato) : dato(dato), sig(NULL) {}
  NodoLista(T dato, NodoLista<T> *sig) : dato(dato), sig(sig) {}
};

template <class T>
class Lista
{
private:
  NodoLista<T> *inicio;
  NodoLista<T> *fin;
  int cant;
  int (*fComp)(T, T);

  void vaciarRec(NodoLista<T> *nodo)
  {
    if (nodo)
    {
      vaciarRec(nodo->sig);
      delete nodo;
    }
  }

  void insertarOrdRec(T dato, NodoLista<T> *&nodo)
  {
    if (fComp(dato, nodo->dato) <= 0)
    {
      NodoLista<T> *nuevo = new NodoLista<T>(dato, nodo);
      nodo = nuevo;
      // O... Versión cheta: nodo = new NodoLista<T>(dato, nodo);
      cant++;
    }
    else
    {
      insertarOrdRec(dato, nodo->sig);
    }
  }

  void mostrarRec(NodoLista<T> *&nodo)
  {
    if (nodo)
    {
      mostrarRec(nodo->sig);
    }
  }

  bool perteneceRec(T dato, NodoLista<T> *&nodo)
  {
    if (nodo)
    {
      if (nodo->dato == dato)
      {
        return true;
      }
      else
      {
        return perteneceRec(dato, nodo->sig);
      }
    }
  }

public:
  Lista() : inicio(NULL), fin(NULL), cant(0) {}

  ~Lista()
  {
    vaciar();
  }

  void vaciar()
  {
    vaciarRec(inicio);
    inicio = fin = NULL;
    cant = 0;
  }

  void insertarPpio(T dato)
  {
    inicio = new NodoLista<T>(dato, inicio);
    if (fin == NULL)
    {
      fin = inicio;
    }
    cant++;
  }

  void insertarFin(T dato)
  {
    NodoLista<T> *nuevo = new NodoLista<T>(dato);
    if (fin == NULL)
    {
      fin = inicio = nuevo;
    }
    else
    {
      fin->sig = nuevo;
      fin = fin->sig;
    }
    cant++;
  }

  // Pre: largo > 0
  T obtenerPpio()
  {
    return inicio->dato;
  }

  // Pre: largo > 0
  void borrarPpio()
  {
    NodoLista<T> *aBorrar = inicio;
    inicio = inicio->sig;
    delete aBorrar;
    cant--;
    if (!inicio)
    {
      fin = NULL;
    }
  }

  int largo()
  {
    return cant;
  }

  void mostrar()
  {
    mostrarRec(inicio);
  }

  bool pertenece(T dato)
  {
    return perteneceRec(dato, inicio);
  }
};

int comparar(int a, int b)
{
  return a - b;
}
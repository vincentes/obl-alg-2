#include "tads/graph.cpp"
#include <iostream>
#include <fstream>
#include "string.h"

using namespace std;

class Building {
public:
    int xLeft;
    int xRight;
    int height;
    Building() {}
    Building(int xLeft, int xRight, int height) : xLeft(xLeft),xRight(xRight),height(height) {}
};
  
class Strip {
public: 
    int left;
    int height;
    Strip()
    {
        left = 0;
        height = 0;
    }
    Strip(int l, int h)
    {
        left = l;
        height = h;
    }
};
  
class SkyLine {
public:
    Strip* array;
    int capacity;
    int size;
  
    ~SkyLine() { delete[] array; }
    int count() { return size; }
  
    SkyLine* Merge(SkyLine* other);
    
    SkyLine(int capacity)
    {
        this->capacity = capacity;
        array = new Strip[capacity];
        size = 0;
    }
  
    void append(Strip* strip)
    {
        if (size > 0 && array[size - 1].height == strip->height)
            return;
        if (size > 0 && array[size - 1].left == strip->left) {
            array[size - 1].height = array[size - 1].height > strip->height ? array[size - 1].height : strip->height;
            return;
        }
  
        array[size] = *strip;
        size++;
    }
  
    void print()
    {
        for (int i = 0; i < size; i++) {
            cout << array[i].left << " " << array[i].height << endl;
        }
    }
};

SkyLine* findSkyline(Building array[], int firstBuilding, int lastBuilding)
{
    if (firstBuilding == lastBuilding) {
        // one building needs two points to define skyline
        SkyLine* result = new SkyLine(2);
        // add strips
        result->append(
            new Strip(array[firstBuilding].xLeft, array[firstBuilding].height));
        result->append(
            new Strip(array[firstBuilding].xRight, 0));
        return result;
    }
    int mid = (firstBuilding + lastBuilding) / 2;

    // Divide & conquer
    SkyLine* sLeft = findSkyline(array, firstBuilding, mid);
    SkyLine* sRight = findSkyline(array, mid+1, lastBuilding);
    SkyLine* result = sLeft->Merge(sRight);
    
    delete sLeft;
    delete sRight;

    return result;
}

SkyLine* SkyLine::Merge(SkyLine* other)
{
    SkyLine* result = new SkyLine(this->size + other->size);
  
    int h1 = 0, h2 = 0;
    int i = 0, j = 0;

    while (i < this->size && j < other->size) {
        // compare strips setting hight according to the highest one
        if (this->array[i].left <= other->array[j].left) {
            int x1 = this->array[i].left;
            h1 = this->array[i].height;
            int maxHeight = h1 > h2 ? h1 : h2;
  
            result->append(new Strip(x1, maxHeight));

            i++;
        }
        else {
            int x2 = other->array[j].left;
            h2 = other->array[j].height;
            int maxHeight = h1 > h2 ? h1 : h2;
            result->append(new Strip(x2, maxHeight));
            j++;
        }
    }
  
    while (i < this->size) {
        result->append(new Strip(other->array[i].left, other->array[i].height));
        i++;
    }
    while (j < other->size) {
        result->append(new Strip(other->array[j].left, other->array[j].height));
        j++;
    }
    return result;
}
  
int main()
{
    // // IMPORTANTE! BORRAR O COMENTAR LAS SIGUIENTES LINEAS  EN TODOS LOS EJERCICIOS DEL OBLIGATORIO. NO PUEDEN ESTAR EN NINGUNA ENTREGA!
    // ifstream myFile("test-cases/ejercicio9/siluetas.1.in.txt");
    // cin.rdbuf(myFile.rdbuf());
    // // Si desean tirar la salida a un archivo, usen las siguientes líneas (si no, sáquenlas):
    // ofstream myFile2("test-cases/ejercicio9/siluetas.1.mine.txt");
    // cout.rdbuf(myFile2.rdbuf());

    int B;
    cin >> B;
    Building* buildings = new Building[B];
    for (int i = 0; i < B; i++)
    {
        std::string left;
        cin >> left;
        std::string right;
        cin >> right;
        std::string height;
        cin >> height;
        buildings[i] = Building(stoi(left),stoi(right),stoi(height));
    }    
  
    SkyLine* skyLine = findSkyline(buildings, 0, B-1);
    skyLine->print();
    return 0;
}
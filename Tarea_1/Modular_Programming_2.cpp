#include <iostream>
using namespace std;

int* gpVect = nullptr; // Puntero al buffer dinámico para guardar los elementos
int gnCount = 0; // Contador para saber el número de elementos utilizados
int gnMax = 0; // Variable que contiene el tamaño asignado

struct Vector
{
    int* m_pVect; // Puntero al buffer
    int m_nCount; // Controla cuántos elementos se utilizan actualmente
    int m_nMax; // Controla cuántos elementos se asignan como máximo
    int m_nDelta; // Para controlar el crecimiento
};

void Resize(Vector* pThis)
{
    int* newBuffer = new int[pThis->m_nMax + pThis->m_nDelta];
    // Copiar los elementos existentes al nuevo búfer
    for (int i = 0; i < pThis->m_nCount; i++)
    {
        newBuffer[i] = pThis->m_pVect[i];
    }
    // Liberar el búfer anterior
    delete[] pThis->m_pVect;
    // Actualizar los punteros y tamaños
    pThis->m_pVect = newBuffer;
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) // Verificar el desbordamiento
        Resize(pThis); // Redimensionar el vector antes de insertar elem
    // Insertar el elemento al final de la secuencia
    pThis->m_pVect[pThis->m_nCount++] = elem;
}


int main()
{
    Vector vec;
    vec.m_pVect = nullptr;
    vec.m_nCount = 0;
    vec.m_nMax = 0;
    vec.m_nDelta = 5;

    Insert(&vec, 10);
    Insert(&vec, 20);
    Insert(&vec, 30);

    for (int i = 0; i < vec.m_nCount; i++)
    {
        cout << vec.m_pVect[i] << " ";
    }
    cout << endl;

    delete[] vec.m_pVect;

    return 0;
}

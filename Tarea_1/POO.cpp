#include <iostream>
using namespace std;

class CVector
{
private:
    int* m_pVect; 
    int m_nCount; 
    int m_nMax;
    int m_nDelta; 

    void Init(int delta); 
    void Resize(); 

public:
    CVector(int delta = 10); 
    ~CVector(); 
    void Insert(int elem); 
    int GetSize() const; 
    int GetElement(int index) const; 
};

CVector::CVector(int delta)
{
    Init(delta);
}

CVector::~CVector()
{
    delete[] m_pVect;
}

void CVector::Init(int delta)
{
    m_pVect = nullptr;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

void CVector::Resize()
{
    int* newVect = new int[m_nMax + m_nDelta];

    for (int i = 0; i < m_nCount; i++)
    {
        newVect[i] = m_pVect[i];
    }

    delete[] m_pVect;
    m_pVect = newVect;
    m_nMax += m_nDelta;
}

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax) 
        Resize(); 

    m_pVect[m_nCount++] = elem; 
}

int CVector::GetSize() const
{
    return m_nCount;
}

int CVector::GetElement(int index) const
{
    if (index >= 0 && index < m_nCount)
        return m_pVect[index];
    else
        throw out_of_range("Índice fuera de rango");
}

int main()
{
    CVector vector;
    for (int i = 1; i <= 20; i++)
    {
        vector.Insert(i);
    }
    for (int i = 0; i < vector.GetSize(); i++)
    {
        cout << vector.GetElement(i) << " ";
    }
    return 0;
}
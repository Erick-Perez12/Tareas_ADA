#include <iostream>
using namespace std;

template <typename Type> 
class CVector
{
private:
    Type* m_pVect, m_nCount,m_nMax, m_nDelta; 

    void Init(int delta); 
    void Resize(); 

public:
    CVector(int delta = 10); 
    ~CVector(); 
    void Insert(Type elem); 
    int GetSize() const; 
    int GetElement(int index) const; 
};

template <typename Type> CVector<Type>::CVector(int delta)
{
    Init(delta);
}

template <typename Type> CVector<Type>::~CVector()
{
    delete[] m_pVect;
}

template <typename Type> void CVector<Type>::Init(int delta)
{
    m_pVect = nullptr;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

template <typename Type> void CVector<Type>::Resize()
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

template <typename Type> void CVector<Type>::Insert(Type elem)
{
    if (m_nCount == m_nMax) 
        Resize(); 

    m_pVect[m_nCount++] = elem; 
}

template <typename Type> int CVector<Type>::GetSize() const
{
    return m_nCount;
}

template <typename Type> int CVector<Type>::GetElement(int index) const
{
    if (index >= 0 && index < m_nCount)
        return m_pVect[index];
    else
        throw out_of_range("Índice fuera de rango");
}

int main()
{
    CVector<int> vector;
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

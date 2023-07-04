#include <vector>
#include <iostream>

class CMyComplexDataStructure {
    std::vector<float> m_container;

public:
    void Insert(float fVal) { m_container.push_back(fVal); }

    template <typename objclass>
    void sumone(objclass funobj) {
        for (auto& val : m_container)
            funobj(val);
    }
};

template <typename objclass>
class funcobjclass {
public:
    void operator()(objclass& objinstance) {
        objinstance++;
    }
};

int main() {
    CMyComplexDataStructure ds;
    ds.Insert(3.5);
    ds.Insert(4.5);
    ds.Insert(6.5);
    ds.Insert(3.9);

    funcobjclass<float> x;
    ds.sumone(x);
    return 0;
}
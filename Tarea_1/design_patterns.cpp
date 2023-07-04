#include <vector>
#include <list>
#include <iostream>

template <typename Container>
void Write(const Container& ds, std::ostream& os)
{
    for (const auto& element : ds)
        os << element << "\n";
}

int main()
{
    std::list<float> mylist;
    std::vector<float> myvector;

    for (int i = 0; i < 10; i++)
    {
        mylist.push_back(static_cast<float>(i));
        myvector.push_back(static_cast<float>(i + 50));
    }

    Write(mylist, std::cout);
    Write(myvector, std::cout);

    return 0;
}
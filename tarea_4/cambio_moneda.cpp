#include <iostream>
#include <stdio.h>

int count(int S[], int n, const int target)
{
    int T[9];
    for (int i = 0; i <= target; i++) {
        T[i] = 0;
    }
    T[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = S[i]; j <= target; j++) {
            //std::cout << j <<" - "<<S[i] << "\n";
            T[j] += T[j - S[i]];
            std::cout << "T[" << j << "] = " << T[j] << std::endl;
        }
        std::cout << std::endl;
    }
    return T[target];
}

int main(void)
{
    int S[] = { 1, 3, 5, 7 };
    int n = sizeof(S) / sizeof(S[0]);
    std::cout << n;
    int target = 8;
    printf("El numero total de formas de hacer el cambio para %d es %d\n", target, count(S, n, target));
    return 0;
}

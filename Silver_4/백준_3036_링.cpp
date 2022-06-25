#include <iostream>
#include <vector>
#include <math.h>

struct Fraction
{
    int numerator;   // 분자
    int denominator; // 분모

    void Print()
    {
        std::cout << numerator << "/" << denominator << "\n";
    }
};

void Reduced_Fraction(Fraction &f, int i)
{
    int min = std::min(f.numerator, f.denominator);
    while (i <= min)
    {
        if (f.denominator % i == 0 && f.numerator % i == 0) // 만약 분모가 분자로 나누어 떨어지면
        {
            f.denominator /= i;
            f.numerator /= i;
            i = 1;
        }
        i++;
    }
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> ring_radius;
    for (size_t i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        ring_radius.push_back(n);
    }

    // 8 4 2 >> 8이 한 바퀴 돌면 4는 2바퀴, 2는 4가 2 바퀴 돌았으므로 4바퀴 돈다.
    std::vector<Fraction> fraction_vec(N);
    for (size_t i = 0; i < N - 1; i++)
    {
        fraction_vec[i].numerator = ring_radius[0];
        fraction_vec[i].denominator = ring_radius[i + 1];
        Reduced_Fraction(fraction_vec[i], 2);
    }
    for (size_t i = 0; i < N - 1; i++)
        fraction_vec[i].Print();
}
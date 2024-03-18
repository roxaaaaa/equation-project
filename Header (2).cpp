#include "Header.h"

ostream& operator<<(ostream& os, const Equation& e)
{
    e.printOn(os);

    return os;
}

//-----------------------------------------------------------

void Linear::printOn(ostream& os) const
{
    os << "Linear equation: " << a << "x + " << b;
}

void Linear::storeOn(ofstream& fout) const
{
    fout << "L " << a << " " << b;
}

double Linear::root() const
{
    if (a == 0)
    {
        cout << "Coefficient 'a' cannot be zero for a linear equation." << endl;
        return 0;
    }

    return (-b) / a;
}

//-----------------------------------------------------------

void Quadratic::printOn(ostream& os) const
{
    os << "Quadratic equation: " << a << "x^2 +" << b << "x + " << c;
}

void Quadratic::storeOn(ofstream& fout) const
{
    fout << "Q " << a << " " << b << " " << c;
}

double Quadratic::root() const
{
    double discriminant = b * b - 4 * a * c;
    double x1, x2;

    if (discriminant > 0)
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        return x1, x2;
    }

    else if (discriminant == 0)
    {
        cout << "Roots are real and same." << endl;
        x1 = -b / (2 * a);

        return x1;
    }

    else
    {
        cout << "discriminant is < 0" << endl;

        return false;
    }
}
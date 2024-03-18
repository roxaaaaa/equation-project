#include "Header.h"

int main()
{
    cout << " * Static array *\n------------------\n";
    Equation* e[] =
    {
        new Linear(4, 2),
        new Linear(3, 6),
        new Quadratic(8, 4, 2),
        new Quadratic(3, 9, 1),
        new Quadratic(2, 8, 16)
    };

    double n = sizeof(e) / sizeof(*e);

    for (int i = 0; i < n; ++i)
    {
        cout << *e[i] << '\n';
    }

    cout << "\nStoring and loading equations to a dynamic array\n\n";

    ofstream fout("Text.txt"); 
    if (!fout)
    {
        cout << "Error" << endl;
        return 1;
    }

    fout << n << '\n'; // запис кількості рівнянь у файл

    for (int i = 0; i < n; ++i)
    {
        e[i]->storeOn(fout); // збереження рівнянь у файл
        fout << endl;
    }
    fout.close(); 

    ifstream fin("Text.txt"); 
    if (!fin)
    {
        cout << "Error: Cannot open the file." << endl;
        return 1;
    }

    fin >> n; 
    Equation** D = new Equation * [n]; // створення динамічного масиву рівнянь

    for (int i = 0; i < n; ++i)
    {
        char type;
        fin >> type;

        switch (type)
        {
        case 'L':
            int p, q;
            fin >> p >> q;
            D[i] = new Linear(p, q);
            cout << *D[i] << " | x = ";
            cout << D[i]->root() << endl;

            break;

        case 'Q':
            int a, b, c;
            fin >> a >> b >> c;
            D[i] = new Quadratic(a, b, c);
            cout << *D[i] << " | roots: ";
            double root = D[i]->root();
            cout << *D[i] << ", " << root << endl;

            break;
        }
    }

    fin.close(); 

    for (int i = 0; i < n; ++i) // звільнення пам'яті
    {
        delete D[i];
    }
    delete[] D;

    system("pause");
    return 0;
}
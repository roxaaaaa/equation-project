#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

class Equation
{
public:
	virtual ~Equation() {}
	virtual double root() const abstract;
	virtual void printOn(ostream&) const abstract;
	virtual void storeOn(ofstream&) const abstract;
};

ostream& operator<<(ostream& os, const Equation& e);// єдиний оператор виведення для всієї ієрархії

// конструктор з параметрами, в якого всі параметри мають значення за замовчанням, стає також і конструктором за замовчанням

class Linear : public Equation
{
protected:
	double a;
	double b;

public:
	Linear(double a = 1, double b = 1) : a(a), b(b) {}
	virtual void printOn(ostream&) const override;
	virtual void storeOn(ofstream&) const override;
	virtual double root() const override;
};

class Quadratic : public Equation
{
private:
	double a;
	double b;
	double c;

public:
	Quadratic(double a = 1, double b = 1, double c = 1) : a(a), b(b), c(c) {}
	virtual void printOn(ostream&) const override;
	virtual void storeOn(ofstream&) const override;
	virtual double root() const override;
};
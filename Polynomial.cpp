#include "Polynomial.h"

Polynomial::Polynomial(double *coef, int exp)
{
	for (int i = 0; i < sizeof(coef); i++)
	{
		this->coef.push_back(coef[i]);
	}
	this->exp = exp;
}
Polynomial::Polynomial(const Polynomial& poly)
{
	for (int i = 0; i < poly.coef.size(); i++)
	{
		this->coef.push_back(poly.coef[i]);
	}
	this->exp = poly.exp;
}
const Polynomial& Polynomial::operator = (const Polynomial& poly)
{
	for (int i = 0; i < poly.coef.size(); i++)
	{
		this->coef.push_back(poly.coef[i]);
	}
	this->exp = poly.exp;
	return *this;
}
double& Polynomial::operator [] (int i)
{
	return coef[i];
}
const double& Polynomial::operator[](int degree)const
{
	return coef[degree];
}
int evaluate(Polynomial poly, int x)
{
	int result = 0;
	for (int i = 0; i < poly.coef.size(); i++)
	{
		result += poly.coef[i] * pow(x, i);
	}
	return result;
}
int Polynomial::mySize()
{
	return exp + 1;
}
Polynomial operator + (const Polynomial& poly1, const Polynomial& poly2)
{
	Polynomial tempt;
	if (poly1.exp > poly2.exp)
	{
		tempt.exp = poly1.exp;
	}
	else
	{
		tempt.exp = poly2.exp;
	}
	for (int i = 0; i < tempt.exp; i++)
	{
		if (i > poly1.coef.size() - 1 && i < poly2.coef.size())
		{
			tempt.coef.push_back(poly2.coef[i]);
		}
		else if (i > poly2.coef.size() - 1 && i < poly1.coef.size())
		{
			tempt.coef.push_back(poly1.coef[i]);
		}
		else
		{
			tempt.coef.push_back(poly1.coef[i] + poly2.coef[i]);
		}
	}
	return tempt;
}
Polynomial operator + (const double tempt, const Polynomial& poly)
{
	Polynomial a;
	a.exp = poly.exp;
	a.coef.assign(poly.coef.begin(), poly.coef.end());
	a.coef[0] += tempt;
	return a;
}
Polynomial operator - (const Polynomial& poly1, const Polynomial& poly2)
{
	Polynomial tempt;
	if (poly1.exp > poly2.exp)
	{
		tempt.exp = poly1.exp;
	}
	else
	{
		tempt.exp = poly2.exp;
	}
	for (int i = 0; i < tempt.exp; i++)
	{
		if (i > poly1.coef.size() - 1 && i < poly2.coef.size())
		{
			tempt.coef.push_back(poly2.coef[i]);
		}
		else if (i > poly2.coef.size() - 1 && i < poly1.coef.size())
		{
			tempt.coef.push_back(poly1.coef[i]);
		}
		else
		{
			tempt.coef.push_back(poly1.coef[i] - poly2.coef[i]);
		}
	}
	return tempt;
}
Polynomial operator - (const double tempt, const Polynomial& poly)
{
	Polynomial a;
	a.exp = poly.exp;
	a.coef.assign(poly.coef.begin(), poly.coef.end());
	a.coef[0] -= tempt;
	return a;
}
Polynomial operator * (const Polynomial& poly1, const Polynomial& poly2)
{
	Polynomial tempt;
	tempt.exp = poly1.exp + poly2.exp - 1;
	double* array = new double[tempt.exp];
	for (int i = 0; i < tempt.exp; i++)
		array[i] = 0;
	for(int i = 0; i < poly1.exp; i++)
		for (int j = 0; j < poly2.exp; j++)
		{
			
			array[i + j] = poly1.coef[i] + poly2.coef[i];
			
			
		}
	for (int i = 0; i < tempt.exp; i++)
		tempt.coef.push_back(array[i]);
	delete[] array;
	return tempt;
}

Polynomial operator * (const double tempt, const Polynomial& poly)
{
	Polynomial a;
	a.exp = poly.exp;
	a.coef.assign(poly.coef.begin(), poly.coef.end());
	for (int i = 0; i < poly.exp; i++)
	{
		a.coef[i] *= tempt;
	}
		
	return a;
}

ostream& operator << (ostream& outputStream, const Polynomial& poly)
{
	return outputStream;
}

Polynomial::Polynomial():exp(0)
{
}


Polynomial::~Polynomial()
{
}

//input-main1.cpp
int main()
{
	Polynomial empty;
	double one[] = { 1 };
	Polynomial One(one, 1);
	double quad[] = { 3, 2, 1 };
	double cubic[] = { 1, 2, 0, 3 };
	Polynomial q(quad, 3); // q is 3 + 2*x + x*x
	Polynomial c(cubic, 4);// c is 1 + 2*x + 0*x*x + 3*x*x*x
	Polynomial p = q;  // test copy constructor
	Polynomial r;
	r = q;             //test operator=
	r = c;

	cout << "Polynomial q " << endl;
	for (int i = 0; i < 3; i++)
		cout << "term with degree " << i << " has coefficient " << q[i] << endl;

	cout << "Polynomial c " << endl;
	for (int i = 0; i < 4; i++)
		cout << "term with degree " << i << " has coefficient " << c[i] << endl;

	cout << "value of q(2) is " << evaluate(q, 2) << endl;
	cout << "value of p(2) is " << evaluate(p, 2) << endl;
	cout << "value of r(2) is " << evaluate(r, 2) << endl;
	cout << "value of c(2) is " << evaluate(c, 2) << endl;

	r = q + c;
	cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;

	r = q - c;
	cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

	r = q * c;
	cout << "size of q*c is " << r.mySize() << endl;
	cout << "Polynomial r (= q*c) " << endl;

	for (int i = 0; i < r.mySize(); i++)
		cout << "term with degree " << i << " has coefficient " << r[i] << endl;

	cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;
	system("pause");
	return 0;
}

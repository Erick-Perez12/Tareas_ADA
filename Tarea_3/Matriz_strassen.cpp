#include<iostream>
#include<vector>
using namespace std;

void insert(vector<vector<double>>& x)
{
	for (int i = 0; i < 4; i++)
	{	
		vector<double> aux;
		for (int j = 0; j < 4; j++)
		{
			double val=1+rand()%(11-1);
			aux.push_back(val);
			cout << val << " ";
		}
		x.push_back(aux);
		cout << endl;
	}
}

double cal11(vector<vector<double>>& x)
{
	return (x[0][0] * x[0][1]) + (x[0][1] * x[1][0]);
}

double cal21(vector<vector<double>>& x)
{
	return (x[2][0] * x[3][1]) + (x[2][1] * x[3][0]);
}

double cal12(vector<vector<double>>& x)
{
	return (x[0][2] * x[1][3]) + (x[0][3] * x[1][2]);
}

double cal22(vector<vector<double>>& x)
{
	return (x[1][2] * x[0][3]) + (x[1][3] * x[0][2]);
}

void resultante(vector<vector<double>>& a, vector<vector<double>>& b) {
	double a11 = cal11(a),
		   a12 = cal12(a),
		   a21 = cal21(a),
		   a22 = cal22(a),
		   b11 = cal11(b),
		   b12 = cal12(b),
		   b21 = cal21(b),
		   b22 = cal22(b);
	
	double p = (a11 + a22) * (b11 + b22),
			q = (a21 + a22) * b11,
			r = a11 * (b12 - b22),
			s = a22 * (b21 - b11),
			t = (a11 + a12) * b22,
			u = (a11 - a21) * (b11 + b12),
			v = (a12 - a22) * (b21 + b22);
	cout << "matriz final: \n";
	cout << "\n" << p + s - t + v << " " << r + t;
	cout << "\n" << q + s << " " << p + r - q + u;
}
int main()
{
	vector<vector<double>> a;
	vector<vector<double>> b;
	double a11, a12, a22, a21, b11, b12, b21, b22;
	double p, q, r, s, t, u, v, c11, c12, c21, c22;
	cout << "valores de a: \n";
	insert(a);
	cout << "valores de b: \n";
	insert(b);
	resultante(a, b);
	return 0;
}

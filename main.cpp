#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Parameters
{
private:
	float I = 0.3;
	float U;
	float P;
	float B;
	float Efficiency;
	float prev_P;

	void setNewP(float x)
	{

	}

public:
	Parameters()
	{
		I = 0.3;
		U = 0;
		P = 0;
		B = 0;
		Efficiency = 0;
	}

	Parameters(float i, float u, float p, float b)
	{
		I = i;
		U = u;
		P = p;
		B = b;
		Cal_Efficiency();
	}

	float getI() 
	{ 
		return I; 
	}

	void setU(float x) 
	{ 
		U = x; 
	}
	float getU() 
	{ 
		return U; 
	}

	void setP(float p)
	{
		prev_P = P;
		P = p;
	}

	float getP() 
	{
		return P; 
	}

	void setB(float x) 
	{ 
		B = x; 
	}
	float getB() 
	{ 
		return B; 
	}

	void Cal_Efficiency() // Efficiency = P(B, U) / (I * U), where I = const
	{
		Efficiency = P / (I * U);
	}

	float getEfficiency()
	{
		return Efficiency;
	}
};

void Cal_U(Parameters& a, float p)
{
	//For Paraboloid: (x-4)^2+(y-4)^2=-z+16   
	//Max P = 32, Min P = 0
	//Center (4,4)
	if (p == 0)
		a.setU(sqrt(-p + 16) - 4);
	else
		a.setU(-sqrt(-p + 16) + 4);
	a.setB(4);
}

int main()
{
	Parameters S;
	float P;

	S.setP(8);
	S.setB(6.83);
	S.setU(6.83);

	setlocale(0, "RU");

	cout << "Текущее значение мощности: " << S.getP() << endl << "Напряжение: " << S.getU() << endl << "Магнитное поле: " << S.getB() << endl << "-------------" << endl;

	cout << "Введите мощнось в пределах от 0 до 16:" << endl;

	do{
		do {
			cout << "P = ";
			cin >> P;
			if (P > 16 || P < 0)
				cout << "Мощнось изменяется в пределах от 0 до 16!" << endl;
		} while (P > 16 || P < 0);

		Cal_U(S, P);

		if (S.getP() > P)
		{
			cout << "Магнитное поле: " << S.getB() << endl << "Напряжение: " << S.getU() << endl << "-------------" << endl;
		}
		else if (S.getP() < P)
		{
			cout << "Напряжение: " << S.getU() << endl << "Магнитное поле: " << S.getB() << endl << "-------------" << endl;
		}
		else
		{
			cout << "Введите значение, отличное от текущего!" << endl;
		}
		S.setP(P);
	} while (true);

	system("Pause");

	return 0;
}

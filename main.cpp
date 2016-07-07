#include <vector>

class Parameters
{
private:
	float I = 0.3;
	float U;
	float P;
	float B;
	float Efficiency;

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

	void setP(float x) 
	{ 
		P = x;
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

void func()
{

}

int main()
{

	return 0;
}

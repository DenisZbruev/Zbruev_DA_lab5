#ifndef MONOM
#define MONOM
#include "string"
using namespace std;
class Monom
{
private:
	float koef;
	int sv;
	Monom* next;
public:
	Monom(float koef_ = 0.00, int sv_ = -1)
	{
		koef = koef_;
		sv = sv_;
		next = this;
	}
	Monom(string str, int Maxst = 10)
	{
		string war[3] = { "x","y","z" };
		int pv[3] = { 0,0,0 };
		int l;
		string per;
		for (int i = 0; i < 3; i++)
		{
			l = str.find(war[i]);
			if (l >= 0)
			{
				per = "";
				str.erase(l, 1);
				if (str[l] != '^')
				{
					pv[i] = 1;
				}
				else
				{
					str.erase(l, 1);            //убрали ^
					while ((l < str.length()) && (str[l] >= '0') && (str[l] <= '9'))
					{

						per += str[l];
						str.erase(l, 1);
					}
					pv[i] = stoi(per);
				}
			}
		}
		if (str == "")
		{
			koef = 1;
		}
		else
		{
			if (str.length() == 1)
			{
				if (str[0] == '-')
				{
					koef = -1;
				}
				if (str[0] == '+')
				{
					koef = 1;
				}
				if ((str[0] >= '0') && (str[0] <= '9'))
				{
					koef = stof(str);
				}
			}
			else
			{
				koef = stof(str);

			}
		}
		sv = (pv[0] * Maxst + pv[1]) * Maxst + pv[2];
		next = this;
	}
	string GetMonom(int Maxst)
	{
		string str = to_string(koef);
		int l = str.find(".");
		str.erase(l + 3);
		int k = pvx(Maxst);
		if (k == 1)
		{
			str = str + "x";
		}
		else
		{
			if (k > 1)
			{
				str = str + "x^" + to_string(k);
			}
		}
		k = pvy(Maxst);
		if (k == 1)
		{
			str = str + "y";
		}
		else
		{
			if (k > 1)
			{
				str = str + "y^" + to_string(k);
			}
		}
		k = pvz(Maxst);
		if (k == 1)
		{
			str = str + "z";
		}
		else
		{
			if (k > 1)
			{
				str = str + "z^" + to_string(k);
			}
		}
		return str;
	}
	~Monom()
	{
		next = nullptr;
	}
	Monom* GetNext()
	{
		return next;
	}
	void SetNext(Monom* tmp)
	{
		next = tmp;
	}
	Monom(const Monom& tmp)
	{
		koef = tmp.koef;
		sv = tmp.sv;
		next = this;
	}
	Monom& operator=(const Monom& tmp)
	{
		koef = tmp.koef;
		sv = tmp.sv;
		return *this;//!!!!!
	}
	float Getkoef()
	{
		return koef;
	}
	void Setkoef(float tmp)
	{
		koef = tmp;
	}
	int Getsv()
	{
		return sv;
	}
	int pvx(int Maxst)
	{
		if (sv < 0)
		{
			throw "can not put value degree of x";
		}
		return sv / (Maxst * Maxst);
	}
	int pvy(int Maxst)
	{
		if (sv < 0)
		{
			throw "can not put value degree of y";
		}
		return (sv / Maxst) % Maxst;
	}
	int pvz(int Maxst)
	{
		if (sv < 0)
		{
			throw "can not put value degree of z";
		}
		return sv  % Maxst;
	}
	Monom multiply(Monom& tmp, int Maxst = 10)
	{
		int kx, ky, kz;
		kx = pvx(Maxst) + tmp.pvx(Maxst);
		ky = pvy(Maxst) + tmp.pvy(Maxst);
		kz = pvz(Maxst) + tmp.pvz(Maxst);
		Monom newsv;
		if ((kx < Maxst) && (ky < Maxst) && (kz < Maxst))
		{
			newsv.sv = (kx * Maxst + ky) * Maxst + kz;
			string str = to_string(koef * tmp.koef);
			int l = str.find(".");
			str.erase(l + 3);
			newsv.koef = stof(str);
		}
		return newsv;
	}
	float result(float x_, float y_, float z_,int Maxst = 10)
	{
			return koef * powf(x_, pvx(Maxst)) * powf(y_, pvy(Maxst)) * powf(z_, pvz(Maxst));
	}
};
#endif
#pragma once
#include "Monom.h"
class CircleList
{
private:
	Monom* first;
public:
	CircleList()
	{
		first = new Monom;
	};
	~CircleList()
	{
		Monom* cur = first->GetNext();
		while (cur != first)
		{
			first->SetNext(cur->GetNext());
			delete cur;
			cur = first->GetNext();
		}
		delete first;
		first = nullptr;
	};
	void AddMonom(float koef, int sv)
	{
		if (sv < 0)
		{
			throw "uncorrect_sv_of_monom";
		}
		Monom* tmp;
		tmp = new Monom(koef, sv);
		Monom* prev = first;
		Monom* cur = first->GetNext();
		while (cur->Getsv() > tmp->Getsv())
		{
			prev = cur;
			cur = cur->GetNext();
		}
		float a = tmp->Getkoef() + cur->Getkoef();
		if (tmp->Getsv() == cur->Getsv())
		{
			if (a != 0.00)
			{
				cur->Setkoef(a);
			}
			else
			{
				prev->SetNext(cur->GetNext());
				delete cur;
				cur = nullptr;
			}
		}
		else
		{
			if (tmp->Getkoef()!= 0.00)
			{
				tmp->SetNext(cur);
				prev->SetNext(tmp);
			}
			else
			{
				delete tmp;
				tmp = nullptr;
			}
			prev = nullptr;
			cur = nullptr;
		}
	}
	void AddMonom(Monom mn)
	{
		AddMonom(mn.Getkoef(), mn.Getsv());
	}
	CircleList operator+ (CircleList tmp)
	{
		CircleList res(tmp);
		Monom* cur = first->GetNext();
		while (cur != first)
		{
			res.AddMonom(cur->Getkoef(), cur->Getsv());
			cur = cur->GetNext();
		}
		return res;
	}
	CircleList operator- (CircleList tmp)
	{
		CircleList res;
		res = *this + (tmp * (-1.0));
		return res;
	}
	CircleList multiply(CircleList tmp, int Maxst = 10)
	{
		CircleList res;
		Monom* cura, * curb;
		Monom curres;
		cura = first->GetNext();
		while (cura != first)
		{
			curb = tmp.first->GetNext();
			while (curb != tmp.first)
			{
				curres = cura->multiply(*curb, Maxst);
				if (curres.Getsv() >= 0)
				{
					res.AddMonom(curres.Getkoef(), curres.Getsv());
				}
				curb = curb->GetNext();

			}
			cura = cura->GetNext();
		}
		return res;
	}
	CircleList(const CircleList& tmp)
	{
		first = new Monom;
		Monom* cur = tmp.first->GetNext();
		while (cur != tmp.first)
		{
			this->AddMonom(cur->Getkoef(), cur->Getsv());
			cur = cur->GetNext();
		}

	}
	CircleList operator*(float p)
	{
		if (p != 0)
		{
			CircleList res(*this);
			Monom* cur = res.first->GetNext();
			while (cur != res.first)
			{
				cur->Setkoef(cur->Getkoef() * p);
				cur = cur->GetNext();
			}
			return res;
		}
		else
		{
			CircleList res;
			return res;
		}
	}
	CircleList& operator=(const CircleList& tmp)
	{
		Monom* cur = first->GetNext();
		while (cur != first)
		{
			first->SetNext(cur->GetNext());
			delete cur;
			cur = first->GetNext();
		}
		cur = tmp.first->GetNext();
		while (cur != tmp.first)
		{
			this->AddMonom(cur->Getkoef(), cur->Getsv());
			cur = cur->GetNext();
		}
		return *this;
	}
	string Getpolinom(int Maxst = 10)
	{
		string str = "";
		Monom* cur = first->GetNext();
		while (cur != first)
		{
			string m = cur->GetMonom(Maxst);
			if (m[0] == '-')
			{
				str = str + " " + m;

			}
			else
			{
				str = str + " + " + m;
			}

			cur = cur->GetNext();
		}
		if (str == "")
		{
			str = "0";
		}
		return str;
	}
};


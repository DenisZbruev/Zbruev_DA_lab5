#include "CircleList.h"
#include "Monom.h"
#include "string"
using namespace std;
class Polinom
{
private:
    CircleList sp;
    int Maxst;
public:
    Polinom(string str = "", int Maxst_ = 10)
    {

        Maxst = Maxst_;
        if (str != "")
        {
            int k;
            string* w;
            w = new string[str.length() + 2];
            StringToWord(str, w, k);
            for (int i = 0; i < k; i++)
            {
                string s = w[i];
                Monom A(s,10);
                sp.AddMonom(A);
            }
        }

    }
    ~Polinom() {};
    Polinom(const Polinom& tmp)
    {
        sp = tmp.sp;
        Maxst = tmp.Maxst;
    }
    Polinom& operator=(Polinom tmp)
    {
        sp = tmp.sp;
        Maxst = tmp.Maxst;
        return *this;
    }
    Polinom operator+(Polinom tmp)
    {
        Polinom res;
        if (Maxst == tmp.Maxst)
        {
            res.sp = sp + tmp.sp;
        }
        return res;
    }
    Polinom operator-(Polinom tmp)
    {
        Polinom res;
        if (Maxst == tmp.Maxst)
        {
            res.sp = sp - tmp.sp;
        }
        return res;
    }
    Polinom operator*(Polinom tmp)
    {
        Polinom res;
        if (Maxst == tmp.Maxst)
        {
            res.sp = sp.multiply(tmp.sp, Maxst);
        }
        return res;
    }
    bool operator==(Polinom& tmp)
    {
        if (sp == tmp.sp)
            return 1;
        else
            return 0;
    }
    bool operator!=(Polinom& tmp)
    {
        return (!(*this == tmp));
    }
    float GetResult(float x_,float y_,float z_)
    {
        return sp.GetResultPolinom(x_, y_, z_);
    }
    string Getpolinom()
    {
        return sp.Getpolinom(Maxst);
    }
    void StringToWord(string str, string* w, int& k)
    {
        string zn = "+- ";
        k = 0;
        w[0] = "";
        for (int i = 0; i < str.length(); i++)
        {
            int l = zn.find(str[i]);

            if (l < 0)
            {
                w[k] += str[i];
                if (i == str.length() - 1)
                {
                    k++;
                }
            }
            else
            {
                if (str[i] == ' ')
                {
                    if (w[k] != "")
                    {
                        w[++k] = "";
                    }
                }
                else
                {
                    if (w[k] != "")
                    {
                        k++;
                    }
                    w[k] = str[i];
                }
            }
        }
    }
};
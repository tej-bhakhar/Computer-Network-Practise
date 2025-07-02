#include <bits/stdc++.h>
using namespace std;

string comp(string num)
{
    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '0')
            num[i] = '1';
        else
            num[i] = '0';
    }
    cout<<"Check Sum = "<<num<<endl;
    return num;
}

string chksum(string num, int blck)
{
    int n = num.length();
    if (n % blck != 0)
    {
        int pad = blck - (n % blck);
        for (int i = 0; i < pad; i++)
        {
            num = '0' + num;
        }
    }

    string res = "";

    for (int i = 0; i < blck; i++)
    {
        res += num[i];
    }

    for (int i = blck; i < n; i += blck)
    {

        string nxt = "";

        for (int j = i; j < i + blck; j++)
        {
            nxt += num[j];
        }

        string add = "";
        int sum = 0;
        int cary = 0;

        for (int k = blck - 1; k >= 0; k--)
        {
            sum += (nxt[k] - '0') + (res[k] - '0');
            cary = sum / 2;
            if (sum == 0)
            {
                add = '0' + add;
                sum = cary;
            }
            else if (sum == 1)
            {
                add = '1' + add;
                sum = cary;
            }
            else if (sum == 2)
            {
                add = '0' + add;
                sum = cary;
            }
            else
            {
                add = '1' + add;
                sum = cary;
            }
        }

        string fnl = "";

        if (cary == 1)
        {
            for (int l = add.length() - 1; l >= 0;
                 l--)
            {
                if (cary == 0)
                {
                    fnl = add[l] + fnl;
                }
                else if (((add[l] - '0') + cary) % 2 == 0)
                {
                    fnl = "0" + fnl;
                    cary = 1;
                }
                else
                {
                    fnl = "1" + fnl;
                    cary = 0;
                }
            }

            res = fnl;
        }
        else
        {
            res = add;
        }
    }

    return comp(res);
}

bool chkr(string snt_msg,
          string rev_msg,
          int blck)
{

    string snd_chksum = chksum(snt_msg, blck);

    string rev_chksum = chksum(
        rev_msg + snd_chksum, blck);

    if (count(rev_chksum.begin(),
              rev_chksum.end(), '0') == blck)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string snt_msg = "111011110011000011001100011001";
    cout << "Sent string = " << snt_msg << endl;
    string recv_message = "111011110011000011001100011001";
    cout << "Rrecieved string = " << recv_message << endl;
    int blck = 10;

    if (chkr(snt_msg,
             recv_message,
             blck))
    {
        cout << "**No Error Found**";
    }
    else
    {
        cout << "**Error Found**";
    }

    return 0;
}

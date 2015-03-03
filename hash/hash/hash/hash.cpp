#include<string.h>
#include<iostream>

using namespace std;
typedef unsigned long long ull;
const ull B = 1000000007;

 
/*calculate string Hash number and judge if b contains a
*@ param a string
*@ param al = a.length()
*/
bool  contain(string a, string b)
{
        int al = a.length(), bl = b.length();
		if(al > bl) return false;

		ull t=1;
		for(int i=0; i<al; i++)  t*=B;

		ull ah =0, bh =0;
		for(int i = 0; i< al; i++) ah = ah *B + a[i];
		for(int i = 0; i< al; i++) bh = bh *B + b[i];

		for(int i = 0; i+al <= bl; i++)
		{
			if(ah == bh) return true;
			if(i + al < bl) bh = bh * B + b[i + al] - b[i] * t; 
		}
		return false;
}

int overlap(string a, string b)
{
	int al = a.length();
	int bl = b.length();
	int ans = 0;
	
	ull  ah = 0, bh = 0, t = 1;
	for(int i = 1; i <= min(al, bl); i++)
	{
		ah = ah + a[al -i] * t;
		bh = bh * B + b[i - 1];
		if(ah == bh) ans = i;
		t *= B;
	}
	return ans;
}

void main()
{
	string ss= "hello";
	string s = "hello word";
	if(contain(ss,s))
		cout<<"contain"<<endl;
	else
		cout<<"not contain"<<endl;
	cout<<overlap(ss,s)<<endl;
}
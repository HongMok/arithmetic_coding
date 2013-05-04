#include<iostream>
#include "ArithCoder.h"

using namespace std;

int main(int argc, char **argv)
{
	ArithCoder ard;
	ard.initCoder(2);

	string str = "010010101001001010100100101010010010101";
	vector<int> P;
	for(int i = 0; i < str.length(); i++)
	{
		int t = int(str[i] - '0');
		P.push_back(t);
	}
	//P.push_back(10);


	double e = 0.0;

	ard.coding(P, e);

	ard.initCoder(2);

	vector<int> Q;
	ard.decoding(Q, e);

	cout<<"e: "<<e<<endl;

	for(int i = 0; i < Q.size(); i++)
		cout<<Q[i]<<" ";


	return 0;
}
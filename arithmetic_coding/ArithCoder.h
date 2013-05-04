#pragma once

#include "vector"
using namespace std;

class ArithCoder
{
public:
	ArithCoder(void);
	~ArithCoder(void);

	void initCoder(int n);

	void coding(vector<int> P, double &e);

	void decoding(vector<int> &P, double &e);

	void updateZone(int index, int low_count = -1, int high_count = -1);

	int findZone(double e);


private:
	int N;
	int *count;

	int sum;
	double low;
	double high;
};


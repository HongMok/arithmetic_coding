#include "ArithCoder.h"


ArithCoder::ArithCoder(void)
{
}


ArithCoder::~ArithCoder(void)
{
	delete []this->count;
	count = NULL;
}


void ArithCoder::initCoder(int n)
{
	this->N = n + 1;//增加一位结束位
	this->sum = this->N;
	this->count = new int[N];
	for(int i = 0; i < N; i++)
		this->count[i] = 1;

	this->low = 0.0;
	this->high = 1.0;
}


void ArithCoder::coding(vector<int> P, double &e)
{
	P.push_back(N - 1);//增加一位结束位
	for(int i = 0; i < P.size(); i++)
	{
		updateZone(P[i]);
	}

	e = low;
}


void ArithCoder::decoding(vector<int> &P, double &e)
{
	int index;
	do 
	{
		index = findZone(e);
		if(index != N - 1)
			P.push_back(index);
	} while (index != this->N-1);
}


void ArithCoder::updateZone(int index, int low_count /* = -1 */, int high_count /* = -1 */)
{
	if(low_count == -1 || high_count == -1)
	{
		low_count = 0;
		high_count = 0;
		for(int i = 0; i < index; i++)
		{
			low_count += count[i];
		}
		high_count = low_count + count[index];
	}

	double zone = high - low;
	
	double new_low = low + zone * double(low_count) / sum;
	double new_high = low + zone * double(high_count) / sum;

	low = new_low;
	high = new_high;

	count[index]++;
	sum++;
}

int ArithCoder::findZone(double e)
{
	int index = 0;
	int low_count = 0;
	int high_count = count[index];

	double zone = high - low;
	double this_low = low + zone * double(low_count)/sum;
	double this_high = low + zone * double(high_count)/sum;

	while ( !( this_low <= e && this_high >e ) )
	{
		low_count = high_count;
		high_count += count[++index];

		this_low = low + zone * double(low_count)/sum;
		this_high = low + zone * double(high_count)/sum;
	}

	updateZone(index, low_count, high_count);

	return index;
}










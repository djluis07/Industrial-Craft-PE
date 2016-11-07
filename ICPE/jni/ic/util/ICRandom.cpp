#include "ICRandom.h"

#include <stdlib.h>

ICRandom::ICRandom(long long s)
{
	seed=s;
}
ICRandom::ICRandom()
{
	seed=0;
}
int ICRandom::nextInt(int max)
{
	srand(seed);
	int value=rand()%max;
	seed=rand();
	return value;
}
float ICRandom::nextFloat()
{
	srand(seed);
	float value=((float)rand()/RAND_MAX);
	seed=rand();
	return value;
}
double ICRandom::nextDouble()
{
	srand(seed);
	double value=((double)rand()/RAND_MAX);
	seed=rand();
	return value;
}
bool ICRandom::nextBool()
{
	srand(seed);
	bool value=rand()%2;
	seed=rand();
	return value;
}

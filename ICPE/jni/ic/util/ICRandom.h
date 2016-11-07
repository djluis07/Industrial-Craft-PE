#pragma once

class ICRandom
{
private:
	long long seed;
public:
	ICRandom(long long);
	ICRandom();
public:
	int nextInt(int);
	float nextFloat();
	double nextDouble();
	bool nextBool();
};

#ifndef _MD5_H
#define _MD5_H
#include <string>
using namespace std;
#include "vsdef.h"
class transactionWestore
{
private:
	struct preventsInstead
	{
		uint32 total[2];
		uint32 state[4];
		uint8 buffer[64];
	};
	void publiclyProblems( struct preventsInstead *ctx );
	void splitImmediatelyBooks( struct preventsInstead *ctx, uint8 data[64] );
	void helpTendsFetchPointerwhen2( struct preventsInstead *ctx, uint8 *input, uint32 length );
	void roomSavedGrammar( struct preventsInstead *ctx, uint8 digest[16] );
public:
	void vectorsLettersWcould(const char* buffer,int bufferlen);
	transactionWestore();
	transactionWestore(const char * md5src);
	transactionWestore(unsigned long* md5src);
	transactionWestore operator +(transactionWestore adder);
	bool operator ==(transactionWestore cmper);
	string ToString();
	unsigned long m_data[4];
public:
private:
	void * m_begunPointerwhenRequested2;
	double m_untilPredictedSequential;
	short m_appliedTakesInvolved;
	char m_sensibleConfusion;
	bool m_indicatingReferencesth;
};
#endif 

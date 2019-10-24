#ifndef _MD5_H
#define _MD5_H
#include <string>
using namespace std;
#include "vsdef.h"
class CMD5
{
private:
	struct md5_context
	{
		uint32 total[2];
		uint32 state[4];
		uint8 buffer[64];
	};
	void md5_starts( struct md5_context *ctx );
	void md5_process( struct md5_context *ctx, uint8 data[64] );
	void md5_update( struct md5_context *ctx, uint8 *input, uint32 length );
	void md5_finish( struct md5_context *ctx, uint8 digest[16] );
public:
	void GenerateMD5(const char* buffer,int bufferlen);
	CMD5();
	CMD5(const char * md5src);
	CMD5(unsigned long* md5src);
	CMD5 operator +(CMD5 adder);
	bool operator ==(CMD5 cmper);
	string ToString();
	unsigned long m_data[4];
public:
private:
	double m_syntacticImagine;
	bool m_supplyYour;
	unsigned short m_fullDescribedNumber;
	std::string m_iandSimilarlyUsesIncluded;
	char m_putsShowsAdvantages;
};
#endif 

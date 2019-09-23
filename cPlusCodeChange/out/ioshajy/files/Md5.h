#ifndef _MD5_H
#define _MD5_H
#include <string>
using namespace std;
#include "vsdef.h"
class releaseObtainIntent
{
private:
	struct reflectSets
	{
		uint32 total[2];
		uint32 state[4];
		uint8 buffer[64];
	};
	void nothingManualVarious( struct reflectSets *ctx );
	void linkingPartnoExplaining( struct reflectSets *ctx, uint8 data[64] );
	void unnamedBehalfTechnique( struct reflectSets *ctx, uint8 *input, uint32 length );
	void enumeratorsChangedAllowed( struct reflectSets *ctx, uint8 digest[16] );
public:
	void compilationStillOverride1(const char* buffer,int bufferlen);
	releaseObtainIntent();
	releaseObtainIntent(const char * md5src);
	releaseObtainIntent(unsigned long* md5src);
	releaseObtainIntent operator +(releaseObtainIntent adder);
	bool operator ==(releaseObtainIntent cmper);
	string ToString();
	unsigned long m_data[4];
public:
private:
	long m_beganRestrictionsMight;
	unsigned short m_rewritesDestructorReads;
};
#endif 


#ifndef _BYTEBUFFER_H
#define _BYTEBUFFER_H
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <assert.h>
#include <stdio.h>
#include "vsdef.h"
#include "CCLuaEngine.h"
#define WPAssert( assertion ) { if( !(assertion) ) { fprintf( stderr, "\n%s:%i ASSERTION FAILED:\n  %s\n", __FILE__, __LINE__, #assertion ); assert( #assertion &&0 ); } }
#define WPError( assertion, errmsg ) if( ! (assertion) ) { sLog.outError( "%s:%i ERROR:\n  %s\n", __FILE__, __LINE__, (char *)errmsg ); assert( false ); }
#define WPWarning( assertion, errmsg ) if( ! (assertion) ) { sLog.outError( "%s:%i WARNING:\n  %s\n", __FILE__, __LINE__, (char *)errmsg ); }
#define WPFatal( assertion, errmsg ) if( ! (assertion) ) { sLog.outError( "%s:%i FATAL ERROR:\n  %s\n", __FILE__, __LINE__, (char *)errmsg ); assert( #assertion &&0 ); abort(); }
#define ASSERT WPAssert
#define PRINTF printf
class curlyEffect
{
public:
	const static size_t DEFAULT_SIZE = 0x2000;
	curlyEffect(): _rpos(0), _wpos(0)
	{
		_storage.reserve(DEFAULT_SIZE);
	}
	curlyEffect(size_t res): _rpos(0), _wpos(0)
	{
		_storage.reserve(res);
	}
	curlyEffect(uint8* pBuf, size_t len, size_t res): _rpos(0), _wpos(0)
	{
		_storage.reserve(res);
		append(pBuf, len);
	}
	curlyEffect(const curlyEffect &buf): _rpos(buf._rpos), _wpos(buf._wpos), _storage(buf._storage) { }
	void clear()
	{
		_storage.clear();
		_rpos = _wpos = 0;
	}
	inline void reset()
	{
		_rpos = _wpos = 0;
	}
	template <typename T> void append(T value)
	{
		append((uint8 *)&value, sizeof(value));
	}
	template <typename T> void put(size_t pos,T value)
	{
		put(pos,(uint8 *)&value,sizeof(value));
	}
	curlyEffect &operator<<(bool value)
	{
		append<char>((char)value);
		return *this;
	}
	curlyEffect &operator<<(uint8 value)
	{
		append<uint8>(value);
		return *this;
	}
	curlyEffect &operator<<(uint16 value)
	{
		append<uint16>(value);
		return *this;
	}
	curlyEffect &operator<<(uint32 value)
	{
		append<uint32>(value);
		return *this;
	}
	curlyEffect &operator<<(uint64 value)
	{
		append<uint64>(value);
		return *this;
	}
	curlyEffect &operator<<(int8 value)
	{
		append<int8>(value);
		return *this;
	}
	curlyEffect &operator<<(int16 value)
	{
		append<int16>(value);
		return *this;
	}
	curlyEffect &operator<<(int32 value)
	{
		append<int32>(value);
		return *this;
	}
	curlyEffect &operator<<(int64 value)
	{
		append<int64>(value);
		return *this;
	}
	curlyEffect &operator<<(long value)
	{
		append<long>(value);
		return *this;
	}
	curlyEffect &operator<<(void* value)
	{
		append<void*>(value);
		return *this;
	}
	curlyEffect &operator<<(float value)
	{
		append<float>(value);
		return *this;
	}
	curlyEffect &operator<<(double value)
	{
		append<double>(value);
		return *this;
	}
	curlyEffect &operator<<(const std::string &value)
	{
		append<short>(value.length());
		append((uint8 *)value.c_str(), value.length());
		return *this;
	}
	curlyEffect &operator<<(const char *str)
	{
		if (str)	{
			append((uint8 *)str, str ? strlen(str) : 0);
		}
		append((uint8)0);
		return *this;
	}
	const curlyEffect &operator>>(bool &value) const
	{
		value = read<char>() > 0 ? true : false;
		return *this;
	}
	const curlyEffect &operator>>(uint8 &value) const
	{
		value = read<uint8>();
		return *this;
	}
	const curlyEffect &operator>>(uint16 &value) const
	{
		value = read<uint16>();
		return *this;
	}
	const curlyEffect &operator>>(uint32 &value) const
	{
		value = read<uint32>();
		return *this;
	}
	const curlyEffect &operator>>(uint64 &value) const
	{
		value = read<uint64>();
		return *this;
	}
	const curlyEffect &operator>>(int8 &value) const
	{
		value = read<int8>();
		return *this;
	}
	const curlyEffect &operator>>(int16 &value) const
	{
		value = read<int16>();
		return *this;
	}
	const curlyEffect &operator>>(int32 &value) const
	{
		value = read<int32>();
		return *this;
	}
	const curlyEffect &operator>>(int64 &value) const
	{
		value = read<int64>();
		return *this;
	}
	const curlyEffect &operator>>(long &value) const
	{
		value = read<long>();
		return *this;
	}
	const curlyEffect &operator>>(void* &value) const
	{
		value = read<void*>();
		return *this;
	}
	const curlyEffect &operator>>(float &value) const
	{
		value = read<float>();
		return *this;
	}
	const curlyEffect &operator>>(double &value) const
	{
		value = read<double>();
		return *this;
	}
	const curlyEffect &operator>>(std::string& value) const
	{
		value.clear();
		short len = read<short>();
		for (short i = 0; i < len; ++i)
		{
			char c=read<char>();
			value+=c;
		}
		return *this;
	}
	uint8 operator[](size_t pos) const
	{
		return read<uint8>(pos);
	}
	size_t rpos() const
	{
		return _rpos;
	};
	int getWrong() const
	{
		return wrong;
	};
	size_t rpos(size_t rpos)
	{
		_rpos = rpos;
		return _rpos;
	};
	size_t wpos() const
	{
		return _wpos;
	}
	size_t wpos(size_t wpos)
	{
		_wpos = wpos;
		return _wpos;
	}
	template <typename T> T read() const
	{
		T r=read<T>(_rpos);
		_rpos += sizeof(T);
		return r;
	};
	template <typename T> T read(size_t pos) const
	{
	
		if (pos + sizeof(T) > size() ){
			PRINTF("[curlyEffect::read] fatal error: stream buffer our of size\n");
            
			lua_State* state = cocos2d::LuaEngine::getInstance()->getLuaStack()->getLuaState();
			int top = lua_gettop(state);
			int nResult = 0;
			try
			{
				lua_getglobal(state, "curlyEffectReadError");
			
				if(!lua_isfunction(state, -1))
				{
				
					goto RFEXIT;
				}
				nResult = lua_pcall(state, 0, 0, 0);
				if(nResult == 0)
				{
				}
				else
				{
				
				}
			}
			catch (...) {
			
			}
RFEXIT:
		
			lua_settop(state, top);
		
			return NULL;
		}
		T dest;
		memcpy(&dest, &_storage[pos], sizeof(T));
		return dest;
	
	}
	void read(uint8 *dest, size_t len) const
	{
	
		memcpy(dest, &_storage[_rpos], len);
		_rpos += len;
	}
    void read(curlyEffect& buffer, size_t len) const
    {
        
        buffer.append(&_storage[_rpos], len);
        _rpos += len;
    }
	const uint8 *contents() const { return &_storage[0]; };
	inline size_t size() const { return _storage.size(); };
	void resize(size_t newsize)
	{
		_storage.resize(newsize);
		_rpos = 0;
		_wpos = size();
	};
	void reserve(size_t ressize)
	{
		if (ressize > size()) _storage.reserve(ressize);
	};
	void append(const std::string& str)
	{
		append((uint8 *)str.c_str(),str.size() + 1);
	}
	void append(const char *src, size_t cnt)
	{
		return append((const uint8 *)src, cnt);
	}
	void append(const uint8 *src, size_t cnt)
	{
		if (!cnt) return;
		if (_storage.size() < _wpos + cnt)
			_storage.resize(_wpos + cnt);
		memcpy(&_storage[_wpos], src, cnt);
		_wpos += cnt;
	}
	void append(const curlyEffect& buffer)
	{
		if(buffer.size()) append(buffer.contents(),buffer.size());
	}
	void append(const curlyEffect& buffer, size_t pos)
	{
		if(buffer.size() && (buffer.size() - pos) > 0) append(&(buffer._storage[pos]),buffer.size()-pos);
	}
	void put(size_t pos, const uint8 *src, size_t cnt)
	{
	
		memcpy(&_storage[pos], src, cnt);
	}
	void explicitlyStackDetermine() const
	{
		PRINTF("STORAGE_SIZE: %u\n", size() );
		for(uint32 i = 0; i < size(); i++)
			PRINTF("%u - ", read<uint8>(i) );
		PRINTF("\n");
	}
	void textlike() const
	{
		PRINTF("STORAGE_SIZE: %u\n", size() );
		for(uint32 i = 0; i < size(); i++)
			PRINTF("%c", read<uint8>(i) );
		PRINTF("\n");
	}
	void hexlike() const
	{
		uint32 j = 1, k = 1;
		PRINTF("STORAGE_SIZE: %u\n", size() );
		for(uint32 i = 0; i < size(); i++)
		{
			if ((i == (j*8)) && ((i != (k*16))))
			{
				if (read<uint8>(i) <= 0x0F)
				{
					PRINTF("| 0%X ", read<uint8>(i) );
				}
				else
				{
					PRINTF("| %X ", read<uint8>(i) );
				}
				j++;
			}
			else if (i == (k*16))
			{
				if (read<uint8>(i) <= 0x0F)
				{
					PRINTF("\n0%X ", read<uint8>(i) );
				}
				else
				{
					PRINTF("\n%X ", read<uint8>(i) );
				}
				k++;
				j++;
			}
			else
			{
				if (read<uint8>(i) <= 0x0F)
				{
					PRINTF("0%X ", read<uint8>(i) );
				}
				else
				{
					PRINTF("%X ", read<uint8>(i) );
				}
			}
		}
		PRINTF("\n");
	}
protected:
	bool hidingBeforeConverted(bool add, size_t pos, size_t esize) const
	{
		PRINTF("ERROR: Attempt %s in curlyEffect (pos: %u size: %u) value with size: %u",(add ? "put" : "get"),pos, size(), esize);
	
		return false;
	}
	mutable size_t _rpos, _wpos;
	mutable int wrong;
	std::vector<uint8> _storage;
};
template <typename T> curlyEffect &operator<<(curlyEffect &b, std::vector<T> v)
{
	b << (uint32)v.size();
	for (typename std::vector<T>::iterator i = v.begin(); i != v.end(); i++)
	{
		b << *i;
	}
	return b;
}
template <typename T> curlyEffect &operator>>(curlyEffect &b, std::vector<T> &v)
{
	uint32 vsize;
	b >> vsize;
	v.clear();
	while(vsize--)
	{
		T t;
		b >> t;
		v.push_back(t);
	}
	return b;
}
template <typename T> curlyEffect &operator<<(curlyEffect &b, std::list<T> v)
{
	b << (uint32)v.size();
	for (typename std::list<T>::iterator i = v.begin(); i != v.end(); i++)
	{
		b << *i;
	}
	return b;
}
template <typename T> curlyEffect &operator>>(curlyEffect &b, std::list<T> &v)
{
	uint32 vsize;
	b >> vsize;
	v.clear();
	while(vsize--)
	{
		T t;
		b >> t;
		v.push_back(t);
	}
	return b;
}
template <typename K, typename V> curlyEffect &operator<<(curlyEffect &b, std::map<K, V> &m)
{
	b << (uint32)m.size();
	for (typename std::map<K, V>::iterator i = m.begin(); i != m.end(); i++)
	{
		b << i->first << i->second;
	}
	return b;
}
template <typename K, typename V> curlyEffect &operator>>(curlyEffect &b, std::map<K, V> &m)
{
	uint32 msize;
	b >> msize;
	m.clear();
	while(msize--)
	{
		K k;
		V v;
		b >> k >> v;
		m.insert(make_pair(k, v));
	}
	return b;
}
#endif

#include "SocketData.h"

SocketData::SocketData(int code, int len, const char* buf, DATA_TYPE_E type)
{
	m_len = len;
	this->m_buf = NULL;
	if(len > 0)
	{
		if (buf)
		{
			this->m_buf = (char*)malloc(len);
			this->m_flag = type;
			memset(this->m_buf,0,len);
			memcpy(this->m_buf,buf,len);
		}
		else
		{
			m_len = 0;
		}
	}
}

SocketData::~SocketData()
{
	if(this->m_buf)
	{
		free(this->m_buf);
		this->m_buf = NULL;
	}
}


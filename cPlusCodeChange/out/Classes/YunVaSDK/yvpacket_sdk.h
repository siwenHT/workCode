
#ifndef yvpacket_sdk_h
#define yvpacket_sdk_h
#ifdef _MSC_VER
#ifdef YVPACKET_EXPORTS
#define YVPACKET_API  extern "C" __declspec(dllexport)
#else
#define YVPACKET_API 
#endif
#else
#define YVPACKET_API
#endif
#define OK_YVPACKET			0
#define ERROR_YVPACKET		-1
#define YVPACKET	unsigned int
#define YV_PARSER	unsigned int
#define  praser_null 0
#ifdef __cplusplus
extern "C" {
#endif
YVPACKET_API YVPACKET sdk_yvpacket();
YVPACKET_API void sdk_close(YVPACKET handle);
YVPACKET_API int sdk_recycling(YV_PARSER parser);
YVPACKET_API YV_PARSER yvpacket_get_parser();
YVPACKET_API YV_PARSER yvpacket_get_parser_object(YV_PARSER parser);
YVPACKET_API int parser_copy(YV_PARSER dst, YV_PARSER src);
YVPACKET_API void parser_set_object(YV_PARSER parser, unsigned char cmdId, YV_PARSER value);
YVPACKET_API void parser_set_uint8(YV_PARSER parser, unsigned char cmdId, unsigned char value);
YVPACKET_API void parser_set_uint32(YV_PARSER parser, unsigned char cmdId, unsigned int value);
YVPACKET_API void parser_set_integer(YV_PARSER parser, unsigned char cmdId, int value);
YVPACKET_API void parser_set_string(YV_PARSER parser, unsigned char cmdId, char* value);
 YVPACKET_API void parser_set_buffer(YV_PARSER parser, unsigned char cmdId, char* value, int len);
YVPACKET_API void parser_ready(YV_PARSER parser);
YVPACKET_API void parser_get_object(YV_PARSER parser, unsigned char cmdId, YV_PARSER object, int index);
YVPACKET_API unsigned char parser_get_uint8(YV_PARSER parser, unsigned char cmdId, int index);
YVPACKET_API unsigned int parser_get_uint32(YV_PARSER parser, unsigned char cmdId, int index);
YVPACKET_API int parser_get_integer(YV_PARSER parser, unsigned char cmdId, int index);
YVPACKET_API char* parser_get_string(YV_PARSER parser, unsigned char cmdId, int index);
YVPACKET_API char* parser_get_buffer(YV_PARSER parser, unsigned char cmdId, int* len, int index);
YVPACKET_API bool parser_is_empty(YV_PARSER parser, unsigned char cmdId, int index);
#ifdef __cplusplus
}
#endif
#endif

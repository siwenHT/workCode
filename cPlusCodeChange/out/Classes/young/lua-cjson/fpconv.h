
# define FPCONV_G_FMT_BUFSIZE   32
#ifdef USE_INTERNAL_FPCONV
static inline void fpconv_init()
{
    
}
#else
extern inline void fpconv_init();
#endif
extern int fpconv_g_fmt(char*, double, int);
extern double fpconv_strtod(const char*, char**);

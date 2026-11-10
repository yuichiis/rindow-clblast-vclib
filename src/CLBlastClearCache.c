#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastClearCache not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastClearCache)( /* CLBlastClearCache */
                /*  */
);
static PFNCLBlastClearCache _g_CLBlastClearCache = NULL;
CLBlastStatusCode CLBlastClearCache(
                
)
{
    if(_g_CLBlastClearCache==NULL) {
        _g_CLBlastClearCache = rindow_load_clblast_func("CLBlastClearCache"); 
        if(_g_CLBlastClearCache==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastClearCache(
    
    );
}

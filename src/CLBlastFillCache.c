#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastFillCache not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastFillCache)( /* CLBlastFillCache */
    const cl_device_id            /* device */
);
static PFNCLBlastFillCache _g_CLBlastFillCache = NULL;
CLBlastStatusCode CLBlastFillCache(
    const cl_device_id            device
)
{
    if(_g_CLBlastFillCache==NULL) {
        _g_CLBlastFillCache = rindow_load_clblast_func("CLBlastFillCache"); 
        if(_g_CLBlastFillCache==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastFillCache(
        device    
    );
}

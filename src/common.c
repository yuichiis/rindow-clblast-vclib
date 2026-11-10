#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"

static HMODULE _h_clblast = NULL;
static char msg_load_error[]  = "Load error: clblast\n";
void* rindow_load_clblast_func(char *funcname)
{
    if(_h_clblast==NULL) {
        _h_clblast = LoadLibraryA( "clblast.dll" );
        if(_h_clblast==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_load_error, sizeof(msg_load_error), NULL, NULL);
            return NULL;
        }
    }
    return GetProcAddress( _h_clblast, funcname );
}

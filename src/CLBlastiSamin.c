#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastiSamin not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastiSamin)( /* CLBlastiSamin */
    const size_t            /* n */,
    cl_mem            /* imin_buffer */,
    const size_t            /* imin_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastiSamin _g_CLBlastiSamin = NULL;
CLBlastStatusCode CLBlastiSamin(
    const size_t            n,
    cl_mem            imin_buffer,
    const size_t            imin_offset,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastiSamin==NULL) {
        _g_CLBlastiSamin = rindow_load_clblast_func("CLBlastiSamin"); 
        if(_g_CLBlastiSamin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastiSamin(
        n,
        imin_buffer,
        imin_offset,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastiHmin not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastiHmin)( /* CLBlastiHmin */
    const size_t            /* n */,
    cl_mem            /* imin_buffer */,
    const size_t            /* imin_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastiHmin _g_CLBlastiHmin = NULL;
CLBlastStatusCode CLBlastiHmin(
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
    if(_g_CLBlastiHmin==NULL) {
        _g_CLBlastiHmin = rindow_load_clblast_func("CLBlastiHmin"); 
        if(_g_CLBlastiHmin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastiHmin(
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

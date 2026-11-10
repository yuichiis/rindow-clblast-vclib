#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastiDamin not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastiDamin)( /* CLBlastiDamin */
    const size_t            /* n */,
    cl_mem            /* imin_buffer */,
    const size_t            /* imin_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastiDamin _g_CLBlastiDamin = NULL;
CLBlastStatusCode CLBlastiDamin(
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
    if(_g_CLBlastiDamin==NULL) {
        _g_CLBlastiDamin = rindow_load_clblast_func("CLBlastiDamin"); 
        if(_g_CLBlastiDamin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastiDamin(
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

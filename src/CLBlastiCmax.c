#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastiCmax not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastiCmax)( /* CLBlastiCmax */
    const size_t            /* n */,
    cl_mem            /* imax_buffer */,
    const size_t            /* imax_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastiCmax _g_CLBlastiCmax = NULL;
CLBlastStatusCode CLBlastiCmax(
    const size_t            n,
    cl_mem            imax_buffer,
    const size_t            imax_offset,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastiCmax==NULL) {
        _g_CLBlastiCmax = rindow_load_clblast_func("CLBlastiCmax"); 
        if(_g_CLBlastiCmax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastiCmax(
        n,
        imax_buffer,
        imax_offset,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

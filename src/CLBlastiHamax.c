#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastiHamax not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastiHamax)( /* CLBlastiHamax */
    const size_t            /* n */,
    cl_mem            /* imax_buffer */,
    const size_t            /* imax_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastiHamax _g_CLBlastiHamax = NULL;
CLBlastStatusCode CLBlastiHamax(
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
    if(_g_CLBlastiHamax==NULL) {
        _g_CLBlastiHamax = rindow_load_clblast_func("CLBlastiHamax"); 
        if(_g_CLBlastiHamax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastiHamax(
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

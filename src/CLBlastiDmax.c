#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastiDmax not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastiDmax)( /* CLBlastiDmax */
    const size_t            /* n */,
    cl_mem            /* imax_buffer */,
    const size_t            /* imax_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastiDmax _g_CLBlastiDmax = NULL;
CLBlastStatusCode CLBlastiDmax(
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
    if(_g_CLBlastiDmax==NULL) {
        _g_CLBlastiDmax = rindow_load_clblast_func("CLBlastiDmax"); 
        if(_g_CLBlastiDmax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastiDmax(
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

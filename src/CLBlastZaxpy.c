#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastZaxpy not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastZaxpy)( /* CLBlastZaxpy */
    const size_t            /* n */,
    const cl_double2            /* alpha */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastZaxpy _g_CLBlastZaxpy = NULL;
CLBlastStatusCode CLBlastZaxpy(
    const size_t            n,
    const cl_double2            alpha,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastZaxpy==NULL) {
        _g_CLBlastZaxpy = rindow_load_clblast_func("CLBlastZaxpy"); 
        if(_g_CLBlastZaxpy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastZaxpy(
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        y_buffer,
        y_offset,
        y_inc,
        queue,
        event    
    );
}

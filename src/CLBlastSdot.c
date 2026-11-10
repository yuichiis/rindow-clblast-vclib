#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSdot not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSdot)( /* CLBlastSdot */
    const size_t            /* n */,
    cl_mem            /* dot_buffer */,
    const size_t            /* dot_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSdot _g_CLBlastSdot = NULL;
CLBlastStatusCode CLBlastSdot(
    const size_t            n,
    cl_mem            dot_buffer,
    const size_t            dot_offset,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSdot==NULL) {
        _g_CLBlastSdot = rindow_load_clblast_func("CLBlastSdot"); 
        if(_g_CLBlastSdot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSdot(
        n,
        dot_buffer,
        dot_offset,
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

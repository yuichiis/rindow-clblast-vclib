#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSrotm not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSrotm)( /* CLBlastSrotm */
    const size_t            /* n */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_mem            /* sparam_buffer */,
    const size_t            /* sparam_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSrotm _g_CLBlastSrotm = NULL;
CLBlastStatusCode CLBlastSrotm(
    const size_t            n,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_mem            sparam_buffer,
    const size_t            sparam_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSrotm==NULL) {
        _g_CLBlastSrotm = rindow_load_clblast_func("CLBlastSrotm"); 
        if(_g_CLBlastSrotm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSrotm(
        n,
        x_buffer,
        x_offset,
        x_inc,
        y_buffer,
        y_offset,
        y_inc,
        sparam_buffer,
        sparam_offset,
        queue,
        event    
    );
}

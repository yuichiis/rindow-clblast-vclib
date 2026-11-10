#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDhad not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDhad)( /* CLBlastDhad */
    const size_t            /* n */,
    const double            /* alpha */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    const double            /* beta */,
    cl_mem            /* z_buffer */,
    const size_t            /* z_offset */,
    const size_t            /* z_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDhad _g_CLBlastDhad = NULL;
CLBlastStatusCode CLBlastDhad(
    const size_t            n,
    const double            alpha,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    const double            beta,
    cl_mem            z_buffer,
    const size_t            z_offset,
    const size_t            z_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDhad==NULL) {
        _g_CLBlastDhad = rindow_load_clblast_func("CLBlastDhad"); 
        if(_g_CLBlastDhad==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDhad(
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        y_buffer,
        y_offset,
        y_inc,
        beta,
        z_buffer,
        z_offset,
        z_inc,
        queue,
        event    
    );
}

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHhad not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHhad)( /* CLBlastHhad */
    const size_t            /* n */,
    const cl_half            /* alpha */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    const cl_half            /* beta */,
    cl_mem            /* z_buffer */,
    const size_t            /* z_offset */,
    const size_t            /* z_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastHhad _g_CLBlastHhad = NULL;
CLBlastStatusCode CLBlastHhad(
    const size_t            n,
    const cl_half            alpha,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    const cl_half            beta,
    cl_mem            z_buffer,
    const size_t            z_offset,
    const size_t            z_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastHhad==NULL) {
        _g_CLBlastHhad = rindow_load_clblast_func("CLBlastHhad"); 
        if(_g_CLBlastHhad==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHhad(
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

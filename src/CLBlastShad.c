#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastShad not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastShad)( /* CLBlastShad */
    const size_t            /* n */,
    const float            /* alpha */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    const float            /* beta */,
    cl_mem            /* z_buffer */,
    const size_t            /* z_offset */,
    const size_t            /* z_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastShad _g_CLBlastShad = NULL;
CLBlastStatusCode CLBlastShad(
    const size_t            n,
    const float            alpha,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    const float            beta,
    cl_mem            z_buffer,
    const size_t            z_offset,
    const size_t            z_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastShad==NULL) {
        _g_CLBlastShad = rindow_load_clblast_func("CLBlastShad"); 
        if(_g_CLBlastShad==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastShad(
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

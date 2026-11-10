#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSgemv not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSgemv)( /* CLBlastSgemv */
    const CLBlastLayout            /* layout */,
    const CLBlastTranspose            /* a_transpose */,
    const size_t            /* m */,
    const size_t            /* n */,
    const float            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const float            /* beta */,
    cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSgemv _g_CLBlastSgemv = NULL;
CLBlastStatusCode CLBlastSgemv(
    const CLBlastLayout            layout,
    const CLBlastTranspose            a_transpose,
    const size_t            m,
    const size_t            n,
    const float            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const float            beta,
    cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSgemv==NULL) {
        _g_CLBlastSgemv = rindow_load_clblast_func("CLBlastSgemv"); 
        if(_g_CLBlastSgemv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSgemv(
        layout,
        a_transpose,
        m,
        n,
        alpha,
        a_buffer,
        a_offset,
        a_ld,
        x_buffer,
        x_offset,
        x_inc,
        beta,
        y_buffer,
        y_offset,
        y_inc,
        queue,
        event    
    );
}

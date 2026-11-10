#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDsbmv not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDsbmv)( /* CLBlastDsbmv */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const size_t            /* n */,
    const size_t            /* k */,
    const double            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const double            /* beta */,
    cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDsbmv _g_CLBlastDsbmv = NULL;
CLBlastStatusCode CLBlastDsbmv(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const size_t            n,
    const size_t            k,
    const double            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const double            beta,
    cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDsbmv==NULL) {
        _g_CLBlastDsbmv = rindow_load_clblast_func("CLBlastDsbmv"); 
        if(_g_CLBlastDsbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDsbmv(
        layout,
        triangle,
        n,
        k,
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

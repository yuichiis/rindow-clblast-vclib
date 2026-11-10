#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDspmv not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDspmv)( /* CLBlastDspmv */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const size_t            /* n */,
    const double            /* alpha */,
    const cl_mem            /* ap_buffer */,
    const size_t            /* ap_offset */,
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
static PFNCLBlastDspmv _g_CLBlastDspmv = NULL;
CLBlastStatusCode CLBlastDspmv(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const size_t            n,
    const double            alpha,
    const cl_mem            ap_buffer,
    const size_t            ap_offset,
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
    if(_g_CLBlastDspmv==NULL) {
        _g_CLBlastDspmv = rindow_load_clblast_func("CLBlastDspmv"); 
        if(_g_CLBlastDspmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDspmv(
        layout,
        triangle,
        n,
        alpha,
        ap_buffer,
        ap_offset,
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

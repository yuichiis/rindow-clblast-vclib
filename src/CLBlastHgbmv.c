#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHgbmv not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHgbmv)( /* CLBlastHgbmv */
    const CLBlastLayout            /* layout */,
    const CLBlastTranspose            /* a_transpose */,
    const size_t            /* m */,
    const size_t            /* n */,
    const size_t            /* kl */,
    const size_t            /* ku */,
    const cl_half            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const cl_half            /* beta */,
    cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastHgbmv _g_CLBlastHgbmv = NULL;
CLBlastStatusCode CLBlastHgbmv(
    const CLBlastLayout            layout,
    const CLBlastTranspose            a_transpose,
    const size_t            m,
    const size_t            n,
    const size_t            kl,
    const size_t            ku,
    const cl_half            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const cl_half            beta,
    cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastHgbmv==NULL) {
        _g_CLBlastHgbmv = rindow_load_clblast_func("CLBlastHgbmv"); 
        if(_g_CLBlastHgbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHgbmv(
        layout,
        a_transpose,
        m,
        n,
        kl,
        ku,
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

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastCtrmm not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastCtrmm)( /* CLBlastCtrmm */
    const CLBlastLayout            /* layout */,
    const CLBlastSide            /* side */,
    const CLBlastTriangle            /* triangle */,
    const CLBlastTranspose            /* a_transpose */,
    const CLBlastDiagonal            /* diagonal */,
    const size_t            /* m */,
    const size_t            /* n */,
    const cl_float2            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    cl_mem            /* b_buffer */,
    const size_t            /* b_offset */,
    const size_t            /* b_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastCtrmm _g_CLBlastCtrmm = NULL;
CLBlastStatusCode CLBlastCtrmm(
    const CLBlastLayout            layout,
    const CLBlastSide            side,
    const CLBlastTriangle            triangle,
    const CLBlastTranspose            a_transpose,
    const CLBlastDiagonal            diagonal,
    const size_t            m,
    const size_t            n,
    const cl_float2            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    cl_mem            b_buffer,
    const size_t            b_offset,
    const size_t            b_ld,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastCtrmm==NULL) {
        _g_CLBlastCtrmm = rindow_load_clblast_func("CLBlastCtrmm"); 
        if(_g_CLBlastCtrmm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastCtrmm(
        layout,
        side,
        triangle,
        a_transpose,
        diagonal,
        m,
        n,
        alpha,
        a_buffer,
        a_offset,
        a_ld,
        b_buffer,
        b_offset,
        b_ld,
        queue,
        event    
    );
}

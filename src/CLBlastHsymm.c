#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHsymm not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHsymm)( /* CLBlastHsymm */
    const CLBlastLayout            /* layout */,
    const CLBlastSide            /* side */,
    const CLBlastTriangle            /* triangle */,
    const size_t            /* m */,
    const size_t            /* n */,
    const cl_half            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const cl_mem            /* b_buffer */,
    const size_t            /* b_offset */,
    const size_t            /* b_ld */,
    const cl_half            /* beta */,
    cl_mem            /* c_buffer */,
    const size_t            /* c_offset */,
    const size_t            /* c_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastHsymm _g_CLBlastHsymm = NULL;
CLBlastStatusCode CLBlastHsymm(
    const CLBlastLayout            layout,
    const CLBlastSide            side,
    const CLBlastTriangle            triangle,
    const size_t            m,
    const size_t            n,
    const cl_half            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    const cl_mem            b_buffer,
    const size_t            b_offset,
    const size_t            b_ld,
    const cl_half            beta,
    cl_mem            c_buffer,
    const size_t            c_offset,
    const size_t            c_ld,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastHsymm==NULL) {
        _g_CLBlastHsymm = rindow_load_clblast_func("CLBlastHsymm"); 
        if(_g_CLBlastHsymm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHsymm(
        layout,
        side,
        triangle,
        m,
        n,
        alpha,
        a_buffer,
        a_offset,
        a_ld,
        b_buffer,
        b_offset,
        b_ld,
        beta,
        c_buffer,
        c_offset,
        c_ld,
        queue,
        event    
    );
}

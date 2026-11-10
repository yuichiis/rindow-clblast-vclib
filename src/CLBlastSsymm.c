#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSsymm not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSsymm)( /* CLBlastSsymm */
    const CLBlastLayout            /* layout */,
    const CLBlastSide            /* side */,
    const CLBlastTriangle            /* triangle */,
    const size_t            /* m */,
    const size_t            /* n */,
    const float            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const cl_mem            /* b_buffer */,
    const size_t            /* b_offset */,
    const size_t            /* b_ld */,
    const float            /* beta */,
    cl_mem            /* c_buffer */,
    const size_t            /* c_offset */,
    const size_t            /* c_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSsymm _g_CLBlastSsymm = NULL;
CLBlastStatusCode CLBlastSsymm(
    const CLBlastLayout            layout,
    const CLBlastSide            side,
    const CLBlastTriangle            triangle,
    const size_t            m,
    const size_t            n,
    const float            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    const cl_mem            b_buffer,
    const size_t            b_offset,
    const size_t            b_ld,
    const float            beta,
    cl_mem            c_buffer,
    const size_t            c_offset,
    const size_t            c_ld,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSsymm==NULL) {
        _g_CLBlastSsymm = rindow_load_clblast_func("CLBlastSsymm"); 
        if(_g_CLBlastSsymm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSsymm(
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

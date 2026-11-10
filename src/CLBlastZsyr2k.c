#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastZsyr2k not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastZsyr2k)( /* CLBlastZsyr2k */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const CLBlastTranspose            /* ab_transpose */,
    const size_t            /* n */,
    const size_t            /* k */,
    const cl_double2            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const cl_mem            /* b_buffer */,
    const size_t            /* b_offset */,
    const size_t            /* b_ld */,
    const cl_double2            /* beta */,
    cl_mem            /* c_buffer */,
    const size_t            /* c_offset */,
    const size_t            /* c_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastZsyr2k _g_CLBlastZsyr2k = NULL;
CLBlastStatusCode CLBlastZsyr2k(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const CLBlastTranspose            ab_transpose,
    const size_t            n,
    const size_t            k,
    const cl_double2            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    const cl_mem            b_buffer,
    const size_t            b_offset,
    const size_t            b_ld,
    const cl_double2            beta,
    cl_mem            c_buffer,
    const size_t            c_offset,
    const size_t            c_ld,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastZsyr2k==NULL) {
        _g_CLBlastZsyr2k = rindow_load_clblast_func("CLBlastZsyr2k"); 
        if(_g_CLBlastZsyr2k==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastZsyr2k(
        layout,
        triangle,
        ab_transpose,
        n,
        k,
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

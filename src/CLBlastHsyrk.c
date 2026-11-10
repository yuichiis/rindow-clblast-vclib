#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHsyrk not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHsyrk)( /* CLBlastHsyrk */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const CLBlastTranspose            /* a_transpose */,
    const size_t            /* n */,
    const size_t            /* k */,
    const cl_half            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const cl_half            /* beta */,
    cl_mem            /* c_buffer */,
    const size_t            /* c_offset */,
    const size_t            /* c_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastHsyrk _g_CLBlastHsyrk = NULL;
CLBlastStatusCode CLBlastHsyrk(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const CLBlastTranspose            a_transpose,
    const size_t            n,
    const size_t            k,
    const cl_half            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    const cl_half            beta,
    cl_mem            c_buffer,
    const size_t            c_offset,
    const size_t            c_ld,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastHsyrk==NULL) {
        _g_CLBlastHsyrk = rindow_load_clblast_func("CLBlastHsyrk"); 
        if(_g_CLBlastHsyrk==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHsyrk(
        layout,
        triangle,
        a_transpose,
        n,
        k,
        alpha,
        a_buffer,
        a_offset,
        a_ld,
        beta,
        c_buffer,
        c_offset,
        c_ld,
        queue,
        event    
    );
}

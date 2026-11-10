#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastZsyrk not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastZsyrk)( /* CLBlastZsyrk */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const CLBlastTranspose            /* a_transpose */,
    const size_t            /* n */,
    const size_t            /* k */,
    const cl_double2            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const cl_double2            /* beta */,
    cl_mem            /* c_buffer */,
    const size_t            /* c_offset */,
    const size_t            /* c_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastZsyrk _g_CLBlastZsyrk = NULL;
CLBlastStatusCode CLBlastZsyrk(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const CLBlastTranspose            a_transpose,
    const size_t            n,
    const size_t            k,
    const cl_double2            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    const cl_double2            beta,
    cl_mem            c_buffer,
    const size_t            c_offset,
    const size_t            c_ld,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastZsyrk==NULL) {
        _g_CLBlastZsyrk = rindow_load_clblast_func("CLBlastZsyrk"); 
        if(_g_CLBlastZsyrk==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastZsyrk(
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

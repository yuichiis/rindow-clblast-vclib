#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDomatcopy not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDomatcopy)( /* CLBlastDomatcopy */
    const CLBlastLayout            /* layout */,
    const CLBlastTranspose            /* a_transpose */,
    const size_t            /* m */,
    const size_t            /* n */,
    const double            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    cl_mem            /* b_buffer */,
    const size_t            /* b_offset */,
    const size_t            /* b_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDomatcopy _g_CLBlastDomatcopy = NULL;
CLBlastStatusCode CLBlastDomatcopy(
    const CLBlastLayout            layout,
    const CLBlastTranspose            a_transpose,
    const size_t            m,
    const size_t            n,
    const double            alpha,
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
    if(_g_CLBlastDomatcopy==NULL) {
        _g_CLBlastDomatcopy = rindow_load_clblast_func("CLBlastDomatcopy"); 
        if(_g_CLBlastDomatcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDomatcopy(
        layout,
        a_transpose,
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

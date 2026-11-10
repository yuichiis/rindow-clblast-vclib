#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSomatcopy not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSomatcopy)( /* CLBlastSomatcopy */
    const CLBlastLayout            /* layout */,
    const CLBlastTranspose            /* a_transpose */,
    const size_t            /* m */,
    const size_t            /* n */,
    const float            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    cl_mem            /* b_buffer */,
    const size_t            /* b_offset */,
    const size_t            /* b_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSomatcopy _g_CLBlastSomatcopy = NULL;
CLBlastStatusCode CLBlastSomatcopy(
    const CLBlastLayout            layout,
    const CLBlastTranspose            a_transpose,
    const size_t            m,
    const size_t            n,
    const float            alpha,
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
    if(_g_CLBlastSomatcopy==NULL) {
        _g_CLBlastSomatcopy = rindow_load_clblast_func("CLBlastSomatcopy"); 
        if(_g_CLBlastSomatcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSomatcopy(
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

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSgemmWithTempBuffer not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSgemmWithTempBuffer)( /* CLBlastSgemmWithTempBuffer */
    const CLBlastLayout            /* layout */,
    const CLBlastTranspose            /* a_transpose */,
    const CLBlastTranspose            /* b_transpose */,
    const size_t            /* m */,
    const size_t            /* n */,
    const size_t            /* k */,
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
    cl_event *            /* event */,
    cl_mem            /* temp_buffer */
);
static PFNCLBlastSgemmWithTempBuffer _g_CLBlastSgemmWithTempBuffer = NULL;
CLBlastStatusCode CLBlastSgemmWithTempBuffer(
    const CLBlastLayout            layout,
    const CLBlastTranspose            a_transpose,
    const CLBlastTranspose            b_transpose,
    const size_t            m,
    const size_t            n,
    const size_t            k,
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
    cl_event *            event,
    cl_mem            temp_buffer
)
{
    if(_g_CLBlastSgemmWithTempBuffer==NULL) {
        _g_CLBlastSgemmWithTempBuffer = rindow_load_clblast_func("CLBlastSgemmWithTempBuffer"); 
        if(_g_CLBlastSgemmWithTempBuffer==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSgemmWithTempBuffer(
        layout,
        a_transpose,
        b_transpose,
        m,
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
        event,
        temp_buffer    
    );
}

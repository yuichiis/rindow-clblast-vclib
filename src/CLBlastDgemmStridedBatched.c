#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDgemmStridedBatched not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDgemmStridedBatched)( /* CLBlastDgemmStridedBatched */
    const CLBlastLayout            /* layout */,
    const CLBlastTranspose            /* a_transpose */,
    const CLBlastTranspose            /* b_transpose */,
    const size_t            /* m */,
    const size_t            /* n */,
    const size_t            /* k */,
    const double            /* alpha */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const size_t            /* a_stride */,
    const cl_mem            /* b_buffer */,
    const size_t            /* b_offset */,
    const size_t            /* b_ld */,
    const size_t            /* b_stride */,
    const double            /* beta */,
    cl_mem            /* c_buffer */,
    const size_t            /* c_offset */,
    const size_t            /* c_ld */,
    const size_t            /* c_stride */,
    const size_t            /* batch_count */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDgemmStridedBatched _g_CLBlastDgemmStridedBatched = NULL;
CLBlastStatusCode CLBlastDgemmStridedBatched(
    const CLBlastLayout            layout,
    const CLBlastTranspose            a_transpose,
    const CLBlastTranspose            b_transpose,
    const size_t            m,
    const size_t            n,
    const size_t            k,
    const double            alpha,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    const size_t            a_stride,
    const cl_mem            b_buffer,
    const size_t            b_offset,
    const size_t            b_ld,
    const size_t            b_stride,
    const double            beta,
    cl_mem            c_buffer,
    const size_t            c_offset,
    const size_t            c_ld,
    const size_t            c_stride,
    const size_t            batch_count,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDgemmStridedBatched==NULL) {
        _g_CLBlastDgemmStridedBatched = rindow_load_clblast_func("CLBlastDgemmStridedBatched"); 
        if(_g_CLBlastDgemmStridedBatched==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDgemmStridedBatched(
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
        a_stride,
        b_buffer,
        b_offset,
        b_ld,
        b_stride,
        beta,
        c_buffer,
        c_offset,
        c_ld,
        c_stride,
        batch_count,
        queue,
        event    
    );
}

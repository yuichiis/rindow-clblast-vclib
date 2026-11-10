#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHgemmBatched not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHgemmBatched)( /* CLBlastHgemmBatched */
    const CLBlastLayout            /* layout */,
    const CLBlastTranspose            /* a_transpose */,
    const CLBlastTranspose            /* b_transpose */,
    const size_t            /* m */,
    const size_t            /* n */,
    const size_t            /* k */,
    const cl_half *            /* alphas */,
    const cl_mem            /* a_buffer */,
    const size_t *            /* a_offsets */,
    const size_t            /* a_ld */,
    const cl_mem            /* b_buffer */,
    const size_t *            /* b_offsets */,
    const size_t            /* b_ld */,
    const cl_half *            /* betas */,
    cl_mem            /* c_buffer */,
    const size_t *            /* c_offsets */,
    const size_t            /* c_ld */,
    const size_t            /* batch_count */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastHgemmBatched _g_CLBlastHgemmBatched = NULL;
CLBlastStatusCode CLBlastHgemmBatched(
    const CLBlastLayout            layout,
    const CLBlastTranspose            a_transpose,
    const CLBlastTranspose            b_transpose,
    const size_t            m,
    const size_t            n,
    const size_t            k,
    const cl_half *            alphas,
    const cl_mem            a_buffer,
    const size_t *            a_offsets,
    const size_t            a_ld,
    const cl_mem            b_buffer,
    const size_t *            b_offsets,
    const size_t            b_ld,
    const cl_half *            betas,
    cl_mem            c_buffer,
    const size_t *            c_offsets,
    const size_t            c_ld,
    const size_t            batch_count,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastHgemmBatched==NULL) {
        _g_CLBlastHgemmBatched = rindow_load_clblast_func("CLBlastHgemmBatched"); 
        if(_g_CLBlastHgemmBatched==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHgemmBatched(
        layout,
        a_transpose,
        b_transpose,
        m,
        n,
        k,
        alphas,
        a_buffer,
        a_offsets,
        a_ld,
        b_buffer,
        b_offsets,
        b_ld,
        betas,
        c_buffer,
        c_offsets,
        c_ld,
        batch_count,
        queue,
        event    
    );
}

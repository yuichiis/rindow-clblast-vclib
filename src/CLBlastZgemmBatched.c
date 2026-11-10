#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastZgemmBatched not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastZgemmBatched)( /* CLBlastZgemmBatched */
    const CLBlastLayout            /* layout */,
    const CLBlastTranspose            /* a_transpose */,
    const CLBlastTranspose            /* b_transpose */,
    const size_t            /* m */,
    const size_t            /* n */,
    const size_t            /* k */,
    const cl_double2 *            /* alphas */,
    const cl_mem            /* a_buffer */,
    const size_t *            /* a_offsets */,
    const size_t            /* a_ld */,
    const cl_mem            /* b_buffer */,
    const size_t *            /* b_offsets */,
    const size_t            /* b_ld */,
    const cl_double2 *            /* betas */,
    cl_mem            /* c_buffer */,
    const size_t *            /* c_offsets */,
    const size_t            /* c_ld */,
    const size_t            /* batch_count */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastZgemmBatched _g_CLBlastZgemmBatched = NULL;
CLBlastStatusCode CLBlastZgemmBatched(
    const CLBlastLayout            layout,
    const CLBlastTranspose            a_transpose,
    const CLBlastTranspose            b_transpose,
    const size_t            m,
    const size_t            n,
    const size_t            k,
    const cl_double2 *            alphas,
    const cl_mem            a_buffer,
    const size_t *            a_offsets,
    const size_t            a_ld,
    const cl_mem            b_buffer,
    const size_t *            b_offsets,
    const size_t            b_ld,
    const cl_double2 *            betas,
    cl_mem            c_buffer,
    const size_t *            c_offsets,
    const size_t            c_ld,
    const size_t            batch_count,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastZgemmBatched==NULL) {
        _g_CLBlastZgemmBatched = rindow_load_clblast_func("CLBlastZgemmBatched"); 
        if(_g_CLBlastZgemmBatched==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastZgemmBatched(
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

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHGemmTempBufferSize not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHGemmTempBufferSize)( /* CLBlastHGemmTempBufferSize */
    const CLBlastLayout            /* layout */,
    const CLBlastTranspose            /* a_transpose */,
    const CLBlastTranspose            /* b_transpose */,
    const size_t            /* m */,
    const size_t            /* n */,
    const size_t            /* k */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    const size_t            /* b_offset */,
    const size_t            /* b_ld */,
    const size_t            /* c_offset */,
    const size_t            /* c_ld */,
    cl_command_queue *            /* queue */,
    size_t *            /* temp_buffer_size */
);
static PFNCLBlastHGemmTempBufferSize _g_CLBlastHGemmTempBufferSize = NULL;
CLBlastStatusCode CLBlastHGemmTempBufferSize(
    const CLBlastLayout            layout,
    const CLBlastTranspose            a_transpose,
    const CLBlastTranspose            b_transpose,
    const size_t            m,
    const size_t            n,
    const size_t            k,
    const size_t            a_offset,
    const size_t            a_ld,
    const size_t            b_offset,
    const size_t            b_ld,
    const size_t            c_offset,
    const size_t            c_ld,
    cl_command_queue *            queue,
    size_t *            temp_buffer_size
)
{
    if(_g_CLBlastHGemmTempBufferSize==NULL) {
        _g_CLBlastHGemmTempBufferSize = rindow_load_clblast_func("CLBlastHGemmTempBufferSize"); 
        if(_g_CLBlastHGemmTempBufferSize==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHGemmTempBufferSize(
        layout,
        a_transpose,
        b_transpose,
        m,
        n,
        k,
        a_offset,
        a_ld,
        b_offset,
        b_ld,
        c_offset,
        c_ld,
        queue,
        temp_buffer_size    
    );
}

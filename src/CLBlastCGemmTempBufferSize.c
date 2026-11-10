#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastCGemmTempBufferSize not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastCGemmTempBufferSize)( /* CLBlastCGemmTempBufferSize */
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
static PFNCLBlastCGemmTempBufferSize _g_CLBlastCGemmTempBufferSize = NULL;
CLBlastStatusCode CLBlastCGemmTempBufferSize(
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
    if(_g_CLBlastCGemmTempBufferSize==NULL) {
        _g_CLBlastCGemmTempBufferSize = rindow_load_clblast_func("CLBlastCGemmTempBufferSize"); 
        if(_g_CLBlastCGemmTempBufferSize==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastCGemmTempBufferSize(
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

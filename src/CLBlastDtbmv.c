#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDtbmv not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDtbmv)( /* CLBlastDtbmv */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const CLBlastTranspose            /* a_transpose */,
    const CLBlastDiagonal            /* diagonal */,
    const size_t            /* n */,
    const size_t            /* k */,
    const cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDtbmv _g_CLBlastDtbmv = NULL;
CLBlastStatusCode CLBlastDtbmv(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const CLBlastTranspose            a_transpose,
    const CLBlastDiagonal            diagonal,
    const size_t            n,
    const size_t            k,
    const cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDtbmv==NULL) {
        _g_CLBlastDtbmv = rindow_load_clblast_func("CLBlastDtbmv"); 
        if(_g_CLBlastDtbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDtbmv(
        layout,
        triangle,
        a_transpose,
        diagonal,
        n,
        k,
        a_buffer,
        a_offset,
        a_ld,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

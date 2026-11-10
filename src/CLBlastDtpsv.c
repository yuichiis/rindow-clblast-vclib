#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDtpsv not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDtpsv)( /* CLBlastDtpsv */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const CLBlastTranspose            /* a_transpose */,
    const CLBlastDiagonal            /* diagonal */,
    const size_t            /* n */,
    const cl_mem            /* ap_buffer */,
    const size_t            /* ap_offset */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDtpsv _g_CLBlastDtpsv = NULL;
CLBlastStatusCode CLBlastDtpsv(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const CLBlastTranspose            a_transpose,
    const CLBlastDiagonal            diagonal,
    const size_t            n,
    const cl_mem            ap_buffer,
    const size_t            ap_offset,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDtpsv==NULL) {
        _g_CLBlastDtpsv = rindow_load_clblast_func("CLBlastDtpsv"); 
        if(_g_CLBlastDtpsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDtpsv(
        layout,
        triangle,
        a_transpose,
        diagonal,
        n,
        ap_buffer,
        ap_offset,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

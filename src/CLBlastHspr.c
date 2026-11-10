#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHspr not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHspr)( /* CLBlastHspr */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const size_t            /* n */,
    const cl_half            /* alpha */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_mem            /* ap_buffer */,
    const size_t            /* ap_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastHspr _g_CLBlastHspr = NULL;
CLBlastStatusCode CLBlastHspr(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const size_t            n,
    const cl_half            alpha,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_mem            ap_buffer,
    const size_t            ap_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastHspr==NULL) {
        _g_CLBlastHspr = rindow_load_clblast_func("CLBlastHspr"); 
        if(_g_CLBlastHspr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHspr(
        layout,
        triangle,
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        ap_buffer,
        ap_offset,
        queue,
        event    
    );
}

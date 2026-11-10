#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDspr not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDspr)( /* CLBlastDspr */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const size_t            /* n */,
    const double            /* alpha */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_mem            /* ap_buffer */,
    const size_t            /* ap_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDspr _g_CLBlastDspr = NULL;
CLBlastStatusCode CLBlastDspr(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const size_t            n,
    const double            alpha,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_mem            ap_buffer,
    const size_t            ap_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDspr==NULL) {
        _g_CLBlastDspr = rindow_load_clblast_func("CLBlastDspr"); 
        if(_g_CLBlastDspr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDspr(
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

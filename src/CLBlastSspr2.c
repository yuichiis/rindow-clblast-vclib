#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSspr2 not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSspr2)( /* CLBlastSspr2 */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const size_t            /* n */,
    const float            /* alpha */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_mem            /* ap_buffer */,
    const size_t            /* ap_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSspr2 _g_CLBlastSspr2 = NULL;
CLBlastStatusCode CLBlastSspr2(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const size_t            n,
    const float            alpha,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_mem            ap_buffer,
    const size_t            ap_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSspr2==NULL) {
        _g_CLBlastSspr2 = rindow_load_clblast_func("CLBlastSspr2"); 
        if(_g_CLBlastSspr2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSspr2(
        layout,
        triangle,
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        y_buffer,
        y_offset,
        y_inc,
        ap_buffer,
        ap_offset,
        queue,
        event    
    );
}

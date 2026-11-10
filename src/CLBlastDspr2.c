#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDspr2 not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDspr2)( /* CLBlastDspr2 */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const size_t            /* n */,
    const double            /* alpha */,
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
static PFNCLBlastDspr2 _g_CLBlastDspr2 = NULL;
CLBlastStatusCode CLBlastDspr2(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const size_t            n,
    const double            alpha,
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
    if(_g_CLBlastDspr2==NULL) {
        _g_CLBlastDspr2 = rindow_load_clblast_func("CLBlastDspr2"); 
        if(_g_CLBlastDspr2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDspr2(
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

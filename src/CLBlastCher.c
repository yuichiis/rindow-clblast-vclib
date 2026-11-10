#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastCher not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastCher)( /* CLBlastCher */
    const CLBlastLayout            /* layout */,
    const CLBlastTriangle            /* triangle */,
    const size_t            /* n */,
    const float            /* alpha */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastCher _g_CLBlastCher = NULL;
CLBlastStatusCode CLBlastCher(
    const CLBlastLayout            layout,
    const CLBlastTriangle            triangle,
    const size_t            n,
    const float            alpha,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastCher==NULL) {
        _g_CLBlastCher = rindow_load_clblast_func("CLBlastCher"); 
        if(_g_CLBlastCher==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastCher(
        layout,
        triangle,
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        a_buffer,
        a_offset,
        a_ld,
        queue,
        event    
    );
}

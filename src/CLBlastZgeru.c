#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastZgeru not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastZgeru)( /* CLBlastZgeru */
    const CLBlastLayout            /* layout */,
    const size_t            /* m */,
    const size_t            /* n */,
    const cl_double2            /* alpha */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_mem            /* a_buffer */,
    const size_t            /* a_offset */,
    const size_t            /* a_ld */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastZgeru _g_CLBlastZgeru = NULL;
CLBlastStatusCode CLBlastZgeru(
    const CLBlastLayout            layout,
    const size_t            m,
    const size_t            n,
    const cl_double2            alpha,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_mem            a_buffer,
    const size_t            a_offset,
    const size_t            a_ld,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastZgeru==NULL) {
        _g_CLBlastZgeru = rindow_load_clblast_func("CLBlastZgeru"); 
        if(_g_CLBlastZgeru==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastZgeru(
        layout,
        m,
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        y_buffer,
        y_offset,
        y_inc,
        a_buffer,
        a_offset,
        a_ld,
        queue,
        event    
    );
}

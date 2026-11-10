#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastZgerc not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastZgerc)( /* CLBlastZgerc */
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
static PFNCLBlastZgerc _g_CLBlastZgerc = NULL;
CLBlastStatusCode CLBlastZgerc(
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
    if(_g_CLBlastZgerc==NULL) {
        _g_CLBlastZgerc = rindow_load_clblast_func("CLBlastZgerc"); 
        if(_g_CLBlastZgerc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastZgerc(
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

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDrotm not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDrotm)( /* CLBlastDrotm */
    const size_t            /* n */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_mem            /* sparam_buffer */,
    const size_t            /* sparam_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDrotm _g_CLBlastDrotm = NULL;
CLBlastStatusCode CLBlastDrotm(
    const size_t            n,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_mem            sparam_buffer,
    const size_t            sparam_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDrotm==NULL) {
        _g_CLBlastDrotm = rindow_load_clblast_func("CLBlastDrotm"); 
        if(_g_CLBlastDrotm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDrotm(
        n,
        x_buffer,
        x_offset,
        x_inc,
        y_buffer,
        y_offset,
        y_inc,
        sparam_buffer,
        sparam_offset,
        queue,
        event    
    );
}

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDrot not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDrot)( /* CLBlastDrot */
    const size_t            /* n */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    const double            /* cos */,
    const double            /* sin */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDrot _g_CLBlastDrot = NULL;
CLBlastStatusCode CLBlastDrot(
    const size_t            n,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    const double            cos,
    const double            sin,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDrot==NULL) {
        _g_CLBlastDrot = rindow_load_clblast_func("CLBlastDrot"); 
        if(_g_CLBlastDrot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDrot(
        n,
        x_buffer,
        x_offset,
        x_inc,
        y_buffer,
        y_offset,
        y_inc,
        cos,
        sin,
        queue,
        event    
    );
}

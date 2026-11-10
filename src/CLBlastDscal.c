#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDscal not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDscal)( /* CLBlastDscal */
    const size_t            /* n */,
    const double            /* alpha */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDscal _g_CLBlastDscal = NULL;
CLBlastStatusCode CLBlastDscal(
    const size_t            n,
    const double            alpha,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDscal==NULL) {
        _g_CLBlastDscal = rindow_load_clblast_func("CLBlastDscal"); 
        if(_g_CLBlastDscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDscal(
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

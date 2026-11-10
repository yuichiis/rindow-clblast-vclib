#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHscal not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHscal)( /* CLBlastHscal */
    const size_t            /* n */,
    const cl_half            /* alpha */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastHscal _g_CLBlastHscal = NULL;
CLBlastStatusCode CLBlastHscal(
    const size_t            n,
    const cl_half            alpha,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastHscal==NULL) {
        _g_CLBlastHscal = rindow_load_clblast_func("CLBlastHscal"); 
        if(_g_CLBlastHscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHscal(
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

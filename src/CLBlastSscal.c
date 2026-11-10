#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSscal not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSscal)( /* CLBlastSscal */
    const size_t            /* n */,
    const float            /* alpha */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSscal _g_CLBlastSscal = NULL;
CLBlastStatusCode CLBlastSscal(
    const size_t            n,
    const float            alpha,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSscal==NULL) {
        _g_CLBlastSscal = rindow_load_clblast_func("CLBlastSscal"); 
        if(_g_CLBlastSscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSscal(
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

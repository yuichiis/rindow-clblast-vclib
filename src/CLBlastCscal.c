#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastCscal not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastCscal)( /* CLBlastCscal */
    const size_t            /* n */,
    const cl_float2            /* alpha */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastCscal _g_CLBlastCscal = NULL;
CLBlastStatusCode CLBlastCscal(
    const size_t            n,
    const cl_float2            alpha,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastCscal==NULL) {
        _g_CLBlastCscal = rindow_load_clblast_func("CLBlastCscal"); 
        if(_g_CLBlastCscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastCscal(
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

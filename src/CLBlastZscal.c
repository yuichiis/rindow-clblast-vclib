#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastZscal not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastZscal)( /* CLBlastZscal */
    const size_t            /* n */,
    const cl_double2            /* alpha */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastZscal _g_CLBlastZscal = NULL;
CLBlastStatusCode CLBlastZscal(
    const size_t            n,
    const cl_double2            alpha,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastZscal==NULL) {
        _g_CLBlastZscal = rindow_load_clblast_func("CLBlastZscal"); 
        if(_g_CLBlastZscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastZscal(
        n,
        alpha,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

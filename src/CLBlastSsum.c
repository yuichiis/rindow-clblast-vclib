#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSsum not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSsum)( /* CLBlastSsum */
    const size_t            /* n */,
    cl_mem            /* sum_buffer */,
    const size_t            /* sum_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSsum _g_CLBlastSsum = NULL;
CLBlastStatusCode CLBlastSsum(
    const size_t            n,
    cl_mem            sum_buffer,
    const size_t            sum_offset,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSsum==NULL) {
        _g_CLBlastSsum = rindow_load_clblast_func("CLBlastSsum"); 
        if(_g_CLBlastSsum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSsum(
        n,
        sum_buffer,
        sum_offset,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDzsum not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDzsum)( /* CLBlastDzsum */
    const size_t            /* n */,
    cl_mem            /* sum_buffer */,
    const size_t            /* sum_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDzsum _g_CLBlastDzsum = NULL;
CLBlastStatusCode CLBlastDzsum(
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
    if(_g_CLBlastDzsum==NULL) {
        _g_CLBlastDzsum = rindow_load_clblast_func("CLBlastDzsum"); 
        if(_g_CLBlastDzsum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDzsum(
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

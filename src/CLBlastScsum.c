#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastScsum not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastScsum)( /* CLBlastScsum */
    const size_t            /* n */,
    cl_mem            /* sum_buffer */,
    const size_t            /* sum_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastScsum _g_CLBlastScsum = NULL;
CLBlastStatusCode CLBlastScsum(
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
    if(_g_CLBlastScsum==NULL) {
        _g_CLBlastScsum = rindow_load_clblast_func("CLBlastScsum"); 
        if(_g_CLBlastScsum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastScsum(
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

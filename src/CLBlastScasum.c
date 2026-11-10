#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastScasum not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastScasum)( /* CLBlastScasum */
    const size_t            /* n */,
    cl_mem            /* asum_buffer */,
    const size_t            /* asum_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastScasum _g_CLBlastScasum = NULL;
CLBlastStatusCode CLBlastScasum(
    const size_t            n,
    cl_mem            asum_buffer,
    const size_t            asum_offset,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastScasum==NULL) {
        _g_CLBlastScasum = rindow_load_clblast_func("CLBlastScasum"); 
        if(_g_CLBlastScasum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastScasum(
        n,
        asum_buffer,
        asum_offset,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

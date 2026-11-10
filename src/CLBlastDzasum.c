#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDzasum not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDzasum)( /* CLBlastDzasum */
    const size_t            /* n */,
    cl_mem            /* asum_buffer */,
    const size_t            /* asum_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDzasum _g_CLBlastDzasum = NULL;
CLBlastStatusCode CLBlastDzasum(
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
    if(_g_CLBlastDzasum==NULL) {
        _g_CLBlastDzasum = rindow_load_clblast_func("CLBlastDzasum"); 
        if(_g_CLBlastDzasum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDzasum(
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

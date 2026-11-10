#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastCswap not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastCswap)( /* CLBlastCswap */
    const size_t            /* n */,
    cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastCswap _g_CLBlastCswap = NULL;
CLBlastStatusCode CLBlastCswap(
    const size_t            n,
    cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastCswap==NULL) {
        _g_CLBlastCswap = rindow_load_clblast_func("CLBlastCswap"); 
        if(_g_CLBlastCswap==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastCswap(
        n,
        x_buffer,
        x_offset,
        x_inc,
        y_buffer,
        y_offset,
        y_inc,
        queue,
        event    
    );
}

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastCdotu not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastCdotu)( /* CLBlastCdotu */
    const size_t            /* n */,
    cl_mem            /* dot_buffer */,
    const size_t            /* dot_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    const cl_mem            /* y_buffer */,
    const size_t            /* y_offset */,
    const size_t            /* y_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastCdotu _g_CLBlastCdotu = NULL;
CLBlastStatusCode CLBlastCdotu(
    const size_t            n,
    cl_mem            dot_buffer,
    const size_t            dot_offset,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    const cl_mem            y_buffer,
    const size_t            y_offset,
    const size_t            y_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastCdotu==NULL) {
        _g_CLBlastCdotu = rindow_load_clblast_func("CLBlastCdotu"); 
        if(_g_CLBlastCdotu==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastCdotu(
        n,
        dot_buffer,
        dot_offset,
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

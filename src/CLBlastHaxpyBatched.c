#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHaxpyBatched not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHaxpyBatched)( /* CLBlastHaxpyBatched */
    const size_t            /* n */,
    const cl_half *            /* alphas */,
    const cl_mem            /* x_buffer */,
    const size_t *            /* x_offsets */,
    const size_t            /* x_inc */,
    cl_mem            /* y_buffer */,
    const size_t *            /* y_offsets */,
    const size_t            /* y_inc */,
    const size_t            /* batch_count */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastHaxpyBatched _g_CLBlastHaxpyBatched = NULL;
CLBlastStatusCode CLBlastHaxpyBatched(
    const size_t            n,
    const cl_half *            alphas,
    const cl_mem            x_buffer,
    const size_t *            x_offsets,
    const size_t            x_inc,
    cl_mem            y_buffer,
    const size_t *            y_offsets,
    const size_t            y_inc,
    const size_t            batch_count,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastHaxpyBatched==NULL) {
        _g_CLBlastHaxpyBatched = rindow_load_clblast_func("CLBlastHaxpyBatched"); 
        if(_g_CLBlastHaxpyBatched==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHaxpyBatched(
        n,
        alphas,
        x_buffer,
        x_offsets,
        x_inc,
        y_buffer,
        y_offsets,
        y_inc,
        batch_count,
        queue,
        event    
    );
}

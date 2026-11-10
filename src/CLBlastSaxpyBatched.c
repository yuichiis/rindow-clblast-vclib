#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSaxpyBatched not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSaxpyBatched)( /* CLBlastSaxpyBatched */
    const size_t            /* n */,
    const float *            /* alphas */,
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
static PFNCLBlastSaxpyBatched _g_CLBlastSaxpyBatched = NULL;
CLBlastStatusCode CLBlastSaxpyBatched(
    const size_t            n,
    const float *            alphas,
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
    if(_g_CLBlastSaxpyBatched==NULL) {
        _g_CLBlastSaxpyBatched = rindow_load_clblast_func("CLBlastSaxpyBatched"); 
        if(_g_CLBlastSaxpyBatched==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSaxpyBatched(
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

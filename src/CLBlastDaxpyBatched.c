#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDaxpyBatched not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDaxpyBatched)( /* CLBlastDaxpyBatched */
    const size_t            /* n */,
    const double *            /* alphas */,
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
static PFNCLBlastDaxpyBatched _g_CLBlastDaxpyBatched = NULL;
CLBlastStatusCode CLBlastDaxpyBatched(
    const size_t            n,
    const double *            alphas,
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
    if(_g_CLBlastDaxpyBatched==NULL) {
        _g_CLBlastDaxpyBatched = rindow_load_clblast_func("CLBlastDaxpyBatched"); 
        if(_g_CLBlastDaxpyBatched==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDaxpyBatched(
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

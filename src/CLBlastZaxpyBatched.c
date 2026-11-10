#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastZaxpyBatched not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastZaxpyBatched)( /* CLBlastZaxpyBatched */
    const size_t            /* n */,
    const cl_double2 *            /* alphas */,
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
static PFNCLBlastZaxpyBatched _g_CLBlastZaxpyBatched = NULL;
CLBlastStatusCode CLBlastZaxpyBatched(
    const size_t            n,
    const cl_double2 *            alphas,
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
    if(_g_CLBlastZaxpyBatched==NULL) {
        _g_CLBlastZaxpyBatched = rindow_load_clblast_func("CLBlastZaxpyBatched"); 
        if(_g_CLBlastZaxpyBatched==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastZaxpyBatched(
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

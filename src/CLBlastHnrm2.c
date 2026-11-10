#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastHnrm2 not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastHnrm2)( /* CLBlastHnrm2 */
    const size_t            /* n */,
    cl_mem            /* nrm2_buffer */,
    const size_t            /* nrm2_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastHnrm2 _g_CLBlastHnrm2 = NULL;
CLBlastStatusCode CLBlastHnrm2(
    const size_t            n,
    cl_mem            nrm2_buffer,
    const size_t            nrm2_offset,
    const cl_mem            x_buffer,
    const size_t            x_offset,
    const size_t            x_inc,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastHnrm2==NULL) {
        _g_CLBlastHnrm2 = rindow_load_clblast_func("CLBlastHnrm2"); 
        if(_g_CLBlastHnrm2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastHnrm2(
        n,
        nrm2_buffer,
        nrm2_offset,
        x_buffer,
        x_offset,
        x_inc,
        queue,
        event    
    );
}

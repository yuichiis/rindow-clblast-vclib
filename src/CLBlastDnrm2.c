#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDnrm2 not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDnrm2)( /* CLBlastDnrm2 */
    const size_t            /* n */,
    cl_mem            /* nrm2_buffer */,
    const size_t            /* nrm2_offset */,
    const cl_mem            /* x_buffer */,
    const size_t            /* x_offset */,
    const size_t            /* x_inc */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDnrm2 _g_CLBlastDnrm2 = NULL;
CLBlastStatusCode CLBlastDnrm2(
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
    if(_g_CLBlastDnrm2==NULL) {
        _g_CLBlastDnrm2 = rindow_load_clblast_func("CLBlastDnrm2"); 
        if(_g_CLBlastDnrm2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDnrm2(
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

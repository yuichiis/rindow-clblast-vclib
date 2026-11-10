#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSrotmg not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSrotmg)( /* CLBlastSrotmg */
    cl_mem            /* sd1_buffer */,
    const size_t            /* sd1_offset */,
    cl_mem            /* sd2_buffer */,
    const size_t            /* sd2_offset */,
    cl_mem            /* sx1_buffer */,
    const size_t            /* sx1_offset */,
    const cl_mem            /* sy1_buffer */,
    const size_t            /* sy1_offset */,
    cl_mem            /* sparam_buffer */,
    const size_t            /* sparam_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSrotmg _g_CLBlastSrotmg = NULL;
CLBlastStatusCode CLBlastSrotmg(
    cl_mem            sd1_buffer,
    const size_t            sd1_offset,
    cl_mem            sd2_buffer,
    const size_t            sd2_offset,
    cl_mem            sx1_buffer,
    const size_t            sx1_offset,
    const cl_mem            sy1_buffer,
    const size_t            sy1_offset,
    cl_mem            sparam_buffer,
    const size_t            sparam_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSrotmg==NULL) {
        _g_CLBlastSrotmg = rindow_load_clblast_func("CLBlastSrotmg"); 
        if(_g_CLBlastSrotmg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSrotmg(
        sd1_buffer,
        sd1_offset,
        sd2_buffer,
        sd2_offset,
        sx1_buffer,
        sx1_offset,
        sy1_buffer,
        sy1_offset,
        sparam_buffer,
        sparam_offset,
        queue,
        event    
    );
}

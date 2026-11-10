#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSrotg not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSrotg)( /* CLBlastSrotg */
    cl_mem            /* sa_buffer */,
    const size_t            /* sa_offset */,
    cl_mem            /* sb_buffer */,
    const size_t            /* sb_offset */,
    cl_mem            /* sc_buffer */,
    const size_t            /* sc_offset */,
    cl_mem            /* ss_buffer */,
    const size_t            /* ss_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSrotg _g_CLBlastSrotg = NULL;
CLBlastStatusCode CLBlastSrotg(
    cl_mem            sa_buffer,
    const size_t            sa_offset,
    cl_mem            sb_buffer,
    const size_t            sb_offset,
    cl_mem            sc_buffer,
    const size_t            sc_offset,
    cl_mem            ss_buffer,
    const size_t            ss_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSrotg==NULL) {
        _g_CLBlastSrotg = rindow_load_clblast_func("CLBlastSrotg"); 
        if(_g_CLBlastSrotg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSrotg(
        sa_buffer,
        sa_offset,
        sb_buffer,
        sb_offset,
        sc_buffer,
        sc_offset,
        ss_buffer,
        ss_offset,
        queue,
        event    
    );
}

#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastSim2col not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastSim2col)( /* CLBlastSim2col */
    const CLBlastKernelMode            /* kernel_mode */,
    const size_t            /* channels */,
    const size_t            /* height */,
    const size_t            /* width */,
    const size_t            /* kernel_h */,
    const size_t            /* kernel_w */,
    const size_t            /* pad_h */,
    const size_t            /* pad_w */,
    const size_t            /* stride_h */,
    const size_t            /* stride_w */,
    const size_t            /* dilation_h */,
    const size_t            /* dilation_w */,
    const cl_mem            /* im_buffer */,
    const size_t            /* im_offset */,
    cl_mem            /* col_buffer */,
    const size_t            /* col_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastSim2col _g_CLBlastSim2col = NULL;
CLBlastStatusCode CLBlastSim2col(
    const CLBlastKernelMode            kernel_mode,
    const size_t            channels,
    const size_t            height,
    const size_t            width,
    const size_t            kernel_h,
    const size_t            kernel_w,
    const size_t            pad_h,
    const size_t            pad_w,
    const size_t            stride_h,
    const size_t            stride_w,
    const size_t            dilation_h,
    const size_t            dilation_w,
    const cl_mem            im_buffer,
    const size_t            im_offset,
    cl_mem            col_buffer,
    const size_t            col_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastSim2col==NULL) {
        _g_CLBlastSim2col = rindow_load_clblast_func("CLBlastSim2col"); 
        if(_g_CLBlastSim2col==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastSim2col(
        kernel_mode,
        channels,
        height,
        width,
        kernel_h,
        kernel_w,
        pad_h,
        pad_w,
        stride_h,
        stride_w,
        dilation_h,
        dilation_w,
        im_buffer,
        im_offset,
        col_buffer,
        col_offset,
        queue,
        event    
    );
}

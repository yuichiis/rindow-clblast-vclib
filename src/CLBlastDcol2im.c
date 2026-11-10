#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDcol2im not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDcol2im)( /* CLBlastDcol2im */
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
    const cl_mem            /* col_buffer */,
    const size_t            /* col_offset */,
    cl_mem            /* im_buffer */,
    const size_t            /* im_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDcol2im _g_CLBlastDcol2im = NULL;
CLBlastStatusCode CLBlastDcol2im(
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
    const cl_mem            col_buffer,
    const size_t            col_offset,
    cl_mem            im_buffer,
    const size_t            im_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDcol2im==NULL) {
        _g_CLBlastDcol2im = rindow_load_clblast_func("CLBlastDcol2im"); 
        if(_g_CLBlastDcol2im==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDcol2im(
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
        col_buffer,
        col_offset,
        im_buffer,
        im_offset,
        queue,
        event    
    );
}

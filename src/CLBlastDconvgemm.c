#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastDconvgemm not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastDconvgemm)( /* CLBlastDconvgemm */
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
    const size_t            /* num_kernels */,
    const size_t            /* batch_count */,
    const cl_mem            /* im_buffer */,
    const size_t            /* im_offset */,
    const cl_mem            /* kernel_buffer */,
    const size_t            /* kernel_offset */,
    cl_mem            /* result_buffer */,
    const size_t            /* result_offset */,
    cl_command_queue *            /* queue */,
    cl_event *            /* event */
);
static PFNCLBlastDconvgemm _g_CLBlastDconvgemm = NULL;
CLBlastStatusCode CLBlastDconvgemm(
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
    const size_t            num_kernels,
    const size_t            batch_count,
    const cl_mem            im_buffer,
    const size_t            im_offset,
    const cl_mem            kernel_buffer,
    const size_t            kernel_offset,
    cl_mem            result_buffer,
    const size_t            result_offset,
    cl_command_queue *            queue,
    cl_event *            event
)
{
    if(_g_CLBlastDconvgemm==NULL) {
        _g_CLBlastDconvgemm = rindow_load_clblast_func("CLBlastDconvgemm"); 
        if(_g_CLBlastDconvgemm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastDconvgemm(
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
        num_kernels,
        batch_count,
        im_buffer,
        im_offset,
        kernel_buffer,
        kernel_offset,
        result_buffer,
        result_offset,
        queue,
        event    
    );
}

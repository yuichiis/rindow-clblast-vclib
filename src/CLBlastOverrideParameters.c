#include <Windows.h>
#include <clblast_c.h>
#include "vclib.h"
static char msg_function_not_found[]  = "CLBlastOverrideParameters not found\n";
typedef CLBlastStatusCode (CALLBACK* PFNCLBlastOverrideParameters)( /* CLBlastOverrideParameters */
    const cl_device_id            /* device */,
    const char *            /* kernel_name */,
    const CLBlastPrecision            /* precision */,
    const size_t            /* num_parameters */,
    const char * *            /* parameters_names */,
    const size_t *            /* parameters_values */
);
static PFNCLBlastOverrideParameters _g_CLBlastOverrideParameters = NULL;
CLBlastStatusCode CLBlastOverrideParameters(
    const cl_device_id            device,
    const char *            kernel_name,
    const CLBlastPrecision            precision,
    const size_t            num_parameters,
    const char * *            parameters_names,
    const size_t *            parameters_values
)
{
    if(_g_CLBlastOverrideParameters==NULL) {
        _g_CLBlastOverrideParameters = rindow_load_clblast_func("CLBlastOverrideParameters"); 
        if(_g_CLBlastOverrideParameters==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_CLBlastOverrideParameters(
        device,
        kernel_name,
        precision,
        num_parameters,
        parameters_names,
        parameters_values    
    );
}

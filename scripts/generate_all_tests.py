import re

with open(r'C:\CLBlast\CLBlast-1.7.0-windows-x64\include\clblast_c.h') as f:
    text = f.read()

pattern = r'CLBlastStatusCode\s+PUBLIC_API\s+(\w+)\s*\((.*?)\);'
matches = re.findall(pattern, text, re.DOTALL)

# Routines that return CLBlastNotImplemented in CLBlast
NOT_IMPLEMENTED_ROUTINES = {
    'CLBlastSrotg', 'CLBlastDrotg',
    'CLBlastSrotmg', 'CLBlastDrotmg',
    'CLBlastSrot', 'CLBlastDrot',
    'CLBlastSrotm', 'CLBlastDrotm',
    'CLBlastStbsv', 'CLBlastDtbsv', 'CLBlastCtbsv', 'CLBlastZtbsv',
    'CLBlastStpsv', 'CLBlastDtpsv', 'CLBlastCtpsv', 'CLBlastZtpsv',
}

def map_arg(vtype, vname, fn):
    # Buffers
    if 'cl_mem' in vtype:
        if vname in ('a_buffer', 'ap_buffer', 'sa_buffer', 'sd1_buffer', 'im_buffer'):
            return 'buf_a'
        elif vname in ('b_buffer', 'sb_buffer', 'sd2_buffer', 'col_buffer'):
            return 'buf_b'
        elif vname in ('c_buffer', 'sc_buffer', 'kernel_buffer'):
            return 'buf_c'
        elif vname in ('x_buffer', 'sx1_buffer', 'ss_buffer'):
            return 'buf_x'
        elif vname in ('y_buffer', 'sy1_buffer'):
            return 'buf_y'
        elif vname in ('z_buffer', 'sparam_buffer'):
            return 'buf_z'
        elif vname in ('asum_buffer', 'dot_buffer', 'nrm2_buffer', 'sum_buffer', 'result_buffer', 'imax_buffer', 'imin_buffer'):
            return 'buf_res'
        elif vname == 'temp_buffer':
            return 'buf_temp'
        else:
            return 'buf_a'
    
    # Enums
    if vtype == 'const CLBlastLayout':
        return 'CLBlastLayoutRowMajor'
    if vtype == 'const CLBlastTranspose':
        return 'CLBlastTransposeNo'
    if vtype == 'const CLBlastTriangle':
        return 'CLBlastTriangleUpper'
    if vtype == 'const CLBlastDiagonal':
        return 'CLBlastDiagonalNonUnit'
    if vtype == 'const CLBlastSide':
        return 'CLBlastSideLeft'
    if vtype == 'const CLBlastKernelMode':
        return 'CLBlastKernelModeCrossCorrelation'
    if vtype == 'const CLBlastPrecision':
        return 'CLBlastPrecisionSingle'

    # Dimensions and sizes
    if vtype == 'const size_t':
        if vname in ('m', 'n'):
            return '4'
        elif vname == 'k':
            # Band matrix routines (hbmv, sbmv, tbmv) require a_ld >= k + 1. With a_ld=4, k must be <= 3.
            return '1'
        elif vname in ('a_ld', 'b_ld', 'c_ld'):
            return '4'
        elif vname in ('kl', 'ku'):
            return '1'
        elif vname in ('x_inc', 'y_inc', 'z_inc'):
            return '1'
        elif vname in ('a_stride', 'b_stride', 'c_stride'):
            return '16'
        elif vname == 'batch_count':
            return '2'
        elif vname in ('channels', 'height', 'width'):
            return '4' if vname != 'channels' else '1'
        elif vname in ('kernel_h', 'kernel_w'):
            return '2'
        elif vname in ('pad_h', 'pad_w'):
            return '0'
        elif vname in ('stride_h', 'stride_w', 'dilation_h', 'dilation_w'):
            return '1'
        elif vname in ('num_kernels', 'num_parameters'):
            return '1' if vname == 'num_kernels' else '0'
        elif 'offset' in vname:
            return '0'
        else:
            return '1'

    # Offset arrays
    if vtype == 'const size_t*':
        if vname == 'parameters_values':
            return 'nullptr'
        return 'offsets_arr.data()'

    # Scalars
    if vname == 'alpha':
        if vtype == 'const float':
            return '1.0f'
        elif vtype == 'const double':
            return '1.0'
        elif vtype == 'const cl_float2':
            return 'alpha_c'
        elif vtype == 'const cl_double2':
            return 'alpha_z'
        elif vtype == 'const cl_half':
            return 'alpha_h'
    if vname == 'beta':
        if vtype == 'const float':
            return '0.0f'
        elif vtype == 'const double':
            return '0.0'
        elif vtype == 'const cl_float2':
            return 'beta_c'
        elif vtype == 'const cl_double2':
            return 'beta_z'
        elif vtype == 'const cl_half':
            return 'beta_h'
    if vname == 'alphas':
        if vtype == 'const float*':
            return 'alphas_s.data()'
        elif vtype == 'const double*':
            return 'alphas_d.data()'
        elif vtype == 'const cl_float2*':
            return 'alphas_c.data()'
        elif vtype == 'const cl_double2*':
            return 'alphas_z.data()'
        elif vtype == 'const cl_half*':
            return 'alphas_h.data()'
    if vname == 'betas':
        if vtype == 'const float*':
            return 'betas_s.data()'
        elif vtype == 'const double*':
            return 'betas_d.data()'
        elif vtype == 'const cl_float2*':
            return 'betas_c.data()'
        elif vtype == 'const cl_double2*':
            return 'betas_z.data()'
        elif vtype == 'const cl_half*':
            return 'betas_h.data()'
    if vname == 'cos':
        return '1.0f' if vtype == 'const float' else '1.0'
    if vname == 'sin':
        return '0.0f' if vtype == 'const float' else '0.0'

    # Special pointers
    if vtype == 'cl_command_queue*':
        return '&queue'
    if vtype == 'cl_event*':
        return 'nullptr'
    if vtype == 'const cl_device_id':
        return 'device'
    if vtype == 'const char*':
        return '"Xgemm"'
    if vtype == 'const char**':
        return 'nullptr'
    if vtype == 'size_t*':
        return '&temp_buffer_size_val'

    raise ValueError(f"Unmapped argument: {vtype} {vname} in {fn}")

# Generate test cases
test_cases = []
for fn, raw_args in matches:
    clean = ' '.join(raw_args.split())
    if not clean:
        call_args = []
    else:
        call_args = []
        for arg in clean.split(','):
            arg = arg.strip()
            parts = arg.split()
            vname = parts[-1].lstrip('*')
            vtype = ' '.join(parts[:-1])
            if '*' in parts[-1]:
                vtype += ' ' + '*' * parts[-1].count('*')
            call_args.append(map_arg(vtype, vname, fn))

    args_str = ', '.join(call_args)
    if fn in NOT_IMPLEMENTED_ROUTINES:
        test_case = f"""TEST_F(CLBlastAllTest, {fn}) {{
    GTEST_SKIP() << "{fn} is not implemented in CLBlast (CLBlastNotImplemented)";
}}"""
    elif fn == 'CLBlastOverrideParameters':
        test_case = f"""TEST_F(CLBlastAllTest, {fn}) {{
    // Verify CLBlastOverrideParameters can be called from DLL
    CLBlastStatusCode status = {fn}({args_str});
    // With 0 parameters, CLBlast returns CLBlastMissingOverrideParameter (-2047)
    EXPECT_TRUE(status == CLBlastSuccess || status == CLBlastMissingOverrideParameter);
}}"""
    else:
        test_case = f"""TEST_F(CLBlastAllTest, {fn}) {{
    CLBlastStatusCode status = {fn}({args_str});
    if (status == CLBlastNotImplemented) {{
        GTEST_SKIP() << "{fn} is not implemented in CLBlast";
    }} else {{
        EXPECT_EQ(CLBlastSuccess, status);
    }}
}}"""
    test_cases.append(test_case)

header = """#define CL_TARGET_OPENCL_VERSION 120
#include <CL/opencl.h>
#include <clblast_c.h>
#include <clblast_half.h>
#include <gtest/gtest.h>
#include <vector>

class CLBlastAllTest : public ::testing::Test {
protected:
    cl_platform_id platform = nullptr;
    cl_device_id device = nullptr;
    cl_context context = nullptr;
    cl_command_queue queue = nullptr;

    cl_mem buf_a = nullptr;
    cl_mem buf_b = nullptr;
    cl_mem buf_c = nullptr;
    cl_mem buf_x = nullptr;
    cl_mem buf_y = nullptr;
    cl_mem buf_z = nullptr;
    cl_mem buf_res = nullptr;
    cl_mem buf_temp = nullptr;

    cl_float2 alpha_c;
    cl_float2 beta_c;
    cl_double2 alpha_z;
    cl_double2 beta_z;
    cl_half alpha_h;
    cl_half beta_h;

    std::vector<float> alphas_s;
    std::vector<float> betas_s;
    std::vector<double> alphas_d;
    std::vector<double> betas_d;
    std::vector<cl_float2> alphas_c;
    std::vector<cl_float2> betas_c;
    std::vector<cl_double2> alphas_z;
    std::vector<cl_double2> betas_z;
    std::vector<cl_half> alphas_h;
    std::vector<cl_half> betas_h;
    std::vector<size_t> offsets_arr;
    size_t temp_buffer_size_val = 0;

    void SetUp() override {
        cl_uint num_platforms = 0;
        cl_int err = clGetPlatformIDs(1, &platform, &num_platforms);
        ASSERT_EQ(CL_SUCCESS, err);
        ASSERT_GT(num_platforms, 0u);

        cl_uint num_devices = 0;
        err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 1, &device, &num_devices);
        ASSERT_EQ(CL_SUCCESS, err);
        ASSERT_GT(num_devices, 0u);

        context = clCreateContext(nullptr, 1, &device, nullptr, nullptr, &err);
        ASSERT_EQ(CL_SUCCESS, err);

        queue = clCreateCommandQueue(context, device, 0, &err);
        ASSERT_EQ(CL_SUCCESS, err);

        const size_t buf_size = 65536; // 64KB
        std::vector<char> zero_data(buf_size, 0);

        buf_a = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, buf_size, zero_data.data(), &err);
        ASSERT_EQ(CL_SUCCESS, err);
        buf_b = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, buf_size, zero_data.data(), &err);
        ASSERT_EQ(CL_SUCCESS, err);
        buf_c = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, buf_size, zero_data.data(), &err);
        ASSERT_EQ(CL_SUCCESS, err);
        buf_x = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, buf_size, zero_data.data(), &err);
        ASSERT_EQ(CL_SUCCESS, err);
        buf_y = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, buf_size, zero_data.data(), &err);
        ASSERT_EQ(CL_SUCCESS, err);
        buf_z = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, buf_size, zero_data.data(), &err);
        ASSERT_EQ(CL_SUCCESS, err);
        buf_res = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, buf_size, zero_data.data(), &err);
        ASSERT_EQ(CL_SUCCESS, err);
        buf_temp = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR, buf_size, zero_data.data(), &err);
        ASSERT_EQ(CL_SUCCESS, err);

        alpha_c.s[0] = 1.0f; alpha_c.s[1] = 0.0f;
        beta_c.s[0] = 0.0f; beta_c.s[1] = 0.0f;
        alpha_z.s[0] = 1.0; alpha_z.s[1] = 0.0;
        beta_z.s[0] = 0.0; beta_z.s[1] = 0.0;
        alpha_h = FloatToHalf(1.0f);
        beta_h = FloatToHalf(0.0f);

        alphas_s = {1.0f, 1.0f};
        betas_s = {0.0f, 0.0f};
        alphas_d = {1.0, 1.0};
        betas_d = {0.0, 0.0};
        alphas_c = {alpha_c, alpha_c};
        betas_c = {beta_c, beta_c};
        alphas_z = {alpha_z, alpha_z};
        betas_z = {beta_z, beta_z};
        alphas_h = {alpha_h, alpha_h};
        betas_h = {beta_h, beta_h};
        offsets_arr = {0, 16};
    }

    void TearDown() override {
        if (buf_a) clReleaseMemObject(buf_a);
        if (buf_b) clReleaseMemObject(buf_b);
        if (buf_c) clReleaseMemObject(buf_c);
        if (buf_x) clReleaseMemObject(buf_x);
        if (buf_y) clReleaseMemObject(buf_y);
        if (buf_z) clReleaseMemObject(buf_z);
        if (buf_res) clReleaseMemObject(buf_res);
        if (buf_temp) clReleaseMemObject(buf_temp);
        if (queue) clReleaseCommandQueue(queue);
        if (context) clReleaseContext(context);
    }
};
"""

full_code = header + "\n" + "\n\n".join(test_cases) + "\n"
with open(r'tests/all_routines_test.cpp', 'w', encoding='utf-8') as f:
    f.write(full_code)

print(f"Generated tests/all_routines_test.cpp with {len(test_cases)} test cases.")

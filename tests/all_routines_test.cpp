#define CL_TARGET_OPENCL_VERSION 120
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

TEST_F(CLBlastAllTest, CLBlastSrotg) {
    GTEST_SKIP() << "CLBlastSrotg is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastDrotg) {
    GTEST_SKIP() << "CLBlastDrotg is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastSrotmg) {
    GTEST_SKIP() << "CLBlastSrotmg is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastDrotmg) {
    GTEST_SKIP() << "CLBlastDrotmg is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastSrot) {
    GTEST_SKIP() << "CLBlastSrot is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastDrot) {
    GTEST_SKIP() << "CLBlastDrot is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastSrotm) {
    GTEST_SKIP() << "CLBlastSrotm is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastDrotm) {
    GTEST_SKIP() << "CLBlastDrotm is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastSswap) {
    CLBlastStatusCode status = CLBlastSswap(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSswap is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDswap) {
    CLBlastStatusCode status = CLBlastDswap(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDswap is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCswap) {
    CLBlastStatusCode status = CLBlastCswap(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCswap is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZswap) {
    CLBlastStatusCode status = CLBlastZswap(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZswap is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHswap) {
    CLBlastStatusCode status = CLBlastHswap(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHswap is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSscal) {
    CLBlastStatusCode status = CLBlastSscal(4, 1.0f, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSscal is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDscal) {
    CLBlastStatusCode status = CLBlastDscal(4, 1.0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDscal is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCscal) {
    CLBlastStatusCode status = CLBlastCscal(4, alpha_c, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCscal is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZscal) {
    CLBlastStatusCode status = CLBlastZscal(4, alpha_z, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZscal is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHscal) {
    CLBlastStatusCode status = CLBlastHscal(4, alpha_h, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHscal is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastScopy) {
    CLBlastStatusCode status = CLBlastScopy(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastScopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDcopy) {
    CLBlastStatusCode status = CLBlastDcopy(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDcopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCcopy) {
    CLBlastStatusCode status = CLBlastCcopy(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCcopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZcopy) {
    CLBlastStatusCode status = CLBlastZcopy(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZcopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHcopy) {
    CLBlastStatusCode status = CLBlastHcopy(4, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHcopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSaxpy) {
    CLBlastStatusCode status = CLBlastSaxpy(4, 1.0f, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSaxpy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDaxpy) {
    CLBlastStatusCode status = CLBlastDaxpy(4, 1.0, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDaxpy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCaxpy) {
    CLBlastStatusCode status = CLBlastCaxpy(4, alpha_c, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCaxpy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZaxpy) {
    CLBlastStatusCode status = CLBlastZaxpy(4, alpha_z, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZaxpy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHaxpy) {
    CLBlastStatusCode status = CLBlastHaxpy(4, alpha_h, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHaxpy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSdot) {
    CLBlastStatusCode status = CLBlastSdot(4, buf_res, 0, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSdot is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDdot) {
    CLBlastStatusCode status = CLBlastDdot(4, buf_res, 0, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDdot is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHdot) {
    CLBlastStatusCode status = CLBlastHdot(4, buf_res, 0, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHdot is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCdotu) {
    CLBlastStatusCode status = CLBlastCdotu(4, buf_res, 0, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCdotu is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZdotu) {
    CLBlastStatusCode status = CLBlastZdotu(4, buf_res, 0, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZdotu is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCdotc) {
    CLBlastStatusCode status = CLBlastCdotc(4, buf_res, 0, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCdotc is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZdotc) {
    CLBlastStatusCode status = CLBlastZdotc(4, buf_res, 0, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZdotc is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSnrm2) {
    CLBlastStatusCode status = CLBlastSnrm2(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSnrm2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDnrm2) {
    CLBlastStatusCode status = CLBlastDnrm2(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDnrm2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastScnrm2) {
    CLBlastStatusCode status = CLBlastScnrm2(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastScnrm2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDznrm2) {
    CLBlastStatusCode status = CLBlastDznrm2(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDznrm2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHnrm2) {
    CLBlastStatusCode status = CLBlastHnrm2(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHnrm2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSasum) {
    CLBlastStatusCode status = CLBlastSasum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSasum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDasum) {
    CLBlastStatusCode status = CLBlastDasum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDasum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastScasum) {
    CLBlastStatusCode status = CLBlastScasum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastScasum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDzasum) {
    CLBlastStatusCode status = CLBlastDzasum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDzasum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHasum) {
    CLBlastStatusCode status = CLBlastHasum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHasum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSsum) {
    CLBlastStatusCode status = CLBlastSsum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSsum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDsum) {
    CLBlastStatusCode status = CLBlastDsum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDsum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastScsum) {
    CLBlastStatusCode status = CLBlastScsum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastScsum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDzsum) {
    CLBlastStatusCode status = CLBlastDzsum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDzsum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHsum) {
    CLBlastStatusCode status = CLBlastHsum(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHsum is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiSamax) {
    CLBlastStatusCode status = CLBlastiSamax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiSamax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiDamax) {
    CLBlastStatusCode status = CLBlastiDamax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiDamax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiCamax) {
    CLBlastStatusCode status = CLBlastiCamax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiCamax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiZamax) {
    CLBlastStatusCode status = CLBlastiZamax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiZamax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiHamax) {
    CLBlastStatusCode status = CLBlastiHamax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiHamax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiSamin) {
    CLBlastStatusCode status = CLBlastiSamin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiSamin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiDamin) {
    CLBlastStatusCode status = CLBlastiDamin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiDamin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiCamin) {
    CLBlastStatusCode status = CLBlastiCamin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiCamin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiZamin) {
    CLBlastStatusCode status = CLBlastiZamin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiZamin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiHamin) {
    CLBlastStatusCode status = CLBlastiHamin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiHamin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiSmax) {
    CLBlastStatusCode status = CLBlastiSmax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiSmax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiDmax) {
    CLBlastStatusCode status = CLBlastiDmax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiDmax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiCmax) {
    CLBlastStatusCode status = CLBlastiCmax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiCmax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiZmax) {
    CLBlastStatusCode status = CLBlastiZmax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiZmax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiHmax) {
    CLBlastStatusCode status = CLBlastiHmax(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiHmax is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiSmin) {
    CLBlastStatusCode status = CLBlastiSmin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiSmin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiDmin) {
    CLBlastStatusCode status = CLBlastiDmin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiDmin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiCmin) {
    CLBlastStatusCode status = CLBlastiCmin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiCmin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiZmin) {
    CLBlastStatusCode status = CLBlastiZmin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiZmin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastiHmin) {
    CLBlastStatusCode status = CLBlastiHmin(4, buf_res, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastiHmin is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSgemv) {
    CLBlastStatusCode status = CLBlastSgemv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, 1.0f, buf_a, 0, 4, buf_x, 0, 1, 0.0f, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSgemv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDgemv) {
    CLBlastStatusCode status = CLBlastDgemv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, 1.0, buf_a, 0, 4, buf_x, 0, 1, 0.0, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDgemv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCgemv) {
    CLBlastStatusCode status = CLBlastCgemv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, alpha_c, buf_a, 0, 4, buf_x, 0, 1, beta_c, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCgemv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZgemv) {
    CLBlastStatusCode status = CLBlastZgemv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, alpha_z, buf_a, 0, 4, buf_x, 0, 1, beta_z, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZgemv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHgemv) {
    CLBlastStatusCode status = CLBlastHgemv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, alpha_h, buf_a, 0, 4, buf_x, 0, 1, beta_h, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHgemv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSgbmv) {
    CLBlastStatusCode status = CLBlastSgbmv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, 1, 1, 1.0f, buf_a, 0, 4, buf_x, 0, 1, 0.0f, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSgbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDgbmv) {
    CLBlastStatusCode status = CLBlastDgbmv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, 1, 1, 1.0, buf_a, 0, 4, buf_x, 0, 1, 0.0, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDgbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCgbmv) {
    CLBlastStatusCode status = CLBlastCgbmv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, 1, 1, alpha_c, buf_a, 0, 4, buf_x, 0, 1, beta_c, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCgbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZgbmv) {
    CLBlastStatusCode status = CLBlastZgbmv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, 1, 1, alpha_z, buf_a, 0, 4, buf_x, 0, 1, beta_z, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZgbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHgbmv) {
    CLBlastStatusCode status = CLBlastHgbmv(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, 1, 1, alpha_h, buf_a, 0, 4, buf_x, 0, 1, beta_h, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHgbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastChemv) {
    CLBlastStatusCode status = CLBlastChemv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_c, buf_a, 0, 4, buf_x, 0, 1, beta_c, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastChemv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZhemv) {
    CLBlastStatusCode status = CLBlastZhemv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_z, buf_a, 0, 4, buf_x, 0, 1, beta_z, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZhemv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastChbmv) {
    CLBlastStatusCode status = CLBlastChbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1, alpha_c, buf_a, 0, 4, buf_x, 0, 1, beta_c, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastChbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZhbmv) {
    CLBlastStatusCode status = CLBlastZhbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1, alpha_z, buf_a, 0, 4, buf_x, 0, 1, beta_z, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZhbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastChpmv) {
    CLBlastStatusCode status = CLBlastChpmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_c, buf_a, 0, buf_x, 0, 1, beta_c, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastChpmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZhpmv) {
    CLBlastStatusCode status = CLBlastZhpmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_z, buf_a, 0, buf_x, 0, 1, beta_z, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZhpmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSsymv) {
    CLBlastStatusCode status = CLBlastSsymv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0f, buf_a, 0, 4, buf_x, 0, 1, 0.0f, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSsymv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDsymv) {
    CLBlastStatusCode status = CLBlastDsymv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0, buf_a, 0, 4, buf_x, 0, 1, 0.0, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDsymv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHsymv) {
    CLBlastStatusCode status = CLBlastHsymv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_h, buf_a, 0, 4, buf_x, 0, 1, beta_h, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHsymv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSsbmv) {
    CLBlastStatusCode status = CLBlastSsbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1, 1.0f, buf_a, 0, 4, buf_x, 0, 1, 0.0f, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSsbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDsbmv) {
    CLBlastStatusCode status = CLBlastDsbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1, 1.0, buf_a, 0, 4, buf_x, 0, 1, 0.0, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDsbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHsbmv) {
    CLBlastStatusCode status = CLBlastHsbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1, alpha_h, buf_a, 0, 4, buf_x, 0, 1, beta_h, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHsbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSspmv) {
    CLBlastStatusCode status = CLBlastSspmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0f, buf_a, 0, buf_x, 0, 1, 0.0f, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSspmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDspmv) {
    CLBlastStatusCode status = CLBlastDspmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0, buf_a, 0, buf_x, 0, 1, 0.0, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDspmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHspmv) {
    CLBlastStatusCode status = CLBlastHspmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_h, buf_a, 0, buf_x, 0, 1, beta_h, buf_y, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHspmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastStrmv) {
    CLBlastStatusCode status = CLBlastStrmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastStrmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDtrmv) {
    CLBlastStatusCode status = CLBlastDtrmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDtrmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCtrmv) {
    CLBlastStatusCode status = CLBlastCtrmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCtrmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZtrmv) {
    CLBlastStatusCode status = CLBlastZtrmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZtrmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHtrmv) {
    CLBlastStatusCode status = CLBlastHtrmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHtrmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastStbmv) {
    CLBlastStatusCode status = CLBlastStbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 1, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastStbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDtbmv) {
    CLBlastStatusCode status = CLBlastDtbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 1, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDtbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCtbmv) {
    CLBlastStatusCode status = CLBlastCtbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 1, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCtbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZtbmv) {
    CLBlastStatusCode status = CLBlastZtbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 1, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZtbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHtbmv) {
    CLBlastStatusCode status = CLBlastHtbmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 1, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHtbmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastStpmv) {
    CLBlastStatusCode status = CLBlastStpmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastStpmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDtpmv) {
    CLBlastStatusCode status = CLBlastDtpmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDtpmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCtpmv) {
    CLBlastStatusCode status = CLBlastCtpmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCtpmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZtpmv) {
    CLBlastStatusCode status = CLBlastZtpmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZtpmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHtpmv) {
    CLBlastStatusCode status = CLBlastHtpmv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHtpmv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastStrsv) {
    CLBlastStatusCode status = CLBlastStrsv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastStrsv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDtrsv) {
    CLBlastStatusCode status = CLBlastDtrsv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDtrsv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCtrsv) {
    CLBlastStatusCode status = CLBlastCtrsv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCtrsv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZtrsv) {
    CLBlastStatusCode status = CLBlastZtrsv(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, buf_a, 0, 4, buf_x, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZtrsv is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastStbsv) {
    GTEST_SKIP() << "CLBlastStbsv is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastDtbsv) {
    GTEST_SKIP() << "CLBlastDtbsv is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastCtbsv) {
    GTEST_SKIP() << "CLBlastCtbsv is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastZtbsv) {
    GTEST_SKIP() << "CLBlastZtbsv is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastStpsv) {
    GTEST_SKIP() << "CLBlastStpsv is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastDtpsv) {
    GTEST_SKIP() << "CLBlastDtpsv is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastCtpsv) {
    GTEST_SKIP() << "CLBlastCtpsv is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastZtpsv) {
    GTEST_SKIP() << "CLBlastZtpsv is not implemented in CLBlast (CLBlastNotImplemented)";
}

TEST_F(CLBlastAllTest, CLBlastSger) {
    CLBlastStatusCode status = CLBlastSger(CLBlastLayoutRowMajor, 4, 4, 1.0f, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSger is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDger) {
    CLBlastStatusCode status = CLBlastDger(CLBlastLayoutRowMajor, 4, 4, 1.0, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDger is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHger) {
    CLBlastStatusCode status = CLBlastHger(CLBlastLayoutRowMajor, 4, 4, alpha_h, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHger is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCgeru) {
    CLBlastStatusCode status = CLBlastCgeru(CLBlastLayoutRowMajor, 4, 4, alpha_c, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCgeru is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZgeru) {
    CLBlastStatusCode status = CLBlastZgeru(CLBlastLayoutRowMajor, 4, 4, alpha_z, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZgeru is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCgerc) {
    CLBlastStatusCode status = CLBlastCgerc(CLBlastLayoutRowMajor, 4, 4, alpha_c, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCgerc is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZgerc) {
    CLBlastStatusCode status = CLBlastZgerc(CLBlastLayoutRowMajor, 4, 4, alpha_z, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZgerc is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCher) {
    CLBlastStatusCode status = CLBlastCher(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0f, buf_x, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCher is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZher) {
    CLBlastStatusCode status = CLBlastZher(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0, buf_x, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZher is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastChpr) {
    CLBlastStatusCode status = CLBlastChpr(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0f, buf_x, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastChpr is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZhpr) {
    CLBlastStatusCode status = CLBlastZhpr(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0, buf_x, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZhpr is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCher2) {
    CLBlastStatusCode status = CLBlastCher2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_c, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCher2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZher2) {
    CLBlastStatusCode status = CLBlastZher2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_z, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZher2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastChpr2) {
    CLBlastStatusCode status = CLBlastChpr2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_c, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastChpr2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZhpr2) {
    CLBlastStatusCode status = CLBlastZhpr2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_z, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZhpr2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSsyr) {
    CLBlastStatusCode status = CLBlastSsyr(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0f, buf_x, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSsyr is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDsyr) {
    CLBlastStatusCode status = CLBlastDsyr(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0, buf_x, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDsyr is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHsyr) {
    CLBlastStatusCode status = CLBlastHsyr(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_h, buf_x, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHsyr is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSspr) {
    CLBlastStatusCode status = CLBlastSspr(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0f, buf_x, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSspr is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDspr) {
    CLBlastStatusCode status = CLBlastDspr(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0, buf_x, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDspr is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHspr) {
    CLBlastStatusCode status = CLBlastHspr(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_h, buf_x, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHspr is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSsyr2) {
    CLBlastStatusCode status = CLBlastSsyr2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0f, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSsyr2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDsyr2) {
    CLBlastStatusCode status = CLBlastDsyr2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDsyr2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHsyr2) {
    CLBlastStatusCode status = CLBlastHsyr2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_h, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHsyr2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSspr2) {
    CLBlastStatusCode status = CLBlastSspr2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0f, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSspr2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDspr2) {
    CLBlastStatusCode status = CLBlastDspr2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, 1.0, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDspr2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHspr2) {
    CLBlastStatusCode status = CLBlastHspr2(CLBlastLayoutRowMajor, CLBlastTriangleUpper, 4, alpha_h, buf_x, 0, 1, buf_y, 0, 1, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHspr2 is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSgemm) {
    CLBlastStatusCode status = CLBlastSgemm(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 1.0f, buf_a, 0, 4, buf_b, 0, 4, 0.0f, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSgemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDgemm) {
    CLBlastStatusCode status = CLBlastDgemm(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 1.0, buf_a, 0, 4, buf_b, 0, 4, 0.0, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDgemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCgemm) {
    CLBlastStatusCode status = CLBlastCgemm(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alpha_c, buf_a, 0, 4, buf_b, 0, 4, beta_c, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCgemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZgemm) {
    CLBlastStatusCode status = CLBlastZgemm(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alpha_z, buf_a, 0, 4, buf_b, 0, 4, beta_z, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZgemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHgemm) {
    CLBlastStatusCode status = CLBlastHgemm(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alpha_h, buf_a, 0, 4, buf_b, 0, 4, beta_h, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHgemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSsymm) {
    CLBlastStatusCode status = CLBlastSsymm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, 4, 4, 1.0f, buf_a, 0, 4, buf_b, 0, 4, 0.0f, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSsymm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDsymm) {
    CLBlastStatusCode status = CLBlastDsymm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, 4, 4, 1.0, buf_a, 0, 4, buf_b, 0, 4, 0.0, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDsymm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCsymm) {
    CLBlastStatusCode status = CLBlastCsymm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, 4, 4, alpha_c, buf_a, 0, 4, buf_b, 0, 4, beta_c, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCsymm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZsymm) {
    CLBlastStatusCode status = CLBlastZsymm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, 4, 4, alpha_z, buf_a, 0, 4, buf_b, 0, 4, beta_z, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZsymm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHsymm) {
    CLBlastStatusCode status = CLBlastHsymm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, 4, 4, alpha_h, buf_a, 0, 4, buf_b, 0, 4, beta_h, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHsymm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastChemm) {
    CLBlastStatusCode status = CLBlastChemm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, 4, 4, alpha_c, buf_a, 0, 4, buf_b, 0, 4, beta_c, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastChemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZhemm) {
    CLBlastStatusCode status = CLBlastZhemm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, 4, 4, alpha_z, buf_a, 0, 4, buf_b, 0, 4, beta_z, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZhemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSsyrk) {
    CLBlastStatusCode status = CLBlastSsyrk(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, 1.0f, buf_a, 0, 4, 0.0f, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSsyrk is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDsyrk) {
    CLBlastStatusCode status = CLBlastDsyrk(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, 1.0, buf_a, 0, 4, 0.0, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDsyrk is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCsyrk) {
    CLBlastStatusCode status = CLBlastCsyrk(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, alpha_c, buf_a, 0, 4, beta_c, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCsyrk is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZsyrk) {
    CLBlastStatusCode status = CLBlastZsyrk(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, alpha_z, buf_a, 0, 4, beta_z, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZsyrk is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHsyrk) {
    CLBlastStatusCode status = CLBlastHsyrk(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, alpha_h, buf_a, 0, 4, beta_h, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHsyrk is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCherk) {
    CLBlastStatusCode status = CLBlastCherk(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, 1.0f, buf_a, 0, 4, 0.0f, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCherk is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZherk) {
    CLBlastStatusCode status = CLBlastZherk(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, 1.0, buf_a, 0, 4, 0.0, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZherk is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSsyr2k) {
    CLBlastStatusCode status = CLBlastSsyr2k(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, 1.0f, buf_a, 0, 4, buf_b, 0, 4, 0.0f, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSsyr2k is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDsyr2k) {
    CLBlastStatusCode status = CLBlastDsyr2k(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, 1.0, buf_a, 0, 4, buf_b, 0, 4, 0.0, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDsyr2k is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCsyr2k) {
    CLBlastStatusCode status = CLBlastCsyr2k(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, alpha_c, buf_a, 0, 4, buf_b, 0, 4, beta_c, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCsyr2k is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZsyr2k) {
    CLBlastStatusCode status = CLBlastZsyr2k(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, alpha_z, buf_a, 0, 4, buf_b, 0, 4, beta_z, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZsyr2k is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHsyr2k) {
    CLBlastStatusCode status = CLBlastHsyr2k(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, alpha_h, buf_a, 0, 4, buf_b, 0, 4, beta_h, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHsyr2k is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCher2k) {
    CLBlastStatusCode status = CLBlastCher2k(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, alpha_c, buf_a, 0, 4, buf_b, 0, 4, 0.0f, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCher2k is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZher2k) {
    CLBlastStatusCode status = CLBlastZher2k(CLBlastLayoutRowMajor, CLBlastTriangleUpper, CLBlastTransposeNo, 4, 1, alpha_z, buf_a, 0, 4, buf_b, 0, 4, 0.0, buf_c, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZher2k is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastStrmm) {
    CLBlastStatusCode status = CLBlastStrmm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 4, 1.0f, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastStrmm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDtrmm) {
    CLBlastStatusCode status = CLBlastDtrmm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 4, 1.0, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDtrmm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCtrmm) {
    CLBlastStatusCode status = CLBlastCtrmm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 4, alpha_c, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCtrmm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZtrmm) {
    CLBlastStatusCode status = CLBlastZtrmm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 4, alpha_z, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZtrmm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHtrmm) {
    CLBlastStatusCode status = CLBlastHtrmm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 4, alpha_h, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHtrmm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastStrsm) {
    CLBlastStatusCode status = CLBlastStrsm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 4, 1.0f, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastStrsm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDtrsm) {
    CLBlastStatusCode status = CLBlastDtrsm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 4, 1.0, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDtrsm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCtrsm) {
    CLBlastStatusCode status = CLBlastCtrsm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 4, alpha_c, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCtrsm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZtrsm) {
    CLBlastStatusCode status = CLBlastZtrsm(CLBlastLayoutRowMajor, CLBlastSideLeft, CLBlastTriangleUpper, CLBlastTransposeNo, CLBlastDiagonalNonUnit, 4, 4, alpha_z, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZtrsm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastShad) {
    CLBlastStatusCode status = CLBlastShad(4, 1.0f, buf_x, 0, 1, buf_y, 0, 1, 0.0f, buf_z, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastShad is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDhad) {
    CLBlastStatusCode status = CLBlastDhad(4, 1.0, buf_x, 0, 1, buf_y, 0, 1, 0.0, buf_z, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDhad is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastChad) {
    CLBlastStatusCode status = CLBlastChad(4, alpha_c, buf_x, 0, 1, buf_y, 0, 1, beta_c, buf_z, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastChad is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZhad) {
    CLBlastStatusCode status = CLBlastZhad(4, alpha_z, buf_x, 0, 1, buf_y, 0, 1, beta_z, buf_z, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZhad is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHhad) {
    CLBlastStatusCode status = CLBlastHhad(4, alpha_h, buf_x, 0, 1, buf_y, 0, 1, beta_h, buf_z, 0, 1, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHhad is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSomatcopy) {
    CLBlastStatusCode status = CLBlastSomatcopy(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, 1.0f, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSomatcopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDomatcopy) {
    CLBlastStatusCode status = CLBlastDomatcopy(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, 1.0, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDomatcopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastComatcopy) {
    CLBlastStatusCode status = CLBlastComatcopy(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, alpha_c, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastComatcopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZomatcopy) {
    CLBlastStatusCode status = CLBlastZomatcopy(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, alpha_z, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZomatcopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHomatcopy) {
    CLBlastStatusCode status = CLBlastHomatcopy(CLBlastLayoutRowMajor, CLBlastTransposeNo, 4, 4, alpha_h, buf_a, 0, 4, buf_b, 0, 4, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHomatcopy is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSim2col) {
    CLBlastStatusCode status = CLBlastSim2col(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_a, 0, buf_b, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSim2col is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDim2col) {
    CLBlastStatusCode status = CLBlastDim2col(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_a, 0, buf_b, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDim2col is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCim2col) {
    CLBlastStatusCode status = CLBlastCim2col(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_a, 0, buf_b, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCim2col is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZim2col) {
    CLBlastStatusCode status = CLBlastZim2col(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_a, 0, buf_b, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZim2col is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHim2col) {
    CLBlastStatusCode status = CLBlastHim2col(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_a, 0, buf_b, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHim2col is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastScol2im) {
    CLBlastStatusCode status = CLBlastScol2im(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_b, 0, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastScol2im is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDcol2im) {
    CLBlastStatusCode status = CLBlastDcol2im(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_b, 0, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDcol2im is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCcol2im) {
    CLBlastStatusCode status = CLBlastCcol2im(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_b, 0, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCcol2im is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZcol2im) {
    CLBlastStatusCode status = CLBlastZcol2im(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_b, 0, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZcol2im is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHcol2im) {
    CLBlastStatusCode status = CLBlastHcol2im(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, buf_b, 0, buf_a, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHcol2im is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSconvgemm) {
    CLBlastStatusCode status = CLBlastSconvgemm(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, 1, 2, buf_a, 0, buf_c, 0, buf_res, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSconvgemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDconvgemm) {
    CLBlastStatusCode status = CLBlastDconvgemm(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, 1, 2, buf_a, 0, buf_c, 0, buf_res, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDconvgemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHconvgemm) {
    CLBlastStatusCode status = CLBlastHconvgemm(CLBlastKernelModeCrossCorrelation, 1, 4, 4, 2, 2, 0, 0, 1, 1, 1, 1, 1, 2, buf_a, 0, buf_c, 0, buf_res, 0, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHconvgemm is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSaxpyBatched) {
    CLBlastStatusCode status = CLBlastSaxpyBatched(4, alphas_s.data(), buf_x, offsets_arr.data(), 1, buf_y, offsets_arr.data(), 1, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSaxpyBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDaxpyBatched) {
    CLBlastStatusCode status = CLBlastDaxpyBatched(4, alphas_d.data(), buf_x, offsets_arr.data(), 1, buf_y, offsets_arr.data(), 1, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDaxpyBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCaxpyBatched) {
    CLBlastStatusCode status = CLBlastCaxpyBatched(4, alphas_c.data(), buf_x, offsets_arr.data(), 1, buf_y, offsets_arr.data(), 1, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCaxpyBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZaxpyBatched) {
    CLBlastStatusCode status = CLBlastZaxpyBatched(4, alphas_z.data(), buf_x, offsets_arr.data(), 1, buf_y, offsets_arr.data(), 1, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZaxpyBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHaxpyBatched) {
    CLBlastStatusCode status = CLBlastHaxpyBatched(4, alphas_h.data(), buf_x, offsets_arr.data(), 1, buf_y, offsets_arr.data(), 1, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHaxpyBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSgemmBatched) {
    CLBlastStatusCode status = CLBlastSgemmBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alphas_s.data(), buf_a, offsets_arr.data(), 4, buf_b, offsets_arr.data(), 4, betas_s.data(), buf_c, offsets_arr.data(), 4, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSgemmBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDgemmBatched) {
    CLBlastStatusCode status = CLBlastDgemmBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alphas_d.data(), buf_a, offsets_arr.data(), 4, buf_b, offsets_arr.data(), 4, betas_d.data(), buf_c, offsets_arr.data(), 4, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDgemmBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCgemmBatched) {
    CLBlastStatusCode status = CLBlastCgemmBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alphas_c.data(), buf_a, offsets_arr.data(), 4, buf_b, offsets_arr.data(), 4, betas_c.data(), buf_c, offsets_arr.data(), 4, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCgemmBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZgemmBatched) {
    CLBlastStatusCode status = CLBlastZgemmBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alphas_z.data(), buf_a, offsets_arr.data(), 4, buf_b, offsets_arr.data(), 4, betas_z.data(), buf_c, offsets_arr.data(), 4, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZgemmBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHgemmBatched) {
    CLBlastStatusCode status = CLBlastHgemmBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alphas_h.data(), buf_a, offsets_arr.data(), 4, buf_b, offsets_arr.data(), 4, betas_h.data(), buf_c, offsets_arr.data(), 4, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHgemmBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSgemmStridedBatched) {
    CLBlastStatusCode status = CLBlastSgemmStridedBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 1.0f, buf_a, 0, 4, 16, buf_b, 0, 4, 16, 0.0f, buf_c, 0, 4, 16, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSgemmStridedBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDgemmStridedBatched) {
    CLBlastStatusCode status = CLBlastDgemmStridedBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 1.0, buf_a, 0, 4, 16, buf_b, 0, 4, 16, 0.0, buf_c, 0, 4, 16, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDgemmStridedBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCgemmStridedBatched) {
    CLBlastStatusCode status = CLBlastCgemmStridedBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alpha_c, buf_a, 0, 4, 16, buf_b, 0, 4, 16, beta_c, buf_c, 0, 4, 16, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCgemmStridedBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZgemmStridedBatched) {
    CLBlastStatusCode status = CLBlastZgemmStridedBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alpha_z, buf_a, 0, 4, 16, buf_b, 0, 4, 16, beta_z, buf_c, 0, 4, 16, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZgemmStridedBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHgemmStridedBatched) {
    CLBlastStatusCode status = CLBlastHgemmStridedBatched(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alpha_h, buf_a, 0, 4, 16, buf_b, 0, 4, 16, beta_h, buf_c, 0, 4, 16, 2, &queue, nullptr);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHgemmStridedBatched is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSgemmWithTempBuffer) {
    CLBlastStatusCode status = CLBlastSgemmWithTempBuffer(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 1.0f, buf_a, 0, 4, buf_b, 0, 4, 0.0f, buf_c, 0, 4, &queue, nullptr, buf_temp);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSgemmWithTempBuffer is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDgemmWithTempBuffer) {
    CLBlastStatusCode status = CLBlastDgemmWithTempBuffer(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 1.0, buf_a, 0, 4, buf_b, 0, 4, 0.0, buf_c, 0, 4, &queue, nullptr, buf_temp);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDgemmWithTempBuffer is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCgemmWithTempBuffer) {
    CLBlastStatusCode status = CLBlastCgemmWithTempBuffer(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alpha_c, buf_a, 0, 4, buf_b, 0, 4, beta_c, buf_c, 0, 4, &queue, nullptr, buf_temp);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCgemmWithTempBuffer is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZgemmWithTempBuffer) {
    CLBlastStatusCode status = CLBlastZgemmWithTempBuffer(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alpha_z, buf_a, 0, 4, buf_b, 0, 4, beta_z, buf_c, 0, 4, &queue, nullptr, buf_temp);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZgemmWithTempBuffer is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHgemmWithTempBuffer) {
    CLBlastStatusCode status = CLBlastHgemmWithTempBuffer(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, alpha_h, buf_a, 0, 4, buf_b, 0, 4, beta_h, buf_c, 0, 4, &queue, nullptr, buf_temp);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHgemmWithTempBuffer is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastSGemmTempBufferSize) {
    CLBlastStatusCode status = CLBlastSGemmTempBufferSize(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 0, 4, 0, 4, 0, 4, &queue, &temp_buffer_size_val);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastSGemmTempBufferSize is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastDGemmTempBufferSize) {
    CLBlastStatusCode status = CLBlastDGemmTempBufferSize(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 0, 4, 0, 4, 0, 4, &queue, &temp_buffer_size_val);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastDGemmTempBufferSize is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastCGemmTempBufferSize) {
    CLBlastStatusCode status = CLBlastCGemmTempBufferSize(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 0, 4, 0, 4, 0, 4, &queue, &temp_buffer_size_val);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastCGemmTempBufferSize is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastZGemmTempBufferSize) {
    CLBlastStatusCode status = CLBlastZGemmTempBufferSize(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 0, 4, 0, 4, 0, 4, &queue, &temp_buffer_size_val);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastZGemmTempBufferSize is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastHGemmTempBufferSize) {
    CLBlastStatusCode status = CLBlastHGemmTempBufferSize(CLBlastLayoutRowMajor, CLBlastTransposeNo, CLBlastTransposeNo, 4, 4, 1, 0, 4, 0, 4, 0, 4, &queue, &temp_buffer_size_val);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastHGemmTempBufferSize is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastClearCache) {
    CLBlastStatusCode status = CLBlastClearCache();
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastClearCache is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastFillCache) {
    CLBlastStatusCode status = CLBlastFillCache(device);
    if (status == CLBlastNotImplemented) {
        GTEST_SKIP() << "CLBlastFillCache is not implemented in CLBlast";
    } else {
        EXPECT_EQ(CLBlastSuccess, status);
    }
}

TEST_F(CLBlastAllTest, CLBlastOverrideParameters) {
    // Verify CLBlastOverrideParameters can be called from DLL
    CLBlastStatusCode status = CLBlastOverrideParameters(device, "Xgemm", CLBlastPrecisionSingle, 0, nullptr, nullptr);
    // With 0 parameters, CLBlast returns CLBlastMissingOverrideParameter (-2047)
    EXPECT_TRUE(status == CLBlastSuccess || status == CLBlastMissingOverrideParameter);
}

#define CL_TARGET_OPENCL_VERSION 120
#include <CL/opencl.h>
#include <clblast_c.h>
#include <clblast_half.h>
#include <gtest/gtest.h>
#include <vector>
#include <cmath>

class CLBlastAxpyTest : public ::testing::Test {
protected:
    cl_platform_id platform = nullptr;
    cl_device_id device = nullptr;
    cl_context context = nullptr;
    cl_command_queue queue = nullptr;

    void SetUp() override {
        cl_uint num_platforms = 0;
        cl_int err = clGetPlatformIDs(1, &platform, &num_platforms);
        ASSERT_EQ(CL_SUCCESS, err) << "clGetPlatformIDs failed";
        ASSERT_GT(num_platforms, 0u) << "No OpenCL platform found";

        cl_uint num_devices = 0;
        err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 1, &device, &num_devices);
        ASSERT_EQ(CL_SUCCESS, err) << "clGetDeviceIDs failed";
        ASSERT_GT(num_devices, 0u) << "No OpenCL device found";

        context = clCreateContext(nullptr, 1, &device, nullptr, nullptr, &err);
        ASSERT_EQ(CL_SUCCESS, err) << "clCreateContext failed";

        queue = clCreateCommandQueue(context, device, 0, &err);
        ASSERT_EQ(CL_SUCCESS, err) << "clCreateCommandQueue failed";
    }

    void TearDown() override {
        if (queue) {
            clReleaseCommandQueue(queue);
            queue = nullptr;
        }
        if (context) {
            clReleaseContext(context);
            context = nullptr;
        }
    }
};

TEST_F(CLBlastAxpyTest, Saxpy) {
    const size_t n = 5;
    const float alpha = 2.0f;
    std::vector<float> x = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    std::vector<float> y = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f};

    cl_int err;
    cl_mem buf_x = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(float) * n, x.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    cl_mem buf_y = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(float) * n, y.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    CLBlastStatusCode status = CLBlastSaxpy(n, alpha, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    EXPECT_EQ(CLBlastSuccess, status);

    err = clEnqueueReadBuffer(queue, buf_y, CL_TRUE, 0, sizeof(float) * n, y.data(), 0, nullptr, nullptr);
    EXPECT_EQ(CL_SUCCESS, err);

    EXPECT_FLOAT_EQ(12.0f, y[0]);
    EXPECT_FLOAT_EQ(24.0f, y[1]);
    EXPECT_FLOAT_EQ(36.0f, y[2]);
    EXPECT_FLOAT_EQ(48.0f, y[3]);
    EXPECT_FLOAT_EQ(60.0f, y[4]);

    clReleaseMemObject(buf_x);
    clReleaseMemObject(buf_y);
}

TEST_F(CLBlastAxpyTest, Daxpy) {
    const size_t n = 4;
    const double alpha = 3.0;
    std::vector<double> x = {1.0, -2.0, 3.0, -4.0};
    std::vector<double> y = {5.0, 6.0, 7.0, 8.0};

    cl_int err;
    cl_mem buf_x = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(double) * n, x.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    cl_mem buf_y = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(double) * n, y.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    CLBlastStatusCode status = CLBlastDaxpy(n, alpha, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    EXPECT_EQ(CLBlastSuccess, status);

    err = clEnqueueReadBuffer(queue, buf_y, CL_TRUE, 0, sizeof(double) * n, y.data(), 0, nullptr, nullptr);
    EXPECT_EQ(CL_SUCCESS, err);

    EXPECT_DOUBLE_EQ(8.0, y[0]);
    EXPECT_DOUBLE_EQ(0.0, y[1]);
    EXPECT_DOUBLE_EQ(16.0, y[2]);
    EXPECT_DOUBLE_EQ(-4.0, y[3]);

    clReleaseMemObject(buf_x);
    clReleaseMemObject(buf_y);
}

TEST_F(CLBlastAxpyTest, Caxpy) {
    const size_t n = 2;
    cl_float2 alpha;
    alpha.s[0] = 2.0f;
    alpha.s[1] = 1.0f;

    std::vector<cl_float2> x(n);
    x[0].s[0] = 1.0f; x[0].s[1] = 2.0f;
    x[1].s[0] = 3.0f; x[1].s[1] = 4.0f;

    std::vector<cl_float2> y(n);
    y[0].s[0] = 5.0f; y[0].s[1] = 6.0f;
    y[1].s[0] = 7.0f; y[1].s[1] = 8.0f;

    cl_int err;
    cl_mem buf_x = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(cl_float2) * n, x.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    cl_mem buf_y = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(cl_float2) * n, y.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    CLBlastStatusCode status = CLBlastCaxpy(n, alpha, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    EXPECT_EQ(CLBlastSuccess, status);

    err = clEnqueueReadBuffer(queue, buf_y, CL_TRUE, 0, sizeof(cl_float2) * n, y.data(), 0, nullptr, nullptr);
    EXPECT_EQ(CL_SUCCESS, err);

    EXPECT_FLOAT_EQ(5.0f, y[0].s[0]);
    EXPECT_FLOAT_EQ(11.0f, y[0].s[1]);
    EXPECT_FLOAT_EQ(9.0f, y[1].s[0]);
    EXPECT_FLOAT_EQ(19.0f, y[1].s[1]);

    clReleaseMemObject(buf_x);
    clReleaseMemObject(buf_y);
}

TEST_F(CLBlastAxpyTest, Zaxpy) {
    const size_t n = 2;
    cl_double2 alpha;
    alpha.s[0] = 2.0;
    alpha.s[1] = -1.0;

    std::vector<cl_double2> x(n);
    x[0].s[0] = 1.0; x[0].s[1] = 1.0;
    x[1].s[0] = 2.0; x[1].s[1] = -1.0;

    std::vector<cl_double2> y(n);
    y[0].s[0] = 3.0; y[0].s[1] = 4.0;
    y[1].s[0] = 1.0; y[1].s[1] = 2.0;

    cl_int err;
    cl_mem buf_x = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(cl_double2) * n, x.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    cl_mem buf_y = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(cl_double2) * n, y.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    CLBlastStatusCode status = CLBlastZaxpy(n, alpha, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    EXPECT_EQ(CLBlastSuccess, status);

    err = clEnqueueReadBuffer(queue, buf_y, CL_TRUE, 0, sizeof(cl_double2) * n, y.data(), 0, nullptr, nullptr);
    EXPECT_EQ(CL_SUCCESS, err);

    EXPECT_DOUBLE_EQ(6.0, y[0].s[0]);
    EXPECT_DOUBLE_EQ(5.0, y[0].s[1]);
    EXPECT_DOUBLE_EQ(4.0, y[1].s[0]);
    EXPECT_DOUBLE_EQ(-2.0, y[1].s[1]);

    clReleaseMemObject(buf_x);
    clReleaseMemObject(buf_y);
}

TEST_F(CLBlastAxpyTest, Haxpy) {
    const size_t n = 2;
    cl_half alpha = FloatToHalf(0.5f);

    std::vector<cl_half> x = {FloatToHalf(2.0f), FloatToHalf(4.0f)};
    std::vector<cl_half> y = {FloatToHalf(1.0f), FloatToHalf(2.0f)};

    cl_int err;
    cl_mem buf_x = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(cl_half) * n, x.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    cl_mem buf_y = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(cl_half) * n, y.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    CLBlastStatusCode status = CLBlastHaxpy(n, alpha, buf_x, 0, 1, buf_y, 0, 1, &queue, nullptr);
    EXPECT_EQ(CLBlastSuccess, status);

    err = clEnqueueReadBuffer(queue, buf_y, CL_TRUE, 0, sizeof(cl_half) * n, y.data(), 0, nullptr, nullptr);
    EXPECT_EQ(CL_SUCCESS, err);

    EXPECT_NEAR(2.0f, HalfToFloat(y[0]), 0.01f);
    EXPECT_NEAR(4.0f, HalfToFloat(y[1]), 0.01f);

    clReleaseMemObject(buf_x);
    clReleaseMemObject(buf_y);
}

TEST_F(CLBlastAxpyTest, SaxpyBatched) {
    const size_t n = 3;
    const size_t batch_count = 2;
    std::vector<float> alphas = {2.0f, 3.0f};

    std::vector<float> x = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f};
    std::vector<float> y = {10.0f, 20.0f, 30.0f, 40.0f, 50.0f, 60.0f};
    std::vector<size_t> x_offsets = {0, 3};
    std::vector<size_t> y_offsets = {0, 3};
    const size_t x_inc = 1;
    const size_t y_inc = 1;

    cl_int err;
    cl_mem buf_x = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(float) * x.size(), x.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    cl_mem buf_y = clCreateBuffer(context, CL_MEM_READ_WRITE | CL_MEM_COPY_HOST_PTR,
                                  sizeof(float) * y.size(), y.data(), &err);
    ASSERT_EQ(CL_SUCCESS, err);

    CLBlastStatusCode status = CLBlastSaxpyBatched(
        n, alphas.data(),
        buf_x, x_offsets.data(), x_inc,
        buf_y, y_offsets.data(), y_inc,
        batch_count, &queue, nullptr
    );
    EXPECT_EQ(CLBlastSuccess, status);

    err = clEnqueueReadBuffer(queue, buf_y, CL_TRUE, 0, sizeof(float) * y.size(), y.data(), 0, nullptr, nullptr);
    EXPECT_EQ(CL_SUCCESS, err);

    EXPECT_FLOAT_EQ(12.0f, y[0]);
    EXPECT_FLOAT_EQ(24.0f, y[1]);
    EXPECT_FLOAT_EQ(36.0f, y[2]);
    EXPECT_FLOAT_EQ(52.0f, y[3]);
    EXPECT_FLOAT_EQ(65.0f, y[4]);
    EXPECT_FLOAT_EQ(78.0f, y[5]);

    clReleaseMemObject(buf_x);
    clReleaseMemObject(buf_y);
}

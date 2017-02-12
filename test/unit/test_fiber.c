#include <unity.h>
#include <string.h>

#include <fiber.h>

#define kFIBER_TRACE_LENGTH 8
#define kMARK               (void *)(long)1

static void *fiber_trace[kFIBER_TRACE_LENGTH];
static Fiber *fiber;
static int resumed_times;

void *fiberRoutine(void *arg)
{
    fiber_trace[0] = arg;
    return NULL;
}


void *fiberRoutineThatYieldsProcessor(void *arg)
{
    fiber_trace[0] = arg;
    Fiber_Yield(fiber);
    fiber_trace[1] = arg;
    return NULL;
}


void *fiberRoutineThatYieldsProcessorInLoop(void *arg)
{
    while (1) {
        resumed_times++;
        Fiber_Yield(fiber);
    }
    return NULL;
}


void setUp(void)
{
    memset(fiber_trace, 0, sizeof(fiber_trace));
}


void tearDown(void)
{
    Fiber_Destroy(fiber);
}


void should_create_and_destroy_fiber(void)
{
    fiber = Fiber_Create(fiberRoutine, NULL);

    TEST_ASSERT_NOT_NULL(fiber);
}


void should_run_single_fiber(void)
{
    fiber = Fiber_Create(fiberRoutine, kMARK);

    Fiber_Run(fiber);

    TEST_ASSERT_EQUAL_INT(kMARK, fiber_trace[0]);
}


void should_release_cpu_after_yielding(void)
{
    fiber = Fiber_Create(fiberRoutineThatYieldsProcessor, kMARK);

    Fiber_Run(fiber);

    TEST_ASSERT_EQUAL_INT(kMARK, fiber_trace[0]);
    TEST_ASSERT_EQUAL_INT(NULL, fiber_trace[1]);
}


void should_resume_fiber(void)
{
    fiber = Fiber_Create(fiberRoutineThatYieldsProcessor, kMARK);
    Fiber_Run(fiber);

    Fiber_Resume(fiber);

    TEST_ASSERT_EQUAL_INT(kMARK, fiber_trace[0]);
    TEST_ASSERT_EQUAL_INT(kMARK, fiber_trace[1]);
}


void should_swap_context_many_times(void)
{
    int i;

    fiber = Fiber_Create(fiberRoutineThatYieldsProcessorInLoop, kMARK);

    resumed_times = 0;
    for (i=0; i<1000; ++i) {
        Fiber_Resume(fiber);
    }

    TEST_ASSERT_EQUAL_INT(1000, resumed_times);
}

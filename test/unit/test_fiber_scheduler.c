#include <unity.h>

#include <fiber_scheduler.h>

FiberScheduler *fiber_scheduler;

void setUp(void)
{
	fiber_scheduler = FiberScheduler_Create();
}


void tearDown(void)
{
	FiberScheduler_Destroy(fiber_scheduler);
}


void should_create_and_destroy_fiber_scheduler(void)
{
	TEST_ASSERT_NOT_NULL(fiber_scheduler);
}


void should_register_fiber_in_fiber_scheduler(void)
{
	Fiber *fiber;
	int ret;

	ret = FiberScheduler_RegisterFiber(fiber_scheduler, fiber);

	TEST_ASSERT_EQUAL_INT(0, ret);
}

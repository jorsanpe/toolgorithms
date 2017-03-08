/**
 *  fiber_scheduler.c --
 *
 * Copyright (C) 2017 Jordi Sánchez, jorsanpe@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <fiber_scheduler.h>

struct fiber_scheduler {
	int placeholder;
};

FiberScheduler *FiberScheduler_Create(void)
{
	return malloc(sizeof(FiberScheduler));
}


void FiberScheduler_Destroy(FiberScheduler *self)
{
	free(self);
}


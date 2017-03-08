/**
 * fiber_scheduler.h -- Fiber scheduler library
 *
 * Copyright (C) 2017 Jordi Sánchez, jorsanpe@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#pragma once


typedef struct fiber_scheduler FiberScheduler;

FiberScheduler *FiberScheduler_Create(void);

void FiberScheduler_Destroy(FiberScheduler *self);

int FiberScheduler_RegisterFiber(FiberScheduler *self, Fiber *fiber);

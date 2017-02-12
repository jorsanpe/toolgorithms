/**
 * fiber.h -- Fiber library
 *
 * Copyright (C) 2015 Jordi Sánchez, jorsanpe@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */

#define kFIBER_CONTEXT_SAVED    0
#define kFIBER_CONTEXT_RESTORED 1

typedef struct fiber Fiber;

Fiber *Fiber_Create(void *(*routine)(void *), void *arg);

void Fiber_Destroy(Fiber *self);

void Fiber_Run(Fiber *self);

void Fiber_Yield(Fiber *self);

void Fiber_Resume(Fiber *self);

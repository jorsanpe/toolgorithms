/**
 *  fiber.c -- 
 *
 * Copyright (C) 2016 Jordi Sánchez, jorsanpe@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdlib.h>
#include <ucontext.h>
#include <fiber.h>

struct fiber {
    void *(*routine)(void *);
    void *arg;
    ucontext_t context;
    ucontext_t parent_context;
    unsigned char stack[SIGSTKSZ];
};


static void createContext(Fiber* self)
{
    getcontext(&self->context);
    self->context.uc_link = &self->parent_context;
    self->context.uc_stack.ss_sp = self->stack;
    self->context.uc_stack.ss_size = SIGSTKSZ;
    makecontext(&self->context, (void (*)(void)) self->routine, 1, self->arg);
}


Fiber *Fiber_Create(void *(*routine)(void *), void *arg)
{
    Fiber *self = malloc(sizeof(Fiber));

    self->routine = routine;
    self->arg = arg;
    createContext(self);

    return self;
}


void Fiber_Destroy(Fiber *self)
{
    free(self);
}


void Fiber_Run(Fiber *self)
{
    Fiber_Resume(self);
}


void Fiber_Yield(Fiber *self)
{
    swapcontext(&self->context, &self->parent_context);
}


void Fiber_Resume(Fiber *self)
{
    swapcontext(&self->parent_context, &self->context);
}


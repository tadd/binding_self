#include "binding_eval_with_block.h"

/*
 * copy from vm_core.h
 */

#define GetCoreDataFromValue(obj, type, ptr) do { \
    (ptr) = (type*)DATA_PTR(obj); \
} while (0)

typedef struct rb_block_struct {
    VALUE self;			/* share with method frame if it's only block */
    VALUE klass;		/* share with method frame if it's only block */
    VALUE *ep;			/* share with method frame if it's only block */
    void *iseq; // changed
    VALUE proc;
} rb_block_t;

#define GetEnvPtr(obj, ptr) \
  GetCoreDataFromValue((obj), rb_env_t, (ptr))

typedef struct {
    VALUE *env;
    int env_size;
    int local_size;
    VALUE prev_envval;		/* for GC mark */
    rb_block_t block;
} rb_env_t;

#define GetBindingPtr(obj, ptr) \
  GetCoreDataFromValue((obj), rb_binding_t, (ptr))

typedef struct {
    VALUE env;
    VALUE path;
    VALUE blockprocval;	/* for GC mark */
    unsigned short first_lineno;
} rb_binding_t;

/*
 * copy ends here
 */

static VALUE
get_self(VALUE bindingval)
{
    rb_binding_t *binding;
    rb_env_t *env;

    GetBindingPtr(bindingval, binding);
    GetEnvPtr(binding->env, env);
    return env->block.self;
}

static VALUE
block_eval(VALUE binding)
{
    const VALUE self = get_self(binding);

    return rb_obj_instance_eval(0, NULL, self);
}


static VALUE
bind_eval_with_block(int argc, VALUE *argv, VALUE binding)
{
    if (rb_block_given_p()) {
	rb_check_arity(argc, 0, 0);
	return block_eval(binding);
    } else
	return rb_funcallv(binding, rb_intern("_eval_original"), argc, argv);
}


void
Init_binding_eval_with_block(void)
{
    rb_define_alias(rb_cBinding, "_eval_original", "eval");
    rb_define_method(rb_cBinding, "eval", bind_eval_with_block, -1);
}

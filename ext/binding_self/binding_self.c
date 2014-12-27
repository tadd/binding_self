#include "binding_self.h"
#include VM_CORE_HEADER_FILE

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
bind_self(VALUE binding)
{
  return get_self(binding);
}

void
Init_binding_self(void)
{
    rb_define_method(rb_cBinding, "self", bind_self, 0);
}

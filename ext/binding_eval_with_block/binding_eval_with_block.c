#include "binding_eval_with_block.h"

void
Init_binding_eval_with_block(void)
{
    rb_define_alias(rb_cBinding, "_eval_original", "eval");
}

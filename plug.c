#include <assert.h>
#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_types/_null.h>
#include <sys/_types/_size_t.h>

typedef struct {
} Plug;

static Plug *p = NULL;

void plug_init() {
  p = malloc(sizeof(*p));
  assert(p != NULL);
  memset(p, 0, sizeof(*p));

  TraceLog(LOG_INFO, "==================");
  TraceLog(LOG_INFO, "Initialized Plugin");
  TraceLog(LOG_INFO, "==================");
}

void *plug_pre_reload(void) {
  return p;
}

void plug_post_reload(void *state) {
  p = state;
}; 

void plug_update(void) {
  BeginDrawing();
  ClearBackground(GetColor(0x181818FF));
  EndDrawing();
}


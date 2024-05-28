#include <alloca.h>
#include <raylib.h>
#include <dlfcn.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "plug.h"

const char *libplug_path = "libplug.so";
void *libplug = NULL;

bool reload_libplug() {
  if (libplug != NULL) {
    dlclose(libplug);
  }

  libplug = dlopen(libplug_path, RTLD_NOW);
  if (libplug == NULL) {
    fprintf(stderr, "ERROR: could not load%s: %s\n", libplug_path, dlerror());
    return false;
  }

  plug_init = dlsym(libplug, "plug_init");
  if (plug_init == NULL) {
    fprintf(stderr, "ERROR: %s\n", dlerror());
    return false;
  }

  plug_pre_reload = dlsym(libplug, "plug_pre_reload");
  if (plug_pre_reload == NULL) {
    fprintf(stderr, "ERROR: %s\n", dlerror());
    return false;
  }

  plug_post_reload = dlsym(libplug, "plug_post_reload");
  if (plug_post_reload == NULL) {
    fprintf(stderr, "ERROR: %s\n", dlerror());
    return false;
  }

  plug_update = dlsym(libplug, "plug_update");
  if (plug_update == NULL) {
    fprintf(stderr, "ERROR: %s\n", dlerror());
    return false;
  }

  return true;
}

int main() {
  if (!reload_libplug()) return 1;

  InitWindow(1280, 720, "raylib hot reload");
  SetTargetFPS(30);
  plug_init();

  while (!WindowShouldClose()) {
    if (IsKeyPressed(KEY_R)) {
      void *state = plug_pre_reload();
      reload_libplug();
      plug_post_reload(state);
    }

    plug_update();
  }

  CloseWindow();

  return 0;
}

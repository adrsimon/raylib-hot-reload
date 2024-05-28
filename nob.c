#include <malloc/_malloc_type.h>
#define NOB_IMPLEMENTATION
#include "nob.h"

void gcc(Nob_Cmd *cmd) {
  nob_cmd_append(cmd, "gcc");
  nob_cmd_append(cmd, "-Wall", "-Wextra");
  nob_cmd_append(cmd, "-I./raylib/include");
}

void libs(Nob_Cmd *cmd) {
  nob_cmd_append(cmd, "-Wl,-rpath,./raylib/lib/");
  nob_cmd_append(cmd, "-L./raylib/lib/");
  nob_cmd_append(cmd, "-lraylib");
}

bool build_plug(Nob_Cmd *cmd) {
  cmd->count = 0;
  gcc(cmd);
  nob_cmd_append(cmd, "-fPIC", "-shared");
  nob_cmd_append(cmd, "-o", "./libplug.so");
  nob_cmd_append(cmd, "plug.c");
  libs(cmd);
  return nob_cmd_run_sync(*cmd);
}

bool build_main(Nob_Cmd *cmd) {
  cmd->count = 0;
  gcc(cmd);
  nob_cmd_append(cmd, "-o", "main");
  nob_cmd_append(cmd, "main.c");
  libs(cmd);

  return nob_cmd_run_sync(*cmd);
}

int main(int argc, char *argv[]) {
  NOB_GO_REBUILD_URSELF(argc, argv);

  Nob_Cmd cmd = {0};

  if (!build_plug(&cmd)) return 1;
  if (!build_main(&cmd)) return 1;

  return 0;
}

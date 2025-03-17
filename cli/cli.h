#pragma once

typedef struct {
  char *name;
  char arg;

  int (*call)(void *args);

  char *usage;

} cli_arg_t;

int cli_debug();
int cli_print_help(void *arg);

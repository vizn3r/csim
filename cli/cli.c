#include "cli.h"
#include <stdio.h>
#include <string.h>

cli_arg_t args[] = {{.name = "help",
                     .arg = 'h',
                     .usage = "Print help menu",
                     .call = &cli_print_help},
                    {.name = "debug",
                     .arg = 'd',
                     .usage = "Debug for libraries",
                     .call = &cli_debug}};

int main(int argc, char **argv) {
  printf("SIM CLI\n  by vizn3r\n\n");
  int ret = 0;

  if (argc <= 1) {
    cli_print_help(NULL);
    return ret;
  }

  for (int i = 1; i < argc; i++) {
    char *arg = argv[i];
    if (strlen(arg) <= 1 || arg[0] != '-') {
      printf("\nInvalid parameter '%s'\n", arg);
      return 1;
    }

    for (int i = 0; i < (sizeof(args) / sizeof(cli_arg_t)); i++) {
      if (arg[1] == args[i].arg) {
        ret = args[i].call(arg);
      }
    }
  }

  return ret;
}

int cli_debug() {
  printf(">>> CLI DEBUG TEST <<<\n");

  return 0;
}

int cli_print_help(void *void_arg) {
  char *arg = (char *)void_arg;

  printf("List of arguments:\n\n");
  for (int i = 0; i < (sizeof(args) / sizeof(cli_arg_t)); i++) {
    printf("  -%c  %s  %s\n", args[i].arg, args[i].name, args[i].usage);
  }
  printf("\n");

  return 0;
}

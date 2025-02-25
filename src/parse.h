#ifndef PARSE_H
#define PARSE_H

#include "expand.h"

static const int max_read_line_len = 1024*10;

static const int ERROR_NULL                      =  0;
static const int ERROR_EOF                       =  1;
static const int ERROR_BADEOF                    =  2;
static const int ERROR_INVALID_LINE              =  3;
static const int ERROR_INVALID_STRING            =  4;
static const int ERROR_INVALID_MODIFICATION      =  5;
static const int ERROR_UNTERMINATED_STRING       =  6;
static const int ERROR_UNPARENTED_MODIFICATION   =  7;
static const int ERROR_INVALID_NULL_MODIFICATION =  8;
static const int ERROR_MODIFICATION_EMPTY_GAMUT  =  9;
static const int ERROR_NULL_CHILD                = 10;
static const int ERROR_TAG_RANGE                 = 11;
static const int ERROR_TAG_SPECIFY               = 12;

struct parse_error
{
  int error;
  int force;
  char *txt;
};

int parse_modification(FILE *fp, int *line_n, char *buff, char **b, modification *m, parse_error *er);
int parse_modifications(FILE *fp, int *line_n, char *buff, char **b, group *g, parse_error *er);
int parse_child(FILE *fp, int unquoted, int *line_n, char *buff, char **b, group *g, group *prev_g, int depth, parse_error *er);
int parse_childs(FILE *fp, int unquoted, int *line_n, char *buff, char **b, group *g, int depth, parse_error *er);
int parse_tag(FILE *fp, int *line_n, char *buff, char **b, tag *t, int u, parse_error *er);
group *parse(FILE *fp, int unquoted);
void print_tag(tag t, int u);

#endif //PARSE_H


#ifndef TYPEDEFS_H
#define TYPEDEFS_H

typedef enum _bool
{
	false = 0,
	true = 1
} Bool;

typedef enum errors
{
	READLINE = 0
} Errors;

typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

#endif /* TYPEDEFS_H */

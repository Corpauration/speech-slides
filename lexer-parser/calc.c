#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum TokenKind {
  NUMBER,
  PLUS,
  MINUS,
  TIMES,
  DIVIDE,
  LPAREN,
  RPAREN
} TokenKind;

typedef struct Token {
  TokenKind kind;
  int value;
} Token;

typedef struct Lexer {
  char c;
  int cursor;
  char content[4096];
  int is_finish;
} Lexer;

Lexer *init_lexer(char *text) {
  Lexer *res = malloc(sizeof(Lexer));

  strcpy(res->content, text);
  res->cursor = 0;
  res->c = res->content[res->cursor];
  res->is_finish = 0;

  return res;
}

void lexer_advance(Lexer *l) {
  if (!(l->is_finish)) {
    if (strlen(l->content) <= (l->cursor + 1)) {
      l->is_finish = 1;
    } else {
      l->cursor += 1;
      l->c = l->content[l->cursor];
    }
  }
}

void lexer_skip_whitespaces(Lexer *l) {
  while (l->c == ' ' || l->c == '\t')
    lexer_advance(l);
}

int is_num(char c) { return (c > 47 && c < 58); }

Token *lexer_get_token(Lexer *l) {
  Token *res = malloc(sizeof(Token));
  int i = 0;
  char temp[4096];

  lexer_skip_whitespaces(l);

  if (is_num(l->c)) {
    while (is_num(l->c) && !(l->is_finish)) {
      temp[i] = l->c;
      i++;
      lexer_advance(l);
    }
    temp[i] = '\0';
    res->kind = NUMBER;
    res->value = atoi(temp);
    return res;
  } else {
    switch (l->c) {
    case '+':
      lexer_advance(l);
      res->kind = PLUS;
      return res;
    case '-':
      lexer_advance(l);
      res->kind = MINUS;
      return res;
    case '*':
      lexer_advance(l);
      res->kind = TIMES;
      return res;
    case '/':
      lexer_advance(l);
      res->kind = DIVIDE;
      return res;
    case '(':
      lexer_advance(l);
      res->kind = LPAREN;
      return res;
    case ')':
      lexer_advance(l);
      res->kind = RPAREN;
      return res;
    default:
      fprintf(stderr, "Ca ne sert à rien\n");
      exit(EXIT_FAILURE);
    }
  }
  return res;
}

void print_token(Token *t) {
  switch (t->kind) {
  case NUMBER:
    printf("NUMBER %d", t->value);
    break;
  case PLUS:
    printf("PLUS");
    break;
  case MINUS:
    printf("MINUS");
    break;
  case TIMES:
    printf("TIMES");
    break;
  case DIVIDE:
    printf("DIVIDE");
    break;
  case LPAREN:
    printf("LPAREN");
    break;
  case RPAREN:
    printf("RPAREN");
    break;
  }

  printf("\n");
}

typedef enum NodeKind {
  NODE_NUMBER,
  NODE_PLUS,
  NODE_MINUS,
  NODE_TIMES,
  NODE_DIVIDE,
  NODE_UMINUS,
  NODE_NONE
} NodeKind;

typedef struct Node {
  NodeKind kind;
  int value;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct Parser {
  int size;
  int cursor;
  Token **tlist;
} Parser;

int parser_finish(Parser *p) { return (p->size <= p->cursor); }

Token *parser_curent(Parser *p) { return p->tlist[p->cursor]; }

void parser_next(Parser *p) {
  if (!parser_finish(p)) {
    p->cursor += 1;
  }
}

Node *parse_expression(Parser *p);

Node *parse_primary_expression(Parser *p) {
  Node *res = malloc(sizeof(Node));
  Token *t = parser_curent(p);

  switch (t->kind) {
  case NUMBER:
    res->kind = NODE_NUMBER;
    res->value = t->value;
    printf("%d", res->value);
    parser_next(p);
    return res;
  case MINUS:
    parser_next(p);
    res->kind = NODE_UMINUS;
    res->left = parse_primary_expression(p);
    return res;
  case LPAREN:
    parser_next(p);
    res = parse_expression(p);
    parser_next(p);
    return res;
  default:
    fprintf(stderr, "T mauvais jack\n");
    exit(EXIT_FAILURE);
  }
  return res;
}

Node *parse_factor_expression(Parser *p) {
  Node *temp;
  Node *left = parse_primary_expression(p);
  Token *t = parser_curent(p);

  while (t->kind == TIMES || t->kind == DIVIDE) {
    temp = malloc(sizeof(Node));
    if (t->kind == TIMES) {
      temp->kind = NODE_TIMES;
    } else {
      temp->kind = NODE_DIVIDE;
    }
    parser_next(p);
    temp->left = left;
    temp->right = parse_primary_expression(p);
    left = temp;
    if (parser_finish(p)) {
      break;
    }
    t = parser_curent(p);
  }

  return left;
}

Node *parse_expression(Parser *p) {
  Node *temp;
  Node *left = parse_factor_expression(p);
  Token *t = parser_curent(p);

  while (t->kind == PLUS || t->kind == MINUS) {
    temp = malloc(sizeof(Node));
    if (t->kind == NODE_PLUS) {
      temp->kind = NODE_PLUS;
    } else {
      temp->kind = NODE_MINUS;
    }
    parser_next(p);
    temp->left = left;
    temp->right = parse_factor_expression(p);
    left = temp;
    if (parser_finish(p)) {
      break;
    }
    t = parser_curent(p);
  }

  return left;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    fprintf(stderr, "T mauvais jack\n");
    return 1;
  }

  Lexer *l = init_lexer(argv[1]);
  Token *tlist[4096];
  int tnum = 0;

  printf("Le lexer qui marche :\n");
  while (!l->is_finish) {
    tlist[tnum] = lexer_get_token(l);
    print_token(tlist[tnum]);
    tnum++;
  }

  Parser p = (Parser){
      tnum,
      0,
      tlist
  };
  Node* tree = parse_expression(&p);

  free(l);
  return 0;
}

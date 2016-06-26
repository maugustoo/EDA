NAME = eda

INCDIR = inc
SRCDIR = src
OBJDIR = obj
BINDIR = bin

CC = gcc

CFLAGS = -I

EDA = $(BINDIR)/$(NAME)
INC = ${wildcard $(INCDIR)/*.h}
SRC = ${wildcard $(SRCDIR)/*.c}
OBJ = ${addprefix $(OBJDIR)/, ${notdir ${SRC:.c=.o}}}

.PHONY: clean depend

all:
	@echo oi
	@mkdir -p $(OBJDIR) $(BINDIR)
	@echo tchau
	$(MAKE) $(EDA)
	@echo lucas xp

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo eda queria passae $@ ...
	@$(CC) -c $(CFLAGS) $< -o $@

$(EDA): $(OBJ)
	@echo mas nao... $@
	@$(CC) -c $(OBJ) -o $@

clean:
	@echo limpa limpa
	rm -f $(OBJDIR)/*.o

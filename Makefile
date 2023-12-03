CC = g++
CFLAGS = -Wall -g
OBJDIR = objects
SOLNUM = 03

main: $(OBJDIR)/Main.o $(OBJDIR)/Solution$(SOLNUM).o $(OBJDIR)/StringSplitter.o
	$(CC) $(CFLAGS) -o main $^

$(OBJDIR)/Main.o: Main.cpp Solution$(SOLNUM).h StringSplitter.h
	$(CC) $(CFLAGS) -c Main.cpp -o $(OBJDIR)/Main.o

$(OBJDIR)/Solution$(SOLNUM).o: Solution$(SOLNUM).cpp Solution$(SOLNUM).h
	$(CC) $(CFLAGS) -c Solution$(SOLNUM).cpp -o $(OBJDIR)/Solution$(SOLNUM).o

$(OBJDIR)/StringSplitter.o: StringSplitter.cpp StringSplitter.h
	$(CC) $(CFLAGS) -c $< -o $@
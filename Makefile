CC = g++
CFLAGS = -Wall -g
OBJDIR = objects

main: $(OBJDIR)/Main.o $(OBJDIR)/Solution02.o $(OBJDIR)/StringSplitter.o
	$(CC) $(CFLAGS) -o main $^

$(OBJDIR)/Main.o: Main.cpp Solution02.h StringSplitter.h
	$(CC) $(CFLAGS) -c Main.cpp -o $(OBJDIR)/Main.o

$(OBJDIR)/Solution02.o: Solution02.cpp Solution01.h
	$(CC) $(CFLAGS) -c Solution02.cpp -o $(OBJDIR)/Solution02.o

$(OBJDIR)/StringSplitter.o: StringSplitter.cpp StringSplitter.h
	$(CC) $(CFLAGS) -c $< -o $@
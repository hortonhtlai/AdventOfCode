CC = g++
CFLAGS = -Wall -g
OBJDIR = objects

main: $(OBJDIR)/Main.o $(OBJDIR)/Solution01.o $(OBJDIR)/StringSplitter.o
	$(CC) $(CFLAGS) -o main $(OBJDIR)/main.o $(OBJDIR)/Solution01.o $(OBJDIR)/StringSplitter.o

$(OBJDIR)/Main.o: Main.cpp Solution01.h StringSplitter.h
	$(CC) $(CFLAGS) -c Main.cpp -o $(OBJDIR)/Main.o

$(OBJDIR)/Solution01.o: Solution01.cpp Solution01.h
	$(CC) $(CFLAGS) -c Solution01.cpp -o $(OBJDIR)/Solution01.o

$(OBJDIR)/StringSplitter.o: StringSplitter.cpp StringSplitter.h
	$(CC) $(CFLAGS) -c StringSplitter.cpp -o $(OBJDIR)/StringSplitter.o
CC = g++
CFLAGS = -Wall -g
OBJDIR = objects
SOLNUM = 20

main: $(OBJDIR)/Main.o $(OBJDIR)/Solution$(SOLNUM).o $(OBJDIR)/StringParser.o
	$(CC) $(CFLAGS) -o main $^

$(OBJDIR)/Main.o: Main.cpp Solution$(SOLNUM).h StringParser.h
	$(CC) $(CFLAGS) -c Main.cpp -o $(OBJDIR)/Main.o

$(OBJDIR)/Solution%.o: Solution%.cpp Solution%.h StringParser.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/StringParser.o: StringParser.cpp StringParser.h
	$(CC) $(CFLAGS) -c $< -o $@
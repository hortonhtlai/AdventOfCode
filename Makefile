CC = g++
CFLAGS = -Wall -g
OBJDIR = objects

main: $(OBJDIR)/Main.o $(OBJDIR)/Solution*.o $(OBJDIR)/StringSplitter.o
	$(CC) $(CFLAGS) -o main $^

$(OBJDIR)/Main.o: Main.cpp Solution*.h StringSplitter.h
	$(CC) $(CFLAGS) -c Main.cpp -o $(OBJDIR)/Main.o

$(OBJDIR)/Solution%.o: Solution%.cpp Solution%.h StringSplitter.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/StringSplitter.o: StringSplitter.cpp StringSplitter.h
	$(CC) $(CFLAGS) -c $< -o $@
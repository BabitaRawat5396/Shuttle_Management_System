CC = g++
CFLAGS = -g
SRCDIR = src
OBJDIR = obj
BINDIR = bin
HEADERDIR = $(SRCDIR)/headers

HEADERS = $(wildcard $(HEADERDIR)/*.h)

SOURCES = $(wildcard $(SRCDIR)/*.cpp)

OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

TARGET = $(BINDIR)/Shuttle

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c $< -o $@

clean:
	del $(OBJDIR)\*.o
	del $(BINDIR)\Con_Man_Sys.exe

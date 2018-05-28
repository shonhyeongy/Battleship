CC = g++
TARGET = battleship
SOURCES = BattleShipApp.cpp \
            BattleShipMap_1.cpp \
            Pane.cpp \
            StatPane.cpp
LDFLAGS = -lncurses
all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)
clean:
	rm -rf *.o $(TARGET)

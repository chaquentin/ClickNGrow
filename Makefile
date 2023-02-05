##
## EPITECH PROJECT, 2023
## rush
## File description:
## Makefile
##

SRC =	AGameObject.cpp	\
		ConvertMoney.cpp	\
		DogPiss.cpp	\
		Egg.cpp	\
		Fertilizer.cpp	\
		GrandpaSkeleton.cpp	\
		GrandpasStool.cpp	\
		GrannyBreaksHerWater.cpp	\
		GrannysAshes.cpp	\
		Hud.cpp	\
		main.cpp	\
		Pub.cpp	\
		Rain.cpp	\
		WaterDrop.cpp	\
		WateringCan.cpp	\
		Save.cpp	\

$(eval SRC=$(addprefix src/, $(SRC)))

OBJ =	$(SRC:.cpp=.o)

%.o:	%.cpp
	$(CXX) -c -o $@ $< $(CFLAGS)

NAME =	ClickNGrow

CFLAGS = -Wall -Wextra -I./include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -ljsoncpp

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f vgcore.*
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug:	CFLAGS += -g3
debug:	re

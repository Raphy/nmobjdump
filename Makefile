##
## Makefile for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Tue Mar 11 11:36:38 2014 raphael defreitas
## Last update Tue Mar 11 11:58:49 2014 raphael defreitas
##

##### COMMON SETTINGS #####
CC		?=	clang

##### NM SETTINGS #####
NM_NAME		=	my_nm
NM_SOURCES	=	$(shell find nm/sources -name "*.c")
NM_OBJECTS	=	$(NM_SOURCES:.c=.o)
NM_CFLAGS	=	-I ./nm/headers -Wall -Wextra -pedantic 
NM_LDFLAGS	=	

##### OBJDUMP SETTINGS #####
OBJDUMP_NAME	=	my_objdump
OBJDUMP_SOURCES	=	$(shell find objdump/sources -name "*.c")
OBJDUMP_OBJECTS	=	$(OBJDUMP_SOURCES:.c=.o)
OBJDUMP_CFLAGS	=	-I ./objdump/headers -Wall -Wextra -pedantic
OBJDUMP_LDFLAGS	=	

##### NM RULES  #####
nm		:	CFLAGS = $(NM_CFLAGS)
nm		:	$(NM_OBJECTS)
			$(CC) $(NM_CFLAGS) $(NM_OBJECTS) -o $(NM_NAME) $(NM_LDFLAGS)

nm-clean	:
			rm -rf $(NM_OBJECTS)

nm-fclean	:	nm-clean
			rm -rf $(NM_NAME)

nm-re		:	nm-fclean nm

##### OBJDUMP RULES  #####
objdump		:	CFLAGS = $(OBJDUMP_CFLAGS)
objdump		:	$(OBJDUMP_OBJECTS)
			$(CC) $(OBJDUMP_CFLAGS) $(OBJDUMP_OBJECTS) -o $(OBJDUMP_NAME) $(OBJDUMP_LDFLAGS)

objdump-clean	:
			rm -rf $(OBJDUMP_OBJECTS)

objdump-fclean	:	objdump-clean
			rm -rf $(OBJDUMP_NAME)

objdump-re	:	objdump-fclean objdump

##### COMMON RULES  #####
all		:	nm objdump

clean		:	nm-clean objdump-clean

fclean		:	nm-fclean objdump-fclean

re		:	fclean all

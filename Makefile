##
## Makefile for nmobjdump in /home/raphy/Epitech/Tech_2/PSU_2013_nmobjdump
## 
## Made by raphael defreitas
## Login   <defrei_r@epitech.net>
## 
## Started on  Tue Mar 11 11:36:38 2014 raphael defreitas
## Last update Wed Mar 12 13:46:43 2014 raphael defreitas
##

##### COMMON SETTINGS #####
CC		?=	clang
COMMON_CFLAGS	=	-I ./common/headers -Wall -Wextra -pedantic -g
COMMON_SOURCES	=	$(shell find common/sources -name "*.c")
COMMON_OBJECTS	=	$(COMMON_SOURCES:.c=.o)

##### NM SETTINGS #####
NM_NAME		=	my_nm
NM_SOURCES	=	$(shell find nm/sources -name "*.c")
NM_OBJECTS	=	$(NM_SOURCES:.c=.o)
NM_CFLAGS	=	-I ./nm/headers
NM_LDFLAGS	=	

##### OBJDUMP SETTINGS #####
OBJDUMP_NAME	=	my_objdump
OBJDUMP_SOURCES	=	$(shell find objdump/sources -name "*.c")
OBJDUMP_OBJECTS	=	$(OBJDUMP_SOURCES:.c=.o)
OBJDUMP_CFLAGS	=	-I ./objdump/headers
OBJDUMP_LDFLAGS	=	

##### COMMON RULES  #####
all		:	nm objdump

clean		:	nm-clean objdump-clean
			rm -rf $(COMMON_OBJECTS)

fclean		:	clean nm-fclean objdump-fclean

re		:	fclean all

##### NM RULES  #####
nm		:	$(NM_NAME)

$(NM_NAME)	:	CFLAGS = $(COMMON_CFLAGS) $(NM_CFLAGS)
$(NM_NAME)	:	$(COMMON_OBJECTS) $(NM_OBJECTS)
			$(CC) $(CFLAGS) $(COMMON_OBJECTS) $(NM_OBJECTS) -o $(NM_NAME) $(LDFLAGS)

nm-clean	:
			rm -rf $(NM_OBJECTS)

nm-fclean	:	nm-clean
			rm -rf $(NM_NAME)

nm-re		:	nm-fclean nm

##### OBJDUMP RULES  #####
objdump		:	$(OBJDUMP_NAME)

$(OBJDUMP_NAME)	:	CFLAGS = $(COMMON_CFLAGS) $(OBJDUMP_CFLAGS)
$(OBJDUMP_NAME)	:	$(COMMON_OBJECTS) $(OBJDUMP_OBJECTS)
			$(CC) $(CFLAGS) $(COMMON_OBJECTS) $(OBJDUMP_OBJECTS) -o $(OBJDUMP_NAME) $(LDFLAGS)

objdump-clean	:
			rm -rf $(OBJDUMP_OBJECTS)

objdump-fclean	:	objdump-clean
			rm -rf $(OBJDUMP_NAME)

objdump-re	:	objdump-fclean objdump

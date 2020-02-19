#
# PROGRAM:    assignment9.cc
# PROGRAMMER: Margaret Higginbotham
# LOGON ID:   Z1793581
# DATE DUE:   May 2, 2018
#

# Complier Variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment9.exe: assignment9.cc
	g++ $(CCFLAGS) assignment9.cc -o assignment9.exe

# Pseudo-target to remove object code and executable files
clean:
	-rm assignment9.exe

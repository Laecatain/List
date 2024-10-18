# Makefile for compiling List.cpp into list_test executable and generating a report

CC=g++
CFLAGS=-Wall -std=c++20

# Define object files and executable name
OBJ=list.o
EXECUTABLE=list_test

# Define source and header files
SOURCES=List.cpp
HEADERS=List.h

# Define the report files
REPORT_SRC=report.tex
REPORT_PDF=report.pdf

# Rule to compile the sources into an executable
$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(HEADERS)

# Rule to compile a single object file
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and executable
clean:
	rm -f $(OBJ) $(EXECUTABLE) $(REPORT_PDF) *.log *.aux *.out *.toc *.bbl *.blg

# Rule to generate the report
report: $(REPORT_PDF)

# Rule to compile the LaTeX report using xelatex
$(REPORT_PDF): $(REPORT_SRC)
	xelatex $(REPORT_SRC)

# Default target is to build the executable
all: $(EXECUTABLE)

.PHONY: all clean report

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic

.PHONY: help list all clean 1 2 3
help: list
list:
	@echo "make 1: build and check Task A (GradeItem)"
	@echo "make 2: build and check Task B (Lab and Exam)"
	@echo "make 3: build and check Task C (Quiz, report functions, gradebook)"
all: task_a_check task_b_check task_c_check gradebook
1: task_a_check
	@./task_a_check
2: task_b_check
	@./task_b_check
3: task_c_check gradebook
	@status=0; ./task_c_check || status=1; \
	bash support/compare_output.sh ./gradebook expected/gradebook.txt || status=1; \
	exit $$status
task_a_check: grade_item.h support/task_a_driver.cpp
	$(CXX) $(CXXFLAGS) support/task_a_driver.cpp -o task_a_check
task_b_check: grade_item.h support/task_b_driver.cpp
	$(CXX) $(CXXFLAGS) support/task_b_driver.cpp -o task_b_check
task_c_check: grade_item.h report_functions.cpp support/task_c_driver.cpp
	$(CXX) $(CXXFLAGS) report_functions.cpp support/task_c_driver.cpp -o task_c_check
gradebook: grade_item.h report_functions.cpp gradebook.cpp
	$(CXX) $(CXXFLAGS) report_functions.cpp gradebook.cpp -o gradebook
clean:
	$(RM) task_a_check task_a_check.exe task_b_check task_b_check.exe task_c_check task_c_check.exe gradebook gradebook.exe *.o *.obj

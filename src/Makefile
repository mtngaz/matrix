WWW = -Werror -Wextra -Wall
G = gcc
OS = $(shell uname)

ifeq ($(OS), Linux)
	FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
	FLAGS = -lcheck
endif

all : clean s21_matrix.a test gcov_report

clean: 
	rm -rf *.o *.a *.gch *.gcno *.gcna *.gcda *.info test test_html

test: clean
	$(G) $(WWW) s21_*.c unit_test.c real_matrix.c create_complements_matrix.c create_minor.c get_determinant.c $(FLAGS) -o test
	./test

s21_matrix.a:
	$(G) $(WWW) -c s21_*.c real_matrix.c create_complements_matrix.c create_minor.c get_determinant.c
	ar r s21_matrix.a *.o
	rm *.o

gcov_report:
	$(G) $(WWW) -fprofile-arcs -ftest-coverage unit_test.c real_matrix.c create_complements_matrix.c create_minor.c get_determinant.c s21_*.c $(FLAGS) -o test
	./test
	lcov -t "test_html" -o unit_test.info -c -d .
	genhtml -o test_html unit_test.info
	open test_html/index.html

leaks:
	leaks -atExit -- ./test

style_i:
	clang-format -style=google -i s21_*.c s21_*.h real_matrix.c create_complements_matrix.c create_minor.c get_determinant.c unit_test.c

style_n:
	clang-format -style=google -n s21_*.c s21_*.h real_matrix.c create_complements_matrix.c create_minor.c get_determinant.c unit_test.c
CPPSTATIC=main.o actions/delete_button.o actions/copy_button.o actions/move_button.o filesystem_management/filesystem_management.o filesystem_management/gtk_filesystem_entry.o command_handling/command_button.o command_handling/command_text_view.o command_handling/shell_usage.o
HEADERS=actions/delete_button.h actions/action_button.h actions/copy_button.h actions/move_button.h actions/actions_grid.h filesystem_management/filesystem_abstract_class.h filesystem_management/filesystem_management.h filesystem_management/gtk_filesystem_entry.h command_handling/command_button.h command_handling/command_text_view.h command_handling/shell_usage.h

all:	target
	g++ --std="c++14" $(shell pkg-config --cflags glibmm-2.4 gtkmm-3.0) -Bstatic $(CPPSTATIC) $(shell pkg-config --libs glibmm-2.4 gtkmm-3.0) -o main
target:	$(CPPSTATIC)
.SUFFIXES:	.o .cpp .h


depend: .depend

.depend: $(HEADERS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ -MF  ./.depend;

include .depend

.cpp.o:
	g++ -c --std="c++14" $(shell pkg-config --cflags glibmm-2.4 gtkmm-3.0) $< -o $@ $(shell pkg-config --libs glibmm-2.4 gtkmm-3.0)

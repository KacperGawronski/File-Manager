#include "move_button.h"
/*
FilesystemEntriesView *left_view,*right_view;
Gtk::Entry *left_path_entry,*right_path_entry;
*/


actions::MoveButton::MoveButton(Gtk::Entry &left_path, Gtk::Entry &right_path,FileSystemEntriesView &left,FileSystemEntriesView &right):ActionButton(left_path,right_path,left,right){
	this->set_label("Move");
}

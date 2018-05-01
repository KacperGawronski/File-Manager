#include "move_button.h"
/*
FilesystemEntriesView *left_view,*right_view;
Gtk::Entry *left_path_entry,*right_path_entry;
*/


actions::MoveButton::MoveButton(ACTION_BUTTON_CONSTRUCTOR_LONG_ARGS):ActionButton(ACTION_BUTTON_SHORT_ARGS){
	this->set_label("Move");
}

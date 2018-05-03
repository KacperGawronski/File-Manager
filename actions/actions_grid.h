#ifndef ACTIONS_GRID_H
#define ACTIONS_GRID_H
#include <gtkmm-3.0/gtkmm.h>
#include "move_button.h"
#include "copy_button.h"
#include "delete_button.h"
class ActionsGrid:public Gtk::Grid{
	private:
		//actions::MoveButton *move_button;
		actions::CopyButton *copy_button;
		//actions::DeleteButton *delete_button;
	public:
		ActionsGrid(FileSystemEntriesView &left,FileSystemEntriesView &right);
		
		~ActionsGrid();
};



#endif
